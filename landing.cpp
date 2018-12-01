#include <ros/ros.h>
#include <geometry_msgs/Point.h>

int main(int argc, char** argv)
{

  /*****************************************************************************
   ros node stuff : like nodehandle 
   publisher for cb_point topic
  *****************************************************************************/
  ros::init(argc, argv, "cb_publisher");
  ros::NodeHandle nh;
  ros::Publisher cb_pub = nh.advertise<geometry_msgs::Point>("cb_img", 1000);
  float t=0;
  while (nh.ok()) 
  {
    ros::Rate loop_rate(10);
    
    geometry_msgs::Point p;
    p.x = 2*t;
    p.y = t*t;
    p.z = 0;
 

    /*****************************************************************************
     giving data to point after applying modifier 
    *****************************************************************************/

    
    cb_pub.publish(p);
    t += 0.05;
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
