// #define DEBUG 1
/*
 *  aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized.cpp
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
 *  Generated from NESTML at time: 2024-03-13 22:51:44.264823
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

#include "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized.h"

// ---------------------------------------------------------------------------
//   Recordables map
// ---------------------------------------------------------------------------
nest::RecordablesMap<aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized> aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::recordablesMap_;
namespace nest
{

  // Override the create() method with one call to RecordablesMap::insert_()
  // for each quantity to be recorded.
  template <>
  void RecordablesMap<aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized>::create()
  {
    // add state variables to recordables map
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_V_m, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_V_m);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_w, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_w);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_refr_t, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_refr_t);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_g_exc__X__exc_spikes, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_g_exc__X__exc_spikes);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_g_exc__X__exc_spikes__d, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_g_exc__X__exc_spikes__d);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_g_inh__X__inh_spikes, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_g_inh__X__inh_spikes);
    insert_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_names::_g_inh__X__inh_spikes__d, &aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_g_inh__X__inh_spikes__d);

    // Add vector variables
  }
}
std::vector<std::tuple<int, int>> aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::rport_to_nestml_buffer_idx =
    {

        {aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::EXC_SPIKES, aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::INH_SPIKES},
};

// ---------------------------------------------------------------------------
//   Default constructors defining default parameters and state
//   Note: the implementation is empty. The initialization is of variables
//   is a part of aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized's constructor.
// ---------------------------------------------------------------------------

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::Parameters_::Parameters_()
{
}

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::State_::State_()
{
}

// ---------------------------------------------------------------------------
//   Parameter and state extractions and manipulation functions
// ---------------------------------------------------------------------------

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::Buffers_::Buffers_(aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized &n) : logger_(n), spike_inputs_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_inputs_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), spike_input_received_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_input_received_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), __s(nullptr), __c(nullptr), __e(nullptr)
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::Buffers_::Buffers_(const Buffers_ &, aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized &n) : logger_(n), spike_inputs_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_inputs_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), spike_input_received_(std::vector<nest::RingBuffer>(NUM_SPIKE_RECEPTORS)), spike_input_received_grid_sum_(std::vector<double>(NUM_SPIKE_RECEPTORS)), __s(nullptr), __c(nullptr), __e(nullptr)
{
  // Initialization of the remaining members is deferred to init_buffers_().
}

// ---------------------------------------------------------------------------
//   Default constructor for node
// ---------------------------------------------------------------------------

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized() : ArchivingNode(), P_(), S_(), B_(*this)
{
  init_state_internal_();
  recordablesMap_.create();
  pre_run_hook();
}

// ---------------------------------------------------------------------------
//   Copy constructor for node
// ---------------------------------------------------------------------------

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized(const aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized &__n) : ArchivingNode(), P_(__n.P_), S_(__n.S_), B_(__n.B_, *this)
{

  // copy parameter struct P_
  P_.C_m = __n.P_.C_m;
  P_.refr_T = __n.P_.refr_T;
  P_.V_reset = __n.P_.V_reset;
  P_.g_L = __n.P_.g_L;
  P_.E_L = __n.P_.E_L;
  P_.a = __n.P_.a;
  P_.b = __n.P_.b;
  P_.Delta_T = __n.P_.Delta_T;
  P_.tau_w = __n.P_.tau_w;
  P_.V_th = __n.P_.V_th;
  P_.V_peak = __n.P_.V_peak;
  P_.tau_syn_exc = __n.P_.tau_syn_exc;
  P_.tau_syn_inh = __n.P_.tau_syn_inh;
  P_.I_e = __n.P_.I_e;
  P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized = __n.P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized;

  // copy state struct S_
  S_.ode_state[State_::V_m] = __n.S_.ode_state[State_::V_m];
  S_.ode_state[State_::w] = __n.S_.ode_state[State_::w];
  S_.refr_t = __n.S_.refr_t;
  S_.is_refractory = __n.S_.is_refractory;
  S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = __n.S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];
  S_.ode_state[State_::g_exc__X__exc_spikes] = __n.S_.ode_state[State_::g_exc__X__exc_spikes];
  S_.ode_state[State_::g_exc__X__exc_spikes__d] = __n.S_.ode_state[State_::g_exc__X__exc_spikes__d];
  S_.ode_state[State_::g_inh__X__inh_spikes] = __n.S_.ode_state[State_::g_inh__X__inh_spikes];
  S_.ode_state[State_::g_inh__X__inh_spikes__d] = __n.S_.ode_state[State_::g_inh__X__inh_spikes__d];

  // copy internals V_
  V_.__h = __n.V_.__h;
  V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized = __n.V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized;
  V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes = __n.V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes;
  V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d = __n.V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d;
  V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes = __n.V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes;
  V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d = __n.V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d;
  V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes = __n.V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes;
  V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d = __n.V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d;
  V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes = __n.V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes;
  V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d = __n.V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d;
  n_incoming_ = __n.n_incoming_;
  max_delay_ = __n.max_delay_;
  last_spike_ = __n.last_spike_;

  // cache initial values
  post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__iv = S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];
}

// ---------------------------------------------------------------------------
//   Destructor for node
// ---------------------------------------------------------------------------

aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::~aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized()
{
  // GSL structs may not have been allocated, so we need to protect destruction

  if (B_.__s)
  {
    gsl_odeiv_step_free(B_.__s);
  }

  if (B_.__c)
  {
    gsl_odeiv_control_free(B_.__c);
  }

  if (B_.__e)
  {
    gsl_odeiv_evolve_free(B_.__e);
  }
}

// ---------------------------------------------------------------------------
//   Node initialization functions
// ---------------------------------------------------------------------------
void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::calibrate_time(const nest::TimeConverter &tc)
{
  LOG(nest::M_WARNING,
      "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized",
      "Simulation resolution has changed. Internal state and parameters of the model have been reset!");

  init_state_internal_();
}
void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::init_state_internal_()
{
#ifdef DEBUG
  std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::init_state_internal_()" << std::endl;
#endif

  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function
  pre_run_hook();
  // by default, integrate all variables
  // use a default "good enough" value for the absolute error. It can be adjusted via `node.set()`
  P_.__gsl_error_tol = 1e-6;
  // initial values for parameters
  P_.C_m = 281.0;                                                 // as pF
  P_.refr_T = 2;                                                  // as ms
  P_.V_reset = (-60.0);                                           // as mV
  P_.g_L = 30.0;                                                  // as nS
  P_.E_L = (-70.6);                                               // as mV
  P_.a = 4;                                                       // as nS
  P_.b = 80.5;                                                    // as pA
  P_.Delta_T = 2.0;                                               // as mV
  P_.tau_w = 144.0;                                               // as ms
  P_.V_th = (-50.4);                                              // as mV
  P_.V_peak = 0;                                                  // as mV
  P_.tau_syn_exc = 0.2;                                           // as ms
  P_.tau_syn_inh = 2.0;                                           // as ms
  P_.I_e = 0;                                                     // as pA
  P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized = 20; // as ms

  V_.__h = nest::Time::get_resolution().get_ms();
  recompute_internal_variables();
  // initial values for state variables
  S_.ode_state[State_::V_m] = P_.E_L;                                                // as mV
  S_.ode_state[State_::w] = 0;                                                       // as pA
  S_.refr_t = 0;                                                                     // as ms
  S_.is_refractory = false;                                                          // as boolean
  S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = 0.0; // as real
  S_.ode_state[State_::g_exc__X__exc_spikes] = 0;                                    // as real
  S_.ode_state[State_::g_exc__X__exc_spikes__d] = 0;                                 // as 1 / s
  S_.ode_state[State_::g_inh__X__inh_spikes] = 0;                                    // as real
  S_.ode_state[State_::g_inh__X__inh_spikes__d] = 0;                                 // as 1 / s
  // state variables for archiving state for paired synapse
  n_incoming_ = 0;
  max_delay_ = 0;
  last_spike_ = -1.;

  // cache initial values
  post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__iv = S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];
}

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::init_buffers_()
{
#ifdef DEBUG
  std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::init_buffers_()" << std::endl;
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

  if (not B_.__s)
  {
    B_.__s = gsl_odeiv_step_alloc(gsl_odeiv_step_rkf45, State_::STATE_VEC_SIZE);
  }
  else
  {
    gsl_odeiv_step_reset(B_.__s);
  }

  if (not B_.__c)
  {
    B_.__c = gsl_odeiv_control_y_new(P_.__gsl_error_tol, 0.0);
  }
  else
  {
    gsl_odeiv_control_init(B_.__c, P_.__gsl_error_tol, 0.0, 1.0, 0.0);
  }

  if (not B_.__e)
  {
    B_.__e = gsl_odeiv_evolve_alloc(State_::STATE_VEC_SIZE);
  }
  else
  {
    gsl_odeiv_evolve_reset(B_.__e);
  }

  // B_.__sys.function = aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_dynamics; // will be set just prior to the call to gsl_odeiv_evolve_apply()
  B_.__sys.jacobian = nullptr;
  B_.__sys.dimension = State_::STATE_VEC_SIZE;
  B_.__sys.params = reinterpret_cast<void *>(this);
  B_.__step = nest::Time::get_resolution().get_ms();
  B_.__integration_step = nest::Time::get_resolution().get_ms();
}

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::recompute_internal_variables(bool exclude_timestep)
{
  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function

  if (exclude_timestep)
  {
    V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized = 1.0 * std::exp((-V_.__h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized); // as real
    V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes = 1.0 * (V_.__h + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                 // as real
    V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc);                                                                                                  // as real
    V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc) / pow(P_.tau_syn_exc, 2);                                                                      // as real
    V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                        // as real
    V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes = 1.0 * (V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                 // as real
    V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh);                                                                                                  // as real
    V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh) / pow(P_.tau_syn_inh, 2);                                                                      // as real
    V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                        // as real
  }
  else
  {
    V_.__h = __resolution;                                                                                                                                                                                        // as ms
    V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized = 1.0 * std::exp((-V_.__h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized); // as real
    V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes = 1.0 * (V_.__h + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                                 // as real
    V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc);                                                                                                  // as real
    V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_exc) / pow(P_.tau_syn_exc, 2);                                                                      // as real
    V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_exc) * std::exp((-V_.__h) / P_.tau_syn_exc) / P_.tau_syn_exc;                                                        // as real
    V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes = 1.0 * (V_.__h + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                                 // as real
    V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d = 1.0 * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh);                                                                                                  // as real
    V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes = (-1.0) * V_.__h * std::exp((-V_.__h) / P_.tau_syn_inh) / pow(P_.tau_syn_inh, 2);                                                                      // as real
    V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d = 1.0 * ((-V_.__h) + P_.tau_syn_inh) * std::exp((-V_.__h) / P_.tau_syn_inh) / P_.tau_syn_inh;                                                        // as real
  }
}
void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::pre_run_hook()
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

extern "C" inline int aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_dynamics(double __time, const double ode_state[], double f[], void *pnode)
{
  typedef aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::State_ State_;
  // get access to node so we can almost work as in a member function
  assert(pnode);
  const aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized &node = *(reinterpret_cast<aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized *>(pnode));

  // ode_state[] here is---and must be---the state vector supplied by the integrator,
  // not the state vector in the node, node.S_.ode_state[].
  f[State_::V_m] = node.P_.g_L * (node.P_.Delta_T * std::exp(((-node.P_.V_th) + std::min(ode_state[State_::V_m], node.P_.V_peak)) / node.P_.Delta_T) / node.P_.C_m + node.P_.E_L / node.P_.C_m - std::min(ode_state[State_::V_m], node.P_.V_peak) / node.P_.C_m) + node.P_.I_e / node.P_.C_m + node.B_.I_stim_grid_sum_ / node.P_.C_m + (1.0 * ode_state[State_::g_exc__X__exc_spikes] - 1.0 * ode_state[State_::g_inh__X__inh_spikes] - ode_state[State_::w]) / node.P_.C_m;
  f[State_::w] = ((-node.P_.E_L) * node.P_.a + node.P_.a * std::min(ode_state[State_::V_m], node.P_.V_peak) - ode_state[State_::w]) / node.P_.tau_w;
  f[State_::g_exc__X__exc_spikes] = 1.0 * ode_state[State_::g_exc__X__exc_spikes__d];
  f[State_::g_exc__X__exc_spikes__d] = (-ode_state[State_::g_exc__X__exc_spikes]) / pow(node.P_.tau_syn_exc, 2) - 2 * ode_state[State_::g_exc__X__exc_spikes__d] / node.P_.tau_syn_exc;
  f[State_::g_inh__X__inh_spikes] = 1.0 * ode_state[State_::g_inh__X__inh_spikes__d];
  f[State_::g_inh__X__inh_spikes__d] = (-ode_state[State_::g_inh__X__inh_spikes]) / pow(node.P_.tau_syn_inh, 2) - 2 * ode_state[State_::g_inh__X__inh_spikes__d] / node.P_.tau_syn_inh;
  f[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = (-ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized]) / node.P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized;
  return GSL_SUCCESS;
}
extern "C" inline int aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_dynamics_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized(double __time, const double ode_state[], double f[], void *pnode)
{
  typedef aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::State_ State_;
  // get access to node so we can almost work as in a member function
  assert(pnode);
  const aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized &node = *(reinterpret_cast<aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized *>(pnode));

  // ode_state[] here is---and must be---the state vector supplied by the integrator,
  // not the state vector in the node, node.S_.ode_state[].
  f[State_::V_m] = 0;
  f[State_::w] = 0;
  f[State_::g_exc__X__exc_spikes] = 1.0 * ode_state[State_::g_exc__X__exc_spikes__d];
  f[State_::g_exc__X__exc_spikes__d] = (-ode_state[State_::g_exc__X__exc_spikes]) / pow(node.P_.tau_syn_exc, 2) - 2 * ode_state[State_::g_exc__X__exc_spikes__d] / node.P_.tau_syn_exc;
  f[State_::g_inh__X__inh_spikes] = 1.0 * ode_state[State_::g_inh__X__inh_spikes__d];
  f[State_::g_inh__X__inh_spikes__d] = (-ode_state[State_::g_inh__X__inh_spikes]) / pow(node.P_.tau_syn_inh, 2) - 2 * ode_state[State_::g_inh__X__inh_spikes__d] / node.P_.tau_syn_inh;
  f[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = (-ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized]) / node.P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized;
  return GSL_SUCCESS;
}
void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::update(nest::Time const &origin, const long from, const long to)
{

  sw_update.start();

  const double __resolution = nest::Time::get_resolution().get_ms(); // do not remove, this is necessary for the resolution() function

#ifdef DEBUG
  std::cout << "In aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::update: t = " << __resolution << std::endl;
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
    const double g_exc__X__exc_spikes__tmp_ = V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes * S_.ode_state[State_::g_exc__X__exc_spikes] + V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d * S_.ode_state[State_::g_exc__X__exc_spikes__d];
    const double g_exc__X__exc_spikes__d__tmp_ = V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes * S_.ode_state[State_::g_exc__X__exc_spikes] + V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d * S_.ode_state[State_::g_exc__X__exc_spikes__d];
    const double g_inh__X__inh_spikes__tmp_ = V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes * S_.ode_state[State_::g_inh__X__inh_spikes] + V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d * S_.ode_state[State_::g_inh__X__inh_spikes__d];
    const double g_inh__X__inh_spikes__d__tmp_ = V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes * S_.ode_state[State_::g_inh__X__inh_spikes] + V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d * S_.ode_state[State_::g_inh__X__inh_spikes__d];

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

      // analytic solver: integrating state variables (first step): g_exc__X__exc_spikes, g_exc__X__exc_spikes__d, g_inh__X__inh_spikes, g_inh__X__inh_spikes__d, post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
      const double g_exc__X__exc_spikes__tmp = V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes * S_.ode_state[State_::g_exc__X__exc_spikes] + V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d * S_.ode_state[State_::g_exc__X__exc_spikes__d];
      const double g_exc__X__exc_spikes__d__tmp = V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes * S_.ode_state[State_::g_exc__X__exc_spikes] + V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d * S_.ode_state[State_::g_exc__X__exc_spikes__d];
      const double g_inh__X__inh_spikes__tmp = V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes * S_.ode_state[State_::g_inh__X__inh_spikes] + V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d * S_.ode_state[State_::g_inh__X__inh_spikes__d];
      const double g_inh__X__inh_spikes__d__tmp = V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes * S_.ode_state[State_::g_inh__X__inh_spikes] + V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d * S_.ode_state[State_::g_inh__X__inh_spikes__d];
      const double post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp = V_.__P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized * S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];

      // numeric solver: integrating state variables: V_m, w, g_exc__X__exc_spikes, g_exc__X__exc_spikes__d, g_inh__X__inh_spikes, g_inh__X__inh_spikes__d,
      double __t = 0;
      B_.__sys.function = aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized_dynamics;
      // numerical integration with adaptive step size control:
      // ------------------------------------------------------
      // gsl_odeiv_evolve_apply performs only a single numerical
      // integration step, starting from t and bounded by step;
      // the while-loop ensures integration over the whole simulation
      // step (0, step] if more than one integration step is needed due
      // to a small integration step size;
      // note that (t+IntegrationStep > step) leads to integration over
      // (t, step] and afterwards setting t to step, but it does not
      // enforce setting IntegrationStep to step-t; this is of advantage
      // for a consistent and efficient integration across subsequent
      // simulation intervals
      while (__t < B_.__step)
      {

        const int status = gsl_odeiv_evolve_apply(B_.__e,
                                                  B_.__c,
                                                  B_.__s,
                                                  &B_.__sys,              // system of ODE
                                                  &__t,                   // from t
                                                  B_.__step,              // to t <= step
                                                  &B_.__integration_step, // integration step size
                                                  S_.ode_state);          // neuronal state

        if (status != GSL_SUCCESS)
        {
          throw nest::GSLSolverFailure(get_name(), status);
        }
      }
      // analytic solver: integrating state variables (second step): g_exc__X__exc_spikes, g_exc__X__exc_spikes__d, g_inh__X__inh_spikes, g_inh__X__inh_spikes__d, post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
      /* replace analytically solvable variables with precisely integrated values  */
      S_.ode_state[State_::g_exc__X__exc_spikes] = g_exc__X__exc_spikes__tmp;
      S_.ode_state[State_::g_exc__X__exc_spikes__d] = g_exc__X__exc_spikes__d__tmp;
      S_.ode_state[State_::g_inh__X__inh_spikes] = g_inh__X__inh_spikes__tmp;
      S_.ode_state[State_::g_inh__X__inh_spikes__d] = g_inh__X__inh_spikes__d__tmp;
      S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp;
    }

    /**
     * Begin NESTML generated code for the onReceive block(s)
     **/

    /**
     * subthreshold updates of the convolution variables
     *
     * step 2: regardless of whether and how integrate_odes() was called, update variables due to convolutions. Set to the updated values at the end of the timestep.
     **/

    S_.ode_state[State_::g_exc__X__exc_spikes] = g_exc__X__exc_spikes__tmp_;
    S_.ode_state[State_::g_exc__X__exc_spikes__d] = g_exc__X__exc_spikes__d__tmp_;
    S_.ode_state[State_::g_inh__X__inh_spikes] = g_inh__X__inh_spikes__tmp_;
    S_.ode_state[State_::g_inh__X__inh_spikes__d] = g_inh__X__inh_spikes__d__tmp_;

    /**
     * spike updates due to convolutions
     **/

    S_.ode_state[State_::g_exc__X__exc_spikes__d] += ((0.001 * B_.spike_inputs_grid_sum_[EXC_SPIKES - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn_exc) / (1 / 1000.0);
    S_.ode_state[State_::g_inh__X__inh_spikes__d] += ((0.001 * B_.spike_inputs_grid_sum_[INH_SPIKES - MIN_SPIKE_RECEPTOR])) * (numerics::e / P_.tau_syn_inh) / (1 / 1000.0);

    /**
     * Begin NESTML generated code for the onCondition block(s)
     **/

    if (S_.ode_state[State_::V_m] >= P_.V_th)
    {
      S_.refr_t = P_.refr_T;
      S_.is_refractory = true;
      S_.ode_state[State_::V_m] = P_.V_reset;
      S_.ode_state[State_::w] += P_.b;

      /**
       * generated code for emit_spike() function
       **/

      set_spiketime(nest::Time::step(origin.get_steps() + lag + 1));
      nest::SpikeEvent se;
      nest::kernel().event_delivery_manager.send(*this, se, lag);
    }
    if (S_.is_refractory && S_.refr_t <= __resolution / 2)
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
  sw_update.stop();
}

// Do not move this function as inline to h-file. It depends on
// universal_data_logger_impl.h being included here.
void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::handle(nest::DataLoggingRequest &e)
{
  B_.logger_.handle(e);
}

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::handle(nest::SpikeEvent &e)
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
    if (nestml_buffer_idx == aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::PORT_NOT_AVAILABLE)
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

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::handle(nest::CurrentEvent &e)
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
aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_spiketime_ms() const
{
  return last_spike_;
}

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::register_stdp_connection(double t_first_read, double delay)
{
  // Mark all entries in the deque, which we will not read in future as read by
  // this input input, so that we safely increment the incoming number of
  // connections afterwards without leaving spikes in the history.
  // For details see bug #218. MH 08-04-22

  for (std::deque<histentry__aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized>::iterator runner = history_.begin();
       runner != history_.end() and (t_first_read - runner->t_ > -1.0 * nest::kernel().connection_manager.get_stdp_eps());
       ++runner)
  {
    (runner->access_counter_)++;
  }

  n_incoming_++;

  max_delay_ = std::max(delay, max_delay_);
}

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_history__(double t1,
                                                                                                               double t2,
                                                                                                               std::deque<histentry__aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized>::iterator *start,
                                                                                                               std::deque<histentry__aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized>::iterator *finish)
{
  *finish = history_.end();
  if (history_.empty())
  {
    *start = *finish;
    return;
  }
  std::deque<histentry__aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized>::reverse_iterator runner = history_.rbegin();
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

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::set_spiketime(nest::Time const &t_sp, double offset)
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
      S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = history_.back().post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_;
    }
    else
    {
      S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = 0.0; // initial value for convolution is always 0
    }

    /**
     * update state variables transferred from synapse from `last_spike_` to `t_sp_ms`
     *
     * variables that will be integrated: ['post_trace__for_stdp_synapse_NESTML_Plastic_Optimized']
     **/

    const double h_prev = t_sp_ms - last_spike_;
    if (h_prev > 1E-12)
    {
      const double prev_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized = 1.0 * std::exp((-V_.__h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized);
      // start rendered code for integrate_odes(post_trace__for_stdp_synapse_NESTML_Plastic_Optimized)

      // analytic solver: integrating state variables (first step): post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
      const double post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp = prev_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized * S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];

      // analytic solver: integrating state variables (second step): post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
      /* replace analytically solvable variables with precisely integrated values  */
      S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp;
    }

    /**
     * print extra on-emit statements transferred from synapse
     **/
    S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] += 1;

    /**
     * print updates due to convolutions
     **/

    last_spike_ = t_sp_ms;
    history_.push_back(histentry__aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized(last_spike_, get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized(), 0));
  }
  else
  {
    last_spike_ = t_sp_ms;
  }
}

void aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::clear_history()
{
  last_spike_ = -1.0;
  history_.clear();
}

double
aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized(double t, const bool before_increment)
{
#ifdef DEBUG
  std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized: getting value at t = " << t << std::endl;
#endif

  // case when the neuron has not yet spiked
  if (history_.empty())
  {
#ifdef DEBUG
    std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized: \thistory empty, returning initial value = " << post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__iv << std::endl;
#endif
    // return initial value
    return post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__iv;
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
      std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized: \tspike occurred at history[i].t_ = " << history_[i].t_ << std::endl;
#endif
      S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = history_[i].post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_;

      /**
       * update state variables transferred from synapse from `history[i].t_` to `t`
       *
       * variables that will be integrated: ['post_trace__for_stdp_synapse_NESTML_Plastic_Optimized']
       **/
      const double prev_h = t - history_[i].t_;
      if (prev_h >= nest::kernel().connection_manager.get_stdp_eps())
      {
        assert(prev_h > 0);

        const double __P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_prev = 1.0 * std::exp((-prev_h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized); // as real
                                                                                                                                                                                                                                     // start rendered code for integrate_odes(post_trace__for_stdp_synapse_NESTML_Plastic_Optimized)

        // analytic solver: integrating state variables (first step): post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
        const double post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp = __P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_prev * S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];

        // analytic solver: integrating state variables (second step): post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
        /* replace analytically solvable variables with precisely integrated values  */
        S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp;
      }

#ifdef DEBUG
      std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized: \treturning " << S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] << std::endl;
#endif
      return S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized]; // type: double
    }
    --i;
  }

  // this case occurs when the trace was requested at a time precisely at that of the first spike in the history
  if ((!before_increment) and t == history_[0].t_)
  {
    S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = history_[0].post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_;

#ifdef DEBUG
    std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized: \ttrace requested at exact time of history entry 0, returning " << S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] << std::endl;
#endif
    return S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];
  }

  // this case occurs when the trace was requested at a time before the first spike in the history
  // return initial value propagated in time
#ifdef DEBUG
  std::cout << "aeif_psc_alpha_neuron_NESTML_Plastic_Optimized__with_stdp_synapse_NESTML_Plastic_Optimized::get_post_trace__for_stdp_synapse_NESTML_Plastic_Optimized: \tfall-through, returning initial value = " << post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__iv << std::endl;
#endif

  if (t == 0.)
  {
    return 0.; // initial value for convolution is always 0
  }

  // set to initial value
  S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = 0.; // initial value for convolution is always 0

  /**
   * update state variables transferred from synapse from initial condition to `t`
   *
   * variables that will be integrated: ['post_trace__for_stdp_synapse_NESTML_Plastic_Optimized']
   **/

  const double prev_h = t;
  assert(prev_h > 0);

  // start rendered code for integrate_odes(post_trace__for_stdp_synapse_NESTML_Plastic_Optimized)

  const double __P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_prev = 1.0 * std::exp((-prev_h) / P_.tau_tr_post__for_stdp_synapse_NESTML_Plastic_Optimized); // as real
  // analytic solver: integrating state variables (first step): post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
  const double post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp = __P__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__post_trace__for_stdp_synapse_NESTML_Plastic_Optimized_prev * S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];

  // analytic solver: integrating state variables (second step): post_trace__for_stdp_synapse_NESTML_Plastic_Optimized,
  /* replace analytically solvable variables with precisely integrated values  */
  S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized] = post_trace__for_stdp_synapse_NESTML_Plastic_Optimized__tmp;

  return S_.ode_state[State_::post_trace__for_stdp_synapse_NESTML_Plastic_Optimized];
}
