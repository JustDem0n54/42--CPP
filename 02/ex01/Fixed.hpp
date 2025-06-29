#ifndef _FIXED_
	#define _FIXED_

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif