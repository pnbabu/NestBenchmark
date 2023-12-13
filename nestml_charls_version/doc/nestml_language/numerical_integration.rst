

.. code-block:: nestml

   input:
       spikes <- spike
       I_stim pA <- continuous

   state:
       V_m mV = E_L     # Membrane potential

   equations:
       kernel I_kernel = exp(-t / tau_syn)
       inline I_syn pA = convolve(I_kernel, spikes) * pA
       V_m' = -(V_m - E_L) / tau_m + (I_syn + I_stim) / C_m

   update:
       integrate_odes()

       if V_m >= V_th: # threshold crossing
           V_m = V_reset
           emit_spike()


.. figure:: https://raw.githubusercontent.com/nest/nestml/master/doc/fig/integration_strategies.png
   :alt: Numerical results from a typical simulation run.




















The following text is based on [2]_.

Consider a linear, time-invariant system

.. math::

   \dot{\mathbf{x}} = \mathbf{Ax} + \mathbf{y}


Here, x(t) is the time-dependent state of the system, and y(t) is the time-dependent input to the system. Both x and y are n-dimensional column vectors containing real numbers. By substitution of variables, any higher-order linear dierential equation is written as a first-order system during processing with the NESTML component ODE-toolbox. A fundamental system of solutions to the homoge-
neous (zero-input) equation _y à Ay is given by the col-
umns of the matrix exponential eAt.

The unique solution of the full equation with initial value :math:`x(t_0)` is

.. math::
   :label: eq_b

   x(t) = \exp{\mathbf{A}(t - t_0)}\mathbf{x}(t_0) + \int_{t_0^+}^t \exp{\mathbf{A}(t - \tau)} y(\tau) d\tau

The first part of the sum is the result of passive propagation of the initial state, wheras the second part represents the input-driven response of the system.  Correspondingly, for a system with no input,
the matrix eAt is termed ``time-evolution operator'' or
``propagator''. In contrast, for a system with input but
zero initial conditions, the same matrix is called the
``impulse response'' of the system.

Digital simulation means to compute the response :math:`\mathbf{x}(t)` of the syetem to a prescribed input :math:`\mathbf{y}(t)`  on an evenly sampled grid :math:`t_k = k\cdot h` where :math:`h` is a fixed step size and :math:`k` takes only integer values. The function :math:`x(t)` then corresponds to the sequence :math:`x(t_k)` of its samples on the grid. For a special type of input functions, the simulation can be performed in an exact way, avoiding potentially inaccurate and unstable integration methods. To this end, we consider (generalized) functions xÖtÜ of the form

.. math::

   \mathbf{y}(t) = \sum_k \mathbf{y}(t_k) \delta(t - t_k)

where :math:`\mathbf{y}` is an :math:`n`\ -dimensional vector for each :math:`k`, and :math:`\delta(t)` is the scalar Dirac delta function.

For pulse train inputs which are restricted to the grid,
the temporal evolution of the continuous system (2)
collapses to a discrete matrix equation. Namely, if we let :math:`t_0 = t_k` and :math:`t = t_{k+1}` be two successive points on the grid, the solution to :eq:`eq_b` is

.. math::

   x(t_{k+1}) = \exp{\mathbf{A}h} \mathbf{x}(t_k) + \mathbf{y}(t_{k+1})

which can be interpreted as an iteration


::

         y_1   y_2   y_3
          ↓     ↓     ↓
   x_0 → x_1 → x_2 → x_3


Starting with an initial state :math:`y_0` and assuming non-zero input only at :math:`t_k` for :math:`k = 1,2,3,\ldots`, it propagates the exact solution on the grid, step by step. The diagram depicts the dependency of the current output of the
system on its previous output and the current input. We
refer to the iteration (5) as the method of ``Exact
Integration''. For a time-invariant system, it is based on
the fixed numerical matrix :math:`\exp\{\mathbf{A}h}`, which has to be
computed only once by using appropriate standard
numerical algorithms. During code generation, this step is performed by ODE-toolbox.

Example: exponential decay
~~~~~~~~~~~~~~~~~~~~~~~~~~

For a scalar value :math:`x` and no external input:

.. math::

   \dot{x} = -a\x

with initial condition :math:`x(0) = x_0`, the solution of this initial value problem is given by

.. math::

   x(t) = x_0\exp{-at}

The iteration yields the sequence

.. math::

   x(t_{k+1}) = \exp{-ah} x(t_k)

Consider now the same system with input:

.. math::

   \dot{x} = -a\x + I

As input, we take a pulse train on the grid. The response :math:`x(t)` is then

.. math

   x(t) = \int_0^t \exp{-a(t - \tau)} I d\tau

The result of a discrete iteration according to (5) is
illustrated in Fig. 4 and describes a scalar system which
relaxes from its previous state according to its autono-
mous dynamics, and which then updates its initial
conditions to satisfy the input.


Example: integrate-and fire
~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. math::

   \dot{\mathbf{x}} = \mathbf{A}\mathbf{x} = \left[\begin{aligned}\tau_\text{syn} & 0\\
   \frac{1}{C_m} & -\frac{1}{\tau_m} \end{aligned}\right]

where the initial conditions are defined at the time that an incoming spike is handled, that is that the variable

.. math::

   \mathbf{x}(0) = \left[\begin{aligned}\Delta I_\text{PSP}\\ V_{m,0}\end{aligned}\right]

In a grid-constrained simulation, only
delays that are an integer multiple of h can be considered because incoming
spikes can be handled only at grid points.

If a model emits a spike at time t that has a delay of d, the simulation algorithm waits until all neurons have completed their updates for the integration step (t − h, t] and then delivers the event to its target(s).

