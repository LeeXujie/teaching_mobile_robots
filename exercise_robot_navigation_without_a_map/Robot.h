#pragma once

#include "opencv2/core.hpp"

using namespace std;
using namespace cv;

class Robot
{ 
  public:

     enum behavior_modes {
        TURN_TO_GOAL,
        GO_STRAIGHT_TO_GOAL,
        OBSTACLE_AVOIDANCE,
        NR_MODES
     };

     char BEHAVIOR_MODE_STRINGS[NR_MODES][100] =
     { "Turn to goal",
       "Go straight to goal",
       "Obstacle avoidance"
     };

                    Robot::Robot(string             name,
                                 int                radius,
                                 Point2d            start_pos,
                                 double             start_orientation,
                                 vector<double>     sensor_angles,
                                 vector<double>     sensor_distances);

    void            compute_sensor_values(Mat world);

    void            update(Mat world);

    Point2d         get_position();

    double          get_orientation();

    double          get_radius();

    int             get_nr_sensors();

    vector<double>  get_sensor_values();

    vector<double>  get_sensor_angles();

    vector<double>  get_sensor_distances();

    void            move(double pixel);

    void            turn(double angle);

    bool            test_wall_bump(Mat world);

    void            set_target_location(Point p);

    void            switch_to_new_behavior_mode(behavior_modes m);

    double          get_distance_to_target();



private:

   string          name;
   double          radius;
   Point2d         pos;
   double          orientation;
   vector<double>  sensor_angles;
   vector<double>  sensor_distances;
   int             nr_sensors;
   vector<double>  sensor_values;
   Point           target_location;

   behavior_modes  current_behavior_mode;   

}; // class Robot