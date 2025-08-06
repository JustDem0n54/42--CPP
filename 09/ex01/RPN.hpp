#ifndef _RPN_
	#define _RPN_

#include <stack>
#include <iostream>
#include <string>
#include <cstdlib>
#include <exception>
#include <stdexcept>

class RPN
{
	private:
		std::stack<int> _rpn;
	public:
		RPN();
		RPN(const RPN& copy);
		~RPN();
		RPN& operator=(const RPN& copy);

		void ResolveRPN(std::string str);
		void ParsingEntry(std::string str) const;
		bool Operation(char c);
		void Stock(int nb);
};

#endif