#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(const PmergeMe&)
{
}

PmergeMe::~PmergeMe()
{}

PmergeMe& PmergeMe::operator=(const PmergeMe&)
{
	return *this;
}

void PmergeMe::ParsingEntry(char **argv, int argc, std::vector<int>& input)
{
	for (int i = 1; i < argc; i++)
	{
		std::string strargv = argv[i];
		int temp = std::atoi(strargv.c_str());
		std::stringstream itoa;
		itoa << temp;
		if (strargv != itoa.str() || temp < 0)
			throw std::invalid_argument("Error: Bad input.");
		input.push_back(temp);
	}
}

int BinarySearch(std::vector<int> sorted, int value)
{
	int low = 0;
	int high = sorted.size();

	while (low < high)
	{
		int mid = low + (high - low) / 2;

		if (sorted[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::BinaryCompare(std::vector<int>& sorted, int value)
{
	int pos = BinarySearch(sorted, value);
	sorted.insert(sorted.begin() + pos, value);
}

void PmergeMe::MinMaxTab(std::vector<int>& max, std::vector<int>& min, int first, int second)
{
	if (first < second)
		std::swap(first, second);
	max.push_back(first);
	min.push_back(second);
}

std::vector<int> PmergeMe::Execute(std::vector<int>& input)
{
	size_t n = input.size();
	if (n <= 1)
		return input;

	std::vector<int> max, min;
	for (size_t i = 0; i + 1 < n; i += 2)
		PmergeMe::MinMaxTab(max, min, input[i], input[i + 1]);

	std::vector<int> sorted = PmergeMe::Execute(max);

	for (size_t i = 0; i < min.size(); ++i)
		PmergeMe::BinaryCompare(sorted, min[i]);
	if (n % 2 != 0)
		PmergeMe::BinaryCompare(sorted, input[n - 1]);

	input = sorted;
	return input;
}

void PmergeMe::ParsingEntry(char **argv, int argc, std::deque<int>& input)
{
	for (int i = 1; i < argc; i++)
	{
		std::string strargv = argv[i];
		int temp = std::atoi(strargv.c_str());
		std::stringstream itoa;
		itoa << temp;
		if (strargv != itoa.str() || temp < 0)
			throw std::invalid_argument("Error: Bad input.");
		input.push_back(temp);
	}
}

int BinarySearch(std::deque<int> sorted, int value)
{
	int low = 0;
	int high = sorted.size();

	while (low < high)
	{
		int mid = low + (high - low) / 2;

		if (sorted[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::BinaryCompare(std::deque<int>& sorted, int value)
{
	int pos = BinarySearch(sorted, value);
	sorted.insert(sorted.begin() + pos, value);
}

void PmergeMe::MinMaxTab(std::deque<int>& max, std::deque<int>& min, int first, int second)
{
	if (first < second)
		std::swap(first, second);
	max.push_back(first);
	min.push_back(second);
}

std::deque<int> PmergeMe::Execute(std::deque<int>& input)
{
	size_t n = input.size();
	if (n <= 1)
		return input;

	std::deque<int> max, min;
	for (size_t i = 0; i + 1 < n; i += 2)
		PmergeMe::MinMaxTab(max, min, input[i], input[i + 1]);

	std::deque<int> sorted = PmergeMe::Execute(max);

	for (size_t i = 0; i < min.size(); ++i)
		PmergeMe::BinaryCompare(sorted, min[i]);
	if (n % 2 != 0)
		PmergeMe::BinaryCompare(sorted, input[n - 1]);

	input = sorted;
	return input;
}


void PmergeMe::FordJonhson(char **argv, int argc)
{
	std::vector<int> input;
	try
	{
		PmergeMe::ParsingEntry(argv, argc, input);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}

	std::cout << "Before : ";
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	clock_t start_vec = clock();

	PmergeMe::Execute(input);

	clock_t end_vec = clock();
	double time_elapsed_vec = static_cast<double>(end_vec - start_vec);
	std::cout << "After : ";
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(6)
              << time_elapsed_vec << "us\n";


	
	std::deque<int> input_deq;
	try
	{
		PmergeMe::ParsingEntry(argv, argc, input_deq);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return ;
	}
	
	clock_t start_deq = clock();

	PmergeMe::Execute(input_deq);

	clock_t end_deq = clock();
	double time_elapsed_deq = static_cast<double>(end_deq - start_deq);
	std::cout << "Time to process a range of " << input_deq.size()
              << " elements with std::deque: " << std::fixed << std::setprecision(5)
              << time_elapsed_deq << "us\n";
}


