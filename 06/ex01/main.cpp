#include "Serializer.hpp"

int main()
{
	Data obj;
	obj.value = 42;

	uintptr_t raw = Serializer::serialize(&obj);
	std::cout << raw << std::endl;
	Data* data = Serializer::deserialize(raw);
	std::cout << data->value << std::endl;
}