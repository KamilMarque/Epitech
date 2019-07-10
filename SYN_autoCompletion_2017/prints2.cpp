//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

void            ValidAddrs::printLastCity(std::vector<std::string> &lines) {
	std::cout << "=> " << lines[0] << std::endl;
	exit(0);
}

void            ValidAddrs::printFirstProp() {
        size_t i = 0;
        std::string tmp2;

        for (std::vector<std::string>::iterator tmp = this->letter.begin();
             tmp != this->letter.end(); ++tmp) {
                tmp2 = confAddrs.getCity()[0];
                std::transform(tmp2.begin(), tmp2.end(),tmp2.begin(), ::toupper);
                std::cout << "{" << tmp2 << (*tmp) << "}";
                if (i == 4 || tmp + 1 == this->letter.end())
                        break ;
                else
                        std::cout << " ";
                i++;
        }
        std::cout << std::endl;
}

void            ValidAddrs::printFirstStreetProp(std::vector<std::string> &city) {
        size_t i = 0;
        std::string tmp2;

        for (std::vector<std::string>::iterator tmp = this->letter.begin();
             tmp != this->letter.end(); ++tmp) {
                tmp2 = confAddrs.getStreet()[0];
                std::transform(tmp2.begin(), tmp2.end(),tmp2.begin(), ::toupper);
                std::cout << "{";
		for (std::vector<std::string>::iterator part = city.begin();
		     part != city.end(); ++part) {
			printMax(*part);
			std::cout << " ";
		}
		std::cout << ", " << tmp2 << (*tmp) << "}";
                if (i == 4 || tmp + 1 == this->letter.end())
                        break ;
                else
                        std::cout << " ";
                i++;
        }
        std::cout << std::endl;
}
