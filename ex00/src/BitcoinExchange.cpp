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
		right = str.substr(ind + charset.length());
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

static bool isLeap(std::string year)
{
	int yearInt = std::atoi(year.c_str());

	if (yearInt % 400 == 0)
		return (1);
	else if (yearInt % 100 == 0)
		return (0);
	else if (yearInt % 4 == 0)
		return (1);
	return (0);
}

static bool goodDayAmount(std::string year, std::string month, std::string day)
{
	if (month > "12" || month == "00" || day == "00")
		return (1);
	else if ((month == "01" || month == "03" || month == "05"
		|| month == "07" || month == "08" || month == "10" || month == "12") && day > "31")
		return (1);
	else if ((month == "04" || month == "06" || month == "09"
		|| month == "11") && day > "30")
		return (1);
	else if (month == "02" && isLeap(year) && day > "29")
		return (1);
	else if (month == "02" && !isLeap(year) && day > "28")
		return (1);
	return (0);
}

static bool	badDate(std::string date)
{
	std::string	year, month, day, month_day;
	split(date, year, month_day, "-");
	split(month_day, month, day, "-");
	return (goodDayAmount(year, month, day));
}

static float	findPrice(std::map<std::string, float> &dataBase, std::string date, std::string amount)
{
	float		price;
	std::string	dateDataBase, priceDataBase;
	std::map<std::string, float>::iterator it = dataBase.begin();

	if (it->first > date)
	{
		price = it->second;
		return (std::strtof(amount.c_str(), NULL) * price);
	}
	for (std::map<std::string, float>::iterator it = dataBase.begin();
		it != dataBase.end(); ++it)
	{
		if (it->first > date || it->first.length() > date.length())
		{
			it--;
			price = it->second;
			return (std::strtof(amount.c_str(), NULL) * price);
		}
	}
	it = dataBase.end();
	it--;
	price = it->second;
	return (std::strtof(amount.c_str(), NULL) * price);
	return (0);
}

static void	putLine(std::map<std::string, float> &dataBase, std::string date, std::string amount)
{
	(void) dataBase;
	if (atof(amount.c_str()) < 0)
		std::cout << RED << "Error" << WHITE << ": not a positive number." << WHITEENDL;
	else if (badDate(date))
		std::cout << RED << "Error" << WHITE << ": bad input => " << RED << date << WHITEENDL;
	else if (std::atof(amount.c_str()) > 1000)
		std::cout << RED << "Error" << WHITE << ": too large number." << WHITEENDL;
	else
		std::cout << date << " => " << amount << " = " << findPrice(dataBase, date, amount) << WHITEENDL;
}

bool	putLines(std::map<std::string, float> &dataBase, char *fileName)
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
			putLine(dataBase, date, amount);
		is_first_line = 0;
	}
	file.close();
	return (true);
}
