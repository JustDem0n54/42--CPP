#ifndef _HARL_
	#define _HARL_

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug();
		void info();
		void warning();
		void error();
	public:
		Harl();
		~Harl();
		void complain(std::string level);
		int getIndex(const std::string& level);
};

#endif