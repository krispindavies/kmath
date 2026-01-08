/*
Copyright (c) 2025 Krispin Davies.

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

#include "kmath/time.h"

#include <format>
#include <iostream>

namespace kmath
{

constexpr int32_t one_second_in_nanoseconds = 1000000000;

void Time::set(const int64_t& sec, const int32_t& nsec)
{
  sec_ = sec;
  nsec_ = nsec;
  rectify();
}

double Time::toDouble() const
{
  return sec_ + nsec_ / 1.0e9;
}

const int64_t& Time::sec() const
{
  return sec_;
}

const int32_t& Time::nsec() const
{
  return nsec_;
}

void Time::rectify()
{
  if (sec_ > 0 && nsec_ < 0)
  {
    const auto x = std::abs(nsec_ + 1) / one_second_in_nanoseconds + 1;
    sec_ -= x;
    nsec_ += x * one_second_in_nanoseconds;
  }
  else if (sec_ > 0 && nsec_ > one_second_in_nanoseconds)
  {
    sec_ += nsec_ / one_second_in_nanoseconds;
    nsec_ = nsec_ % one_second_in_nanoseconds;
  }
  else if (sec_ < 0 && nsec_ > 0)
  {
    const auto x = std::abs((nsec_ - 1) / one_second_in_nanoseconds) + 1;
    sec_ += x;
    nsec_ -= x * one_second_in_nanoseconds;
  }
  else if (sec_ < 0 && nsec_ < one_second_in_nanoseconds)
  {
    sec_ += nsec_ / one_second_in_nanoseconds;
    nsec_ = nsec_ % one_second_in_nanoseconds;
  }
}

std::string to_string(const Time& time)
{
  std::string result;
  if (time.sec() < 0 || (time.sec() == 0 && time.nsec() < 0))
  {
    result += '-';
  }
  result += std::to_string(std::abs(time.sec()));
  if (time.nsec() != 0)
  {
    result += "." + std::format("{:09}", std::abs(time.nsec()));
    const std::size_t last_char = result.find_last_not_of('0');
    if (last_char != std::string::npos)
    {
      result.erase(last_char + 1);
    }
  }
  return result;
}

}  // namespace kmath