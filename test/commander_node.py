#!/usr/bin/env python3

import rospy
from opensimrt_msgs.srv import LabelsSrv
from std_srvs.srv import Empty
import os
rospy.init_node("commander")
stream = os.popen("rostopic list")
rospy.logwarn_once(stream.read())
stream = os.popen("rosservice list")
rospy.logwarn_once(stream.read())

read_labels = rospy.ServiceProxy("/ik/outlabels", LabelsSrv)
start_ik_srv = rospy.ServiceProxy("/inverse_kinematics_from_file/start", Empty)

rospy.sleep(3)
read_labels()
rospy.sleep(0.2)
start_ik_srv()
