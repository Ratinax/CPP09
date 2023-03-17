#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	std::map<std::string, float> dataBase;

	if (!valid_args(argc))
		return (1);
	if (!getDataBaseMap(dataBase))
		return (1);
	if (!putLines(dataBase, argv[1]))
		return (1);
}
