
/**
 *  aeif_cond_alpha_neuron_Nestml_Plastic_Optimized.h
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
 *  Generated from NESTML at time: 2024-03-11 15:33:48.748447
**/
#ifndef AEIF_COND_ALPHA_NEURON_NESTML_PLASTIC_OPTIMIZED
#define AEIF_COND_ALPHA_NEURON_NESTML_PLASTIC_OPTIMIZED

#include "stopwatch.h"

#ifndef HAVE_LIBLTDL
#error "NEST was compiled without support for dynamic loading. Please install libltdl and recompile NEST."
#endif

// C++ includes:
#include <cmath>

#include "config.h"

#ifndef HAVE_GSL
#error "The GSL library is required for the Runge-Kutta solver."
#endif

// External includes:
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv.h>

// Includes from nestkernel:
#include "archiving_node.h"
#include "connection.h"
#include "dict_util.h"
#include "event.h"
#include "nest_types.h"
#include "ring_buffer.h"
#include "universal_data_logger.h"

// Includes from sli:
#include "dictdatum.h"

namespace nest
{
namespace aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names
{
    const Name _V_m( "V_m" );
    const Name _w( "w" );
    const Name _refr_t( "refr_t" );
    const Name _is_refractory( "is_refractory" );
    const Name _g_exc__X__exc_spikes( "g_exc__X__exc_spikes" );
    const Name _g_exc__X__exc_spikes__d( "g_exc__X__exc_spikes__d" );
    const Name _g_inh__X__inh_spikes( "g_inh__X__inh_spikes" );
    const Name _g_inh__X__inh_spikes__d( "g_inh__X__inh_spikes__d" );
    const Name _C_m( "C_m" );
    const Name _refr_T( "refr_T" );
    const Name _V_reset( "V_reset" );
    const Name _g_L( "g_L" );
    const Name _E_L( "E_L" );
    const Name _a( "a" );
    const Name _b( "b" );
    const Name _Delta_T( "Delta_T" );
    const Name _tau_w( "tau_w" );
    const Name _V_th( "V_th" );
    const Name _V_peak( "V_peak" );
    const Name _E_exc( "E_exc" );
    const Name _tau_syn_exc( "tau_syn_exc" );
    const Name _E_inh( "E_inh" );
    const Name _tau_syn_inh( "tau_syn_inh" );
    const Name _I_e( "I_e" );
}
}



/**
 * Function computing right-hand side of ODE for GSL solver.
 * @note Must be declared here so we can befriend it in class.
 * @note Must have C-linkage for passing to GSL. Internally, it is
 *       a first-class C++ function, but cannot be a member function
 *       because of the C-linkage.
 * @note No point in declaring it inline, since it is called
 *       through a function pointer.
 * @param void* Pointer to model neuron instance.
 *
 * Integrate the variables: 
**/
extern "C" inline int aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_dynamics( double, const double ode_state[], double f[], void* pnode );
/**
 * Function computing right-hand side of ODE for GSL solver.
 * @note Must be declared here so we can befriend it in class.
 * @note Must have C-linkage for passing to GSL. Internally, it is
 *       a first-class C++ function, but cannot be a member function
 *       because of the C-linkage.
 * @note No point in declaring it inline, since it is called
 *       through a function pointer.
 * @param void* Pointer to model neuron instance.
 *
 * Integrate the variables: []
**/
extern "C" inline int aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_dynamics( double, const double ode_state[], double f[], void* pnode );

#include "nest_time.h"
  typedef size_t nest_port_t;
  typedef size_t nest_rport_t;

/* BeginDocumentation
  Name: aeif_cond_alpha_neuron_Nestml_Plastic_Optimized

  Description:

    """
  aeif_cond_alpha - Conductance based exponential integrate-and-fire neuron model##############################################################################

  Description
  +++++++++++

  aeif_cond_alpha is the adaptive exponential integrate and fire neuron according to Brette and Gerstner (2005), with post-synaptic conductances in the form of a bi-exponential ("alpha") function.

  The membrane potential is given by the following differential equation:

  .. math::

     C_m \frac{dV_m}{dt} =
     -g_L(V_m-E_L)+g_L\Delta_T\exp\left(\frac{V_m-V_{th}}{\Delta_T}\right) -
   g_e(t)(V_m-E_e) \\
                                                       -g_i(t)(V_m-E_i)-w + I_e

  and

  .. math::

   \tau_w \frac{dw}{dt} = a(V_m-E_L) - w

  Note that the membrane potential can diverge to positive infinity due to the exponential term. To avoid numerical instabilities, instead of :math:`V_m`, the value :math:`\min(V_m,V_{peak})` is used in the dynamical equations.


  References
  ++++++++++

  .. [1] Brette R and Gerstner W (2005). Adaptive exponential
         integrate-and-fire model as an effective description of neuronal
         activity. Journal of Neurophysiology. 943637-3642
         DOI: https://doi.org/10.1152/jn.00686.2005


  See also
  ++++++++

  iaf_cond_alpha, aeif_cond_exp
  """


  Parameters:
  The following parameters can be set in the status dictionary.
C_m [pF]  membrane parameters
 Membrane Capacitance
refr_T [ms]  Duration of refractory period
V_reset [mV]  Reset Potential
g_L [nS]  Leak Conductance
E_L [mV]  Leak reversal Potential (aka resting potential)
a [nS]  spike adaptation parameters
 Subthreshold adaptation
b [pA]  Spike-triggered adaptation
Delta_T [mV]  Slope factor
tau_w [ms]  Adaptation time constant
V_th [mV]  Threshold Potential
V_peak [mV]  Spike detection threshold
E_exc [mV]  synaptic parameters
 Excitatory reversal Potential
tau_syn_exc [ms]  Synaptic Time Constant Excitatory Synapse
E_inh [mV]  Inhibitory reversal Potential
tau_syn_inh [ms]  Synaptic Time Constant for Inhibitory Synapse
I_e [pA]  constant external input current


  Dynamic state variables:
V_m [mV]  Membrane potential
w [pA]  Spike-adaptation current
refr_t [ms]  Refractory period timer


  Sends: nest::SpikeEvent

  Receives: Spike, Current, DataLoggingRequest
*/
class aeif_cond_alpha_neuron_Nestml_Plastic_Optimized : public nest::ArchivingNode
{
public:
  /**
   * The constructor is only used to create the model prototype in the model manager.
  **/
  aeif_cond_alpha_neuron_Nestml_Plastic_Optimized();

  /**
   * The copy constructor is used to create model copies and instances of the model.
   * @node The copy constructor needs to initialize the parameters and the state.
   *       Initialization of buffers and interal variables is deferred to
   *       @c init_buffers_() and @c pre_run_hook() (or calibrate() in NEST 3.3 and older).
  **/
  aeif_cond_alpha_neuron_Nestml_Plastic_Optimized(const aeif_cond_alpha_neuron_Nestml_Plastic_Optimized &);

  /**
   * Destructor.
  **/
  ~aeif_cond_alpha_neuron_Nestml_Plastic_Optimized() override;

  // -------------------------------------------------------------------------
  //   Import sets of overloaded virtual functions.
  //   See: Technical Issues / Virtual Functions: Overriding, Overloading,
  //        and Hiding
  // -------------------------------------------------------------------------

  using nest::Node::handles_test_event;
  using nest::Node::handle;

  /**
   * Used to validate that we can send nest::SpikeEvent to desired target:port.
  **/
  nest_port_t send_test_event(nest::Node& target, nest_rport_t receptor_type, nest::synindex, bool) override;


  // -------------------------------------------------------------------------
  //   Functions handling incoming events.
  //   We tell nest that we can handle incoming events of various types by
  //   defining handle() for the given event.
  // -------------------------------------------------------------------------


  void handle(nest::SpikeEvent &) override;        //! accept spikes
  void handle(nest::CurrentEvent &) override;      //! accept input current

  void handle(nest::DataLoggingRequest &) override;//! allow recording with multimeter
  nest_port_t handles_test_event(nest::SpikeEvent&, nest_port_t) override;
  nest_port_t handles_test_event(nest::CurrentEvent&, nest_port_t) override;
  nest_port_t handles_test_event(nest::DataLoggingRequest&, nest_port_t) override;

  // -------------------------------------------------------------------------
  //   Functions for getting/setting parameters and state values.
  // -------------------------------------------------------------------------

  void get_status(DictionaryDatum &) const override;
  void set_status(const DictionaryDatum &) override;


  // -------------------------------------------------------------------------
  //   Getters/setters for state block
  // -------------------------------------------------------------------------

  inline double get_V_m() const
  {
    return S_.ode_state[State_::V_m];
  }

  inline void set_V_m(const double __v)
  {
    S_.ode_state[State_::V_m] = __v;
  }

  inline double get_w() const
  {
    return S_.ode_state[State_::w];
  }

  inline void set_w(const double __v)
  {
    S_.ode_state[State_::w] = __v;
  }

  inline double get_refr_t() const
  {
    return S_.refr_t;
  }

  inline void set_refr_t(const double __v)
  {
    S_.refr_t = __v;
  }

  inline bool get_is_refractory() const
  {
    return S_.is_refractory;
  }

  inline void set_is_refractory(const bool __v)
  {
    S_.is_refractory = __v;
  }

  inline double get_g_exc__X__exc_spikes() const
  {
    return S_.ode_state[State_::g_exc__X__exc_spikes];
  }

  inline void set_g_exc__X__exc_spikes(const double __v)
  {
    S_.ode_state[State_::g_exc__X__exc_spikes] = __v;
  }

  inline double get_g_exc__X__exc_spikes__d() const
  {
    return S_.ode_state[State_::g_exc__X__exc_spikes__d];
  }

  inline void set_g_exc__X__exc_spikes__d(const double __v)
  {
    S_.ode_state[State_::g_exc__X__exc_spikes__d] = __v;
  }

  inline double get_g_inh__X__inh_spikes() const
  {
    return S_.ode_state[State_::g_inh__X__inh_spikes];
  }

  inline void set_g_inh__X__inh_spikes(const double __v)
  {
    S_.ode_state[State_::g_inh__X__inh_spikes] = __v;
  }

  inline double get_g_inh__X__inh_spikes__d() const
  {
    return S_.ode_state[State_::g_inh__X__inh_spikes__d];
  }

  inline void set_g_inh__X__inh_spikes__d(const double __v)
  {
    S_.ode_state[State_::g_inh__X__inh_spikes__d] = __v;
  }


  // -------------------------------------------------------------------------
  //   Getters/setters for parameters
  // -------------------------------------------------------------------------

  inline double get_C_m() const
  {
    return P_.C_m;
  }

  inline void set_C_m(const double __v)
  {
    P_.C_m = __v;
  }

  inline double get_refr_T() const
  {
    return P_.refr_T;
  }

  inline void set_refr_T(const double __v)
  {
    P_.refr_T = __v;
  }

  inline double get_V_reset() const
  {
    return P_.V_reset;
  }

  inline void set_V_reset(const double __v)
  {
    P_.V_reset = __v;
  }

  inline double get_g_L() const
  {
    return P_.g_L;
  }

  inline void set_g_L(const double __v)
  {
    P_.g_L = __v;
  }

  inline double get_E_L() const
  {
    return P_.E_L;
  }

  inline void set_E_L(const double __v)
  {
    P_.E_L = __v;
  }

  inline double get_a() const
  {
    return P_.a;
  }

  inline void set_a(const double __v)
  {
    P_.a = __v;
  }

  inline double get_b() const
  {
    return P_.b;
  }

  inline void set_b(const double __v)
  {
    P_.b = __v;
  }

  inline double get_Delta_T() const
  {
    return P_.Delta_T;
  }

  inline void set_Delta_T(const double __v)
  {
    P_.Delta_T = __v;
  }

  inline double get_tau_w() const
  {
    return P_.tau_w;
  }

  inline void set_tau_w(const double __v)
  {
    P_.tau_w = __v;
  }

  inline double get_V_th() const
  {
    return P_.V_th;
  }

  inline void set_V_th(const double __v)
  {
    P_.V_th = __v;
  }

  inline double get_V_peak() const
  {
    return P_.V_peak;
  }

  inline void set_V_peak(const double __v)
  {
    P_.V_peak = __v;
  }

  inline double get_E_exc() const
  {
    return P_.E_exc;
  }

  inline void set_E_exc(const double __v)
  {
    P_.E_exc = __v;
  }

  inline double get_tau_syn_exc() const
  {
    return P_.tau_syn_exc;
  }

  inline void set_tau_syn_exc(const double __v)
  {
    P_.tau_syn_exc = __v;
  }

  inline double get_E_inh() const
  {
    return P_.E_inh;
  }

  inline void set_E_inh(const double __v)
  {
    P_.E_inh = __v;
  }

  inline double get_tau_syn_inh() const
  {
    return P_.tau_syn_inh;
  }

  inline void set_tau_syn_inh(const double __v)
  {
    P_.tau_syn_inh = __v;
  }

  inline double get_I_e() const
  {
    return P_.I_e;
  }

  inline void set_I_e(const double __v)
  {
    P_.I_e = __v;
  }


  // -------------------------------------------------------------------------
  //   Getters/setters for internals
  // -------------------------------------------------------------------------

  inline double get_PSConInit_E() const
  {
    return V_.PSConInit_E;
  }

  inline void set_PSConInit_E(const double __v)
  {
    V_.PSConInit_E = __v;
  }
  inline double get___h() const
  {
    return V_.__h;
  }

  inline void set___h(const double __v)
  {
    V_.__h = __v;
  }
  inline double get_PSConInit_I() const
  {
    return V_.PSConInit_I;
  }

  inline void set_PSConInit_I(const double __v)
  {
    V_.PSConInit_I = __v;
  }
  inline double get___P__g_exc__X__exc_spikes__g_exc__X__exc_spikes() const
  {
    return V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes;
  }

  inline void set___P__g_exc__X__exc_spikes__g_exc__X__exc_spikes(const double __v)
  {
    V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes = __v;
  }
  inline double get___P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d() const
  {
    return V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d;
  }

  inline void set___P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d(const double __v)
  {
    V_.__P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d = __v;
  }
  inline double get___P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes() const
  {
    return V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes;
  }

  inline void set___P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes(const double __v)
  {
    V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes = __v;
  }
  inline double get___P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d() const
  {
    return V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d;
  }

  inline void set___P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d(const double __v)
  {
    V_.__P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d = __v;
  }
  inline double get___P__g_inh__X__inh_spikes__g_inh__X__inh_spikes() const
  {
    return V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes;
  }

  inline void set___P__g_inh__X__inh_spikes__g_inh__X__inh_spikes(const double __v)
  {
    V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes = __v;
  }
  inline double get___P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d() const
  {
    return V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d;
  }

  inline void set___P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d(const double __v)
  {
    V_.__P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d = __v;
  }
  inline double get___P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes() const
  {
    return V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes;
  }

  inline void set___P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes(const double __v)
  {
    V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes = __v;
  }
  inline double get___P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d() const
  {
    return V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d;
  }

  inline void set___P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d(const double __v)
  {
    V_.__P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d = __v;
  }


  // -------------------------------------------------------------------------
  //   Methods corresponding to event handlers
  // -------------------------------------------------------------------------

  

  // -------------------------------------------------------------------------
  //   Initialization functions
  // -------------------------------------------------------------------------
  void calibrate_time( const nest::TimeConverter& tc ) override;

protected:

private:
  nest::Stopwatch sw_update;

  void recompute_internal_variables(bool exclude_timestep=false);

private:

  static const nest_port_t MIN_SPIKE_RECEPTOR = 0;
  static const nest_port_t PORT_NOT_AVAILABLE = -1;

  enum SynapseTypes
  {
    EXC_SPIKES = 0,
    INH_SPIKES = 1,
    MAX_SPIKE_RECEPTOR = 2
  };

  static const size_t NUM_SPIKE_RECEPTORS = MAX_SPIKE_RECEPTOR - MIN_SPIKE_RECEPTOR;

static std::vector< std::tuple< int, int > > rport_to_nestml_buffer_idx;

  /**
   * Reset state of neuron.
  **/

  void init_state_internal_();

  /**
   * Reset internal buffers of neuron.
  **/
  void init_buffers_() override;

  /**
   * Initialize auxiliary quantities, leave parameters and state untouched.
  **/
  void pre_run_hook() override;

  /**
   * Take neuron through given time interval
  **/
  void update(nest::Time const &, const long, const long) override;

  // The next two classes need to be friends to access the State_ class/member
  friend class nest::RecordablesMap<aeif_cond_alpha_neuron_Nestml_Plastic_Optimized>;
  friend class nest::UniversalDataLogger<aeif_cond_alpha_neuron_Nestml_Plastic_Optimized>;

  /**
   * Free parameters of the neuron.
   *


   *
   * These are the parameters that can be set by the user through @c `node.set()`.
   * They are initialized from the model prototype when the node is created.
   * Parameters do not change during calls to @c update() and are not reset by
   * @c ResetNetwork.
   *
   * @note Parameters_ need neither copy constructor nor @c operator=(), since
   *       all its members are copied properly by the default copy constructor
   *       and assignment operator. Important:
   *       - If Parameters_ contained @c Time members, you need to define the
   *         assignment operator to recalibrate all members of type @c Time . You
   *         may also want to define the assignment operator.
   *       - If Parameters_ contained members that cannot copy themselves, such
   *         as C-style arrays, you need to define the copy constructor and
   *         assignment operator to copy those members.
  **/
  struct Parameters_
  {    
    //!  membrane parameters
    //!  Membrane Capacitance
    double C_m;
    //!  Duration of refractory period
    double refr_T;
    //!  Reset Potential
    double V_reset;
    //!  Leak Conductance
    double g_L;
    //!  Leak reversal Potential (aka resting potential)
    double E_L;
    //!  spike adaptation parameters
    //!  Subthreshold adaptation
    double a;
    //!  Spike-triggered adaptation
    double b;
    //!  Slope factor
    double Delta_T;
    //!  Adaptation time constant
    double tau_w;
    //!  Threshold Potential
    double V_th;
    //!  Spike detection threshold
    double V_peak;
    //!  synaptic parameters
    //!  Excitatory reversal Potential
    double E_exc;
    //!  Synaptic Time Constant Excitatory Synapse
    double tau_syn_exc;
    //!  Inhibitory reversal Potential
    double E_inh;
    //!  Synaptic Time Constant for Inhibitory Synapse
    double tau_syn_inh;
    //!  constant external input current
    double I_e;

    double __gsl_error_tol;

    /**
     * Initialize parameters to their default values.
    **/
    Parameters_();
  };

  /**
   * Dynamic state of the neuron.
   *
   *
   *
   * These are the state variables that are advanced in time by calls to
   * @c update(). In many models, some or all of them can be set by the user
   * through @c `node.set()`. The state variables are initialized from the model
   * prototype when the node is created. State variables are reset by @c ResetNetwork.
   *
   * @note State_ need neither copy constructor nor @c operator=(), since
   *       all its members are copied properly by the default copy constructor
   *       and assignment operator. Important:
   *       - If State_ contained @c Time members, you need to define the
   *         assignment operator to recalibrate all members of type @c Time . You
   *         may also want to define the assignment operator.
   *       - If State_ contained members that cannot copy themselves, such
   *         as C-style arrays, you need to define the copy constructor and
   *         assignment operator to copy those members.
  **/
  struct State_
  {

    // non-ODE state variables
//!  Refractory period timer
double refr_t;
bool is_refractory;
    //! Symbolic indices to the elements of the state vector y
    enum StateVecElems
    {
      V_m,
      w,
      g_exc__X__exc_spikes,
      g_exc__X__exc_spikes__d,
      g_inh__X__inh_spikes,
      g_inh__X__inh_spikes__d,
      // moved state variables from synapse (numeric)
      // moved state variables from synapse (analytic)
      // final entry to easily get the vector size
      STATE_VEC_SIZE
    };

    //! state vector, must be C-array for GSL solver
    double ode_state[STATE_VEC_SIZE];

    State_();
  };

  struct DelayedVariables_
  {
  };

  /**
   * Internal variables of the neuron.
   *
   *
   *
   * These variables must be initialized by @c pre_run_hook (or calibrate in NEST 3.3 and older), which is called before
   * the first call to @c update() upon each call to @c Simulate.
   * @node Variables_ needs neither constructor, copy constructor or assignment operator,
   *       since it is initialized by @c pre_run_hook() (or calibrate() in NEST 3.3 and older). If Variables_ has members that
   *       cannot destroy themselves, Variables_ will need a destructor.
  **/
  struct Variables_
  {
    //!  Impulse to add to DG_EXC on spike arrival to evoke unit-amplitude conductance excursion
    double PSConInit_E;
    double __h;
    //!  Impulse to add to DG_INH on spike arrival to evoke unit-amplitude conductance excursion
    double PSConInit_I;
    double __P__g_exc__X__exc_spikes__g_exc__X__exc_spikes;
    double __P__g_exc__X__exc_spikes__g_exc__X__exc_spikes__d;
    double __P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes;
    double __P__g_exc__X__exc_spikes__d__g_exc__X__exc_spikes__d;
    double __P__g_inh__X__inh_spikes__g_inh__X__inh_spikes;
    double __P__g_inh__X__inh_spikes__g_inh__X__inh_spikes__d;
    double __P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes;
    double __P__g_inh__X__inh_spikes__d__g_inh__X__inh_spikes__d;
  };

  /**
   * Buffers of the neuron.
   * Usually buffers for incoming spikes and data logged for analog recorders.
   * Buffers must be initialized by @c init_buffers_(), which is called before
   * @c pre_run_hook() (or calibrate() in NEST 3.3 and older) on the first call to @c Simulate after the start of NEST,
   * ResetKernel or ResetNetwork.
   * @node Buffers_ needs neither constructor, copy constructor or assignment operator,
   *       since it is initialized by @c init_nodes_(). If Buffers_ has members that
   *       cannot destroy themselves, Buffers_ will need a destructor.
  **/
  struct Buffers_
  {
    Buffers_(aeif_cond_alpha_neuron_Nestml_Plastic_Optimized &);
    Buffers_(const Buffers_ &, aeif_cond_alpha_neuron_Nestml_Plastic_Optimized &);

    /**
     * Logger for all analog data
    **/
    nest::UniversalDataLogger<aeif_cond_alpha_neuron_Nestml_Plastic_Optimized> logger_;

    // -----------------------------------------------------------------------
    //   Spike buffers and sums of incoming spikes/currents per timestep
    // -----------------------------------------------------------------------    



    /**
     * Buffer containing the incoming spikes
    **/
    inline std::vector< nest::RingBuffer >& get_spike_inputs_()
    {
        return spike_inputs_;
    }
    std::vector< nest::RingBuffer > spike_inputs_;

    /**
     * Buffer containing the sum of all the incoming spikes
    **/
    inline std::vector< double >& get_spike_inputs_grid_sum_()
    {
        return spike_inputs_grid_sum_;
    }
    std::vector< double > spike_inputs_grid_sum_;

    /**
     * Buffer containing a flag whether incoming spikes have been received on a given port
    **/
    inline std::vector< nest::RingBuffer >& get_spike_input_received_()
    {
        return spike_input_received_;
    }
    std::vector< nest::RingBuffer > spike_input_received_;

    /**
     * Buffer containing a flag whether incoming spikes have been received on a given port
    **/
    inline std::vector< double >& get_spike_input_received_grid_sum_()
    {
        return spike_input_received_grid_sum_;
    }
    std::vector< double > spike_input_received_grid_sum_;

    // -----------------------------------------------------------------------
    //   Continuous-input buffers
    // -----------------------------------------------------------------------

    

    nest::RingBuffer
     I_stim;   //!< Buffer for input (type: pA)

    inline nest::RingBuffer& get_I_stim() {
        return I_stim;
    }

    double I_stim_grid_sum_;

    // -----------------------------------------------------------------------
    //   GSL ODE solver data structures
    // -----------------------------------------------------------------------

    gsl_odeiv_step* __s;    //!< stepping function
    gsl_odeiv_control* __c; //!< adaptive stepsize control function
    gsl_odeiv_evolve* __e;  //!< evolution function
    gsl_odeiv_system __sys; //!< struct describing system

    // __integration_step should be reset with the neuron on ResetNetwork,
    // but remain unchanged during calibration. Since it is initialized with
    // step_, and the resolution cannot change after nodes have been created,
    // it is safe to place both here.
    double __step;             //!< step size in ms
    double __integration_step; //!< current integration time step, updated by GSL
  };

  // -------------------------------------------------------------------------
  //   Getters/setters for inline expressions
  // -------------------------------------------------------------------------
  inline double get_V_bounded() const
  {
    return std::min(S_.ode_state[State_::V_m], P_.V_peak);
  }

  inline double get_exp_arg() const
  {
    return ((std::min(S_.ode_state[State_::V_m], P_.V_peak)) - P_.V_th) / P_.Delta_T;
  }

  inline double get_I_spike() const
  {
    return P_.g_L * P_.Delta_T * std::exp((((std::min(S_.ode_state[State_::V_m], P_.V_peak)) - P_.V_th) / P_.Delta_T));
  }

  inline double get_I_syn_exc() const
  {
    return S_.ode_state[State_::g_exc__X__exc_spikes] * 1.0 * ((std::min(S_.ode_state[State_::V_m], P_.V_peak)) - P_.E_exc);
  }

  inline double get_I_syn_inh() const
  {
    return S_.ode_state[State_::g_inh__X__inh_spikes] * 1.0 * ((std::min(S_.ode_state[State_::V_m], P_.V_peak)) - P_.E_inh);
  }



  // -------------------------------------------------------------------------
  //   Getters/setters for input buffers
  // -------------------------------------------------------------------------  




  /**
   * Buffer containing the incoming spikes
  **/
  inline std::vector< nest::RingBuffer >& get_spike_inputs_()
  {
      return B_.get_spike_inputs_();
  }

  /**
   * Buffer containing the sum of all the incoming spikes
  **/
  inline std::vector< double >& get_spike_inputs_grid_sum_()
  {
      return B_.get_spike_inputs_grid_sum_();
  }

  /**
   * Buffer containing a flag whether incoming spikes have been received on a given port
  **/
  inline std::vector< nest::RingBuffer >& get_spike_input_received_()
  {
      return B_.get_spike_input_received_();
  }

  /**
   * Buffer containing a flag whether incoming spikes have been received on a given port
  **/
  inline std::vector< double >& get_spike_input_received_grid_sum_()
  {
      return B_.get_spike_input_received_grid_sum_();
  }

inline nest::RingBuffer& get_I_stim() {
    return B_.get_I_stim();
}

  // -------------------------------------------------------------------------
  //   Member variables of neuron model.
  //   Each model neuron should have precisely the following four data members,
  //   which are one instance each of the parameters, state, buffers and variables
  //   structures. Experience indicates that the state and variables member should
  //   be next to each other to achieve good efficiency (caching).
  //   Note: Devices require one additional data member, an instance of the
  //   ``Device`` child class they belong to.
  // -------------------------------------------------------------------------


  Parameters_       P_;        //!< Free parameters.
  State_            S_;        //!< Dynamic state.
  DelayedVariables_ DV_;       //!< Delayed state variables.
  Variables_        V_;        //!< Internal Variables
  Buffers_          B_;        //!< Buffers.

  //! Mapping of recordables names to access functions
  static nest::RecordablesMap<aeif_cond_alpha_neuron_Nestml_Plastic_Optimized> recordablesMap_;
  friend int aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_dynamics( double, const double ode_state[], double f[], void* pnode );
  friend int aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_dynamics( double, const double ode_state[], double f[], void* pnode );

}; /* neuron aeif_cond_alpha_neuron_Nestml_Plastic_Optimized */

inline nest_port_t aeif_cond_alpha_neuron_Nestml_Plastic_Optimized::send_test_event(nest::Node& target, nest_rport_t receptor_type, nest::synindex, bool)
{
  // You should usually not change the code in this function.
  // It confirms that the target of connection @c c accepts @c nest::SpikeEvent on
  // the given @c receptor_type.
  nest::SpikeEvent e;
  e.set_sender(*this);
  return target.handles_test_event(e, receptor_type);
}

inline nest_port_t aeif_cond_alpha_neuron_Nestml_Plastic_Optimized::handles_test_event(nest::SpikeEvent&, nest_port_t receptor_type)
{
    // You should usually not change the code in this function.
    // It confirms to the connection management system that we are able
    // to handle @c SpikeEvent on port 0. You need to extend the function
    // if you want to differentiate between input ports.
    if (receptor_type != 0)
    {
      throw nest::UnknownReceptorType(receptor_type, get_name());
    }
    return 0;
}

inline nest_port_t aeif_cond_alpha_neuron_Nestml_Plastic_Optimized::handles_test_event(nest::CurrentEvent&, nest_port_t receptor_type)
{
  // You should usually not change the code in this function.
  // It confirms to the connection management system that we are able
  // to handle @c CurrentEvent on port 0. You need to extend the function
  // if you want to differentiate between input ports.
  if (receptor_type != 0)
  {
    throw nest::UnknownReceptorType(receptor_type, get_name());
  }
  return 0;
}

inline nest_port_t aeif_cond_alpha_neuron_Nestml_Plastic_Optimized::handles_test_event(nest::DataLoggingRequest& dlr, nest_port_t receptor_type)
{
  // You should usually not change the code in this function.
  // It confirms to the connection management system that we are able
  // to handle @c DataLoggingRequest on port 0.
  // The function also tells the built-in UniversalDataLogger that this node
  // is recorded from and that it thus needs to collect data during simulation.
  if (receptor_type != 0)
  {
    throw nest::UnknownReceptorType(receptor_type, get_name());
  }

  return B_.logger_.connect_logging_device(dlr, recordablesMap_);
}

inline void aeif_cond_alpha_neuron_Nestml_Plastic_Optimized::get_status(DictionaryDatum &__d) const
{


  def< double >( __d, nest::names::update_stopwatch, sw_update.elapsed() );

  // parameters
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_C_m, get_C_m());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_refr_T, get_refr_T());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_reset, get_V_reset());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_L, get_g_L());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_E_L, get_E_L());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_a, get_a());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_b, get_b());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_Delta_T, get_Delta_T());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_tau_w, get_tau_w());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_th, get_V_th());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_peak, get_V_peak());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_E_exc, get_E_exc());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_tau_syn_exc, get_tau_syn_exc());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_E_inh, get_E_inh());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_tau_syn_inh, get_tau_syn_inh());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_I_e, get_I_e());

  // initial values for state variables in ODE or kernel
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_m, get_V_m());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_w, get_w());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_refr_t, get_refr_t());
  def<bool>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_is_refractory, get_is_refractory());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_exc__X__exc_spikes, get_g_exc__X__exc_spikes());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_exc__X__exc_spikes__d, get_g_exc__X__exc_spikes__d());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_inh__X__inh_spikes, get_g_inh__X__inh_spikes());
  def<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_inh__X__inh_spikes__d, get_g_inh__X__inh_spikes__d());

  ArchivingNode::get_status( __d );

  (*__d)[nest::names::recordables] = recordablesMap_.get_list();
  def< double >(__d, nest::names::gsl_error_tol, P_.__gsl_error_tol);
  if ( P_.__gsl_error_tol <= 0. ){
    throw nest::BadProperty( "The gsl_error_tol must be strictly positive." );
  }
}

inline void aeif_cond_alpha_neuron_Nestml_Plastic_Optimized::set_status(const DictionaryDatum &__d)
{
  // parameters
  double tmp_C_m = get_C_m();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_C_m, tmp_C_m, this);
  double tmp_refr_T = get_refr_T();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_refr_T, tmp_refr_T, this);
  double tmp_V_reset = get_V_reset();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_reset, tmp_V_reset, this);
  double tmp_g_L = get_g_L();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_L, tmp_g_L, this);
  double tmp_E_L = get_E_L();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_E_L, tmp_E_L, this);
  double tmp_a = get_a();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_a, tmp_a, this);
  double tmp_b = get_b();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_b, tmp_b, this);
  double tmp_Delta_T = get_Delta_T();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_Delta_T, tmp_Delta_T, this);
  double tmp_tau_w = get_tau_w();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_tau_w, tmp_tau_w, this);
  double tmp_V_th = get_V_th();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_th, tmp_V_th, this);
  double tmp_V_peak = get_V_peak();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_peak, tmp_V_peak, this);
  double tmp_E_exc = get_E_exc();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_E_exc, tmp_E_exc, this);
  double tmp_tau_syn_exc = get_tau_syn_exc();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_tau_syn_exc, tmp_tau_syn_exc, this);
  double tmp_E_inh = get_E_inh();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_E_inh, tmp_E_inh, this);
  double tmp_tau_syn_inh = get_tau_syn_inh();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_tau_syn_inh, tmp_tau_syn_inh, this);
  double tmp_I_e = get_I_e();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_I_e, tmp_I_e, this);

  // initial values for state variables in ODE or kernel
  double tmp_V_m = get_V_m();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_V_m, tmp_V_m, this);
  double tmp_w = get_w();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_w, tmp_w, this);
  double tmp_refr_t = get_refr_t();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_refr_t, tmp_refr_t, this);
  bool tmp_is_refractory = get_is_refractory();
  nest::updateValueParam<bool>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_is_refractory, tmp_is_refractory, this);
  double tmp_g_exc__X__exc_spikes = get_g_exc__X__exc_spikes();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_exc__X__exc_spikes, tmp_g_exc__X__exc_spikes, this);
  double tmp_g_exc__X__exc_spikes__d = get_g_exc__X__exc_spikes__d();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_exc__X__exc_spikes__d, tmp_g_exc__X__exc_spikes__d, this);
  double tmp_g_inh__X__inh_spikes = get_g_inh__X__inh_spikes();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_inh__X__inh_spikes, tmp_g_inh__X__inh_spikes, this);
  double tmp_g_inh__X__inh_spikes__d = get_g_inh__X__inh_spikes__d();
  nest::updateValueParam<double>(__d, nest::aeif_cond_alpha_neuron_Nestml_Plastic_Optimized_names::_g_inh__X__inh_spikes__d, tmp_g_inh__X__inh_spikes__d, this);

  // We now know that (ptmp, stmp) are consistent. We do not
  // write them back to (P_, S_) before we are also sure that
  // the properties to be set in the parent class are internally
  // consistent.
  ArchivingNode::set_status(__d);

  // if we get here, temporaries contain consistent set of properties
  set_C_m(tmp_C_m);
  set_refr_T(tmp_refr_T);
  set_V_reset(tmp_V_reset);
  set_g_L(tmp_g_L);
  set_E_L(tmp_E_L);
  set_a(tmp_a);
  set_b(tmp_b);
  set_Delta_T(tmp_Delta_T);
  set_tau_w(tmp_tau_w);
  set_V_th(tmp_V_th);
  set_V_peak(tmp_V_peak);
  set_E_exc(tmp_E_exc);
  set_tau_syn_exc(tmp_tau_syn_exc);
  set_E_inh(tmp_E_inh);
  set_tau_syn_inh(tmp_tau_syn_inh);
  set_I_e(tmp_I_e);
  set_V_m(tmp_V_m);
  set_w(tmp_w);
  set_refr_t(tmp_refr_t);
  set_is_refractory(tmp_is_refractory);
  set_g_exc__X__exc_spikes(tmp_g_exc__X__exc_spikes);
  set_g_exc__X__exc_spikes__d(tmp_g_exc__X__exc_spikes__d);
  set_g_inh__X__inh_spikes(tmp_g_inh__X__inh_spikes);
  set_g_inh__X__inh_spikes__d(tmp_g_inh__X__inh_spikes__d);




  updateValue< double >(__d, nest::names::gsl_error_tol, P_.__gsl_error_tol);
  if ( P_.__gsl_error_tol <= 0. )
  {
    throw nest::BadProperty( "The gsl_error_tol must be strictly positive." );
  }

  // recompute internal variables in case they are dependent on parameters or state that might have been updated in this call to set_status()
  recompute_internal_variables();
};



#endif /* #ifndef AEIF_COND_ALPHA_NEURON_NESTML_PLASTIC_OPTIMIZED */
