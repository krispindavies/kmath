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

#include <gtest/gtest.h>

TEST(KMathPose2DTest, construction_test)
{
  // Check default construction.
  kmath::Pose2D pose;
  EXPECT_EQ(0, pose.x());
  EXPECT_EQ(0, pose.y());
  EXPECT_EQ(0, pose.yaw());

  // Check construction with values.
  kmath::Pose2D pose_valued{1.0, -2.0, 3.0};
  EXPECT_EQ(1.0, pose_valued.x());
  EXPECT_EQ(-2.0, pose_valued.y());
  EXPECT_EQ(3.0, pose_valued.yaw());

  // Check copy construction.
  auto pose_copy_constructed{kmath::Pose2D{-4.0, 5.0, -6.0}};
  EXPECT_EQ(-4.0, pose_copy_constructed.x());
  EXPECT_EQ(5.0, pose_copy_constructed.y());
  EXPECT_EQ(-6.0, pose_copy_constructed.yaw());

  // Check move construction.
  auto pose_move_constructed{std::move(pose_copy_constructed)};
  EXPECT_EQ(-4.0, pose_move_constructed.x());
  EXPECT_EQ(5.0, pose_move_constructed.y());
  EXPECT_EQ(-6.0, pose_move_constructed.yaw());

  // Check copy assignment.
  kmath::Pose2D pose_copy_assigned;
  pose_copy_assigned = kmath::Pose2D{7.0, -8.0, -9.0};
  EXPECT_EQ(7.0, pose_copy_assigned.x());
  EXPECT_EQ(-8.0, pose_copy_assigned.y());
  EXPECT_EQ(-9.0, pose_copy_assigned.yaw());

  // Check move assignment.
  kmath::Pose2D pose_move_assigned;
  pose_move_assigned = std::move(pose_copy_assigned);
  EXPECT_EQ(7.0, pose_move_assigned.x());
  EXPECT_EQ(-8.0, pose_move_assigned.y());
  EXPECT_EQ(-9.0, pose_move_assigned.yaw());
}

int main(int argc, char** argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
