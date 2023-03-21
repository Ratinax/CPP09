#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <cstdlib>
# include <ctime>
# include <algorithm>
# include <cmath>

# define WHITEENDL   std::endl << WHITE
# define BLACK			"\033[0m\033[30m"
# define RED			"\033[0m\033[31m"
# define GREEN			"\033[0m\033[32m"
# define YELLOW			"\033[0m\033[33m"
# define BLUE			"\033[0m\033[34m"
# define MAGENTA		"\033[0m\033[35m"
# define CYAN			"\033[0m\033[36m"
# define WHITE			"\033[0m\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

bool	fillNumbers(std::vector<int> &numbers, int argc, char **argv);
void	put(std::vector<int> &v);
void	put(std::deque<int> &v);

template<typename T>
static void	insertSort(T start, T end)
{
	size_t	nbToInsert;
	T		tmp;
	T		startCopy(start);

	start++;
	while (start != end)
	{
		tmp = start;
		nbToInsert = *tmp;
		while (tmp != startCopy && (int)*(tmp - 1) > (int)nbToInsert)
		{
			*tmp = *(tmp - 1); // move the further value on the right by copying it
			tmp--;
		}
		*tmp = nbToInsert; //insert the number in the right place
		start++;
	}
}

template<typename T>
void	mergeInsertSort(T &container, size_t sizeToInsertSort)
{
	size_t	midle;
	size_t	size = container.size();

	if (size < sizeToInsertSort) //stop recursive condition
	{
		insertSort(container.begin(), container.end());
		return ;
	}

	midle = size / 2;

	T	left(container.begin(), container.begin() + midle);
	T	right(container.begin() + midle, container.end());

	mergeInsertSort(left, sizeToInsertSort);
	mergeInsertSort(right, sizeToInsertSort);
	/*std::cout << "left : ";
	put(left);
	std::cout << std::endl;
	std::cout << "right : ";
	put(right);*/
	std::merge(left.begin(), left.end(), right.begin(), right.end(), container.begin()); // insert the values in container when they are sorted
	/*std::cout << std::endl << "result : ";
	put(container);
	std::cout << std::endl << " ---- "<< std::endl;*/
}
#endif
