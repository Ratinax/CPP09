#include "RPN.hpp"

int	main(int argc, char **argv)
{
	int	tmp;
	int	tmp2;

	if (!valid_args(argc, argv))
		return (1);
	std::stack<int> numbers;
	fillStack(numbers, argv[1]);
	for (int i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] == '-' || argv[1][i] == '+'
			|| argv[1][i] == '*' || argv[1][i] == '/')
		{
			tmp = numbers.top();
			numbers.pop();
			tmp2 = numbers.top();
			numbers.pop();
			// std::cout << BLUE << tmp << WHITE << " " << argv[1][i] << " " << CYAN << tmp2 << WHITEENDL;
			if (argv[1][i] == '-')
				numbers.push(tmp - tmp2);
			else if (argv[1][i] == '+')
				numbers.push(tmp + tmp2);
			else if (argv[1][i] == '*')
				numbers.push(tmp * tmp2);
			else if (argv[1][i] == '/' && tmp2 != 0)
				numbers.push(tmp / tmp2);
			else if (argv[1][i] == '/' && tmp2 == 0)
			{
				std::cout << RED << "Error" << WHITE << ": division per 0 !" << WHITEENDL;
				return (1);
			}
			// std::cout << MAGENTA << numbers.top() << WHITEENDL;
		}
	}
	std::cout << GREEN << numbers.top() << WHITEENDL;
	return (0);
}
