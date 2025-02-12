# -*- coding: utf-8 -*-
#
# setup.py
#
# This file is part of NEST.
#
# Copyright (C) 2004 The NEST Initiative
#
# NEST is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# NEST is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with NEST.  If not, see <http://www.gnu.org/licenses/>.

from setuptools import setup

setup(
    name = 'nest-simulator',
    version = '3.6.0-post0.dev0',
    description = 'Python bindings for NEST',
    author = 'The NEST Initiative',
    url = 'https://www.nest-simulator.org',
    license = 'GPLv2+',
    packages = ['nest', 'nest.lib'],
    install_requires = ['numpy', 'scipy'],
    extras_require = {'test': ['junitparser', 'matplotlib', 'pytest']},
    classifiers = [
        'Development Status :: 6 - Mature',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Intended Audience :: Science/Research',
        'Topic :: Scientific/Engineering',
        'Topic :: Scientific/Engineering :: Artificial Intelligence',
    ],
    python_requires = '>=3.8, <4',
    keywords = (",".join([
        'nest',
        'simulator',
        'neuroscience',
        'neural',
        'neuron',
        'network',
        'ai',
        'spike',
        'spiking'
    ])),
    project_urls = {
        'Homepage': 'https://www.nest-simulator.org/',
        'Bug Reports': 'https://github.com/nest/nest-simulator/issues',
        'Source': 'https://github.com/nest/nest-simulator',
        'Documentation': 'https://nest-simulator.readthedocs.io/'
    },
)
