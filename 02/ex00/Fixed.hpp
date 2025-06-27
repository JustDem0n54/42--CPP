#ifndef _FIXED_
	#define _FIXED_

#include <iostream>
#include <string>

class Fixed
{
	private:
		int _value;
		static const int _scale = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		int getRawBits() const;
		void setRawBits(int const raw);
};

#endif