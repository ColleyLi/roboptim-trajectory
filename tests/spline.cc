// Copyright (C) 2009 by Thomas Moulard, AIST, CNRS, INRIA.
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

#include <boost/numeric/ublas/io.hpp>

#include "common.hh"

#include <roboptim-trajectory/fwd.hh>
#include <roboptim-trajectory/spline.hh>

using namespace roboptim;

int run_test ()
{
  Spline::vector_t params (10);
  params.clear ();

  Spline spline (std::make_pair (0., 5.), 10, params, 20);

  std::cout << spline << std::endl;
  return 0;
}

GENERATE_TEST ()
