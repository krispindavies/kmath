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

#include <gtest/gtest.h>

TEST(KmathTimeTest, time_test)
{
  // Check default construction.
  kmath::Time time;
  EXPECT_EQ(0, time.sec_);
  EXPECT_EQ(0, time.nsec_);
  EXPECT_EQ("0", to_string(time));

  // Check time with only nanoseconds.
  time = kmath::Time{ 0, 10 };
  EXPECT_EQ(0, time.sec_);
  EXPECT_EQ(10, time.nsec_);
  EXPECT_EQ("0.00000001", to_string(time));

  // Check time with only seconds.
  time = kmath::Time{ 10, 0 };
  EXPECT_EQ(10, time.sec_);
  EXPECT_EQ(0, time.nsec_);
  EXPECT_EQ("10", to_string(time));

  // Check time with both.
  time = kmath::Time{ 10, 10 };
  EXPECT_EQ(10, time.sec_);
  EXPECT_EQ(10, time.nsec_);
  EXPECT_EQ("10.00000001", to_string(time));
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
