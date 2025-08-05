#ifndef _RPN_
	#define _RPN_

#include <stack>
#include <iostream>
#include <string>

class RPN
{
	private:
		std::stack<int> _rpn;
	public:
		RPN();
		RPN(const RPN& copy);
		~RPN();
		RPN& operator=(const RPN& copy);

		bool ParsingEntry(std::string str) const;
};

#endif