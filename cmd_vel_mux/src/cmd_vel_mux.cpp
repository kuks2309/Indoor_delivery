
#include "ros/ros.h" 
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int8.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Bool.h"

float angular[3] = {0.0,};
float linear[3]  = {0.0,};

void callback1(const geometry_msgs::Twist & cmd_input)
{
  
   linear[0]  = cmd_input.linear.x ;//m/s
   angular[0] = cmd_input.angular.z ;//rad/s
}

void callback2(const geometry_msgs::Twist & cmd_input)
{
   linear[1]  = cmd_input.linear.x ;//m/s
   angular[1] = cmd_input.angular.z ;//rad/s
}

void callback3(const geometry_msgs::Twist & cmd_input)
{
   linear[2]  = cmd_input.linear.x ;//m/s
   angular[2] = cmd_input.angular.z ;//rad/s
}

void cmd_sel_callback(const std_msgs::Int8 & data)
{
	
	


}
int main(int argc, char **argv)
{
 
  
  ros::init(argc, argv, "cmd_vel_mux_node");
  ros::NodeHandle n;

  std::string cmd_vel_input1_topic =  "/cmd_vel";  
  std::string cmd_vel_input2_topic =  "/mobile_base/commands/velocity";
  std::string cmd_vel_input3_topic =  "/cmd_vel_key";
  std::string cmd_output_topic = "/cmd_vel_mux";
  //get param from user launch
  /*serial_com set*/

  /*other*/
  ros::param::get("~cmd_vel_input1_topic", cmd_vel_input1_topic);
  ros::param::get("~cmd_vel_input2_topic", cmd_vel_input2_topic);
  ros::param::get("~cmd_vel_input3_topic", cmd_vel_input3_topic);
  ros::param::get("~cmd_output_topic", cmd_output_topic);
 
  
  ros::Subscriber sub_cmd_vel_inut1 = n.subscribe(cmd_vel_input1_topic, 1, callback1);
  ros::Subscriber sub_cmd_vel_inut2 = n.subscribe(cmd_vel_input2_topic, 1, callback2);
  ros::Subscriber sub_cmd_vel_inut3 = n.subscribe(cmd_vel_input3_topic, 1, callback2);
  ros::Subscriber sub_cmd_select    = n.subscribe("/cmd_sel",1,cmd_sel_callback);
  ros::Publisher  cmd_vel_pub       = n.advertise<geometry_msgs::Twist>(cmd_output_topic, 20);
  
  geometry_msgs::Twist cmd_vel_msg;

  ros::Rate loop_rate(10.0); //10.0HZ
  while(ros::ok())
  {
    
      
      cmd_vel_pub.publish(cmd_vel_msg);      

      ros::spinOnce();
      loop_rate.sleep();
  }

  return 0;
}
