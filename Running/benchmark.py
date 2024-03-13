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

# for iaf_psc_alpha neurons
BASELINENEURON = "iaf_psc_alpha"
NEURONMODELS = [
                "iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic",
                #"iaf_psc_alpha_neuron_Nestml_Optimized",
                "iaf_psc_alpha_neuron_Nestml",
                BASELINENEURON
                ]

legend = {
                "iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic" : "NESTML neur, NESTML syn",
                #"iaf_psc_alpha_neuron_Nestml_Optimized",
                "iaf_psc_alpha_neuron_Nestml":"NESTML neur, NEST syn",
                BASELINENEURON : "NEST neur + syn"
}
"""


# for aeif_psc_alpha neurons
BASELINENEURON = "aeif_psc_alpha"
NEURONMODELS = [
                "aeif_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic",
                #"iaf_psc_alpha_neuron_Nestml_Optimized",
                "aeif_psc_alpha_neuron_Nestml",
                BASELINENEURON
                ]

legend = {
                "aeif_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic" : "NESTML neur, NESTML syn",
                #"iaf_psc_alpha_neuron_Nestml_Optimized",
                "aeif_psc_alpha_neuron_Nestml": "NESTML neur, NEST syn",
                BASELINENEURON : "NEST neur + syn"
}
"""




#NEURONMODELS = ["iaf_psc_alpha"]
#NETWORKSCALES = np.logspace(3.4, 4, 3, dtype=int)
NETWORKSCALES = np.logspace(3, math.log10(20000), 5, dtype=int)  # XXXXXXXXXXXX: was 10 and 30000

NEURONSPERSCALE = 5

#VERTICALTHREADS = np.power(2, np.arange(0, 6, 1, dtype=int))
VERTICALTHREADS = [1, 2, 4, 8, 16, 32, 64, 128] # XXXXXXXXXXXXXXX: more resolution
NUMTHREADS = VERTICALTHREADS[-1]
VERTICALNEWORKSCALE = 10000
ITERATIONS = 2 # XXXXXXXXXXXX: was 10
DEBUG = True

STRONGSCALINGFOLDERNAME = "timings_strong_scaling"
WEAKSCALINGFOLDERNAME = "timings_weak_scaling" 

output_folder = os.path.join(os.path.dirname(__file__), '..', 'Output')

def log(message):
    print(message)
    with open(os.path.join(output_folder,"log.txt"), "a") as f:
        f.write(f"{message}\n")

def start_weak_scaling_Benchmark(iteration, checkMemory=False):
    insert = "/usr/bin/time -f \'%M\'" if checkMemory else ""
    #benchmarkPathStr = '--benchmarkPath ' + WEAKSCALINGFOLDERNAME + "_mem" if checkMemory else ""
    benchmarkPathStr = '--benchmarkPath ' + WEAKSCALINGFOLDERNAME if not checkMemory else ""
    combinations = [{"command":['bash', '-c', f'source {PATHTOSHFILE} && {insert} python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {networkscale} --threads {NUMTHREADS} --iteration {iteration} {benchmarkPathStr}' ],"name":f"{neuronmodel}","networksize":networkscale} for neuronmodel in NEURONMODELS for networkscale in NETWORKSCALES]

    
    log(f"\033[93mMemory Scaling Benchmark {iteration}\033[0m" if checkMemory else f"\033[93mWeak Scaling Benchmark {iteration}\033[0m")
    memoryDict = {}
    for combination in combinations:
        print("RUNNING FOR " + str(combination))
        combined = combination["name"]+","+str(combination["networksize"])
        log(f"\033[93m{combined}\033[0m" if DEBUG else combined)
        result = subprocess.run(combination["command"], text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        if result.stdout:
            fname = "stdout_weak_run_" + combined + "_[iter=" + str(iteration) + "].txt"
            with open(fname, "w") as f:
                f.write(result.stdout)

        if result.stderr:
            fname = "stderr_weak_run_" + combined + "_[iter=" + str(iteration) + "].txt"
            with open(fname, "w") as f:
                f.write(result.stderr)

        if result.returncode != 0:
            log(f"\033[91m{combination['name']} failed\033[0m")
            log(f"\033[91m{result.stderr} failed\033[0m")
        if checkMemory:
            memory = int(result.stderr)
            log(f"\033[93mMemory: {memory}\033[0m" if DEBUG else f"Memory: {memory}")
            memoryDict.setdefault(combination["name"], {}).setdefault(combination["networksize"], []).append(memory)

        deleteDat()
    if checkMemory:
        return memoryDict

def start_strong_scaling_Benchmark(iteration):
    combinations = [{"command":['bash', '-c', f'source {PATHTOSHFILE} && python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {VERTICALNEWORKSCALE} --threads {threads} --iteration {iteration} --benchmarkPath {STRONGSCALINGFOLDERNAME}'],"name":f"{neuronmodel},{threads}"} for neuronmodel in NEURONMODELS for threads in VERTICALTHREADS]
    log(f"Strong Scaling Benchmark {iteration} with {VERTICALNEWORKSCALE} neurons")
    for combination in combinations:
        log(combination["name"])

        combined = combination["name"]

        result = subprocess.run(combination["command"], text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        if result.stdout:
            fname = "stdout_strong_run_" + combined + "_[iter=" + str(iteration) + "].txt"
            with open(fname, "w") as f:
                f.write(result.stdout)

        if result.stderr:
            fname = "stderr_strong_run_" + combined + "_[iter=" + str(iteration) + "].txt"
            with open(fname, "w") as f:
                f.write(result.stderr)

        if result.returncode != 0:
            log(f"\033[91m{combination['name']} failed\033[0m")
            log(f"\033[91m{result.stderr} failed\033[0m")
        deleteDat()


def extract_value_from_filename(filename, key):
    pattern = fr"\[{key}=(.*?)\]"
    match = re.search(pattern, filename)
    return match.group(1) if match else None


def plot_weak_scaling(data):
    plt.figure()
    neurons = []
    referenceValues = data[BASELINENEURON]
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        print("Time_simulate:")
        for threads in x:
            _ = [print(iteration_data['time_simulate']) for iteration_data in values[threads].values()]
        print("biological_time:")
        for threads in x:
            _ = [print(iteration_data['biological_time']) for iteration_data in values[threads].values()]
        y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_std = np.array([np.std([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])

        x = np.array([int(val) for val in x], dtype=int)
        plt.errorbar(x * NEURONSPERSCALE, y, yerr=y_std, label=legend[neuron], fmt='-', ecolor='k', capsize=3)
    
    plt.xlabel('Neuron count')
    plt.ylabel('Wall clock time (s)')
    plt.xscale('log')
    plt.legend() 
    plt.savefig(os.path.join(output_folder, 'weak_scaling_abs.png'))




    plt.figure()
    neurons = []
    referenceValues = data[BASELINENEURON]
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        # Real Time Factor
        reference_y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in referenceValues[threads].values()]) for threads in x])
        y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor = y / reference_y  # Calculate the factor of y in comparison to the reference value
        
        y_std = np.array([np.std([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor_std = y_std / reference_y  # Calculate the standard deviation of the factor
        
        x = np.array([int(val) for val in x], dtype=int)
        plt.errorbar(x * NEURONSPERSCALE, y_factor, yerr=y_factor_std, label=legend[neuron], fmt='-', ecolor='k', capsize=3)
    
    plt.xlabel('Neuron count')
    plt.ylabel('Wall clock time (ratio)')

    plt.xscale('log')

    
    plt.legend() 
    plt.savefig(os.path.join(output_folder, 'weak_scaling_rel.png'))




    plt.figure()
    neurons = []
    referenceValues = data[BASELINENEURON]
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        # Real Time Factor
        reference_y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in referenceValues[threads].values()]) for threads in x])
        y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor = y / reference_y  # Calculate the factor of y in comparison to the reference value
        
        y_std = np.array([np.std([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        #y_factor_std = reference_y / y_std  # Calculate the standard deviation of the factor
        y_factor_std = y_std / reference_y  # Calculate the standard deviation of the factor
        
        x = np.array([int(val) for val in x], dtype=int)
        plt.errorbar(x * NEURONSPERSCALE, y, yerr=y_std, label=legend[neuron], fmt='-', ecolor='k', capsize=3)
    
    plt.xlabel('Neuron count')
    plt.ylabel('Wall clock time (ratio)')

    plt.xscale('log')

    #formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
    #plt.gca().yaxis.set_major_formatter(formatter)
    
    plt.legend()
    plt.savefig(os.path.join(output_folder, 'weak_scaling.png'))


     
def plot_timedist(data):
    for neuron, scales in data.items():
        plt.figure() 
        x = np.array(sorted(scales.keys()), dtype=int)
        simulation_times = [np.mean([iteration_data['time_simulate'] for iteration_data in scales[scale].values()]) for scale in x]
        simulation_std = [np.std([iteration_data['time_simulate'] for iteration_data in scales[scale].values()]) for scale in x]
        building_times = [np.mean([iteration_data['time_construction_connect'] for iteration_data in scales[scale].values()]) for scale in x]
        building_std = [np.std([iteration_data['time_construction_connect'] for iteration_data in scales[scale].values()]) for scale in x]
        total_times = [sim + build for sim, build in zip(simulation_times, building_times)]
        total_std = [sim_std + build_std for sim_std, build_std in zip(simulation_std, building_std)]
        plt.fill_between(x * NEURONSPERSCALE, total_times, label=f'{neuron} building')
        plt.fill_between(x * NEURONSPERSCALE, simulation_times, label=f'{neuron} simulation')
        plt.errorbar(x * NEURONSPERSCALE, total_times, yerr=total_std, fmt='k', capsize=3) 
        plt.errorbar(x * NEURONSPERSCALE, simulation_times, yerr=simulation_std, fmt='k', capsize=3)  
        plt.xlabel('Neuron count')
        plt.ylabel('Time')
        plt.xscale('log')
        plt.yscale('log')

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
        referenceValues = data[BASELINENEURON]
        for neuron, scales in data.items():
            neurons.append(neuron)
            x = np.array(sorted(scales.keys()))
            reference_y = np.array([np.mean([iteration_data['stopwatches'][stopwatch] for iteration_data in referenceValues[scale].values()]) for scale in x])
            y = np.array([np.mean([iteration_data['stopwatches'][stopwatch] for iteration_data in scales[scale].values()]) for scale in x])
            y_factor = y / reference_y
            y_std = np.array([np.std([iteration_data['stopwatches'][stopwatch] for iteration_data in scales[scale].values()]) for scale in x])
            y_factor_std = y_std / reference_y
            #plt.errorbar(x * NEURONSPERSCALE, y_factor, yerr=y_factor_std, fmt='-', ecolor='k', capsize=3)
            plt.plot(x * NEURONSPERSCALE, y_factor, '-', label=legend[neuron])

        plt.xscale('log')
        
        formatter = FuncFormatter(lambda y, _: '{:.1g}'.format(y))
        plt.gca().yaxis.set_major_formatter(formatter)
        formatterX = FuncFormatter(lambda x, _: '{:.1g}'.format(x))
        plt.gca().xaxis.set_major_formatter(formatterX)

        plt.xlabel('Neuron count')
        plt.ylabel('Time')
        plt.title(stopwatch)
        plt.legend()
        plt.savefig(os.path.join(output_folder, f'output_{stopwatch}.png'))
        

def plot_strong_scaling(data):
    plt.figure()
    neurons = []
    referenceValues = data[BASELINENEURON]
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        # Real Time Factor
        y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_std = np.array([np.std([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        x = [int(val) for val in x]
        plt.errorbar(x, y=y, yerr=y_std, label=legend[neuron], fmt='-', ecolor='k', capsize=3)
        
    plt.xlabel('Threads')
    plt.ylabel('Wall clock time (s)')
    plt.xscale('log')

    plt.legend()
    plt.savefig(os.path.join(output_folder, 'strong_scaling_abs.png'))




    plt.figure()
    neurons = []
    referenceValues = data[BASELINENEURON]
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        # Real Time Factor
        reference_y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in referenceValues[threads].values()]) for threads in x])
        y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor = y / reference_y
        y_std = np.array([np.std([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor_std = y_std / reference_y 
        x = [int(val) for val in x]
        plt.errorbar(x, y=y_factor, yerr=y_factor_std, label=legend[neuron], fmt='-', ecolor='k', capsize=3)
        
    plt.xlabel('Threads')
    plt.ylabel('Wall clock time (ratio)')
    
    plt.xscale('log')

    plt.legend()
    plt.savefig(os.path.join(output_folder, 'strong_scaling_rel.png'))




    plt.figure()
    neurons = []
    referenceValues = data[BASELINENEURON]
    for neuron, values in data.items():
        neurons.append(neuron)
        x = sorted(values.keys(), key=lambda k: int(k))
        # Real Time Factor
        reference_y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in referenceValues[threads].values()]) for threads in x])
        y = np.array([np.mean([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor = y / reference_y 
        y_std = np.array([np.std([iteration_data['time_simulate']/(iteration_data["biological_time"]/1000) for iteration_data in values[threads].values()]) for threads in x])
        y_factor_std = y_std / reference_y 
        x = [int(val) for val in x]
        plt.errorbar(x, y=y, yerr=y_std, label=legend[neuron], fmt='-', ecolor='k', capsize=3)
        
    plt.xlabel('Threads')
    plt.ylabel('Wall clock time (ratio)')
    
    plt.xscale('log')

    plt.legend()
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
        x = np.array([int(val) for val in x])
        plt.errorbar(x * NEURONSPERSCALE, y, yerr=y_std, fmt='-', ecolor='k', capsize=3)

        if max(y) > max_y:
            max_y = max(y)

    plt.annotate(f'Max: {format_bytes(max_y,"")}', xy=(0.8, max_y), xytext=(8, 0), 
                 xycoords=('axes fraction', 'data'), textcoords='offset points')
    plt.xlabel('Neuron count')
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
    
    os.remove(os.path.join(output_folder, "log.txt"))
    
    if runSim:
        memoryData = {}
        deleteJson()
        for i in range(ITERATIONS):
            start_weak_scaling_Benchmark(i)
            start_strong_scaling_Benchmark(i)
            
            data = start_weak_scaling_Benchmark(i, checkMemory=True)
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
    log("Finished")
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

