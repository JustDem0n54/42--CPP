#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{}

Point::Point(const float x, const float y): _x(x), _y(y)
{}

Point::Point(const Point& point): _x(point._x), _y(point._y)
{}

Point::~Point()
{}

Point& Point::operator=(const Point& point)
{
	(void)point;
	return *this;
}

const Fixed& Point::get_x() const
{
	return(this->_x);
}

const Fixed& Point::get_y() const
{
	return(this->_y);
}
