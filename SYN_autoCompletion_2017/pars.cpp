//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

void				Addr::parsCity(std::string str) {
	std::string		city = str.substr(0, str.find(","));
	std::string		part;
	size_t			tmp = 0;

	if (city.empty())
		return ;
	while ((tmp = city.find(" ")) != std::string::npos) {
		part = city.substr(0, tmp);
		this->_City.push_back(part);
		city.erase(0, tmp + 1);
	}
	this->_City.push_back(city);
}

void				Addr::parsNum(std::string str) {
	std::string		part;
	size_t			tmp = str.find(",") + 2;

	str.erase(0, tmp);
	part = str.substr(0, str.find(" "));
	this->_Num = part;
}

void				Addr::parsType(std::string str) {
	std::string		part;
	size_t			tmp = str.find(",") + 2;

	str.erase(0, tmp);
	str.erase(0, str.find(" ") + 1);
	part = str.substr(0, str.find(" "));
	this->_Type = part;
}

void				Addr::parsAddr(std::string str) {
	std::string		part;
	size_t			tmp = str.find(",") + 2;

	str.erase(0, tmp);
	str.erase(0, str.find(" ") + 1);
	str.erase(0, str.find(" ") + 1);
	part = str.substr(0, str.size());
	while ((tmp = part.find(" ")) != std::string::npos) {
		this->_Addr.push_back(part.substr(0, tmp));
		part.erase(0, tmp + 1);
	}
	this->_Addr.push_back(part);
}
