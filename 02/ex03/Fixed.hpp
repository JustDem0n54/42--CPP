#ifndef _FIXED_
	#define _FIXED_

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
	private:
		int _value;
		static const int _bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& fixed);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		Fixed& operator=(const Fixed& other);
		Fixed operator+(const Fixed& other) const;
		Fixed operator-(const Fixed& other) const;
		Fixed operator/(const Fixed& other) const;
		Fixed operator*(const Fixed& other) const;
		Fixed operator++(int);
		Fixed& operator++();
		Fixed operator--(int);
		Fixed& operator--();
		bool operator<(const Fixed& other) const;
		bool operator<=(const Fixed& other) const;
		bool operator>(const Fixed& other) const;
		bool operator>=(const Fixed& other) const;
		bool operator==(const Fixed& other) const;
		bool operator!=(const Fixed& other) const;
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
		static float min(const Fixed& a,const Fixed& b);
		static float min(Fixed& a,Fixed& b);
		static float max(const Fixed& a,const Fixed& b);
		static float max(Fixed& a,Fixed& b);
		Fixed& abs();
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif