/**
 * @author      : $USER ($USER@4cb938719f62)
 * @file        : angle_tests
 * @created     : Friday Mar 29, 2024 10:08:58 UTC
 */

#include "geometry_msgs/Quaternion.h"
#include "geometry_msgs/Transform.h"
#include "geometry_msgs/Vector3.h"
#include "osrt_ros/UIMU/ExternalHeading.h"
#include <gtest/gtest.h>

TEST(CalculateAngles,basicCall)
{
	ExternalHeading eH; 
	geometry_msgs::Transform tq1,tq2,tq3;
	geometry_msgs::Quaternion q1,q2,q3;
	q1.w = 1;
	q1.x = 0;
	q1.y = 0;
	q1.z = 0;
	tq1.rotation = q1;

	q2.w = 1;
	q2.x = 0;
	q2.y = 0;
	q2.z = 0;
	tq2.rotation = q2;
	
	q3.w = 1;
	q3.x = 0;
	q3.y = 0;
	q3.z = 0;
	tq3.rotation = q3;

	geometry_msgs::Vector3 v;
	v.x = 1;
	v.y = 0;
	v.z = 0;

	//This is not that easy to test...
	//EXPECT_EQ(0,eH.calculate_angle(tq1,tq2,v));

}


int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
