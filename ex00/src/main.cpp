#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argv;
	std::map<std::string, float> dataBase;
	std::map<std::string, std::string> dataInput;

	if (!valid_args(argc))
		return (1);
	if (!getDataBaseMap(dataBase))
		return (1);
	if (!getDataInputMap(dataInput, argv[1]))
		return (1);
}
