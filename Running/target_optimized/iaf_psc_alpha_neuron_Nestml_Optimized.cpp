// #define DEBUG 1
/*
 *  iaf_psc_alpha_neuron_Nestml_Optimized.cpp
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
 *  Generated from NESTML at time: 2024-01-12 14:07:37.821650
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

#include "iaf_psc_alpha_neuron_Nestml_Optimized.h"

// ---------------------------------------------------------------------------
//   Recordables map
// ---------------------------------------------------------------------------
nest::RecordablesMap<iaf_psc_alpha_neuron_Nestml_Optimized> iaf_psc_alpha_neuron_Nestml_Optimized::recordablesMap_;
namespace nest
{

  // Override the create() method with one call to RecordablesMap::insert_()
  // for each quantity to be recorded.
  template <>
  void RecordablesMap<iaf_psc_alpha_neuron_Nestml_Optimized>::create()
  {
    // add state variables to recordables map
    insert_(iaf_psc_alpha_neuron_Nestml_Optimized_names::_V_m, &iaf_psc_alpha_neuron_Nestml_Optimized::get_V_m);
    insert_(iaf_psc_alpha_neuron_Nestml_Optimized_names::_refr_t, &iaf_psc_alpha_neuron_Nestml_Optimized::get_refr_t);
    insert_(iaf_psc_alpha_neuron_Nestml_Optimized_names::_I_kernel_exc__X__exc_spikes, &iaf_psc_alpha_neuron_Nestml_Optimized::get_I_kernel_exc__X__exc_spikes);
    insert_(iaf_psc_alpha_neuron_Nestml_Optimized_names::_I_kernel_exc__X__exc_spikes__d, &iaf_psc_alpha_neuron_Nestml_Optimized::get_I_kernel_exc__X__exc_spikes__d);
    insert_(iaf_psc_alpha_neuron_Nestml_Optimized_names::_I_kernel_inh__X__inh_spikes, &iaf_psc_alpha_neuron_Nestml_Optimized::get_I_kernel_inh__X__inh_spikes);
    insert_(iaf_psc_alpha_neuron_Nestml_Optimized_names::_I_kernel_inh__X__inh_spikes__d, &iaf_psc_alpha_neuron_Nestml_Optimized::get_I_kernel_inh__X__inh_spikes__d);

    // Add vector variables
  }
}
std::vector<std::tuple<int, int>> iaf_psc_alpha_neuron_Nestml_Optimized::rport_to_nestml_buffer_idx =
    {

        {iaf_psc_alpha_neuron_Nestml_Optimized::EXC_SPIKES, iaf_psc_alpha_neuron_Nestml_Optimized::INH_SPIKES},
};

// ---------------------------------------------------------------------------
//   Default constructors defining default parameters and state
//   Note: the implementation is empty. The initialization is of variables
//   is a part of iaf_psc_alpha_neuron_Nestml_Optimized's constructor.
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_Nestml_Optimized::Parameters_::Parameters_()
{
}

iaf_psc_alpha_neuron_Nestml_Optimized::State_::State_()
{
}

// ---------------------------------------------------------------------------
//   Parameter and state extractions and manipulation functions
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_Nestml_Optimized::Buffers_::Buffers_(iaf_psc_alpha_neuron_Nestml_Optimized &n) : logger_(n), spike_inputs_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_inputs_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), spike_input_received_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_input_received_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS))
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

iaf_psc_alpha_neuron_Nestml_Optimized::Buffers_::Buffers_(const Buffers_ &, iaf_psc_alpha_neuron_Nestml_Optimized &n) : logger_(n), spike_inputs_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_inputs_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), spike_input_received_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_input_received_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS))
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

// ---------------------------------------------------------------------------
//   Default constructor for node
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_Nestml_Optimized::iaf_psc_alpha_neuron_Nestml_Optimized() : ArchivingNode(), P_(), S_(), B_(*this)
{
  init_state_internal_();
  recordablesMap_.create();
  pre_run_hook();
}

// ---------------------------------------------------------------------------
//   Copy constructor for node
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_Nestml_Optimized::iaf_psc_alpha_neuron_Nestml_Optimized(const iaf_psc_alpha_neuron_Nestml_Optimized &__n) : ArchivingNode(), P_(__n.P_), S_(__n.S_), B_(__n.B_, *this)
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

  // copy state struct S_
  S_.V_m = __n.S_.V_m;
  S_.refr_t = __n.S_.refr_t;
  S_.is_refractory = __n.S_.is_refractory;
  S_.I_kernel_exc__X__exc_spikes = __n.S_.I_kernel_exc__X__exc_spikes;
  S_.I_kernel_exc__X__exc_spikes__d = __n.S_.I_kernel_exc__X__exc_spikes__d;
  S_.I_kernel_inh__X__inh_spikes = __n.S_.I_kernel_inh__X__inh_spikes;
  S_.I_kernel_inh__X__inh_spikes__d = __n.S_.I_kernel_inh__X__inh_spikes__d;

  // copy internals V_
  V_.__h = __n.V_.__h;
  V_.__P__V_m__V_m = __n.V_.__P__V_m__V_m;
  V_.__P__V_m__I_kernel_exc__X__exc_spikes = __n.V_.__P__V_m__I_kernel_exc__X__exc_spikes;
  V_.__P__V_m__I_kernel_exc__X__exc_spikes__d = __n.V_.__P__V_m__I_kernel_exc__X__exc_spikes__d;
  V_.__P__V_m__I_kernel_inh__X__inh_spikes = __n.V_.__P__V_m__I_kernel_inh__X__inh_spikes;
  V_.__P__V_m__I_kernel_inh__X__inh_spikes__d = __n.V_.__P__V_m__I_kernel_inh__X__inh_spikes__d;
  V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes = __n.V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes;
  V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d = __n.V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d;
  V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes = __n.V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes;
  V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d = __n.V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d;
  V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes = __n.V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes;
  V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d = __n.V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d;
  V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes = __n.V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes;
  V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d = __n.V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d;
}

// ---------------------------------------------------------------------------
//   Destructor for node
// ---------------------------------------------------------------------------

iaf_psc_alpha_neuron_Nestml_Optimized::~iaf_psc_alpha_neuron_Nestml_Optimized()
{
}

// ---------------------------------------------------------------------------
//   Node initialization functions
// ---------------------------------------------------------------------------
void iaf_psc_alpha_neuron_Nestml_Optimized::calibrate_time(const nest::TimeConverter &tc)
{
  LOG(nest::M_WARNING,
      "iaf_psc_alpha_neuron_Nestml_Optimized",
      "Simulation resolution has changed. Internal state and parameters of the model have been reset!");

  init_state_internal_();
}
void iaf_psc_alpha_neuron_Nestml_Optimized::init_state_internal_()
{
#ifdef DEBUG
  std::cout << "iaf_psc_alpha_neuron_Nestml_Optimized::init_state_internal_()" << std::endl;
#endif

  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function
  pre_run_hook();
  // initial values for parameters
  P_.C_m = 250;       // as pF
  P_.tau_m = 10;      // as ms
  P_.tau_syn_inh = 2; // as ms
  P_.tau_syn_exc = 2; // as ms
  P_.refr_T = 2;      // as ms
  P_.E_L = (-70);     // as mV
  P_.V_reset = (-70); // as mV
  P_.V_th = (-55);    // as mV
  P_.I_e = 0;         // as pA

  V_.__h = nest::Time::get_resolution().get_ms();
  recompute_internal_variables();
  // initial values for state variables
  S_.V_m = P_.E_L;                       // as mV
  S_.refr_t = 0;                         // as ms
  S_.is_refractory = false;              // as boolean
  S_.I_kernel_exc__X__exc_spikes = 0;    // as real
  S_.I_kernel_exc__X__exc_spikes__d = 0; // as 1 / s
  S_.I_kernel_inh__X__inh_spikes = 0;    // as real
  S_.I_kernel_inh__X__inh_spikes__d = 0; // as 1 / s
}

void iaf_psc_alpha_neuron_Nestml_Optimized::init_buffers_()
{
#ifdef DEBUG
  std::cout << "iaf_psc_alpha_neuron_Nestml_Optimized::init_buffers_()" << std::endl;
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

void iaf_psc_alpha_neuron_Nestml_Optimized::recompute_internal_variables(bool exclude_timestep)
{
  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function

  if (exclude_timestep)
  {
    V_.__P__V_m__V_m = 1.0 * std::exp((-V_.__h) / P_.tau_m);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes = P_.tau_m * ((-0.25) * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) + 0.25 * V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc) + 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_m) - 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2))); // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_exc * ((-V_.__h) * P_.tau_m * std::exp(V_.__h / P_.tau_m) + V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2)));                                                                                                                                  // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes = P_.tau_m * (0.25 * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - 0.25 * V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh) - 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_m) + 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));    // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_inh * (V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));                                                                                                                                     // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes = 1.0 * (V_.__h + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc) / pow(P_.tau_syn_exc, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes = 1.0 * (V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh) / pow(P_.tau_syn_inh, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
  }
  else
  {
    V_.__h = __resolution;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as ms
    V_.__P__V_m__V_m = 1.0 * std::exp((-V_.__h) / P_.tau_m);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes = P_.tau_m * ((-0.25) * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) + 0.25 * V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc) + 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_m) - 0.25 * pow(P_.tau_syn_exc, 2) * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2))); // as real
    V_.__P__V_m__I_kernel_exc__X__exc_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_exc * ((-V_.__h) * P_.tau_m * std::exp(V_.__h / P_.tau_m) + V_.__h * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_exc * std::exp(V_.__h / P_.tau_syn_exc)) * std::exp((-V_.__h) / P_.tau_syn_exc - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_exc + 0.25 * pow(P_.tau_syn_exc, 2)));                                                                                                                                  // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes = P_.tau_m * (0.25 * V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - 0.25 * V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - 0.5 * P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh) - 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_m) + 0.25 * pow(P_.tau_syn_inh, 2) * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));    // as real
    V_.__P__V_m__I_kernel_inh__X__inh_spikes__d = 0.25 * P_.tau_m * P_.tau_syn_inh * (V_.__h * P_.tau_m * std::exp(V_.__h / P_.tau_m) - V_.__h * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) + P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_m) - P_.tau_m * P_.tau_syn_inh * std::exp(V_.__h / P_.tau_syn_inh)) * std::exp((-V_.__h) / P_.tau_syn_inh - V_.__h / P_.tau_m) / (P_.C_m * (0.25 * pow(P_.tau_m, 2) - 0.5 * P_.tau_m * P_.tau_syn_inh + 0.25 * pow(P_.tau_syn_inh, 2)));                                                                                                                                     // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes = 1.0 * (V_.__h + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc) / pow(P_.tau_syn_exc, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes = 1.0 * (V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                                   // as real
    V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh) / pow(P_.tau_syn_inh, 2);                                                                                                                                                                                                                                                                                                                                                                                                                                                                        // as real
    V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                                                                                                                                                                                                                                                                                                                                                                                                          // as real
  }
}
void iaf_psc_alpha_neuron_Nestml_Optimized::pre_run_hook()
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

void iaf_psc_alpha_neuron_Nestml_Optimized::update(nest::Time const &origin, const long from, const long to)
{
  sw_update.start();
  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function

#ifdef DEBUG
  std::cout << "In iaf_psc_alpha_neuron_Nestml_Optimized::update: t = " << __resolution << std::endl;
#endif
  sw_update1.start();
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
    const double I_kernel_exc__X__exc_spikes__tmp_ = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d;
    const double I_kernel_exc__X__exc_spikes__d__tmp_ = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d;
    const double I_kernel_inh__X__inh_spikes__tmp_ = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d;
    const double I_kernel_inh__X__inh_spikes__d__tmp_ = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d;

    /**
     * Begin NESTML generated code for the update block(s)
     **/

    if (S_.is_refractory)
    {
      S_.refr_t -= __resolution;
    }
    else
    {
      sw_update2.start();
      // start rendered code for integrate_odes()

      // analytic solver: integrating state variables (first step): V_m, I_kernel_exc__X__exc_spikes, I_kernel_exc__X__exc_spikes__d, I_kernel_inh__X__inh_spikes, I_kernel_inh__X__inh_spikes__d,
      const double V_m__tmp = (-P_.E_L) * V_.__P__V_m__V_m + P_.E_L + S_.I_kernel_exc__X__exc_spikes * V_.__P__V_m__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__V_m__I_kernel_exc__X__exc_spikes__d + S_.I_kernel_inh__X__inh_spikes * V_.__P__V_m__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__V_m__I_kernel_inh__X__inh_spikes__d + S_.V_m * V_.__P__V_m__V_m - P_.I_e * V_.__P__V_m__V_m * P_.tau_m / P_.C_m + P_.I_e * P_.tau_m / P_.C_m - B_.I_stim_grid_sum_ * V_.__P__V_m__V_m * P_.tau_m / P_.C_m + B_.I_stim_grid_sum_ * P_.tau_m / P_.C_m;
      const double I_kernel_exc__X__exc_spikes__tmp = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__I_kernel_exc__X__exc_spikes__d;
      const double I_kernel_exc__X__exc_spikes__d__tmp = S_.I_kernel_exc__X__exc_spikes * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes + S_.I_kernel_exc__X__exc_spikes__d * V_.__P__I_kernel_exc__X__exc_spikes__d__I_kernel_exc__X__exc_spikes__d;
      const double I_kernel_inh__X__inh_spikes__tmp = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__I_kernel_inh__X__inh_spikes__d;
      const double I_kernel_inh__X__inh_spikes__d__tmp = S_.I_kernel_inh__X__inh_spikes * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes + S_.I_kernel_inh__X__inh_spikes__d * V_.__P__I_kernel_inh__X__inh_spikes__d__I_kernel_inh__X__inh_spikes__d;
      // analytic solver: integrating state variables (second step): V_m, I_kernel_exc__X__exc_spikes, I_kernel_exc__X__exc_spikes__d, I_kernel_inh__X__inh_spikes, I_kernel_inh__X__inh_spikes__d,
      /* replace analytically solvable variables with precisely integrated values  */
      // TODO: Why is this here they are set below again?
      S_.V_m = V_m__tmp;
      S_.I_kernel_exc__X__exc_spikes = I_kernel_exc__X__exc_spikes__tmp;
      S_.I_kernel_exc__X__exc_spikes__d = I_kernel_exc__X__exc_spikes__d__tmp;
      S_.I_kernel_inh__X__inh_spikes = I_kernel_inh__X__inh_spikes__tmp;
      S_.I_kernel_inh__X__inh_spikes__d = I_kernel_inh__X__inh_spikes__d__tmp;
      sw_update2.stop();
    }

    /**
     * Begin NESTML generated code for the onReceive block(s)
     **/

    /**
     * subthreshold updates of the convolution variables
     *
     * step 2: regardless of whether and how integrate_odes() was called, update variables due to convolutions. Set to the updated values at the end of the timestep.
     **/

    S_.I_kernel_exc__X__exc_spikes = I_kernel_exc__X__exc_spikes__tmp_;
    S_.I_kernel_exc__X__exc_spikes__d = I_kernel_exc__X__exc_spikes__d__tmp_;
    S_.I_kernel_inh__X__inh_spikes = I_kernel_inh__X__inh_spikes__tmp_;
    S_.I_kernel_inh__X__inh_spikes__d = I_kernel_inh__X__inh_spikes__d__tmp_;

    /**
     * spike updates due to convolutions
     **/

    // TODO:the 0.001 and (1 / 1000.0) cancle each other out
    S_.I_kernel_exc__X__exc_spikes__d += ((0.001 * B_.spike_inputs_grid_sum_[EXC_SPIKES - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn_exc) / (1 / 1000.0);
    S_.I_kernel_inh__X__inh_spikes__d += ((0.001 * B_.spike_inputs_grid_sum_[INH_SPIKES - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn_inh) / (1 / 1000.0);

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
  sw_update1.stop();
  sw_update.stop();
}

// Do not move this function as inline to h-file. It depends on
// universal_data_logger_impl.h being included here.
void iaf_psc_alpha_neuron_Nestml_Optimized::handle(nest::DataLoggingRequest &e)
{
  B_.logger_.handle(e);
}

void iaf_psc_alpha_neuron_Nestml_Optimized::handle(nest::SpikeEvent &e)
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
    if (nestml_buffer_idx == iaf_psc_alpha_neuron_Nestml_Optimized::PORT_NOT_AVAILABLE)
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

void iaf_psc_alpha_neuron_Nestml_Optimized::handle(nest::CurrentEvent &e)
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
