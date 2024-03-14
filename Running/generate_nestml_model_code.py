#!/usr/bin/env python3
#
# -*- coding: utf-8 -*-

from pynestml.frontend.pynestml_frontend import generate_nest_target
import os

#generate code for network with static synapses
current_dir = os.path.dirname(os.path.abspath(__file__))

install_path = os.path.join(current_dir,"../nest-simulator-install/lib/nest")
NEURONS = ["iaf_psc_alpha", "aeif_psc_alpha"]

for neuron in NEURONS:
   input_path = os.path.join(current_dir, f"../nestml/models/neurons/{neuron}_neuron.nestml")
   generate_nest_target(input_path=input_path,
                        module_name = f"{neuron}_nestmlmodule",
                        target_path=f"target_{neuron}",
                        suffix="_NESTML",
                           logging_level="DEBUG",
                           install_path=install_path)

   generate_nest_target(input_path=input_path,
                        module_name =  f"{neuron}_nestmlOptimizedmodule",
                        suffix="_NESTML_Optimized",
                           logging_level="DEBUG",
                           target_path=f"target_{neuron}_optimized",
                           install_path=install_path,
                           codegen_opts={"preserve_expressions":False}
                           )

   input_path = [os.path.join(current_dir, f"../nestml/models/neurons/{neuron}_neuron.nestml"),
               os.path.join(current_dir, "../nestml/models/synapses/stdp_synapse.nestml")]
   generate_nest_target(input_path=input_path,
                        module_name = f"{neuron}_nestmlplasticmodule",
                        suffix="_NESTML_Plastic",
                           logging_level="DEBUG",
                           target_path=f"target_{neuron}_plastic",
                           install_path=install_path,

                        codegen_opts={"neuron_synapse_pairs": [{"neuron": f"{neuron}_neuron",
                                                               "synapse": "stdp_synapse",
                                                               "post_ports": ["post_spikes"]}]})
   generate_nest_target(input_path=input_path,
                        module_name = f"{neuron}_nestmlplasticOptimizedmodule",
                        suffix="_NESTML_Plastic_Optimized",
                           logging_level="DEBUG",
                           target_path=f"target_{neuron}_plastic_optimized",
                           install_path=install_path,

                        codegen_opts={"neuron_synapse_pairs": [{"neuron": f"{neuron}_neuron",
                                                               "synapse": "stdp_synapse",
                                                               "post_ports": ["post_spikes"]}],
                                       "preserve_expressions": False
                                    })



