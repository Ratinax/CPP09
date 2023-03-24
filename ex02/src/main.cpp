#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	std::vector<int>	vectorNumbers;
	double	timeVector, timeDeque;	//time to sort vector and deque
	clock_t start, end;	//time before and after execution of algotihm

	if (!fillNumbers(vectorNumbers, argc, argv)) // fill the vector with numbers
		return (1);
	std::cout << WHITE << "Before:	";
	put(vectorNumbers);					// put before sorted
	std::cout << WHITEENDL;

	std::deque<int>	dequeNumbers(vectorNumbers.begin(), vectorNumbers.end()); // fille the deque with numbers

	start = clock();
	mergeInsertSort(vectorNumbers, std::sqrt(vectorNumbers.size()) + 1); // Algorithme on vector
	end = clock();
	timeVector = (end - start) / (double) CLOCKS_PER_SEC * 1000000.0; // get time

	start = clock();
	mergeInsertSort(dequeNumbers, std::sqrt(dequeNumbers.size()) + 1); // Algorithme on deque
	end = clock();
	timeDeque = (end - start) / (double) CLOCKS_PER_SEC * 1000000.0; // get time

	std::cout << WHITE << "After:	";
	put(vectorNumbers);					//put the vector after beeing sorted
	std::cout << WHITEENDL;
	std::cout << "Time to process a range of " << BLUE << vectorNumbers.size() << WHITE << " elements with std::vector : " << YELLOW << timeVector << WHITE << " us" << WHITEENDL;
	std::cout << "Time to process a range of " << BLUE << vectorNumbers.size() << WHITE << " elements with std::deque : " << YELLOW << timeDeque << WHITE <<" us" << WHITEENDL;
	return (0);
}
