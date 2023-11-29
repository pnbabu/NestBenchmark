import subprocess
import os
import re
import json
import math
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.ticker import FuncFormatter

PATHTOFILE = "/home/lukkyguy/code/BachlorThesis/Running/examples/brunel_alpha_nest.py"
PATHTOSHFILE = "/home/lukkyguy/code/BachlorThesis/Running/start.sh"

NEURONMODELS = ["iaf_psc_alpha_neuron_Nestml","iaf_psc_alpha"]

NETWORKSCALES = np.logspace(2, 4, 10, dtype=int)
THREADS = 8
ITERATIONS=3



def start_benchmark(iteration):
    
    combinations = [['bash', '-c', f'source {PATHTOSHFILE} && python3 {PATHTOFILE} --simulated_neuron {neuronmodel} --network_scale {networkscale} --threads {THREADS} --iteration {iteration}'] for neuronmodel in NEURONMODELS for networkscale in NETWORKSCALES]
    processes = [subprocess.run(command) for command in combinations]


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
    for neuron, values in realTimeFactors.items():
        items = sorted(values.items())
        x, y = zip(*items)
        y = np.array(y)  # convert y to a numpy array
        y_mean = np.mean(y, axis=1)  # calculate mean for each network scale
        y_std = np.std(y, axis=1)  # calculate standard deviation for each network scale
        plt.plot(x, y_mean, label=neuron)
        plt.fill_between(x, y_mean - y_std, y_mean + y_std, alpha=0.2)

    plt.xscale('log')
    plt.yscale('log')
    formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
    plt.gca().yaxis.set_major_formatter(formatter)

    plt.xlabel('Network Scale')
    plt.ylabel('Real Time Factor')
    plt.legend()
    plt.savefig('output.png')

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
        plt.errorbar(x, total_times, yerr=total_std, fmt='k', capsize=3)  # add capsize parameter
        plt.errorbar(x, simulation_times, yerr=simulation_std, fmt='k', capsize=3)  # add capsize parameter
        plt.xlabel('Network Scale')
        plt.ylabel('Time')

        formatter = FuncFormatter(lambda y, _: '{:.16g}'.format(y))
        plt.gca().yaxis.set_major_formatter(formatter)
        plt.title(neuron)
        plt.legend()
        plt.savefig(f'output_{neuron}.png')
        

            
def deleteDat():

    for filename in os.listdir("./"):
        if filename.endswith(".dat"):
            os.remove(f"./{filename}")

def deleteJson():
    for filename in os.listdir("./timings"):
        if filename.endswith(".json"):
            os.remove(f"./timings/{filename}")
            
        

if __name__ == "__main__":
    deleteJson()
    if os.path.exists("output.png"):
        os.remove("output.png")
    for i in range(ITERATIONS):
        start_benchmark(i)
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
    

