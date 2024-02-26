/**
 *  stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic.h
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
 *  Generated from NESTML at time: 2024-02-26 14:19:03.923133
**/

#ifndef STDP_SYNAPSE_NESTML_PLASTIC__WITH_IAF_PSC_ALPHA_NEURON_NESTML_PLASTIC_H
#define STDP_SYNAPSE_NESTML_PLASTIC__WITH_IAF_PSC_ALPHA_NEURON_NESTML_PLASTIC_H

// C++ includes:
#include <cmath>

// Includes from nestkernel:
#include "common_synapse_properties.h"
#include "connection.h"
#include "connector_model.h"
#include "event.h"


// Includes from sli:
#include "dictdatum.h"
#include "dictutils.h"

/** @BeginDocumentation
"""
stdp - Synapse model for spike-timing dependent plasticity########################################################

Description
+++++++++++

stdp_synapse is a synapse with spike-timing dependent plasticity (as defined in [1]_). Here the weight dependence exponent can be set separately for potentiation and depression. Examples:

=================== ==== =============================
Multiplicative STDP [2]_ mu_plus = mu_minus = 1
Additive STDP       [3]_ mu_plus = mu_minus = 0
Guetig STDP         [1]_ mu_plus, mu_minus in [0, 1]
Van Rossum STDP     [4]_ mu_plus = 0 mu_minus = 1
=================== ==== =============================


References
++++++++++

.. [1] Guetig et al. (2003) Learning Input Correlations through Nonlinear
       Temporally Asymmetric Hebbian Plasticity. Journal of Neuroscience

.. [2] Rubin, J., Lee, D. and Sompolinsky, H. (2001). Equilibrium
       properties of temporally asymmetric Hebbian plasticity, PRL
       86,364-367

.. [3] Song, S., Miller, K. D. and Abbott, L. F. (2000). Competitive
       Hebbian learning through spike-timing-dependent synaptic
       plasticity,Nature Neuroscience 3:9,919--926

.. [4] van Rossum, M. C. W., Bi, G-Q and Turrigiano, G. G. (2000).
       Stable Hebbian learning from spike timing-dependent
       plasticity, Journal of Neuroscience, 20:23,8812--8821
"""

**/

//#define DEBUG

namespace nest
{

namespace stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names
{
    const Name _w( "w" );
    const Name _pre_trace( "pre_trace" );
    const Name _d( "d" );
    const Name _lambda( "lambda" );
    const Name _tau_tr_pre( "tau_tr_pre" );
    const Name _tau_tr_post( "tau_tr_post" );
    const Name _alpha( "alpha" );
    const Name _mu_plus( "mu_plus" );
    const Name _mu_minus( "mu_minus" );
    const Name _Wmax( "Wmax" );
    const Name _Wmin( "Wmin" );
}

class stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_PlasticCommonSynapseProperties : public CommonSynapseProperties {
public:

    stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_PlasticCommonSynapseProperties()
    : CommonSynapseProperties()
    {
    }

    /**
     * Get all properties and put them into a dictionary.
     */
    void get_status( DictionaryDatum& d ) const
    {
        CommonSynapseProperties::get_status( d );
    }


    /**
     * Set properties from the values given in dictionary.
     */
    void set_status( const DictionaryDatum& d, ConnectorModel& cm )
    {
      CommonSynapseProperties::set_status( d, cm );
    }

    // N.B.: we define all parameters as public for easy reference conversion later on.
    // This may or may not benefit performance (TODO: compare with inline getters/setters)
};


template < typename targetidentifierT >
class stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic : public Connection< targetidentifierT >
{
  typedef iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic post_neuron_t;


private:
  double t_lastspike_;

  /**
   * Dynamic state of the synapse.
   *
   * These are the state variables that are advanced in time by calls to
   * send(). In many models, some or all of them can be set by the user
   * through ``SetStatus()``.
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
    //!  Synaptic weight
    double w;
    double pre_trace;


  /**
   * Free parameters of the synapse.
   *


   *
   * These are the parameters that can be set by the user through @c SetStatus.
   * Parameters do not change during calls to ``send()`` and are not reset by
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
  */
    //!  Synaptic transmission delay
    double d;
    double lambda;
    double tau_tr_pre;
    double tau_tr_post;
    double alpha;
    double mu_plus;
    double mu_minus;
    double Wmax;
    double Wmin;



  /**
   * Internal variables of the synapse.
   *
   *
   * These variables must be initialized by recompute_internal_variables().
  **/
    double __h;    
    double __P__pre_trace__pre_trace;

  // -------------------------------------------------------------------------
  //   Getters/setters for state block
  // -------------------------------------------------------------------------

  inline double get_w() const
  {
    return w;
  }

  inline void set_w(const double __v)
  {
    w = __v;
  }

  inline double get_pre_trace() const
  {
    return pre_trace;
  }

  inline void set_pre_trace(const double __v)
  {
    pre_trace = __v;
  }


  // -------------------------------------------------------------------------
  //   Getters/setters for parameters
  // -------------------------------------------------------------------------

  inline double get_d() const
  {
    return d;
  }

  inline void set_d(const double __v)
  {
    d = __v;
  }inline double get_lambda() const
  {
    return lambda;
  }

  inline void set_lambda(const double __v)
  {
    lambda = __v;
  }inline double get_tau_tr_pre() const
  {
    return tau_tr_pre;
  }

  inline void set_tau_tr_pre(const double __v)
  {
    tau_tr_pre = __v;
  }inline double get_tau_tr_post() const
  {
    return tau_tr_post;
  }

  inline void set_tau_tr_post(const double __v)
  {
    tau_tr_post = __v;
  }inline double get_alpha() const
  {
    return alpha;
  }

  inline void set_alpha(const double __v)
  {
    alpha = __v;
  }inline double get_mu_plus() const
  {
    return mu_plus;
  }

  inline void set_mu_plus(const double __v)
  {
    mu_plus = __v;
  }inline double get_mu_minus() const
  {
    return mu_minus;
  }

  inline void set_mu_minus(const double __v)
  {
    mu_minus = __v;
  }inline double get_Wmax() const
  {
    return Wmax;
  }

  inline void set_Wmax(const double __v)
  {
    Wmax = __v;
  }inline double get_Wmin() const
  {
    return Wmin;
  }

  inline void set_Wmin(const double __v)
  {
    Wmin = __v;
  }

  // -------------------------------------------------------------------------
  //   Getters/setters for inline expressions
  // -------------------------------------------------------------------------

  

  // -------------------------------------------------------------------------
  //   Function declarations
  // -------------------------------------------------------------------------



  /**
   * Update internal state (``S_``) of the synapse according to the dynamical equations defined in the model and the statements in the ``update`` block.
  **/
  inline void
  update_internal_state_(double t_start, double timestep, const stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_PlasticCommonSynapseProperties& cp);

  void recompute_internal_variables();

public:
  // this line determines which common properties to use
  typedef stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_PlasticCommonSynapseProperties CommonPropertiesType;

  typedef Connection< targetidentifierT > ConnectionBase;
  static constexpr ConnectionModelProperties properties = ConnectionModelProperties::HAS_DELAY
    | ConnectionModelProperties::IS_PRIMARY | ConnectionModelProperties::SUPPORTS_HPC
    | ConnectionModelProperties::SUPPORTS_LBL;

  /**
  * Default constructor.
  *
  * Sets default values for all parameters (skipping common properties).
  *
  * Needed by GenericConnectorModel.
  */
  stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic();

  /**
  * Copy constructor from a property object.
  *
  * Sets default values for all parameters (skipping common properties).
  *
  * Needs to be defined properly in order for GenericConnector to work.
  */
  stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic( const stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic& rhs );

  // Explicitly declare all methods inherited from the dependent base
  // ConnectionBase. This avoids explicit name prefixes in all places these
  // functions are used. Since ConnectionBase depends on the template parameter,
  // they are not automatically found in the base class.
  using ConnectionBase::get_delay_steps;
  using ConnectionBase::set_delay_steps;
  using ConnectionBase::get_delay;
  using ConnectionBase::set_delay;
  using ConnectionBase::get_rport;
  using ConnectionBase::get_target;


  class ConnTestDummyNode : public ConnTestDummyNodeBase
  {
  public:
    // Ensure proper overriding of overloaded virtual functions.
    // Return values from functions are ignored.
    using ConnTestDummyNodeBase::handles_test_event;
    size_t
    handles_test_event( SpikeEvent&, size_t ) override
    {
      return invalid_port;
    }
    size_t
    handles_test_event( RateEvent&, size_t ) override
    {
      return invalid_port;    }
    size_t
    handles_test_event( DataLoggingRequest&, size_t ) override
    {
      return invalid_port;    }
    size_t
    handles_test_event( CurrentEvent&, size_t ) override
    {
      return invalid_port;    }
    size_t
    handles_test_event( ConductanceEvent&, size_t ) override
    {
      return invalid_port;    }
    size_t
    handles_test_event( DoubleDataEvent&, size_t ) override
    {
      return invalid_port;    }
    size_t
    handles_test_event( DSSpikeEvent&, size_t ) override
    {
      return invalid_port;    }
    size_t
    handles_test_event( DSCurrentEvent&, size_t ) override
    {
      return invalid_port;    }
  };

  /**
   *  special case for weights in NEST: only in case a NESTML state variable was decorated by @nest::weight
  **/
  inline void set_weight(double w)
  {
    // special case for variable marked with @nest::weight decorator
    set_w(w);
    return;

    // no variable was decorated by @nest::weight, so no "weight" defined from the NEST perspective
    assert(0);
  }
  void
  check_connection( Node& s,
    Node& t,
    size_t receptor_type,
    const CommonPropertiesType& cp )
  {
    ConnTestDummyNode dummy_target;
    ConnectionBase::check_connection_( dummy_target, s, t, receptor_type );
    try {
      dynamic_cast<iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic&>(t);
    }
    catch (std::bad_cast &exp) {
      std::cout << "wrong type of neuron connected! Synapse 'stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic' will only work with neuron 'iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic'.\n";
      exit(1);
    }

    t.register_stdp_connection( t_lastspike_ - get_delay(), get_delay() );
  }
  bool
  send( Event& e, const size_t tid, const stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_PlasticCommonSynapseProperties& cp )
  {
    auto get_thread = [tid]()
    {
        return tid;
    };

    const double __t_spike = e.get_stamp().get_ms();

    // use accessor functions (inherited from Connection< >) to obtain delay and target
    iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic* __target = static_cast<iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic*>(get_target(tid));
    assert(__target);
    const double __dendritic_delay = get_delay();

    if (t_lastspike_ < 0.)
    {
        // this is the first presynaptic spike to be processed
        t_lastspike_ = 0.;
    }
    double timestep = 0;
    {
      // get spike history in relevant range (t1, t2] from post-synaptic neuron
      std::deque< histentry__iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic >::iterator start;
      std::deque< histentry__iaf_psc_alpha_neuron_Nestml_Plastic__with_stdp_synapse_Nestml_Plastic >::iterator finish;
      // For a new synapse, t_lastspike_ contains the point in time of the last
      // spike. So we initially read the
      // history(t_last_spike - dendritic_delay, ..., T_spike-dendritic_delay]
      // which increases the access counter for these entries.
      // At registration, all entries' access counters of
      // history[0, ..., t_last_spike - dendritic_delay] have been
      // incremented by Archiving_Node::register_stdp_connection(). See bug #218 for
      // details.
      __target->get_history__( t_lastspike_ - __dendritic_delay,
        __t_spike - __dendritic_delay,
        &start,
        &finish );
      // facilitation due to post-synaptic spikes since last pre-synaptic spike
      while ( start != finish )
      {
        const double minus_dt = t_lastspike_ - ( start->t_ + __dendritic_delay );
        // get_history() should make sure that
        // start->t_ > t_lastspike_ - dendritic_delay, i.e. minus_dt < 0
        assert( minus_dt < -kernel().connection_manager.get_stdp_eps() );

#ifdef DEBUG
        std::cout << "\tprocessing post spike at t = " << start->t_ << std::endl;
#endif

        /**
         * update synapse internal state from `t_lastspike_` to `start->t_`
        **/

        update_internal_state_(t_lastspike_, (start->t_ + __dendritic_delay) - t_lastspike_, cp);

        timestep += (start->t_ + __dendritic_delay) - t_lastspike_;

        const double _tr_t = start->t_;

        /**
         *  NESTML generated onReceive code block for postsynaptic port "post_spikes" begins here!
        **/
        const double w_ = Wmax * (w / Wmax + (lambda * pow((1.0 - (w / Wmax)), mu_plus) * pre_trace));
        w = std::min(Wmax, w_);

        /**
         * internal state has now been fully updated to `start->t_ + __dendritic_delay`
        **/

        t_lastspike_ = start->t_ + __dendritic_delay;
        ++start;
      }
    }

    /**
     * update synapse internal state from `t_lastspike_` to `__t_spike`
    **/

    update_internal_state_(t_lastspike_, __t_spike - t_lastspike_, cp);

    const double _tr_t = __t_spike - __dendritic_delay;

    {
        auto get_t = [__t_spike](){ return __t_spike; };    // do not remove, this is in case the predefined time variable ``t`` is used in the NESTML model        
        /**
         *  NESTML generated onReceive code block for presynaptic port "pre_spikes" begins here!
        **/
          pre_trace += 1;
          const double w_ = Wmax * (w / Wmax - (alpha * lambda * pow((w / Wmax), mu_minus) * ((post_neuron_t*)(__target))->get_post_trace__for_stdp_synapse_Nestml_Plastic(_tr_t)));
          w = std::max(Wmin, w_);

          /**
           * generated code for emit_spike() function
          **/

          set_delay( d );
          const long __delay_steps = nest::Time::delay_ms_to_steps( get_delay() );
          set_delay_steps(__delay_steps);
          e.set_receiver( *__target );
          e.set_weight( w );
          // use accessor functions (inherited from Connection< >) to obtain delay in steps and rport
          e.set_delay_steps( get_delay_steps() );
          e.set_rport( get_rport() );
          e();


    }

    /**
     *  update all convolutions with pre spikes
    **/


    /**
     *  in case pre and post spike time coincide and pre update takes priority
    **/


    /**
     *  synapse internal state has now been fully updated to `__t_spike`
    **/

    t_lastspike_ = __t_spike;
return true;
  }

  void get_status( DictionaryDatum& d ) const;

  void set_status( const DictionaryDatum& d, ConnectorModel& cm );
};
template < typename targetidentifierT >
constexpr ConnectionModelProperties stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::properties;


template < typename targetidentifierT >
void
stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::get_status( DictionaryDatum& __d ) const
{
  ConnectionBase::get_status( __d );
  def< long >( __d, names::size_of, sizeof( *this ) );

  // parameters
  def< double >( __d, names::delay, d );  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_lambda, get_lambda());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_tau_tr_pre, get_tau_tr_pre());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_tau_tr_post, get_tau_tr_post());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_alpha, get_alpha());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_mu_plus, get_mu_plus());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_mu_minus, get_mu_minus());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_Wmax, get_Wmax());  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_Wmin, get_Wmin());

  // initial values for state variables in ODE or kernel  
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_w, get_w());
  // special treatment for variable marked with @nest::name decorator
  def<double>(__d, names::weight, get_w());
  def<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_pre_trace, get_pre_trace());
}

template < typename targetidentifierT >
void
stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::set_status( const DictionaryDatum& __d,
  ConnectorModel& cm )
{
  // parameters  
  double tmp_d = get_d();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_d, tmp_d);  
  double tmp_lambda = get_lambda();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_lambda, tmp_lambda);  
  double tmp_tau_tr_pre = get_tau_tr_pre();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_tau_tr_pre, tmp_tau_tr_pre);  
  double tmp_tau_tr_post = get_tau_tr_post();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_tau_tr_post, tmp_tau_tr_post);  
  double tmp_alpha = get_alpha();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_alpha, tmp_alpha);  
  double tmp_mu_plus = get_mu_plus();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_mu_plus, tmp_mu_plus);  
  double tmp_mu_minus = get_mu_minus();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_mu_minus, tmp_mu_minus);  
  double tmp_Wmax = get_Wmax();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_Wmax, tmp_Wmax);  
  double tmp_Wmin = get_Wmin();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_Wmin, tmp_Wmin);

  // initial values for state variables in ODE or kernel  
  double tmp_w = get_w();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_w, tmp_w);
  // special treatment for variables marked with @nest::name decorator
  tmp_w = get_w();
  updateValue<double>(__d, "weight", tmp_w);
  double tmp_pre_trace = get_pre_trace();
  updateValue<double>(__d, nest::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic_names::_pre_trace, tmp_pre_trace);


  // We now know that (ptmp, stmp) are consistent. We do not
  // write them back to (P_, S_) before we are also sure that
  // the properties to be set in the parent class are internally
  // consistent.
  ConnectionBase::set_status( __d, cm );

  // if we get here, temporaries contain consistent set of properties

  // set parameters  
  set_d(tmp_d);  
  set_lambda(tmp_lambda);  
  set_tau_tr_pre(tmp_tau_tr_pre);  
  set_tau_tr_post(tmp_tau_tr_post);  
  set_alpha(tmp_alpha);  
  set_mu_plus(tmp_mu_plus);  
  set_mu_minus(tmp_mu_minus);  
  set_Wmax(tmp_Wmax);  
  set_Wmin(tmp_Wmin);

  // set state  
  set_w(tmp_w);  
  set_pre_trace(tmp_pre_trace);

  // check invariants



  // special treatment of NEST delay
  set_delay(
get_d());

  // recompute internal variables in case they are dependent on parameters or state that might have been updated in this call to set_status()
  __h = nest::Time::get_resolution().get_ms();
  recompute_internal_variables();
}

/**
 * NESTML internals block symbols initialisation
**/
template < typename targetidentifierT >
inline void stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::recompute_internal_variables()
{


  __P__pre_trace__pre_trace = std::exp((-__h) / tau_tr_pre); // as real
}

/**
 * constructor
**/
template < typename targetidentifierT >
stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic() : ConnectionBase()
{
  const double __resolution = nest::Time::get_resolution().get_ms();  // do not remove, this is necessary for the resolution() function
d = 1; // as ms
lambda = 0.01; // as real
tau_tr_pre = 20; // as ms
tau_tr_post = 20; // as ms
alpha = 1; // as real
mu_plus = 1; // as real
mu_minus = 1; // as real
Wmax = 100.0; // as real
Wmin = 0.0; // as real

  __h = nest::Time::get_resolution().get_ms();
  recompute_internal_variables();

  // initial values for state variables in ODE or kernel
w = 1.0; // as real
pre_trace = 0.0; // as real

  t_lastspike_ = 0.;
}

/**
 * copy constructor
**/
template < typename targetidentifierT >
stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic( const stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >& rhs )
: ConnectionBase( rhs )
{
    d = rhs.d;
    lambda = rhs.lambda;
    tau_tr_pre = rhs.tau_tr_pre;
    tau_tr_post = rhs.tau_tr_post;
    alpha = rhs.alpha;
    mu_plus = rhs.mu_plus;
    mu_minus = rhs.mu_minus;
    Wmax = rhs.Wmax;
    Wmin = rhs.Wmin;

  // state variables in ODE or kernel
    w = rhs.w;
    pre_trace = rhs.pre_trace;

    //weight_ = get_named_parameter<double>(names::weight);
    //set_weight( *rhs.weight_ );
    t_lastspike_ = rhs.t_lastspike_;

    // special treatment of NEST delay
    set_delay(rhs.get_delay());
}

template < typename targetidentifierT >
inline void
stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_Plastic< targetidentifierT >::update_internal_state_(double t_start, double timestep, const stdp_synapse_Nestml_Plastic__with_iaf_psc_alpha_neuron_Nestml_PlasticCommonSynapseProperties& cp)
{
    __h = timestep;
    recompute_internal_variables();

    /**
     * Begin NESTML generated code for the update block
    **/

    // start rendered code for integrate_odes()

    // analytic solver: integrating state variables (first step): pre_trace, 
    const double pre_trace__tmp = __P__pre_trace__pre_trace * pre_trace;
    // analytic solver: integrating state variables (second step): pre_trace, 
    /* replace analytically solvable variables with precisely integrated values  */
    pre_trace = pre_trace__tmp;

    /**
     * End NESTML generated code for the update block
    **/
}

} // namespace

#endif /* #ifndef STDP_SYNAPSE_NESTML_PLASTIC__WITH_IAF_PSC_ALPHA_NEURON_NESTML_PLASTIC_H */
