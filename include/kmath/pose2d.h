/*
Copyright (c) 2026 Krispin Davies.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its contributors
   may be used to endorse or promote products derived from this software
   without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <cstddef>
#include <string>

namespace kmath
{

//! Pose in a 2-dimensional world.
class Pose2D
{
public:
  //! Default constructor.
  Pose2D() = default;

  //! Copy constructor.
  Pose2D(const Pose2D& pose) = default;

  //! Move constructor.
  Pose2D(Pose2D&& pose) = default;

  //! Copy assignment operator.
  Pose2D& operator=(const Pose2D& pose) = default;

  //! Move assignment operator.
  Pose2D& operator=(Pose2D&& pose) = default;

  //! Valued constructor.
  Pose2D(const double x, const double y, const double yaw);

  //! Access the x-axis pose value.
  double& x();

  //! Const access the x-axis pose value.
  const double& x() const;

  //! Access the y-axis pose value.
  double& y();

  //! Const access the y-axis pose value.
  const double& y() const;

  //! Access the yaw-rotation pose value.
  double& yaw();

  //! Const access the yaw-rotation pose value.
  const double& yaw() const;

  //! Magnitude of the x and y components of the pose.
  double magnitudeXY();

  //! Magnitude of the x, y, and yaw components of the pose.
  double magnitudeSE2();

protected:
  //! Pose's x-axis value.
  double x_{0.0};

  //! Pose's y-axis value.
  double y_{0.0};

  //! Pose's yaw-rotation value.
  double yaw_{0.0};
};

//! Convert a pose into a string.
std::string to_string(const Pose2D& pose);

}  // namespace kmath