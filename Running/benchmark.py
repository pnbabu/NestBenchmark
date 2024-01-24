import argparse
import subprocess
import sys
import os
import re
import json
import math
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FuncFormatter
import os

parser = argparse.ArgumentParser(description='Run a Benchmark with NEST')
parser.add_argument('--noRunSim', action="store_false", help='Run the Benchmark with NEST Simulator')

current_dir = os.path.dirname(os.path.abspath(__file__))
PATHTOFILE = os.path.join(current_dir, "examples/brunel_alpha_nest.py")
PATHTOSHFILE = os.path.join(current_dir, "start.sh")

NEURONMODELS = ["iaf_psc_alpha_neuron_Nestml_Optimized","iaf_psc_alpha_neuron_Nestml"
                ,"iaf_psc_alpha"
                ]
#NEURONMODELS = ["iaf_psc_alpha"]
#NETWORKSCALES = np.logspace(3.4, 4, 3, dtype=int)
NETWORKSCALES = np.logspace(3, math.log10(30000), 10, dtype=int)

NEURONSPERSCALE = 5

VERTICALTHREADS = np.power(2, np.arange(3, 6, 1, dtype=int))
NUMTHREADS = VERTICALTHREADS[-1]
VERTICALNEWORKSCALE = NETWORKSCALES[-1]
ITERATIONS=10
DEBUG = False

STRONGSCALINGFOLDERNAME = "timings_strong_scaling"
WEAKSCALINGFOLDERNAME = "timings_weak_scaling" 

output_folder = os.path.join(os.path.dirname(__file__), '..', 'Output')
    

def start_weak_scaling_Benchmark(iteration, checkMemory=False):
    insert = "/usr/bin/time -f \'%M\'" if checkMemory else ""
    combinations = [{"command":['bash', '-c', f'source {PATHTOSHFILE} && {insert} python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {networkscale} --threads {NUMTHREADS} --iteration {iteration} --benchmarkPath {WEAKSCALINGFOLDERNAME}' ],"name":f"{neuronmodel}","networksize":networkscale} for neuronmodel in NEURONMODELS for networkscale in NETWORKSCALES]
    print(f"\033[93mMemory Scaling Benchmark {iteration}\033[0m" if checkMemory else f"\033[93mWeak Scaling Benchmark {iteration}\033[0m")
    memoryDict = {}
    for combination in combinations:
        combined = combination["name"]+","+str(combination["networksize"])
        print(f"\033[93m{combined}\033[0m" if DEBUG else combined)
        result = None
        if DEBUG:
            result = subprocess.run(combination["command"], capture_output=False, stderr=subprocess.PIPE)
        else:
            result = subprocess.run(combination["command"], capture_output=False, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE)
        if result.returncode != 0:
            print(f"\033[91m{combination['name']} failed\033[0m")
            print(f"\033[91m{result.stderr} failed\033[0m")
        if checkMemory:
            memory = int(result.stderr)
            print(f"\033[93mMemory: {memory}\033[0m" if DEBUG else f"Memory: {memory}")
            memoryDict.setdefault(combination["name"], {}).setdefault(combination["networksize"], []).append(memory)

        deleteDat()
    if checkMemory:
        return memoryDict

def start_strong_scaling_Benchmark(iteration):
    combinations = [{"command":['bash', '-c', f'source {PATHTOSHFILE} && python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {VERTICALNEWORKSCALE} --threads {threads} --iteration {iteration} --benchmarkPath {STRONGSCALINGFOLDERNAME}'],"name":f"{neuronmodel},{threads}"} for neuronmodel in NEURONMODELS for threads in VERTICALTHREADS]
    print(f"Strong Scaling Benchmark {iteration} with {VERTICALNEWORKSCALE} neurons")
    for combination in combinations:
        print(combination["name"])
        result = subprocess.run(combination["command"], capture_output=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if result.returncode != 0:
            print(f"\033[91m{combination['name']} failed\033[0m")
            print(f"\033[91m{result.stderr} failed\033[0m")
        deleteDat()

def extract_value_from_filename(filename, key):
    pattern = fr"\[{key}=(.*?)\]"
    match = re.search(pattern, filename)
    return match.group(1) if match else None

def plot_weak_scaling(data):
    plt.figure()
    neurons = []
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        #Real Time Factor
        y = np.array([np.mean([iteration_data['time_simulate']/iteration_data["biological_time"]/1000 for iteration_data in values[threads].values()]) for threads in x])
        
        y_std = np.array([np.std([iteration_data['time_simulate']/iteration_data["biological_time"]/1000 for iteration_data in values[threads].values()]) for threads in x])
        x = [int(val) for val in x]
        plt.errorbar(x, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)
    
    plt.xlabel('Neuron Count')
    plt.ylabel('Real Time Factor')

    plt.xscale('log')
    plt.yscale('log')
    formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
    plt.gca().yaxis.set_major_formatter(formatter)
    
    plt.legend(neurons) 
    plt.savefig(os.path.join(output_folder, 'weak_scaling.png'))
     
def plot_timedist(data):
    for neuron, scales in data.items():
        plt.figure() 
        x = sorted(scales.keys())
        simulation_times = [np.mean([iteration_data['time_simulate'] for iteration_data in scales[scale].values()]) for scale in x]
        simulation_std = [np.std([iteration_data['time_simulate'] for iteration_data in scales[scale].values()]) for scale in x]
        building_times = [np.mean([iteration_data['time_construction_connect'] for iteration_data in scales[scale].values()]) for scale in x]
        building_std = [np.std([iteration_data['time_construction_connect'] for iteration_data in scales[scale].values()]) for scale in x]
        total_times = [sim + build for sim, build in zip(simulation_times, building_times)]
        total_std = [sim_std + build_std for sim_std, build_std in zip(simulation_std, building_std)]
        plt.fill_between(x, total_times, label=f'{neuron} building')
        plt.fill_between(x, simulation_times, label=f'{neuron} simulation')
        plt.errorbar(x, total_times, yerr=total_std, fmt='k', capsize=3) 
        plt.errorbar(x, simulation_times, yerr=simulation_std, fmt='k', capsize=3)  
        plt.xlabel('Network Scale')
        plt.ylabel('Time')

        formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
        plt.gca().yaxis.set_major_formatter(formatter)
        formatterX = FuncFormatter(lambda x, _: '{:.16g}'.format(x * NEURONSPERSCALE))
        plt.gca().xaxis.set_major_formatter(formatterX)

        plt.title(neuron)
        plt.legend()
        plt.savefig(os.path.join(output_folder, f'output_{neuron}.png'))

def plot_Custom(data):
    neuron = next(iter(data))
    size = next(iter(data[neuron]))
    entry = data[neuron][size]
    stopwatches = entry[0]["stopwatches"].keys()

    for stopwatch in stopwatches:
        plt.figure()
        neurons = []
        for neuron, scales in data.items():
            neurons.append(neuron)
            x = sorted(scales.keys())
            y = np.array([np.mean([iteration_data['stopwatches'][stopwatch] for iteration_data in scales[scale].values()]) for scale in x])
            y_std = np.array([np.std([iteration_data['stopwatches'][stopwatch] for iteration_data in scales[scale].values()]) for scale in x])
            plt.errorbar(x, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)

        plt.xscale('log')
        plt.yscale('log')
        formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
        plt.gca().yaxis.set_major_formatter(formatter)
        formatterX = FuncFormatter(lambda x, _: '{:.16g}'.format(x * NEURONSPERSCALE))
        plt.gca().xaxis.set_major_formatter(formatterX)

        plt.xlabel('Network Scale')
        plt.ylabel('Time')
        plt.title(stopwatch)
        plt.legend(neurons)
        plt.savefig(os.path.join(output_folder, f'output_{stopwatch}.png'))
        
def plot_strong_scaling(verticaldata):
    plt.figure()
    neurons = []
    for neuron, values in verticaldata.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        # Real Time Factor
        y = np.array([np.mean([iteration_data['time_simulate']/iteration_data["biological_time"]/1000 for iteration_data in values[threads].values()]) for threads in x])
        y_std = np.array([np.std([iteration_data['time_simulate']/iteration_data["biological_time"]/1000 for iteration_data in values[threads].values()]) for threads in x])
        x = [int(val) for val in x]
        plt.errorbar(x, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)
        
    plt.xlabel('Threads')
    plt.ylabel('Real Time Factor')

    
    
    plt.xscale('log')
    plt.yscale('log')

    plt.legend(neurons)
    plt.savefig(os.path.join(output_folder, 'strong_scaling.png'))

def format_bytes(x,_):
    units = ['B', 'KB', 'MB', 'GB', 'TB', 'PB', 'EB', 'ZB', 'YB']
    unit_index = 1  # Set unit_index to 1 for Kbytes


    while x >= 1024 and unit_index < len(units) - 1:
        x /= 1024
        unit_index += 1
    formatted_size = '{:.2f}'.format(x)
    return f'{formatted_size} {units[unit_index]}'

def plotMemory(memoryData):
    plt.figure()
    max_y = 0 
    for neuron, values in memoryData.items():
        x = sorted(values.keys(), key=lambda k: int(k))
        y = np.array([np.mean([iteration_data for iteration_data in values[scale].values()]) for scale in x])
        y_std = np.array([np.std([iteration_data for iteration_data in values[scale].values()]) for scale in x])
        x = [int(val) for val in x] 
        plt.errorbar(x, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)

        if max(y) > max_y:
            max_y = max(y)

    plt.annotate(f'Max: {format_bytes(max_y,"")}', xy=(0.8, max_y), xytext=(8, 0), 
                 xycoords=('axes fraction', 'data'), textcoords='offset points')
    plt.xlabel('Network Scale')
    plt.ylabel('Memory')
    plt.xscale('log')
    plt.yscale('log')
    formatter = FuncFormatter(format_bytes)
    plt.gca().yaxis.set_major_formatter(formatter)
    formatterX = FuncFormatter(lambda x, _: '{:.16g}'.format(x * NEURONSPERSCALE))
    plt.gca().xaxis.set_major_formatter(formatterX)
    
    plt.legend(memoryData.keys())
    plt.savefig(os.path.join(output_folder, 'output_memory.png'))
           
def deleteDat():
    for filename in os.listdir("./"):
        if filename.endswith(".dat"):
            os.remove(f"./{filename}")

def deleteJson():
    for filename in os.listdir(f"./{WEAKSCALINGFOLDERNAME}"):
        if filename.endswith(".json"):
            os.remove(f"./{WEAKSCALINGFOLDERNAME}/{filename}")
    for filename in os.listdir(f"./{STRONGSCALINGFOLDERNAME}"):
        if filename.endswith(".json"):
            os.remove(f"./{STRONGSCALINGFOLDERNAME}/{filename}")
            
if __name__ == "__main__":
    args = parser.parse_args()
    runSim = args.noRunSim
        
    os.makedirs(output_folder, exist_ok=True)
    os.makedirs(WEAKSCALINGFOLDERNAME, exist_ok=True)
    os.makedirs(STRONGSCALINGFOLDERNAME, exist_ok=True)
    
    
    if runSim:
        memoryData = {}
        deleteJson()
        for i in range(ITERATIONS):
            data = start_weak_scaling_Benchmark(i, checkMemory=True)
            start_strong_scaling_Benchmark(i)
            start_weak_scaling_Benchmark(i)
            for name, size_data in data.items():
                memoryData.setdefault(name, {})
                for size, iteration_data in size_data.items():
                    memoryData[name].setdefault(int(size), {})
                    memoryData[name][int(size)][i] = iteration_data[0]
        with open("memory_data.json", "w") as f:
            json.dump(memoryData, f, indent=4)
    memoryData = {}
    
    with open("memory_data.json", "r") as f:
        memoryData = json.load(f)
    
    plotMemory(memoryData)

    deleteDat()
    data = {}
    for filename in os.listdir(f"./{WEAKSCALINGFOLDERNAME}"):
        if filename.endswith(".json"):
            simulated_neuron = extract_value_from_filename(filename, "simulated_neuron")
            network_scale = int(extract_value_from_filename(filename, "network_scale"))
            iteration = int(extract_value_from_filename(filename, "iteration"))
            with open(f"./{WEAKSCALINGFOLDERNAME}/{filename}", "r") as f:
                json_data = json.load(f)
                data.setdefault(simulated_neuron, {}).setdefault(network_scale, {}).setdefault(iteration, json_data)
    plot_weak_scaling(data)
    plot_timedist(data)
    plot_Custom(data)
            
    verticaldata={}
    for filename in os.listdir(f"./{STRONGSCALINGFOLDERNAME}"):
        if filename.endswith(".json"):
            simulated_neuron = extract_value_from_filename(filename, "simulated_neuron")
            iteration = int(extract_value_from_filename(filename, "iteration"))
            threads = int(extract_value_from_filename(filename, "threads"))
            with open(f"./{STRONGSCALINGFOLDERNAME}/{filename}", "r") as f:
                json_data = json.load(f)
                verticaldata.setdefault(simulated_neuron, {}).setdefault(threads, {}).setdefault(iteration, json_data)
    plot_strong_scaling(verticaldata)

