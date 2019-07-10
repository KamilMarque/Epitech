//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

Root::Root() : validAddrs() {
	this->ver = 0;
}

Root::~Root() {
}

int				Root::checkLine(std::string str) {
	size_t			check = str.find(",");

	if (check > str.size() || check == 0 || str[0] == ' ') {
		this->err_add.push_back(str);
		return (-1);
	}
//	suppSpace(check);
	if (checkCity(str) == -1 || checkNum(str) == -1) {
		this->err_add.push_back(str);
		return (-1);
	}
	this->lines.push_back(str);
	return (0);
}

void                    ValidAddrs::launchValidation(std::vector<Addr> &addrs,
                                                     std::vector<std::string> &lines) {
        launchCity(addrs, lines);
	launchStreet(addrs, lines);
}

int				Root::openFile(const char *str) {
        std::ifstream		file(str);
        std::string		line;
	std::vector<Root>	infos;

        if (file) {
                while (getline(file, line))
                        if (checkLine(line) == -1)
				this->ver = -1;
		if (line.empty())
			return (84);
		if (this->ver == -1)
			printErr();
		createAddrs();
		this->validAddrs.launchValidation(this->addrs, this->lines);
		return (0);
	}
        return (84);
}

int				main(int ac, char **av) {
        Root			Root;

	if (ac == 2) {
		if (Root.openFile(av[1]) == 84)
			return (84);
		return (0);
	}
	return (84);
}
