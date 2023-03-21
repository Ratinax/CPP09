#include "PmergeMe.hpp"

bool	fillNumbers(std::vector<int> &numbers, int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << RED << "Error" << WHITE << ": no args" << WHITEENDL;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		if (std::atoi(argv[i]) < 0)
		{
			std::cout << RED << "Error" << WHITE << ": negative arg" << WHITEENDL;
			return (0);
		}
		for (std::vector<int>::iterator it = numbers.begin();
			it != numbers.end(); it++)
		{
			if (*it == std::atoi(argv[i]))
			{
				std::cout << RED << "Error" << WHITE << ": dupplicate args" << WHITEENDL;
				return (0);
			}
		}
		numbers.push_back(std::atoi(argv[i]));
	}
	return (1);
}

void	put(std::vector<int> &v)
{
	for (std::vector<int>::iterator it = v.begin();
	it != v.end(); it++)
	{
		std::cout << WHITE << *it << " ";
	}
}

void	put(std::deque<int> &v)
{
	for (std::deque<int>::iterator it = v.begin();
	it != v.end(); it++)
	{
		std::cout << WHITE << *it << " ";
	}
}
