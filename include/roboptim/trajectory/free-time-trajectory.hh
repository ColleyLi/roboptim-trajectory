// Copyright (C) 2009 by Florent Lamiraux, Thomas Moulard, AIST, CNRS, INRIA.
//
// This file is part of the roboptim.
//
// roboptim is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// roboptim is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with roboptim.  If not, see <http://www.gnu.org/licenses/>.

#ifndef ROBOPTIM_TRAJECTORY_FREETIMETRAJECTORY_HH
# define ROBOPTIM_TRAJECTORY_FREETIMETRAJECTORY_HH
# include <roboptim/trajectory/trajectory.hh>

namespace roboptim
{
  /// \addtogroup roboptim_function
  /// @{

  /// \brief Decorate a trajectory to make time scalable.
  ///
  /// Build a trajectory from an input trajectory and a time scale
  /// factor.
  template <unsigned DerivabilityOrder>
  class FreeTimeTrajectory : public Trajectory<DerivabilityOrder>
  {
  public:
    /// \brief Parent type.
    typedef Trajectory<DerivabilityOrder> parent_t;

    /// \brief Import value type.
    typedef typename parent_t::value_type value_type;
    /// \brief Import size type.
    typedef typename parent_t::size_type size_type;
    /// \brief Import result type.
    typedef typename parent_t::result_t result_t;
    /// \brief Import gradient type.
    typedef typename parent_t::gradient_t gradient_t;
    /// \brief Import vector type.
    typedef typename parent_t::vector_t vector_t;
    /// \brief Import jacobian type.
    typedef typename parent_t::jacobian_t jacobian_t;
    /// \brief Import interval type.
    typedef typename parent_t::interval_t interval_t;

    /// Constructor with fixed definition interval trajectory
    ///
    /// \param traj trajectory defining this one by reparameterization
    /// \param s time scale
    FreeTimeTrajectory (const Trajectory<DerivabilityOrder>& traj, double s) throw ();

    FreeTimeTrajectory (const FreeTimeTrajectory<DerivabilityOrder>& traj) throw ();

    virtual ~FreeTimeTrajectory () throw ();


    virtual jacobian_t variationConfigWrtParam (double t) const throw ();
    virtual jacobian_t variationDerivWrtParam (double t, size_type order)
      const throw ();
    virtual value_type singularPointAtRank (size_type rank) const;
    virtual vector_t derivBeforeSingularPoint (size_type rank, size_type order)
      const;
    virtual vector_t derivAfterSingularPoint (size_type rank, size_type order)
      const;

    virtual void setParameters (const vector_t&) throw ();

    /// \brief Get time scale factor.
    /// \return time scale factor.
    double timeScale () const throw ();

    size_type getTimeScalingIndex () const throw ()
    {
      return 0;
    }

    ROBOPTIM_IMPLEMENT_CLONE(FreeTimeTrajectory<DerivabilityOrder>)

    /// \brief Display the function on the specified output stream.
    ///
    /// \param o output stream used for display
    /// \return output stream
    virtual std::ostream& print (std::ostream& o) const throw ();

  protected:
    void impl_compute (result_t&, double) const throw ();
    void impl_derivative (gradient_t& g, double x, size_type order)
      const throw ();

  private:
    /// \brief Scale input time argument.
    ///
    /// Scale input argument with the same factor that the input
    /// trajectory:
    /// \f[t' = t_{min} + \lambda * (t - t_{min})\f]
    /// where \f$[t_{min}, t_{max}]\f$ is the input trajectory time range and
    /// \f[\lambda\f] the scale factor.
    ///
    /// \param t input time
    /// \return new scaled time
    double scaleTime (double t) const throw ();

    /// \brief Input fixed time trajectory.
    Trajectory<DerivabilityOrder>* trajectory_;
  };

  /// @}

} // end of namespace roboptim.

# include <roboptim/trajectory/free-time-trajectory.hxx>
#endif //! ROBOPTIM_TRAJECTORY_FREETIMETRAJECTORY_HH
