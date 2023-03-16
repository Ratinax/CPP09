#include "BitcoinExchange.hpp"

bool	valid_args(int argc)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error" << WHITE << ": Should have one arg" << WHITEENDL;
		return (false);
	}
	return (true);
}

bool	open_file(std::ifstream &file, char *file_name)
{
	file.open(file_name);
	if (!file.is_open())
	{
		std::cerr << RED << "Error" << WHITE << ": Couldn't open " << file_name << WHITEENDL;
		return (false);
	}
	return (true);
}

void	split(std::string str, std::string &left, std::string &right, std::string charset)
{
	size_t	ind = str.find(charset);

	if (ind == std::string::npos)
	{
		left = str.substr(0, ind);
		right = "";
	}
	else
	{
		left = str.substr(0, ind);
		right = str.substr(ind + 1);
	}
}

bool	getDataBaseMap(std::map<std::string, float> &dataBase)
{
	std::ifstream	file;
	std::string		line, date, price;
	char			filename[] = "data.csv";
	bool			is_first_line = 1;

	if (!open_file(file, filename))
		return (false);
	while (std::getline(file, line))
	{
		split(line, date, price, ",");
		if (is_first_line == 0)
			dataBase[date] = std::strtof(price.c_str(), NULL);
		is_first_line = 0;
	}
	file.close();
	return (true);
}

bool	getDataInputMap(std::map<std::string, std::string> &dataInput, char *fileName)
{
	std::ifstream	file;
	std::string		line, date, amount;
	bool			is_first_line = 1;

	if (!open_file(file, fileName))
		return (false);
	while (std::getline(file, line))
	{
		split(line, date, amount, " | ");
		if (is_first_line == 0)
			dataInput[date] = amount;
		is_first_line = 0;
	}
	file.close();
	return (true);
}
