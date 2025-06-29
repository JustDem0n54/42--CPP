#include "Fixed.hpp"
#include "Point.hpp"

const Fixed area(Point const& a, Point const& b, Point const& c)
{
	Fixed part1(a.get_x() * (b.get_y() - c.get_y()));
	Fixed part2(b.get_x() * (c.get_y() - a.get_y()));
	Fixed part3(c.get_x() * (a.get_y() - b.get_y()));

	Fixed result((part1 + part2 + part3).abs() / Fixed(2));
	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed AreaTotal(area(a, b, c));
	Fixed Area1(area(point, b, c));
	Fixed Area2(area(a, point, c));
	Fixed Area3(area(a, b, point));

	if (Area1 == Fixed(0) || Area2 == Fixed(0) || Area3 == Fixed(0))
		return (false);
	else if (Area1 + Area2 + Area3 == AreaTotal)
		return (true);
	else
		return (false);
}