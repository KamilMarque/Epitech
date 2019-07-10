//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

std::vector<std::string>	&Addr::getCity() {
	return (this->_City);
}

std::string		Addr::getNum() {
 	return (this->_Num);
}

std::string		Addr::getType() {
 	return (this->_Type);
}
std::vector<std::string>		&Addr::getStreet() {
 	return (this->_Addr);
}
