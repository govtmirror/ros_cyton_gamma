//------------------------------------------------------------------------------
// Copyright (c) 2004-2013 Energid Technologies. All rights reserved.
//
/// @file ros_cyton_client_ee_demo.cpp
//
//------------------------------------------------------------------------------


#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float64.h"
#include "std_msgs/Float32MultiArray.h"
#include "std_msgs/Float64MultiArray.h"

#include <sstream>
#include <iostream>
#include <vector>


///Global declaration of publishers
ros::Publisher mode_pub;
ros::Publisher ee_type_pub;
ros::Publisher ee_pos_pub;
ros::Publisher joint_val_pub;
ros::Publisher gripper_val_pub;
ros::Publisher execute_pub;


///Function will send end effector pose, name of end effector to ros_cyton_server
///@param[in] end_effector (String) Name of endeffector
///@parm[in] ee_pose_array (double[]) end effector pose array(x,y,z,roll,pitch,yaw)
///@return[out] status Return the status of function
bool Send_EE_Pose(std::string end_effector,double ee_pose_array[])

{

	std::vector<double> ee_pos(6);
	std_msgs::String ee_type_msg;
	std_msgs::String mode_msg;
	std_msgs::String execute;
	std_msgs::Float64MultiArray ee_pose;

    	ee_pos.insert(ee_pos.begin(),ee_pose_array,ee_pose_array+6);	
        if(end_effector == "point_end_effector")
	{

    		std::stringstream ss1;
    		ss1 << "point_end_effector";
    		ee_type_msg.data = ss1.str();
		ee_pose.data=ee_pos;

	}

       else if(end_effector == "frame_end_effector")
        {

   		std::stringstream ss1;
    		ss1 << "frame_end_effector";
    		ee_type_msg.data = ss1.str();
	  	ee_pose.data=ee_pos;
	}


	std::stringstream ss;
	ss <<"ik_mode";
	mode_msg.data = ss.str();
	std::stringstream ss1;
	ss1 <<"yes";
	execute.data = ss1.str();

	///Sending messages
	mode_pub.publish(mode_msg);
	ee_type_pub.publish(ee_type_msg);
	ee_pos_pub.publish(ee_pose);
	execute_pub.publish(execute);	


	return true;
}




///Function will send joint values to ros_cyton_server
///@param[in] joint_values (double []) Joint values except gripper
///@return[out] status Return the status of function
bool Send_Joint_Pose(double joint_pose_array[])
{

	std::vector<double> joint_pos(7);
	std_msgs::String mode_msg;
	std_msgs::String execute;
	std_msgs::Float64MultiArray joint_pose;

    	joint_pos.insert(joint_pos.begin(),joint_pose_array,joint_pose_array+7);	


	joint_pose.data = joint_pos;

	std::stringstream ss;
	ss <<"joint_mode";
	mode_msg.data = ss.str();

	std::stringstream ss1;
	ss1 <<"yes";
	execute.data = ss1.str();

	///Sending messages
	mode_pub.publish(mode_msg);
	joint_val_pub.publish(joint_pose);
	execute_pub.publish(execute);	

	return true;
}
///Function will send the gripper value 
///@param[in] value (double) Gripper value
///@return[out] status(bool) Status of the function
bool Send_Gripper_Value(double value)

{
	std_msgs::Float64 gripper_val;
	gripper_val.data = value;
	
	gripper_val_pub.publish(gripper_val);


	return true;
}









int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line. For programmatic
   * remappings you can use a different version of init() which takes remappings
   * directly, but for most command-line programs, passing argc and argv is the easiest
   * way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
// %Tag(INIT)%
  ros::init(argc, argv, "ros_cyton_client");
// %EndTag(INIT)%

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
// %Tag(PUBLISHER)%
  mode_pub = n.advertise<std_msgs::String>("mode", 1);
  ee_type_pub = n.advertise<std_msgs::String>("end_effector_type", 1);
  ee_pos_pub = n.advertise<std_msgs::Float64MultiArray>("ee_pose", 1);
  joint_val_pub = n.advertise<std_msgs::Float64MultiArray>("joint_array", 1);
  gripper_val_pub = n.advertise<std_msgs::Float64>("gripper_value", 1);
  execute_pub = n.advertise<std_msgs::String>("execute", 1);


  ros::Rate loop_rate(3);

  while (ros::ok())
  {



//////////////////////////////////////////////////////////////////////////////////////////////
    ///Point End effector pose array
    double val_array1[6]={0.106367,-0.0446491,0.485929,0,0,0};
    double val_array2[6]={0.0630926,-0.045305,0.656195,0.2,0.2,0.2};


    ///Sending first value as point end_effector, it will only send x,y,z
    Send_EE_Pose("point_end_effector",val_array1);
    ros::spinOnce();
    loop_rate.sleep();


    ///Sending second value as point endeffector,
    Send_EE_Pose("point_end_effector",val_array2);
    ros::spinOnce();
    loop_rate.sleep();


    
  }


  return 0;
}


