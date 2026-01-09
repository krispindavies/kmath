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

#include "kmath/pose2d.h"

#include <cmath>
#include <format>

namespace kmath
{

Pose2D::Pose2D(const double x, const double y, const double yaw) : x_(x), y_(y), yaw_(yaw) {}

double& Pose2D::x()
{
  return x_;
}

const double& Pose2D::x() const
{
  return x_;
}

double& Pose2D::y()
{
  return y_;
}

const double& Pose2D::y() const
{
  return y_;
}

double& Pose2D::yaw()
{
  return yaw_;
}

const double& Pose2D::yaw() const
{
  return yaw_;
}

double Pose2D::magnitudeXY()
{
  return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2));
}

double Pose2D::magnitudeSE2()
{
  return std::sqrt(std::pow(x_, 2) + std::pow(y_, 2) + std::pow(yaw_, 2));
}

std::string to_string(const Pose2D& pose)
{
  return std::to_string(pose.x()) + ", " + std::to_string(pose.y()) + ", " + std::to_string(pose.yaw());
}

}  // namespace kmath