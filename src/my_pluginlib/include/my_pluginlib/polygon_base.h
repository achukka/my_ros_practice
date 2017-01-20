#ifndef MY_PLUGINLIB_POLYGON_BASE_H
#define MY_PLUGINLIB_POLYGON_BASE_H

namespace polygon_base
{
	class RegularPolygon
	{
		public:
			virtual void initialize(double side_length) = 0;
			virtual double area() = 0;
			virtual ~RegularPolygon(){}

		protected:
			RegularPolygon(){}

	};

	class MyPolygon
	{
		public:
			virtual void initialize(double length, double width) = 0;
			virtual double area() = 0;
			virtual ~MyPolygon(){}

		protected:
			MyPolygon(){}	
	};
};
#endif