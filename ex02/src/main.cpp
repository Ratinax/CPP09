#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<int>	numbers;

	if (!fillNumbers(numbers, argc, argv))
		return (1);
	std::cout << WHITE << "Before:	";
	put(numbers);
	std::cout << WHITEENDL;
	// get time before
	// Algorithme on vector
	// get time after

	// get time before
	// Algorithme on deque
	// get time after
	std::cout << WHITE << "After:	";
	put(numbers);
	std::cout << WHITEENDL;
	std::cout << "Time to process a range of " << BLUE << numbers.size() << WHITE << " elements with std::[..] : " << YELLOW <<  "time " << WHITE << "us" << WHITEENDL;
	std::cout << "Time to process a range of " << BLUE << numbers.size() << WHITE << " elements with std::[..] : " << YELLOW << "time " << WHITE <<"us" << WHITEENDL;
	return (0);
}
