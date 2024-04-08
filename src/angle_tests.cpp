/**
 * @author      : $USER ($USER@4cb938719f62)
 * @file        : angle_tests
 * @created     : Friday Mar 29, 2024 10:08:58 UTC
 */

#include "geometry_msgs/Quaternion.h"
#include "osrt_ros/UIMU/ExternalHeading.h"
#include <gtest/gtest.h>

TEST(CalculateAngles,basicCall)
{
	ExternalHeading eH; 
	geometry_msgs::Quaternion q1,q2,q3;
	q1.w = 1;
	q1.x = 0;
	q1.y = 0;
	q1.z = 0;
	
	q2.w = 1;
	q2.x = 0;
	q2.y = 0;
	q2.z = 0;
	
	q3.w = 1;
	q3.x = 0;
	q3.y = 0;
	q3.z = 0;
	EXPECT_EQ(0,eH.calculate_damn_angle(q1,q2,q3));

}


int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
