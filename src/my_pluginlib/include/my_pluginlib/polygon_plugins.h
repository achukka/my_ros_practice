#ifndef MY_PLUGINLIB_POLYGON_PLUGINS_H_
#define MY_PLUGINLIB_POLYGON_PLUGINS_H_
#include <my_pluginlib/polygon_base.h>
#include <cmath>

namespace polygon_plugins 
{
  class Triangle : public polygon_base::RegularPolygon
  {
    public:
      Triangle() : side_length_() {}

      void initialize(double side_length)
      {
        side_length_ = side_length;
      }

      double area()
      {
        return 0.5 * side_length_ * getHeight();
      }

      double getHeight()
      {
        return sqrt((side_length_ * side_length_) - ((side_length_ / 2) * (side_length_ / 2)));
      }

    private:
      double side_length_;
  };

  class Square : public polygon_base::RegularPolygon
  {
    public:
      Square() : side_length_() {}

      void initialize(double side_length)
      {
        side_length_ = side_length;
      }

      double area()
      {
        return side_length_ * side_length_;
      }

    private:
      double side_length_;

  };

  class Rectangle : public polygon_base::MyPolygon
  {
    public:
      Rectangle(){
        length_=0;
        width_=0;
      }

      void initialize(double length, double width)
      {
        length_ = length;
        width_ = width;
      }

      double area()
      {
        return length_ * width_;
      }

    private:
      double length_;
      double width_;

  };
};
#endif