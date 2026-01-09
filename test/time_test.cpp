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
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURtime ARE
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

TEST(KMathTimeTest, construction_test)
{
  // Check default construction.
  kmath::Time time;
  EXPECT_EQ(0, time.sec());
  EXPECT_EQ(0, time.nsec());

  // Check construction with values.
  kmath::Time time_valued{1, 2};
  EXPECT_EQ(1, time_valued.sec());
  EXPECT_EQ(2, time_valued.nsec());

  // Check copy construction.
  auto time_copy_constructed{kmath::Time{-3, -4}};
  EXPECT_EQ(-3, time_copy_constructed.sec());
  EXPECT_EQ(-4, time_copy_constructed.nsec());

  // Check move construction.
  auto time_move_constructed{std::move(time_copy_constructed)};
  EXPECT_EQ(-3, time_move_constructed.sec());
  EXPECT_EQ(-4, time_move_constructed.nsec());

  // Check copy assignment.
  kmath::Time time_copy_assigned;
  time_copy_assigned = kmath::Time{5, 6};
  EXPECT_EQ(5, time_copy_assigned.sec());
  EXPECT_EQ(6, time_copy_assigned.nsec());

  // Check move assignment.
  kmath::Time time_move_assigned;
  time_move_assigned = std::move(time_copy_assigned);
  EXPECT_EQ(5, time_move_assigned.sec());
  EXPECT_EQ(6, time_move_assigned.nsec());
}

TEST(KMathTimeTest, rectify_test)
{
  // Check time with positive nanoseconds.
  kmath::Time time{0, 10};
  EXPECT_EQ(0, time.sec());
  EXPECT_EQ(10, time.nsec());

  // Check time with positive seconds.
  time.set(10, 0);
  EXPECT_EQ(10, time.sec());
  EXPECT_EQ(0, time.nsec());

  // Check time with both positive.
  time.set(10, 10);
  EXPECT_EQ(10, time.sec());
  EXPECT_EQ(10, time.nsec());

  // Check time with positive seconds and overly positive nanoseconds.
  time.set(10, 2000000010);
  EXPECT_EQ(12, time.sec());
  EXPECT_EQ(10, time.nsec());

  // Check time with positive seconds and negative nanoseconds.
  time.set(10, -10);
  EXPECT_EQ(9, time.sec());
  EXPECT_EQ(999999990, time.nsec());

  // Check time with positive seconds and overly negative nanoseconds.
  time.set(10, -2000000010);
  EXPECT_EQ(7, time.sec());
  EXPECT_EQ(999999990, time.nsec());

  // Check time with negative nanoseconds.
  time.set(0, -10);
  EXPECT_EQ(0, time.sec());
  EXPECT_EQ(-10, time.nsec());

  // Check time with negative seconds.
  time.set(-10, 0);
  EXPECT_EQ(-10, time.sec());
  EXPECT_EQ(0, time.nsec());

  // Check time with both negative.
  time.set(-10, -10);
  EXPECT_EQ(-10, time.sec());
  EXPECT_EQ(-10, time.nsec());

  // Check time with negative seconds and positive nanoseconds.
  time.set(-10, 10);
  EXPECT_EQ(-9, time.sec());
  EXPECT_EQ(-999999990, time.nsec());

  // Check time with negative seconds and overly negative nanoseconds.
  time.set(-10, -2000000010);
  EXPECT_EQ(-12, time.sec());
  EXPECT_EQ(-10, time.nsec());

  // Check time with negative seconds and overly positive nanoseconds.
  time.set(-10, 2000000010);
  EXPECT_EQ(-7, time.sec());
  EXPECT_EQ(-999999990, time.nsec());
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
