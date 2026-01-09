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

//! A relative time.
class Time
{
public:
  //! Default constructor.
  Time() = default;

  //! Copy constructor.
  Time(const Time& time) = default;

  //! Move constructor.
  Time(Time&& time) = default;

  //! Copy assignment operator.
  Time& operator=(const Time& time) = default;

  //! Move assignment operator.
  Time& operator=(Time&& time) = default;

  //! Valued constructor.
  Time(const int64_t sec, const int32_t nsec);

  //! Set the seconds and nanoseconds values.
  void set(const int64_t& sec, const int32_t& nsec);

  //! Const access the seconds value.
  const int64_t& sec() const;

  //! Const access the nanoseconds value.
  const int32_t& nsec() const;

  //! Convert the time into a double count of seconds.
  double toDouble() const;

protected:
  //! Correct any discrepancies between seconds and nanoseconds.
  void rectify();

  //! Full seconds away from the datum time.
  int64_t sec_{0};

  //! Nanoseconds away from the datum time (above/beyond the nubmer of full seconds).
  int32_t nsec_{0};
};

//! Convert a time into a string.
std::string to_string(const Time& time);

}  // namespace kmath