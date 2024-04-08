cmake_minimum_required(VERSION 3.0.2)
project(test_osrt_ros)

set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

find_package(catkin REQUIRED COMPONENTS
	osrt_ros
	rospy
	rostest
	)
catkin_package(CATKIN_DEPENDS
	roscpp
	osrt_ros
	)
#############
## Testing ##
#############

find_package(osrt_ros REQUIRED COMPONENTS
	osrtRosUIMU
	)
include_directories(
	${catkin_INCLUDE_DIRS}
	)

## Add folders to be run by python nosetests
if(CATKIN_ENABLE_TESTING)

	message(NOTICE "catkin")
foreach(dir ${catkin_INCLUDE_DIRS})
	message(STATUS
		"catkin_dir=${dir}"
		)
endforeach()
	catkin_add_nosetests(test)
	find_package(rostest REQUIRED)
	add_rostest(test/ik_bare_1992.test)
	add_rostest(test/ik_bare_2392.test)
	add_rostest(test/id_agfr.test)
	add_rostest(test/id_cgfr.test)
	add_rostest(test/lower_ik.test)
	add_rostest(test/upper_ik.test)
	catkin_add_gtest(${PROJECT_NAME}-angle src/angle_tests.cpp)
	if(TARGET ${PROJECT_NAME}-angle)
		add_dependencies(${PROJECT_NAME}-angle  ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
		target_link_libraries(${PROJECT_NAME}-angle ${osrt_ros_LIBRARIES} ${catkin_LIBRARIES} )

	endif()
endif()

## Add gtest based cpp test target and link libraries
