#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int i)
{
	this->_value = i << this->_bits;
}

Fixed::Fixed(const float f)
{
	this->_value = roundf(f * (1 << this->_bits));
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result._value = this->_value + other.getRawBits();
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const 
{
	Fixed result;
	result._value = this->_value - other.getRawBits();
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	int dividend = this->_value << _bits;
	result._value = dividend / other.getRawBits();
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	int product = this->_value * other.getRawBits();
	result._value = product >> _bits;
	return result;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->_value < other.getRawBits();
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->_value <= other.getRawBits();
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->_value > other.getRawBits();
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->_value >= other.getRawBits();
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->_value == other.getRawBits();
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->_value != other.getRawBits();
}

Fixed Fixed::operator++(int)
{
	Fixed copy = *this;
	this->_value += 1;
	return copy;
}

Fixed& Fixed::operator++()
{
	this->_value += 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed copy = *this;
	this->_value -= 1;
	return copy;
}

Fixed& Fixed::operator--()
{
	this->_value -= 1;
	return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;	
}

float Fixed::toFloat() const
{
	return static_cast<float>(this->_value) / (1 << this->_bits);
}

int Fixed::toInt() const
{
	return this->_value >> this->_bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}

float Fixed::min(const Fixed& a,const Fixed& b)
{
	if (a < b)
		return a.toFloat();
	else 
		return b.toFloat();
}

float Fixed::min(Fixed& a,Fixed& b)
{
	if (a < b)
		return a.toFloat();
	else 
		return b.toFloat();
}

float Fixed::max(const Fixed& a,const Fixed& b)
{
	if (a > b)
		return a.toFloat();
	else 
		return b.toFloat();
}

float Fixed::max(Fixed& a,Fixed& b)
{
	if (a > b)
		return a.toFloat();
	else 
		return b.toFloat();
}

Fixed& Fixed::abs()
{
	if (this->_value < 0)
		this->_value *= -1;
	return *this;
}
