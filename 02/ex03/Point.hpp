#ifndef _POINT_
	#define _POINT_

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed _x;
		const Fixed _y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& point);
		~Point();
		Point& operator=(const Point& point);
		const Fixed& get_x() const; 
		const Fixed& get_y() const; 
};

#endif