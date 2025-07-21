#ifndef _SPAN_
	#define _SPAN_

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span
{
	private:
		unsigned int N;
		std::vector<int> _tab;
	public:
		Span();
		Span(int nb);
		Span(const Span& copy);
		~Span();
		Span& operator=(const Span& copy);

		void addNumber(int nb);
		int shortestSpan() const;
		int longestSpan() const;
};

#endif