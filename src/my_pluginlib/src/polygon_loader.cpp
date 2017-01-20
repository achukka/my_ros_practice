#include <boost/shared_ptr.hpp>

#include <pluginlib/class_loader.h>
#include <my_pluginlib/polygon_base.h>

int main(int argc, char** argv)
{
  pluginlib::ClassLoader<polygon_base::RegularPolygon> poly_loader("my_pluginlib", "polygon_base::RegularPolygon");
  pluginlib::ClassLoader<polygon_base::MyPolygon> poly_loader_next("my_pluginlib", "polygon_base::MyPolygon");
  
  try
  {
    boost::shared_ptr<polygon_base::RegularPolygon> triangle = poly_loader.createInstance("polygon_plugins::Triangle");
    triangle->initialize(10.0);

    ROS_INFO("Triangle area: %.2f", triangle->area());
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load triangle for some reason. Error: %s", ex.what());
  }

  try
  {
    boost::shared_ptr<polygon_base::RegularPolygon> square = poly_loader.createInstance("polygon_plugins::Square");
    square->initialize(10.0);

    ROS_INFO("Square area: %.2f", square->area());
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load Square for some reason. Error: %s", ex.what());
  }

  try
  {
    boost::shared_ptr<polygon_base::MyPolygon> rectangle = poly_loader_next.createInstance("polygon_plugins::Rectangle");
    rectangle->initialize(20.0,15.0);

    ROS_INFO("Rectangle area: %.2f", rectangle->area());
  }
  catch(pluginlib::PluginlibException& ex)
  {
    ROS_ERROR("The plugin failed to load Rectangle for some reason. Error: %s", ex.what());
  }

  return 0;
}