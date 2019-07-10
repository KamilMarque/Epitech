//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

int				Root::printErr() {
	size_t		i = 0;

	while (i < this->err_add.size()) {
		std::cerr << this->err_add[i++] << std::endl;
	}
	std::cerr << "Unknown address" << std::endl;
	if (lines.size() == 0)
		exit (84);
	return (84);
}

void				Addr::printCity() {
	for (size_t tmp = 0 ; tmp != this->_City.size() ; tmp++)
		std::cout << this->_City[tmp] << std::endl;
}

void				Addr::printAddr() {
	std::cout << "Addr : ";
	for (size_t tmp = 0 ; tmp != this->_Addr.size() ; tmp++)
		std::cout << this->_Addr[tmp] << std::endl;
}

void				Addr::printNum() {
	std::cout << "num == " << this->_Num << std::endl;
}

void				Addr::printType() {
	std::cout << "Type = " << this->_Type << std::endl;
}
