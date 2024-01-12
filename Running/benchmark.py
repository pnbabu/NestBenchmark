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
NETWORKSCALES = np.logspace(3, 5, 10, dtype=int)
NUMTHREADS = 32

VERTICALTHREADS = np.power(2, np.arange(0, 6, 1, dtype=int))
VERTICALNEWORKSCALE = NETWORKSCALES[-1]
ITERATIONS=10
DEBUG = False

output_folder = os.path.join(os.path.dirname(__file__), '..', 'Output')
    

def start_Horizontal_Benchmark(iteration, checkMemory=False):
    insert = "/usr/bin/time -f \'%M\'" if checkMemory else ""
    combinations = [{"command":['bash', '-c', f'source {PATHTOSHFILE} && {insert} python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {networkscale} --threads {NUMTHREADS} --iteration {iteration} --benchmarkPath timings' ],"name":f"{neuronmodel}","networksize":networkscale} for neuronmodel in NEURONMODELS for networkscale in NETWORKSCALES]
    print(f"\033[93mHorizontal Benchmark {iteration}\033[0m")
    memoryDict = {}
    for combination in combinations:
        combined = combination["name"]+","+str(combination["networksize"])
        print(f"\033[93m{combined}\033[0m")
        result = None
        if DEBUG:
            result = subprocess.run(combination["command"], capture_output=False, stderr=subprocess.PIPE)
        else:
            result = subprocess.run(combination["command"], capture_output=False, stdout=subprocess.DEVNULL, stderr=subprocess.PIPE)
        if result.returncode != 0:
            print(f"\033[91m{combination['name']} failed\033[0m")
            sys.exit(1)
        if checkMemory:
            memory = int(result.stderr)
            print(f"\033[93mMemory: {memory}\033[0m")
            memoryDict.setdefault(combination["name"], {}).setdefault(combination["networksize"], []).append(memory)

        deleteDat()
    if checkMemory:
        return memoryDict

def start_Vertical_Benchmark(iteration):
    combinations = [{"command":['bash', '-c', f'source {PATHTOSHFILE} && python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {VERTICALNEWORKSCALE} --threads {threads} --iteration {iteration} --benchmarkPath verticaltimings'],"name":f"{neuronmodel},{threads}"} for neuronmodel in NEURONMODELS for threads in VERTICALTHREADS]
    print(f"Vertical Benchmark {iteration}")
    for combination in combinations:
        print(combination["name"])
        subprocess.run(combination["command"], capture_output=False, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        deleteDat()


def extract_value_from_filename(filename, key):
    pattern = fr"\[{key}=(.*?)\]"
    match = re.search(pattern, filename)
    return match.group(1) if match else None

def plot_benchmark(data):
    realTimeFactors = {}
    for neuron in data:
        realTimeFactors[neuron] = {}
        for scale in data[neuron]:
            iterations = data[neuron][scale].keys()
            realTimeFactors[neuron][scale] = [data[neuron][scale][iteration]["time_simulate"] / (data[neuron][scale][iteration]["biological_time"] / 1000) for iteration in iterations]

    plt.figure()
    neurons = []
    for neuron, values in realTimeFactors.items():
        neurons.append(neuron)
        items = sorted(values.items())
        x, y = zip(*items)
        y = np.array(y)  # convert y to a numpy array
        y_mean = np.mean(y, axis=1)  # calculate mean for each network scale
        y_std = np.std(y, axis=1)  # calculate standard deviation for each network scale
        plt.errorbar(x, y_mean, yerr=y_std, fmt='-', ecolor='k', capsize=3)

    plt.xscale('log')
    plt.yscale('log')
    formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
    plt.gca().yaxis.set_major_formatter(formatter)

    plt.xlabel('Network Scale')
    plt.ylabel('Real Time Factor')
    plt.legend(neurons)
    
    plt.savefig(os.path.join(output_folder, 'output.png'))

    for neuron in data:
        plt.figure()
        
    


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

        plt.xlabel('Network Scale')
        plt.ylabel('Time')
        plt.title(stopwatch)
        plt.legend(neurons)
        plt.savefig(os.path.join(output_folder, f'output_{stopwatch}.png'))
    
        
def plot_verticalScaling(verticaldata):
    plt.figure()
    neurons = []
    for neuron, values in verticaldata.items():
        neurons.append(neuron)
        x = sorted(values.keys())
        y = np.array([np.mean([iteration_data['time_simulate'] for iteration_data in values[threads].values()]) for threads in x])
        y_std = np.array([np.std([iteration_data['time_simulate'] for iteration_data in values[threads].values()]) for threads in x])
        plt.errorbar(x, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)
    plt.xlabel('Threads')
    plt.ylabel('Time')

    plt.xscale('log')
    plt.yscale('log')
    formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
    plt.gca().yaxis.set_major_formatter(formatter)
    
    plt.legend(neurons)
    plt.savefig(os.path.join(output_folder, 'output_vertical.png'))

def plotMemory(memoryData):
    for neuron, values in memoryData.items():
        plt.figure()
        x = sorted(values.keys())
        y = np.array([np.mean([iteration_data for iteration_data in values[scale].values()]) for scale in x])
        y_std = np.array([np.std([iteration_data for iteration_data in values[scale].values()]) for scale in x])
        plt.errorbar(x, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)
        plt.xlabel('Network Scale')
        plt.ylabel('Memory(Bits)')
        plt.xscale('log')
        plt.yscale('log')
        formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
        plt.gca().yaxis.set_major_formatter(formatter)
        plt.title(neuron)
        plt.savefig(os.path.join(output_folder, f'output_memory_{neuron}.png'))



            
def deleteDat():
    for filename in os.listdir("./"):
        if filename.endswith(".dat"):
            os.remove(f"./{filename}")

def deleteJson():
    for filename in os.listdir("./timings"):
        if filename.endswith(".json"):
            os.remove(f"./timings/{filename}")
    for filename in os.listdir("./verticaltimings"):
        if filename.endswith(".json"):
            os.remove(f"./verticaltimings/{filename}")
            
      

if __name__ == "__main__":
    args = parser.parse_args()
    runSim = args.noRunSim
        
    os.makedirs(output_folder, exist_ok=True)
    os.makedirs("timings", exist_ok=True)
    os.makedirs("verticaltimings", exist_ok=True)
    
    memoryData = {}
    if runSim:
        deleteJson()
        for i in range(ITERATIONS):
            #start_Horizontal_Benchmark(i)
            #start_Vertical_Benchmark(i)
            data = start_Horizontal_Benchmark(i, checkMemory=True)
            for name, size_data in data.items():
                memoryData.setdefault(name, {})
                for size, iteration_data in size_data.items():
                    memoryData[name].setdefault(size, {})
                    memoryData[name][size][i] = iteration_data[0]
        plotMemory(memoryData)

    deleteDat()
    data = {}
    for filename in os.listdir("./timings"):
        if filename.endswith(".json"):
            simulated_neuron = extract_value_from_filename(filename, "simulated_neuron")
            network_scale = int(extract_value_from_filename(filename, "network_scale"))
            iteration = int(extract_value_from_filename(filename, "iteration"))
            with open(f"./timings/{filename}", "r") as f:
                json_data = json.load(f)
                data.setdefault(simulated_neuron, {}).setdefault(network_scale, {}).setdefault(iteration, json_data)
    plot_benchmark(data)
    plot_timedist(data)
    plot_Custom(data)
            
    verticaldata={}
    for filename in os.listdir("./verticaltimings"):
        if filename.endswith(".json"):
            simulated_neuron = extract_value_from_filename(filename, "simulated_neuron")
            iteration = int(extract_value_from_filename(filename, "iteration"))
            threads = int(extract_value_from_filename(filename, "threads"))
            with open(f"./verticaltimings/{filename}", "r") as f:
                json_data = json.load(f)
                verticaldata.setdefault(simulated_neuron, {}).setdefault(threads, {}).setdefault(iteration, json_data)
    plot_verticalScaling(verticaldata)

