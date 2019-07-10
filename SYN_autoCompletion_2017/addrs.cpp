//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

Addr::Addr() {
}

Addr::~Addr() {
}


void				Root::createAddrs() {
	for (std::vector<std::string>::iterator line = lines.begin();
	     line != lines.end(); ++line) {
		addrs.push_back(createAddr(*line));
	}
}

Addr				Root::createAddr(std::string str) {
	Addr			tmp;

	tmp.parsCity(str);
	tmp.parsNum(str);
	tmp.parsType(str);
	tmp.parsAddr(str);
	return (tmp);
}
