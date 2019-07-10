//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"
#include "unistd.h"

void                    confirmedAddrs::addCityLetter(std::string cmd) {
        _City[cptCity] += cmd;
}
void                    confirmedAddrs::addStreetLetter(std::string cmd) {
        _Street[cptStreet] += cmd;
}
int			ValidAddrs::isNotTheSameCityBegin(std::string str) {
        std::string	tmp = str.substr(0, confAddrs.getCurrentCitySize());

        if (!iequals(tmp, confAddrs.getCurrentCity()))
                return (1);
        return (0);
}

int			ValidAddrs::isSameCity(std::vector<Addr> &addrs) {
        std::vector<std::string>        reformatedCity;

        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                std::string tmp = "";
                for (std::vector<std::string>::iterator partOfCity = (*addr).getCity().begin();
                     partOfCity != (*addr).getCity().end(); ++partOfCity) {
                        if (tmp != "")
                                tmp += " ";
                        tmp += (*partOfCity);
                }
                reformatedCity.push_back(tmp);
        }
        for (std::vector<std::string>::iterator city = reformatedCity.begin();
             city != reformatedCity.end() - 1; ++city){
                if (!iequals(*city, *(city + 1))) {
			// std::cout << (*city) << "-" << (*(city + 1)) << std::endl;
                        return (0);
                }
        }
        return (1);
}

void			ValidAddrs::completCity(Addr addr) {
	//if les parties déjà complété
        for (std::vector<std::string>::iterator city = addr.getCity().begin();
             city != addr.getCity().end(); ++city)
                findLetter(*city);
}

void			ValidAddrs::divideCity(std::vector<Addr> &addrs) {
        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                completCity(*addr);
        }
}

std::string             ValidAddrs::createCmpCity(std::string cmd) {
        std::string     ret = "";

        ret += confAddrs.getCurrentCity() + cmd;
        return ret;
}

int                     ValidAddrs::haveCommonCity(Addr &addr, std::string cmp) {

	for (std::vector<std::string>::iterator partOfCity = addr.getCity().begin();
             partOfCity != addr.getCity().end(); ++partOfCity)
        {
		if ((*partOfCity).size() >= cmp.size() &&
		    (iequals(cmp, (*partOfCity).substr(0, cmp.size())))) {
                        return (1);
		}
        }
        return (0);
}

bool			ValidAddrs::checkFullName(std::vector<Addr> &addrs){
	for (std::vector<Addr>::iterator addr = addrs.begin() ; addr != addrs.end() ;
	     ++addr) {
		for (std::vector<std::string>::iterator partOfCity = (*addr).getCity().begin() ;
		     partOfCity != (*addr).getCity().end(); ++partOfCity) {
			if (iequals(*partOfCity, confAddrs.getCurrentCity()))
				return true;
		}
	}
	return false;
}

void			ValidAddrs::initConfProp(std::vector<Addr> &addrs) {
	for (std::vector<Addr>::iterator addr = addrs.begin();
	     addr != addrs.end(); ++addr) {
		for (std::vector<std::string>::iterator partOfCity = (*addr).getCity().begin();
		     partOfCity != (*addr).getCity().end(); ++partOfCity){
			if (iequals(*partOfCity, confAddrs.getCurrentCity())) {
				confProp.push_back(*addr);
			}
		}
	}
}

bool			ValidAddrs::isExactlyTheSameCity(std::vector<std::string> &cityOne,
							 std::vector<std::string> &cityTwo) {
	if (cityOne.size() != cityTwo.size())
		return false;
	size_t cpt = 0;
	while (cpt != cityOne.size())
	{
		if (!iequals(cityOne[cpt], cityTwo[cpt]))
			return false;
		cpt++;
	}
	return true;
}

void			ValidAddrs::eraseSameCityConfProp() {
	for (std::vector<Addr>::iterator addr = confProp.begin();
	     addr != confProp.end(); ++addr) {
		std::vector<Addr>::iterator next = addr + 1;

		while (next != confProp.end()) {
			if (isExactlyTheSameCity((*addr).getCity(), (*next).getCity())) {
				next = confProp.erase(next);
				next--;
			}
			next++;
		}
	}
}

void			ValidAddrs::printMax(std::string str) {
	size_t tmp = 0;
	std::string up = "";

	while (tmp != str.size()) {
		up += toupper(str[tmp]);
		tmp++;
	}
	std::cout << up;
}

void			ValidAddrs::printMin(std::string str) {
	size_t tmp = 0;
	std::string low = "";

	while (tmp != str.size()) {
		low += tolower(str[tmp]);
		tmp++;
	}
	std::cout << low;
}

void			ValidAddrs::printConfPropCity() {
	int		cpt = 0;

	for (std::vector<Addr>::iterator addr = confProp.begin();
	     addr != confProp.end() && cpt != 2; ++addr) {
		cpt++;
		std::cout << "{" << cpt << " : ";
		for (std::vector<std::string>::iterator partOfCity = (*addr).getCity().begin();
		     partOfCity != (*addr).getCity().end(); ++partOfCity) {
			if (iequals(*partOfCity, confAddrs.getCurrentCity())) {
				printMax(confAddrs.getCurrentCity());
			}
			else {
				printMin(*partOfCity);
			}
			if (partOfCity + 1 != (*addr).getCity().end())
				std::cout << " ";
		}
		std::cout << "}";
		if (cpt != 2)
			std::cout << " ";
	}
	std::cout << std::endl;
}

bool			ValidAddrs::isAlpha(std::string cmd)
{
	if ((cmd[0] >= 'a' && cmd[0] <= 'z') || (cmd[0] >= 'A' && cmd[0] <= 'Z'))
		return true;
	return false;
}

void			ValidAddrs::eraseCityNotConf(size_t idx, std::vector<Addr> &addrs, std::vector<std::string> &lines) {
	int tmp = 0;
	for (std::vector<Addr>::iterator addr = addrs.begin();
	     addr != addrs.end(); ++addr) {
		if (!isExactlyTheSameCity((*addr).getCity(), confProp[idx - 1].getCity())) {
			addr = addrs.erase(addr);
			addr--;
			lines.erase(lines.begin() + tmp);
			tmp--;
		}
		tmp++;
	}
}

std::string		ValidAddrs::listFullName(std::vector<Addr> &addrs, std::vector<std::string> &lines) {
	std::string cmd = "";

	initConfProp(addrs);
	eraseSameCityConfProp();
	printConfPropCity();
	std::cin >> cmd;
	if (cmd.empty())
		exit(0);
	if (isAlpha(cmd)) {
		if (cmd.size() != 1)
			exit(84);
		return (cmd);
	}
	size_t test = std::stoi(cmd);
	if (confProp.size() < test || test <= 0)
		exit(84);
	eraseCityNotConf(test, addrs, lines);
	return "";
}


void			ValidAddrs::launchCity(std::vector<Addr> &addrs,
					       std::vector<std::string> &lines) {
        std::string	command = "";

        while (isSameCity(addrs) == 0) {
		divideCity(addrs);
		bubbleSort();
		if (letter.size() != 1) {
			if (command == "") {
				printFirstProp();
				std::cin >> command;
				if (command.empty())
					exit (0);
			}
			analyseCmd(command, addrs, lines);
			command = "";
		}
                else {
                        confAddrs.addCityLetter(letter[0]);
                }
                resetLetter();
		if (checkFullName(addrs)) {
			std::string ok = listFullName(addrs, lines);
			if (ok != "") {
				analyseMoreCmd(ok, addrs, lines);
			}
		}
		confProp.clear();
        }
        if (addrs.size() == 1) {
                printLastCity(lines);
	}
}
