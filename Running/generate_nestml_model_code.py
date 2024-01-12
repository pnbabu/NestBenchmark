#!/usr/bin/env python3
#
# -*- coding: utf-8 -*-

from pynestml.frontend.pynestml_frontend import generate_nest_target
import os

current_dir = os.path.dirname(os.path.abspath(__file__))
input_path = os.path.join(current_dir, "../nestml/models/neurons/iaf_psc_alpha_neuron.nestml")
generate_nest_target(input_path=input_path,
                     module_name = "nestmlmodule",
                     suffix="_Nestml",
                        logging_level="DEBUG",
                        install_path=os.path.join(current_dir,"../nest-simulator-install/lib/nest"))

generate_nest_target(input_path=input_path,
                     module_name = "nestmlOptimizedmodule",
                     suffix="_Nestml_Optimized",
                        logging_level="DEBUG",
                        target_path="target_optimized",
                        install_path=os.path.join(current_dir,"../nest-simulator-install/lib/nest"))



