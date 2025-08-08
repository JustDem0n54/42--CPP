#ifndef _PMERGEME_
	#define _PMERGEME_

#include <vector>
#include <deque>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <exception>
#include <algorithm>
#include <cmath>
#include <iomanip>

class PmergeMe
{
	private:
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe& copy);

		
		void FordJonhson(char **argv, int argc);
		
		std::vector<int> Execute(std::vector<int>& input);
		void ParsingEntry(char **argv, int argc, std::vector<int>& input);
		void BinaryCompare(std::vector<int>& sorted, int value);
		void MinMaxTab(std::vector<int>& max, std::vector<int>& min, int first, int second);

		std::deque<int> Execute(std::deque<int>& input);
		void ParsingEntry(char **argv, int argc, std::deque<int>& input);
		void BinaryCompare(std::deque<int>& sorted, int value);
		void MinMaxTab(std::deque<int>& max, std::deque<int>& min, int first, int second);
};

#endif 