#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		this->_input = copy._input;
		this->_max = copy._max;
		this->_min = copy._min;
	}
	return *this;
}

void PmergeMe::ParsingEntry(char **argv, int argc)
{
	for (int i = 1; i < argc; i++)
	{
		std::string strargv = argv[i];
		int temp = std::atoi(strargv.c_str());
		std::stringstream itoa;
		itoa << temp;
		if (strargv != itoa.str() || temp < 0)
			throw std::invalid_argument("Error: Bad input.");
		this->_input.push_back(temp);
	}
}

void PmergeMe::MinMaxTab(int first, int second)
{
	if (first < second)
	{
		_min.push_back(first);
		_max.push_back(second);
	}
	else if (first >= second)
	{
		_max.push_back(first);
		_min.push_back(second);
	}
}

void PmergeMe::DivideElemenent(std::vector<int>::iterator it)
{
	if (_input.size() % 2 != 0 && it + 1 == _input.end())
	{
		_max.push_back(*it);
		return ;
	}
	PmergeMe::MinMaxTab(*it, *(it + 1));
	if (it + 1 == _input.end() || it + 2 == _input.end())
		return ;
	DivideElemenent(it + 2);
}

int PmergeMe::BinaryCompare(std::vector<int>::iterator minit, int start, int end)
{
	int size = ((start + end) / 2);
	std::vector<int>::iterator maxit = _max.begin() + size;
	if (*minit > *maxit)
	{
		if ((maxit + 1 != _max.end() && *minit < *(maxit + 1)))
			return _max.insert(maxit + 1, *minit), 0;
		BinaryCompare(minit, size + 1, end);
	}
	else if (*minit <= *maxit)
	{
		if (*maxit == *minit || maxit == _max.begin() || (maxit - 1 != _max.begin() && *minit >= *(maxit - 1)))
			return _max.insert(maxit, *minit), 0;
		BinaryCompare(minit, start, size);
	}
	return 0;
}

void PmergeMe::FordJonhson(char **argv, int argc)
{
	try
	{
		PmergeMe::ParsingEntry(argv, argc);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	std::vector<int>::iterator it = _input.begin();
	PmergeMe::DivideElemenent(it);
	std::sort(_max.begin(), _max.end());
	for (std::vector<int>::iterator minit = _min.begin(); minit != _min.end(); minit++)
	{
		PmergeMe::BinaryCompare(minit, 0, _max.size());
	}
	for (std::vector<int>::iterator maxx = _max.begin(); maxx != _max.end(); maxx++)
	{
		std::cout << *maxx << std::endl;
	}
}


