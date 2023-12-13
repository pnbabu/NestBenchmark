#!/usr/bin/env python3
#
# -*- coding: utf-8 -*-

from pynestml.frontend.pynestml_frontend import generate_nest_target

generate_nest_target(input_path="/home/charl/nestml-fork-integrate_specific_odes/nestml/models/neurons/iaf_psc_alpha_neuron.nestml",
                     module_name = "nestmlmodule",
                     suffix="_Nestml",
                        logging_level="DEBUG")


