#include "Span.hpp"

Span::Span(): N(0)
{}

Span::Span(int nb): N(nb)
{}

Span::Span(const Span& copy)
{
	this->N = copy.N;
}

Span::~Span()
{}

Span& Span::operator=(const Span& copy)
{
	if (this != &copy)
		this->N = copy.N;
	return *this;
}

void Span::addNumber(int nb)
{
	if (this->_tab.size() >= N || N == 0)
		throw std::runtime_error("Can't add an other number.");
	_tab.push_back(nb);
}

int Span::shortestSpan() const
{
	if (this->_tab.size() < 2 || N == 0)
		throw std::runtime_error("Not enough numbers stored.");

	std::vector<int> sorted = _tab;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

int Span::longestSpan() const
{
	if (this->_tab.size() < 2 || N == 0)
		throw std::runtime_error("Not enough numbers stored.");

	std::vector<int> sorted = _tab;
	std::sort(sorted.begin(), sorted.end());
	int maxSpan = sorted[sorted.size() - 1] - sorted[0];
	return maxSpan;
}
