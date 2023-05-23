cmake_minimum_required(VERSION 3.0.2)
project(test_osrt_ros)

find_package(catkin REQUIRED COMPONENTS
  osrt_ros
  rospy
  rostest
)
catkin_package(
)
#############
## Testing ##
#############

## Add folders to be run by python nosetests
if(CATKIN_ENABLE_TESTING)
  catkin_add_nosetests(test)
  find_package(rostest REQUIRED)
  add_rostest(test/ik_bare_1992.test)
  add_rostest(test/ik_bare_2392.test)
  add_rostest(test/id_agfr.test)
  add_rostest(test/id_cgfr.test)

endif()
