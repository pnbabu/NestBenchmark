// #define DEBUG 1
/*
 *  iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic.cpp
 *
 *  This file is part of NEST.
 *
 *  Copyright (C) 2004 The NEST Initiative
 *
 *  NEST is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  NEST is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with NEST.  If not, see <http://www.gnu.org/licenses/>.
 *
 *  Generated from NESTML at time: 2024-03-13 22:50:34.622114
 **/

// C++ includes:
#include <limits>

// Includes from libnestutil:
#include "numerics.h"

// Includes from nestkernel:
#include "exceptions.h"
#include "kernel_manager.h"
#include "universal_data_logger_impl.h"

// Includes from sli:
#include "dict.h"
#include "dictutils.h"
#include "doubledatum.h"
#include "integerdatum.h"
#include "lockptrdatum.h"

#include "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic.h"

// ---------------------------------------------------------------------------
//   Recordables map
// ---------------------------------------------------------------------------
nest::RecordablesMap<iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic> iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::recordablesMap_;
namespace nest
{

  // Override the create() method with one call to RecordablesMap::insert_()
  // for each quantity to be recorded.
  template <>
  void RecordablesMap<iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic>::create()
  {
    // add state variables to recordables map
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_V_m, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_V_m);
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_refr_t, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_refr_t);
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_post_trace__for_stdp_synapse_NESTML_Plastic, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic);
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_I_kernel_inh__X__inh_spikes, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_I_kernel_inh__X__inh_spikes);
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_I_kernel_inh__X__inh_spikes__d, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_I_kernel_inh__X__inh_spikes__d);
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_I_kernel_exc__X__exc_spikes, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_I_kernel_exc__X__exc_spikes);
    insert_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic_names::_I_kernel_exc__X__exc_spikes__d, &iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_I_kernel_exc__X__exc_spikes__d);

    // Add vector variables
  }
}
std::vector<std::tuple<int, int>> iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::rport_to_nestml_buffer_idx =
    {

        {iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::EXC_SPIKES, iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::INH_SPIKES},
};

// ---------------------------------------------------------------------------
//   Default constructors defining default parameters and state
//   Note: the implementation is empty. The initialization is of variables
//   is a part of iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic's constructor.
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::Parameters_::Parameters_()
{
}

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::State_::State_()
{
}

// ---------------------------------------------------------------------------
//   Parameter and state extractions and manipulation functions
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::Buffers_::Buffers_(iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic &n) : logger_(n), spike_inputs_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_inputs_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), spike_input_received_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_input_received_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS))
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::Buffers_::Buffers_(const Buffers_ &, iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic &n) : logger_(n), spike_inputs_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_inputs_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), spike_input_received_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_input_received_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS))
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

// ---------------------------------------------------------------------------
//   Default constructor for node
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic() : ArchivingNode(), P_(), S_(), B_(*this)
{
  init_state_internal_();
  recordablesMap_.create();
  pre_run_hook();
}

// ---------------------------------------------------------------------------
//   Copy constructor for node
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic(const iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic &__n) : ArchivingNode(), P_(__n.P_), S_(__n.S_), B_(__n.B_, *this)
{

  // copy parameter struct P_
  P_.C_m = __n.P_.C_m;
  P_.tau_m = __n.P_.tau_m;
  P_.tau_syn_inh = __n.P_.tau_syn_inh;
  P_.tau_syn_exc = __n.P_.tau_syn_exc;
  P_.refr_T = __n.P_.refr_T;
  P_.E_L = __n.P_.E_L;
  P_.V_reset = __n.P_.V_reset;
  P_.V_th = __n.P_.V_th;
  P_.I_e = __n.P_.I_e;
  P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic = __n.P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic;

  // copy state struct S_
  S_.V_m = __n.S_.V_m;
  S_.refr_t = __n.S_.refr_t;
  S_.is_refractory = __n.S_.is_refractory;
  S_.post_trace__for_stdp_synapse_NESTML_Plastic = __n.S_.post_trace__for_stdp_synapse_NESTML_Plastic;
  S_.I_kernel_inh__X__inh_spikes = __n.S_.I_kernel_inh__X__inh_spikes;
  S_.I_kernel_inh__X__inh_spikes__d = __n.S_.I_kernel_inh__X__inh_spikes__d;
  S_.I_kernel_exc__X__exc_spikes = __n.S_.I_kernel_exc__X__exc_spikes;
  S_.I_kernel_exc__X__exc_spikes__d = __n.S_.I_kernel_exc__X__exc_spikes__d;

  // copy internals V_
  V_.__h = __n.V_.__h;
  V_.__P__V_m__V_m = __n.V_.__P__V_m__V_m;
  V_.__P__V_m__I_kernel_inh__X__inh_spikes = __n.V_.__P__V_m__I_kernel_inh__X__inh_spikes;
  V_.__P__V_m__I_kernel_inh__X__inh_spikes__d = __n.V_.__P__V_m__I_kernel_inh__X__inh_spikes__d;
  V_.__P__V_m__I_kernel_exc__X__exc_spikes = __n.V_.__P__V_m__I_kernel_exc__X__exc_spikes;
  V_.__P__V_m__I_kernel_exc__X__exc_spikes__d = __n.V_.__P__V_m__I_kernel_exc__X__exc_spikes__d;
  V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic = __n.V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic;
  V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes = __n.V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes;
  V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d = __n.V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d;
  V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes = __n.V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes;
  V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d = __n.V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d;
  V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes = __n.V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes;
  V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d = __n.V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d;
  V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes = __n.V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes;
  V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d = __n.V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d;
  n_incoming_ = __n.n_incoming_;
  max_delay_ = __n.max_delay_;
  last_spike_ = __n.last_spike_;

  // cache initial values
  post_trace__for_stdp_synapse_NESTML_Plastic__iv = S_.post_trace__for_stdp_synapse_NESTML_Plastic;
}

// ---------------------------------------------------------------------------
//   Destructor for node
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::~iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic()
{
}

// ---------------------------------------------------------------------------
//   Node initialization functions
// ---------------------------------------------------------------------------
void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::calibrate_time(const nest::TimeConverter &tc)
{
  LOG(nest::M_WARNING,
      "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic",
      "Simulation resolution has changed. Internal state and parameters of the model have been reset!");

  init_state_internal_();
}
void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::init_state_internal_()
{
#ifdef DEBUG
  std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::init_state_internal_()" << std::endl;
#endif

  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function
  pre_run_hook();
  // initial values for parameters
  P_.C_m = 250;                                         // as pF
  P_.tau_m = 10;                                        // as ms
  P_.tau_syn_inh = 2;                                   // as ms
  P_.tau_syn_exc = 2;                                   // as ms
  P_.refr_T = 2;                                        // as ms
  P_.E_L = (-70);                                       // as mV
  P_.V_reset = (-70);                                   // as mV
  P_.V_th = (-55);                                      // as mV
  P_.I_e = 0;                                           // as pA
  P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic = 20; // as ms

  V_.__h = nest::Time::get_resolution().get_ms();
  recompute_internal_variables();
  // initial values for state variables
  S_.V_m = P_.E_L;                                      // as mV
  S_.refr_t = 0;                                        // as ms
  S_.is_refractory = false;                             // as boolean
  S_.post_trace__for_stdp_synapse_NESTML_Plastic = 0.0; // as real
  S_.I_kernel_inh__X__inh_spikes = 0;                   // as real
  S_.I_kernel_inh__X__inh_spikes__d = 0;                // as 1 / s
  S_.I_kernel_exc__X__exc_spikes = 0;                   // as real
  S_.I_kernel_exc__X__exc_spikes__d = 0;                // as 1 / s
  // state variables for archiving state for paired synapse
  n_incoming_ = 0;
  max_delay_ = 0;
  last_spike_ = -1.;

  // cache initial values
  post_trace__for_stdp_synapse_NESTML_Plastic__iv = S_.post_trace__for_stdp_synapse_NESTML_Plastic;
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::init_buffers_()
{
#ifdef DEBUG
  std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::init_buffers_()" << std::endl;
#endif
  // spike input buffers
  get_spike_inputs_().clear();
  get_spike_inputs_grid_sum_().clear();
  get_spike_input_received_().clear();
  get_spike_input_received_grid_sum_().clear();

  // continuous time input buffers

  get_I_stim().clear();
  B_.I_stim_grid_sum_ = 0;

  B_.logger_.reset();
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::recompute_internal_variables(bool exclude_timestep)
{
  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function

  if (exclude_timestep)
  {
    V_.__P__V_m__V_m = 1.0 * std::exp((-V_.__h) / P_.tau_m);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes = P_.tau_m * (0.25 * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - 0.25 * V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh) - 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_m) + 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));    // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_inh * (V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));                                                                                                                                     // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes = P_.tau_m * ((-0.25) * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) + 0.25 * V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc) + 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_m) - 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2))); // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_exc * ((-V_.__h) * P_.tau_m * std::exp(V_.__h / P_.tau_m) + V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2)));                                                                                                                                  // as real
    V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic = 1.0 * std::exp((-V_.__h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic);                                                                                                                                                                                                                                                                                                                                                                                                                                               // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes = 1.0 * (V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh) / pow(P_.tau_syn_inh, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d = ((-1.0) * V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes = 1.0 * (V_.__h + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc) / pow(P_.tau_syn_exc, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
  }
  else
  {
    V_.__h = __resolution;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as ms
    V_.__P__V_m__V_m = 1.0 * std::exp((-V_.__h) / P_.tau_m);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes = P_.tau_m * (0.25 * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - 0.25 * V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh) - 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_m) + 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));    // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_inh * (V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));                                                                                                                                     // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes = P_.tau_m * ((-0.25) * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) + 0.25 * V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc) + 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_m) - 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2))); // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_exc * ((-V_.__h) * P_.tau_m * std::exp(V_.__h / P_.tau_m) + V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2)));                                                                                                                                  // as real
    V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic = 1.0 * std::exp((-V_.__h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic);                                                                                                                                                                                                                                                                                                                                                                                                                                               // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes = 1.0 * (V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh) / pow(P_.tau_syn_inh, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d = ((-1.0) * V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes = 1.0 * (V_.__h + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc) / pow(P_.tau_syn_exc, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
  }
}
void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::pre_run_hook()
{
  B_.logger_.init();

  // parameters might have changed -- recompute internals
  V_.__h = nest::Time::get_resolution().get_ms();
  recompute_internal_variables();

  // buffers B_
  B_.spike_inputs_.resize(NUM_SPIKE_RECEPTORS);
  B_.spike_inputs_grid_sum_.resize(NUM_SPIKE_RECEPTORS);
  B_.spike_input_received_.resize(NUM_SPIKE_RECEPTORS);
  B_.spike_input_received_grid_sum_.resize(NUM_SPIKE_RECEPTORS);
}

// ---------------------------------------------------------------------------
//   Update and spike handling functions
// ---------------------------------------------------------------------------

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::update(nest::Time const &origin, const long from, const long to)
{

  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function

#ifdef DEBUG
  std::cout << "In iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::update: t = " << __resolution << std::endl;
#endif

  for (long lag = from; lag < to; ++lag)
  {

    auto get_t = [origin, lag]()
    { return nest::Time(nest::Time::step(origin.get_steps() + lag + 1)).get_ms(); };
    /**
     * buffer spikes from spiking input ports
     **/

    for (long i = 0; i < NUM_SPIKE_RECEPTORS; ++i)
    {
      get_spike_inputs_grid_sum_()[i] = get_spike_inputs_()[i].get_value(lag);
      get_spike_input_received_grid_sum_()[i] = get_spike_input_received_()[i].get_value(lag);
    }

    /**
     * subthreshold updates of the convolution variables
     *
     * step 1: regardless of whether and how integrate_odes() will be called, update variables due to convolutions
     **/
    const double I_kernel_inh__X__inh_spikes__tmp_ = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d;
    const double I_kernel_inh__X__inh_spikes__d__tmp_ = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d;
    const double I_kernel_exc__X__exc_spikes__tmp_ = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d;
    const double I_kernel_exc__X__exc_spikes__d__tmp_ = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d;

    /**
     * Begin NESTML generated code for the update block(s)
     **/

    if (S_.is_refractory)
    {
      S_.refr_t -= __resolution;
    }
    else
    {

      // start rendered code for integrate_odes()

      // analytic solver: integrating state variables (first step): V_m, I_kernel_inh__X__inh_spikes, I_kernel_inh__X__inh_spikes__d, I_kernel_exc__X__exc_spikes, I_kernel_exc__X__exc_spikes__d, post_trace__for_stdp_synapse_NESTML_Plastic,
      const double V_m__tmp = (-P_.E_L) * V_.__P__V_m__V_m + P_.E_L + S_.I_kernel_exc__X__exc_spikes * V_.__P__V_m__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__V_m__I_kernel_exc__X__exc_spikes__d + S_.I_kernel_inh__X__inh_spikes * V_.__P__V_m__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__V_m__I_kernel_inh__X__inh_spikes__d + S_.V_m * V_.__P__V_m__V_m - P_.I_e * V_.__P__V_m__V_m * P_.tau_m / P_.C_m + P_.I_e * P_.tau_m / P_.C_m - B_.I_stim_grid_sum_ * V_.__P__V_m__V_m * P_.tau_m / P_.C_m + B_.I_stim_grid_sum_ * P_.tau_m / P_.C_m;
      const double I_kernel_inh__X__inh_spikes__tmp = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d;
      const double I_kernel_inh__X__inh_spikes__d__tmp = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d;
      const double I_kernel_exc__X__exc_spikes__tmp = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d;
      const double I_kernel_exc__X__exc_spikes__d__tmp = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d;
      const double post_trace__for_stdp_synapse_NESTML_Plastic__tmp = V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic * S_.post_trace__for_stdp_synapse_NESTML_Plastic;
      // analytic solver: integrating state variables (second step): V_m, I_kernel_inh__X__inh_spikes, I_kernel_inh__X__inh_spikes__d, I_kernel_exc__X__exc_spikes, I_kernel_exc__X__exc_spikes__d, post_trace__for_stdp_synapse_NESTML_Plastic,
      /* replace analytically solvable variables with precisely integrated values  */
      S_.V_m = V_m__tmp;
      S_.I_kernel_inh__X__inh_spikes = I_kernel_inh__X__inh_spikes__tmp;
      S_.I_kernel_inh__X__inh_spikes__d = I_kernel_inh__X__inh_spikes__d__tmp;
      S_.I_kernel_exc__X__exc_spikes = I_kernel_exc__X__exc_spikes__tmp;
      S_.I_kernel_exc__X__exc_spikes__d = I_kernel_exc__X__exc_spikes__d__tmp;
      S_.post_trace__for_stdp_synapse_NESTML_Plastic = post_trace__for_stdp_synapse_NESTML_Plastic__tmp;
    }

    /**
     * Begin NESTML generated code for the onReceive block(s)
     **/

    /**
     * subthreshold updates of the convolution variables
     *
     * step 2: regardless of whether and how integrate_odes() was called, update variables due to convolutions. Set to the updated values at the end of the timestep.
     **/

    S_.I_kernel_inh__X__inh_spikes = I_kernel_inh__X__inh_spikes__tmp_;
    S_.I_kernel_inh__X__inh_spikes__d = I_kernel_inh__X__inh_spikes__d__tmp_;
    S_.I_kernel_exc__X__exc_spikes = I_kernel_exc__X__exc_spikes__tmp_;
    S_.I_kernel_exc__X__exc_spikes__d = I_kernel_exc__X__exc_spikes__d__tmp_;

    /**
     * spike updates due to convolutions
     **/

    S_.I_kernel_inh__X__inh_spikes__d += ((0.001 * B_.spike_inputs_grid_sum_[INH_SPIKES - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn_inh) / (1 / 1000.0);
    S_.I_kernel_exc__X__exc_spikes__d += ((0.001 * B_.spike_inputs_grid_sum_[EXC_SPIKES - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn_exc) / (1 / 1000.0);

    /**
     * Begin NESTML generated code for the onCondition block(s)
     **/

    if (S_.V_m >= P_.V_th)
    {
      S_.refr_t = P_.refr_T;
      S_.is_refractory = true;
      S_.V_m = P_.V_reset;

      /**
       * generated code for emit_spike() function
       **/

      set_spiketime(nest::Time::step(origin.get_steps() + lag + 1));
      nest::SpikeEvent se;
      nest::kernel().event_delivery_manager.send(*this, se, lag);
    }
    if (S_.refr_t <= __resolution / 2)
    {
      S_.refr_t = 0;
      S_.is_refractory = false;
    }

    /**
     * handle continuous input ports
     **/
    B_.I_stim_grid_sum_ = get_I_stim().get_value(lag);
    // voltage logging
    B_.logger_.record_data(origin.get_steps() + lag);
  }
}

// Do not move this function as inline to h-file. It depends on
// universal_data_logger_impl.h being included here.
void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::handle(nest::DataLoggingRequest &e)
{
  B_.logger_.handle(e);
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::handle(nest::SpikeEvent &e)
{
  assert(e.get_delay_steps() > 0);
  assert(e.get_rport() < B_.spike_inputs_.size());

  double weight = e.get_weight();
  size_t nestml_buffer_idx = 0;
  if (weight >= 0.0)
  {
    nestml_buffer_idx = std::get<0>(rport_to_nestml_buffer_idx[e.get_rport()]);
  }
  else
  {
    nestml_buffer_idx = std::get<1>(rport_to_nestml_buffer_idx[e.get_rport()]);
    if (nestml_buffer_idx == iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::PORT_NOT_AVAILABLE)
    {
      nestml_buffer_idx = std::get<0>(rport_to_nestml_buffer_idx[e.get_rport()]);
    }
    weight = -weight;
  }
  B_.spike_inputs_[nestml_buffer_idx - MIN_SPIKE_RECEPTOR].add_value(
      e.get_rel_delivery_steps(nest::kernel().simulation_manager.get_slice_origin()),
      weight * e.get_multiplicity());
  B_.spike_input_received_[nestml_buffer_idx - MIN_SPIKE_RECEPTOR].add_value(
      e.get_rel_delivery_steps(nest::kernel().simulation_manager.get_slice_origin()),
      1.);
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::handle(nest::CurrentEvent &e)
{
  assert(e.get_delay_steps() > 0);

  const double current = e.get_current(); // we assume that in NEST, this returns a current in pA
  const double weight = e.get_weight();
  get_I_stim().add_value(
      e.get_rel_delivery_steps(nest::kernel().simulation_manager.get_slice_origin()),
      weight * current);
}

// -------------------------------------------------------------------------
//   Methods corresponding to event handlers
// -------------------------------------------------------------------------
// -------------------------------------------------------------------------
//   Methods for neuron/synapse co-generation
// -------------------------------------------------------------------------

inline double
iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_spiketime_ms() const
{
  return last_spike_;
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::register_stdp_connection(double t_first_read, double delay)
{
  // Mark all entries in the deque, which we will not read in future as read by
  // this input input, so that we safely increment the incoming number of
  // connections afterwards without leaving spikes in the history.
  // For details see bug #218. MH 08-04-22

  for (std::deque<histentry__iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic>::iterator runner = history_.begin();
       runner != history_.end() and (t_first_read - runner->t_ > -1.0 * nest::kernel().connection_manager.get_stdp_eps());
       ++runner)
  {
    (runner->access_counter_)++;
  }

  n_incoming_++;

  max_delay_ = std::max(delay, max_delay_);
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_history__(double t1,
                                                                                          double t2,
                                                                                          std::deque<histentry__iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic>::iterator *start,
                                                                                          std::deque<histentry__iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic>::iterator *finish)
{
  *finish = history_.end();
  if (history_.empty())
  {
    *start = *finish;
    return;
  }
  std::deque<histentry__iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic>::reverse_iterator runner = history_.rbegin();
  const double t2_lim = t2 + nest::kernel().connection_manager.get_stdp_eps();
  const double t1_lim = t1 + nest::kernel().connection_manager.get_stdp_eps();
  while (runner != history_.rend() and runner->t_ >= t2_lim)
  {
    ++runner;
  }
  *finish = runner.base();
  while (runner != history_.rend() and runner->t_ >= t1_lim)
  {
    runner->access_counter_++;
    ++runner;
  }
  *start = runner.base();
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::set_spiketime(nest::Time const &t_sp, double offset)
{
  ArchivingNode::set_spiketime(t_sp, offset);

  unsigned int num_transferred_variables = 0;
  ++num_transferred_variables;

  const double t_sp_ms = t_sp.get_ms() - offset;

  if (n_incoming_)
  {
    // prune all spikes from history which are no longer needed
    // only remove a spike if:
    // - its access counter indicates it has been read out by all connected
    //     STDP synapses, and
    // - there is another, later spike, that is strictly more than
    //     (min_global_delay + max_delay_ + eps) away from the new spike (at t_sp_ms)
    while (history_.size() > 1)
    {
      const double next_t_sp = history_[1].t_;
      if (history_.front().access_counter_ >= n_incoming_ * num_transferred_variables and t_sp_ms - next_t_sp > max_delay_ + nest::Time::delay_steps_to_ms(nest::kernel().connection_manager.get_min_delay()) + nest::kernel().connection_manager.get_stdp_eps())
      {
        history_.pop_front();
      }
      else
      {
        break;
      }
    }

    if (history_.size() > 0)
    {
      assert(history_.back().t_ == last_spike_);
      S_.post_trace__for_stdp_synapse_NESTML_Plastic = history_.back().post_trace__for_stdp_synapse_NESTML_Plastic_;
    }
    else
    {
      S_.post_trace__for_stdp_synapse_NESTML_Plastic = 0.0; // initial value for convolution is always 0
    }

    /**
     * update state variables transferred from synapse from `last_spike_` to `t_sp_ms`
     *
     * variables that will be integrated: ['post_trace__for_stdp_synapse_NESTML_Plastic']
     **/

    const double old___h = V_.__h;
    V_.__h = t_sp_ms - last_spike_;
    if (V_.__h > 1E-12)
    {
      recompute_internal_variables(true);

      // start rendered code for integrate_odes(post_trace__for_stdp_synapse_NESTML_Plastic)

      // analytic solver: integrating state variables (first step): post_trace__for_stdp_synapse_NESTML_Plastic,
      const double post_trace__for_stdp_synapse_NESTML_Plastic__tmp = V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic * S_.post_trace__for_stdp_synapse_NESTML_Plastic;
      // analytic solver: integrating state variables (second step): post_trace__for_stdp_synapse_NESTML_Plastic,
      /* replace analytically solvable variables with precisely integrated values  */
      S_.post_trace__for_stdp_synapse_NESTML_Plastic = post_trace__for_stdp_synapse_NESTML_Plastic__tmp;

      V_.__h = old___h;
      recompute_internal_variables(true);
    }

    /**
     * print extra on-emit statements transferred from synapse
     **/
    S_.post_trace__for_stdp_synapse_NESTML_Plastic += 1;

    /**
     * print updates due to convolutions
     **/

    last_spike_ = t_sp_ms;
    history_.push_back(histentry__iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic(last_spike_, get_post_trace__for_stdp_synapse_NESTML_Plastic(), 0));
  }
  else
  {
    last_spike_ = t_sp_ms;
  }
}

void iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::clear_history()
{
  last_spike_ = -1.0;
  history_.clear();
}

double
iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic(double t, const bool before_increment)
{
#ifdef DEBUG
  std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic: getting value at t = " << t << std::endl;
#endif

  // case when the neuron has not yet spiked
  if (history_.empty())
  {
#ifdef DEBUG
    std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic: \thistory empty, returning initial value = " << post_trace__for_stdp_synapse_NESTML_Plastic__iv << std::endl;
#endif
    // return initial value
    return post_trace__for_stdp_synapse_NESTML_Plastic__iv;
  }

  // search for the latest post spike in the history buffer that came strictly before `t`
  int i = history_.size() - 1;
  double eps = 0.;
  if (before_increment)
  {
    eps = nest::kernel().connection_manager.get_stdp_eps();
  }
  while (i >= 0)
  {
    if (t - history_[i].t_ >= eps)
    {
#ifdef DEBUG
      std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic: \tspike occurred at history[i].t_ = " << history_[i].t_ << std::endl;
#endif
      S_.post_trace__for_stdp_synapse_NESTML_Plastic = history_[i].post_trace__for_stdp_synapse_NESTML_Plastic_;

      /**
       * update state variables transferred from synapse from `history[i].t_` to `t`
       *
       * variables that will be integrated: ['post_trace__for_stdp_synapse_NESTML_Plastic']
       **/

      if (t - history_[i].t_ >= nest::kernel().connection_manager.get_stdp_eps())
      {
        const double old___h = V_.__h;
        V_.__h = t - history_[i].t_;
        assert(V_.__h > 0);
        recompute_internal_variables(true);

        // start rendered code for integrate_odes(post_trace__for_stdp_synapse_NESTML_Plastic)

        // analytic solver: integrating state variables (first step): post_trace__for_stdp_synapse_NESTML_Plastic,
        const double post_trace__for_stdp_synapse_NESTML_Plastic__tmp = V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic * S_.post_trace__for_stdp_synapse_NESTML_Plastic;
        // analytic solver: integrating state variables (second step): post_trace__for_stdp_synapse_NESTML_Plastic,
        /* replace analytically solvable variables with precisely integrated values  */
        S_.post_trace__for_stdp_synapse_NESTML_Plastic = post_trace__for_stdp_synapse_NESTML_Plastic__tmp;

        V_.__h = old___h;
        recompute_internal_variables(true);
      }

#ifdef DEBUG
      std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic: \treturning " << S_.post_trace__for_stdp_synapse_NESTML_Plastic << std::endl;
#endif
      return S_.post_trace__for_stdp_synapse_NESTML_Plastic; // type: double
    }
    --i;
  }

  // this case occurs when the trace was requested at a time precisely at that of the first spike in the history
  if ((!before_increment) and t == history_[0].t_)
  {
    S_.post_trace__for_stdp_synapse_NESTML_Plastic = history_[0].post_trace__for_stdp_synapse_NESTML_Plastic_;

#ifdef DEBUG
    std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic: \ttrace requested at exact time of history entry 0, returning " << S_.post_trace__for_stdp_synapse_NESTML_Plastic << std::endl;
#endif
    return S_.post_trace__for_stdp_synapse_NESTML_Plastic;
  }

  // this case occurs when the trace was requested at a time before the first spike in the history
  // return initial value propagated in time
#ifdef DEBUG
  std::cout << "iaf_psc_alpha_neuron_NESTML_Plastic__with_stdp_synapse_NESTML_Plastic::get_post_trace__for_stdp_synapse_NESTML_Plastic: \tfall-through, returning initial value = " << post_trace__for_stdp_synapse_NESTML_Plastic__iv << std::endl;
#endif

  if (t == 0.)
  {
    return 0.; // initial value for convolution is always 0
  }

  // set to initial value
  S_.post_trace__for_stdp_synapse_NESTML_Plastic = 0.; // initial value for convolution is always 0

  /**
   * update state variables transferred from synapse from initial condition to `t`
   *
   * variables that will be integrated: ['post_trace__for_stdp_synapse_NESTML_Plastic']
   **/

  const double old___h = V_.__h;
  V_.__h = t; // from time 0 to the requested time
  assert(V_.__h > 0);
  recompute_internal_variables(true);

  // start rendered code for integrate_odes(post_trace__for_stdp_synapse_NESTML_Plastic)

  // analytic solver: integrating state variables (first step): post_trace__for_stdp_synapse_NESTML_Plastic,
  const double post_trace__for_stdp_synapse_NESTML_Plastic__tmp = V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic__post_trace__for_stdp_synapse_NESTML_Plastic * S_.post_trace__for_stdp_synapse_NESTML_Plastic;
  // analytic solver: integrating state variables (second step): post_trace__for_stdp_synapse_NESTML_Plastic,
  /* replace analytically solvable variables with precisely integrated values  */
  S_.post_trace__for_stdp_synapse_NESTML_Plastic = post_trace__for_stdp_synapse_NESTML_Plastic__tmp;

  V_.__h = old___h;
  recompute_internal_variables(true);

  return S_.post_trace__for_stdp_synapse_NESTML_Plastic;
}
