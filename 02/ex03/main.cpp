#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	const Point a(0,0);
	const Point b(10,0);
	const Point c(5,10);
	const Point point(5 , 9);

	if (bsp(a, b ,c, point))
		std::cout << "point : (" << point.get_x() << ", " << point.get_y() << ") is in the triangle" << std::endl;
	else
		std::cout << "point : (" << point.get_x() << ", " << point.get_y() << ") is not in the triangle" << std::endl;
	return 0;
}