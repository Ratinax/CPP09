#include "RPN.hpp"

static bool	validNbOperator(char *str)
{
	int nbDigit = 0;
	int nbOperator = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '-'
			|| str[i] == '+'
			|| str[i] == '*'
			|| str[i] == '/')
			nbOperator++;
		if (isdigit(str[i]))
			nbDigit++;
		if (nbDigit <= nbOperator && nbDigit != 0 && nbOperator != 0)
			return (0);
	}
	if (nbDigit - 1 != nbOperator)
		return (0);
	return (1);
}

bool	valid_args(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Error" << WHITE << ": Should have one arg" << WHITEENDL;
		return (0);
	}
	if (!argv[1][0])
	{
		std::cout << RED << "Error" << WHITE << ": String should not be empty" << WHITEENDL;
		return (0);
	}
	if (!validNbOperator(argv[1]))
	{
		std::cout << RED << "Error" << WHITE << ": wrong operation amount" << WHITEENDL;
		return (0);
	}
	for (int i = 0; i < argv[1][i]; i++)
	{
		if (!isdigit(argv[1][i]) &&
			!(argv[1][i] == '-'
			|| argv[1][i] == '+'
			|| argv[1][i] == '*'
			|| argv[1][i] == '/')
			&& (argv[1][i] != ' '))
		{
			std::cout << RED << "Error" << WHITE << ": wrong character found" << WHITEENDL;
			return (0);
		}
	}
	return (1);
}
