//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

confirmedAddrs::confirmedAddrs() {
	this->_City.push_back("");
	this->_Street.push_back("");
	this->cptCity = 0;
	this->cptStreet = 0;
}

confirmedAddrs::~confirmedAddrs() {
}

std::vector<std::string>	&confirmedAddrs::getCity() {
	return (this->_City);
}

std::vector<std::string>	&confirmedAddrs::getStreet() {
	return (this->_Street);
}

size_t				confirmedAddrs::getCptCity() {
	return (this->cptCity);
}

void				confirmedAddrs::updateCptCity(size_t com) {
	if (com == 1)
		cptCity++;
	else if (com == 0)
		cptCity--;
}
void				confirmedAddrs::updateCptStreet(size_t com) {
	if (com == 1)
		cptStreet++;
	else if (com == 0)
		cptStreet--;
}

size_t				confirmedAddrs::getCurrentCitySize() {
	return (this->_City[this->_City.size() - 1].size());
}

size_t				confirmedAddrs::getCurrentStreetSize() {
	return (this->_Street[this->_Street.size() - 1].size());
}

std::string			&confirmedAddrs::getCurrentStreet() {
	return (this->_Street[this->cptStreet]);
}

std::string			&confirmedAddrs::getCurrentCity()
{
	return (this->_City[this->cptCity]);
}
