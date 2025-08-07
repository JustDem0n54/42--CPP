#ifndef _PMERGEME_
	#define _PMERGEME_

#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <algorithm>
#include <cmath>

class PmergeMe
{
	private:
		std::vector<int> _input;
		std::vector<int> _max;
		std::vector<int> _min;
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& copy);

		void FordJonhson(char **argv, int argc);
		void ParsingEntry(char **argv, int argc);
		void DivideElemenent(std::vector<int>::iterator it);
		int BinaryCompare(std::vector<int>::iterator minit, int size, int scale);
		void MinMaxTab(int first, int second);
};

#endif 