//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

int			Root::checkCity(std::string str) {
	size_t		i = 0;

	while (str[i] != ',') {
		if (str[i] >= '0' && str[i] <= '9')
			return (-1);
		i++;
	}
	return (0);
}

int                     Root::checkType(std::string str) {
	std::string     tmp = str.substr(0, str.find(" "));

	if (tmp != "allée" && tmp != "avenue" && tmp != "boulevard"
	    && tmp != "chemin" && tmp != "impasse" && tmp != "place"
            && tmp != "quai" && tmp != "rue" && tmp != "square") {
		return (-1);
	}
        return (0);
}

int                     Root::checkNum(std::string str) {
        size_t          i = 0;

        while (str[i] != ',')
                i++;
        i = i + 2;
        while (str[i] != 0 && str[i] != ' ') {
                if (str[i] >= '0' && str[i] <= '9')
                        i++;
                else
                        return (-1);
        }
        i++;
        if (checkType(&str[i]) == -1)
                return (-1);
        return (0);
}
