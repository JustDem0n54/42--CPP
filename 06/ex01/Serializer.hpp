#ifndef _SERIALIZER_
	#define _SERIALIZER_

#include <stdint.h>
#include <iostream>
#include <string>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif