# Install script for directory: /p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator-install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/p/software/jusuf/stages/2023/software/binutils/2.38-GCCcore-11.3.0/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/models.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/binary_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/weight_recorder.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/cm_compartmentcurrents.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/cm_tree.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_neuron_ipn.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_neuron_ipn_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_neuron_opn.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_neuron_opn_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_transformer_node.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_transformer_node_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/ac_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_cond_alpha.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_cond_alpha_astro.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_cond_alpha_multisynapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_cond_beta_multisynapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_cond_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_psc_alpha.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_psc_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_psc_delta.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/aeif_psc_delta_clopath.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/amat2_psc_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/astrocyte_lr_1994.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/bernoulli_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/cm_default.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/clopath_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/cont_delay_synapse_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/cont_delay_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/correlation_detector.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/correlomatrix_detector.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/correlospinmatrix_detector.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/dc_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/diffusion_connection.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/erfc_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gamma_sup_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gap_junction.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gauss_rate.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gif_psc_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gif_psc_exp_multisynapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gif_cond_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gif_cond_exp_multisynapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/gif_pop_psc_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/ginzburg_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/glif_cond.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/glif_psc.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/glif_psc_double_alpha.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/hh_cond_exp_traub.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/hh_cond_beta_gap_traub.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/hh_psc_alpha.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/hh_psc_alpha_clopath.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/hh_psc_alpha_gap.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/ht_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/ht_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_chs_2007.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_chxk_2008.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_cond_alpha.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_cond_alpha_mc.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_cond_beta.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_cond_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_cond_exp_sfa_rr.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_alpha.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_alpha_multisynapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_alpha_ps.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_delta.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_delta_ps.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_exp_htum.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_exp_multisynapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_exp_ps.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_psc_exp_ps_lossless.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/iaf_tum_2000.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/ignore_and_fire.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/izhikevich.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/jonke_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/lin_rate.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/mat2_psc_exp.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/mcculloch_pitts_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/mip_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/multimeter.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_cont_in_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_cont_out_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_event_in_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_event_out_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_rate_in_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_rate_out_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/music_message_in_proxy.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/noise_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/parrot_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/parrot_neuron_ps.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/inhomogeneous_poisson_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/poisson_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/poisson_generator_ps.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/pp_psc_delta.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/pp_cond_exp_mc_urbanczik.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/ppd_sup_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/pulsepacket_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/quantal_stp_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/quantal_stp_synapse_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_connection_delayed.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/rate_connection_instantaneous.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/sic_connection.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/siegert_neuron.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/sigmoid_rate.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/sigmoid_rate_gg_1998.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/sinusoidal_poisson_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/sinusoidal_gamma_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/spike_recorder.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/spike_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/spin_detector.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/spike_train_injector.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/static_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/static_synapse_hom_w.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_dopamine_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_nn_pre_centered_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_nn_restr_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_nn_symm_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_pl_synapse_hom.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_facetshw_synapse_hom_impl.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_facetshw_synapse_hom.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_synapse_hom.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/stdp_triplet_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/step_current_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/step_rate_generator.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/tanh_rate.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/threshold_lin_rate.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/tsodyks2_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/tsodyks_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/tsodyks_synapse_hom.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/urbanczik_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/volume_transmitter.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/vogels_sprekeler_synapse.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/weight_recorder.h"
    "/p/home/jusers/koll1/jusuf/NestBenchmark/nest-simulator/models/spike_dilutor.h"
    )
endif()

