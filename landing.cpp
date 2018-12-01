#include <ros/ros.h>
#include <geometry_msgs/Point.h>

int main(int argc, char** argv)
{

  /*****************************************************************************
   ros node stuff : like nodehandle 
   publisher for cb_image topic
  *****************************************************************************/
  ros::init(argc, argv, "cb_publisher");
  ros::NodeHandle nh;
  ros::Publisher cb_pub = nh.advertise<geometry_msgs::Point>("cb_img", 1000);
  
  while (nh.ok()) 
  {
    float x , y ,z ,freq;
    //creating parameters
    nh.getParam("/cb_publisher/x", x);
    nh.getParam("/cb_publisher/y",y);
    nh.getParam("/cb_publisher/z",z);
    nh.getParam("/cb_publisher/freq",freq);

    ros::Rate loop_rate(freq);
    
    geometry_msgs::Point p;
    p.x =x;
    p.y = y;
    p.z = z;
 

    /*****************************************************************************
     giving data to image after applying modifier 
    *****************************************************************************/

    
    cb_pub.publish(p);
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
