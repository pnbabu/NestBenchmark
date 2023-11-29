# Install script for directory: /home/lukkyguy/code/BachlorThesis/nest-simulator/models

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/lukkyguy/code/BachlorThesis/nest-install")
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
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/nest" TYPE FILE FILES
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/modelsmodule.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/binary_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/cm_compartmentcurrents.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/cm_tree.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_neuron_ipn.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_neuron_ipn_impl.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_neuron_opn.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_neuron_opn_impl.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_transformer_node.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_transformer_node_impl.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/ac_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_cond_alpha.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_cond_alpha_astro.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_cond_alpha_multisynapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_cond_beta_multisynapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_cond_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_psc_alpha.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_psc_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_psc_delta.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/aeif_psc_delta_clopath.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/amat2_psc_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/astrocyte_lr_1994.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/bernoulli_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/cm_default.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/clopath_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/cont_delay_synapse_impl.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/cont_delay_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/correlation_detector.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/correlomatrix_detector.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/correlospinmatrix_detector.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/dc_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/diffusion_connection.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/erfc_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gamma_sup_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gap_junction.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gauss_rate.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gif_psc_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gif_psc_exp_multisynapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gif_cond_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gif_cond_exp_multisynapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/gif_pop_psc_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/ginzburg_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/glif_cond.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/glif_psc.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/glif_psc_double_alpha.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/hh_cond_exp_traub.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/hh_cond_beta_gap_traub.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/hh_psc_alpha.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/hh_psc_alpha_clopath.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/hh_psc_alpha_gap.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/ht_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/ht_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_chs_2007.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_chxk_2008.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_cond_alpha.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_cond_alpha_mc.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_cond_beta.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_cond_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_cond_exp_sfa_rr.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_alpha.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_alpha_multisynapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_alpha_ps.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_delta.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_delta_ps.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_exp_htum.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_exp_multisynapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_exp_ps.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_psc_exp_ps_lossless.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/iaf_tum_2000.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/izhikevich.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/jonke_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/lin_rate.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/mat2_psc_exp.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/mcculloch_pitts_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/mip_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/multimeter.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_cont_in_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_cont_out_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_event_in_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_event_out_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_rate_in_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_rate_out_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/music_message_in_proxy.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/noise_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/parrot_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/parrot_neuron_ps.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/inhomogeneous_poisson_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/poisson_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/poisson_generator_ps.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/pp_psc_delta.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/pp_cond_exp_mc_urbanczik.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/ppd_sup_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/pulsepacket_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/quantal_stp_synapse_impl.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/quantal_stp_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_connection_delayed.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/rate_connection_instantaneous.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/sic_connection.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/siegert_neuron.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/sigmoid_rate.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/sigmoid_rate_gg_1998.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/sinusoidal_poisson_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/sinusoidal_gamma_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/spike_recorder.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/spike_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/spin_detector.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/spike_train_injector.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/static_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/static_synapse_hom_w.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_dopamine_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_nn_pre_centered_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_nn_restr_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_nn_symm_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_pl_synapse_hom.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_facetshw_synapse_hom.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_facetshw_synapse_hom_impl.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_synapse_hom.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/stdp_triplet_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/step_current_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/step_rate_generator.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/tanh_rate.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/threshold_lin_rate.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/tsodyks2_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/tsodyks_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/tsodyks_synapse_hom.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/urbanczik_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/volume_transmitter.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/vogels_sprekeler_synapse.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/weight_recorder.h"
    "/home/lukkyguy/code/BachlorThesis/nest-simulator/models/spike_dilutor.h"
    )
endif()

