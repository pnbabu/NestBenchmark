#!/usr/bin/env python3
#
# -*- coding: utf-8 -*-

from pynestml.frontend.pynestml_frontend import generate_nest_target
import os

for model_name_snip in ["aeif_psc_alpha"]:#, "iaf_psc_alpha"]:
    current_dir = os.path.dirname(os.path.abspath(__file__))
    input_path = os.path.join(current_dir, "../nestml/models/neurons/" + model_name_snip + "_neuron.nestml")
    generate_nest_target(input_path=[input_path,input_path],
                         module_name = "nestmlmodule",
                         suffix="_Nestml",
                         logging_level="DEBUG",
                         install_path=os.path.join(current_dir,"../nest-simulator-install/lib64/nest"))

    generate_nest_target(input_path=input_path,
                         module_name = "nestmlOptimizedmodule",
                         suffix="_Nestml_Optimized",
                         logging_level="DEBUG",
                         target_path="target_optimized",
                         install_path=os.path.join(current_dir,"../nest-simulator-install/lib64/nest"))



    # generate code for network with plastic synapses

    input_path = [os.path.join(current_dir, "../nestml/models/neurons/" + model_name_snip + "_neuron.nestml"),
                  os.path.join(current_dir, "../nestml/models/synapses/stdp_synapse.nestml")]
    generate_nest_target(input_path=input_path,
                         module_name = "nestmlplasticmodule",
                         suffix="_Nestml_Plastic",
                         logging_level="DEBUG",
                         target_path="target_plastic",
                         install_path=os.path.join(current_dir,"../nest-simulator-install/lib64/nest"),
                         codegen_opts={"neuron_synapse_pairs": [{"neuron": model_name_snip + "_neuron",
                                                                 "synapse": "stdp_synapse",
                                                                 "post_ports": ["post_spikes"]}]})



