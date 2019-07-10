/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "my.hpp"

int                     ValidAddrs::isNotTheSameStreetBegin(std::string str) {
        std::string     tmp = str.substr(0, confAddrs.getCurrentStreetSize());

        if (!iequals(tmp, confAddrs.getCurrentStreet()))
                return (1);
        return (0);
}

void            ValidAddrs::findLetterStreet(std::string str) {
        size_t  pos = confAddrs.getCurrentStreetSize();
        size_t  tmp = 0;

        if (pos > str.size() || str.empty() || isNotTheSameStreetBegin(str)) {
                return;
        }
        for (std::vector<std::string>::iterator l = this->letter.begin();
             l != this->letter.end(); ++l) {
                std::transform(str.begin(), str.end(), str.begin(), ::tolower);
                if ((*l)[0] == str[pos]) {
                        this->total[tmp]++;
                        return ;
                }
                tmp++;
        }
        std::string newStr = str.substr(pos, 1);
        std::transform(newStr.begin(), newStr.end(), newStr.begin(), ::tolower);
        this->letter.push_back(newStr);
        this->total.push_back(1);
}

int                     ValidAddrs::isSameStreet(std::vector<Addr> &addrs) {
        std::vector<std::string>        reformatedStreet;

        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                std::string tmp = "";
                for (std::vector<std::string>::iterator partOfStreet = (*addr).getStreet().begin();
                     partOfStreet != (*addr).getStreet().end(); ++partOfStreet) {
                        if (tmp != "")
                                tmp += " ";
                        tmp += (*partOfStreet);
                }
                reformatedStreet.push_back(tmp);
        }
        for (std::vector<std::string>::iterator street = reformatedStreet.begin();
             street != reformatedStreet.end() - 1; ++street){
                if (!iequals(*street, *(street + 1))) {
                        // std::cout << (*city) << "-" << (*(city + 1)) << std::endl;
                        return (0);
                }
        }
        return (1);
}

void                    ValidAddrs::completStreet(Addr addr) {
        for (std::vector<std::string>::iterator street = addr.getStreet().begin();
             street != addr.getStreet().end(); ++street)
                findLetterStreet(*street);
}

void                    ValidAddrs::divideStreet(std::vector<Addr> &addrs) {
        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                completStreet(*addr);
        }
}

std::string             ValidAddrs::createCmpStreet(std::string cmd) {
        std::string     ret = "";

        ret += confAddrs.getCurrentStreet() + cmd;
        return ret;
}

int                     ValidAddrs::haveCommonStreet(Addr &addr, std::string cmp) {

        for (std::vector<std::string>::iterator partOfStreet = addr.getStreet().begin();
             partOfStreet != addr.getStreet().end(); ++partOfStreet)
        {
                if ((*partOfStreet).size() >= cmp.size() &&
                    (iequals(cmp, (*partOfStreet).substr(0, cmp.size())))) {
                        return (1);
                }
        }
        return (0);
}

void                    ValidAddrs::analyseCmdStreet(std::string cmd, std::vector<Addr> &addrs, std::vector<std::string> &lines) {
        std::string     cmp = createCmpStreet(cmd);
        int tmp = 0;
        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr)
        {
                if (!haveCommonStreet(*addr, cmp)) {
                        addr = addrs.erase(addr);
                        --addr;
                        lines.erase(lines.begin() + tmp);
                        tmp--;
                }
                tmp++;
        }
        if (addrs.empty())
                exit(84);
        confAddrs.addStreetLetter(cmd);
}

bool                    ValidAddrs::checkFullNameStreet(std::vector<Addr> &addrs){
        for (std::vector<Addr>::iterator addr = addrs.begin() ; addr != addrs.end() ;
             ++addr) {
                for (std::vector<std::string>::iterator partOfCity = (*addr).getStreet().begin() ;
                     partOfCity != (*addr).getStreet().end(); ++partOfCity) {
                        if (iequals(*partOfCity, confAddrs.getCurrentStreet()))
                                return true;
                }
        }
        return false;
}

void                    ValidAddrs::initConfPropStreet(std::vector<Addr> &addrs) {
        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                for (std::vector<std::string>::iterator partOfCity = (*addr).getStreet().begin();
                     partOfCity != (*addr).getStreet().end(); ++partOfCity){
                        if (iequals(*partOfCity, confAddrs.getCurrentStreet())) {
                                confProp.push_back(*addr);
                        }
                }
        }
}

void                    ValidAddrs::eraseSameStreetConfProp() {
        for (std::vector<Addr>::iterator addr = confProp.begin();
             addr != confProp.end(); ++addr) {
                std::vector<Addr>::iterator next = addr + 1;

                while (next != confProp.end()) {
                        if (isExactlyTheSameCity((*addr).getStreet(), (*next).getStreet())) {
                                next = confProp.erase(next);
                                next--;
                        }
                        next++;
                }
        }
}

void                    ValidAddrs::eraseStreetNotConf(size_t idx, std::vector<Addr> &addrs, std::vector<std::string> &lines) {
        int tmp = 0;
        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                if (!isExactlyTheSameCity((*addr).getStreet(), confProp[idx - 1].getStreet())) {
                        addr = addrs.erase(addr);
                        addr--;
                        lines.erase(lines.begin() + tmp);
                        tmp--;
                }
                tmp++;
        }
}


std::string             ValidAddrs::listFullNameStreet(std::vector<Addr> &addrs, std::vector<std::string> &lines) {
        std::string cmd = "";

        initConfPropStreet(addrs);
        //eraseSameStreetConfProp();
        printConfPropStreet();
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
        eraseStreetNotConf(test, addrs, lines);
        return "";
}

void			ValidAddrs::launchStreet(std::vector<Addr> &addrs,
                                               std::vector<std::string> &lines) {
	        std::string     command = "";

		resetLetter();
        while (isSameStreet(addrs) == 0) {
                divideStreet(addrs);
                bubbleSort();
                if (letter.size() != 1) {
                        if (command == "") {
                                printFirstStreetProp(addrs[0].getCity());
                                std::cin >> command;
                                if (command.empty())
                                        exit (0);
                        }
                        analyseCmdStreet(command, addrs, lines);
                        command = "";
                }
                else {
                        confAddrs.addStreetLetter(letter[0]);
                }
                resetLetter();
                while (checkFullNameStreet(addrs)) {
                        std::string ok = listFullNameStreet(addrs, lines);
                        if (ok != "") {
                                analyseMoreCmdStreet(ok, addrs, lines);
                        }
                confProp.clear();
                }
        }
        if (addrs.size() == 1) {
                printLastCity(lines);
        }
}

bool                    ValidAddrs::isPossibleToCompleteStreet(std::string cmd, std::vector <Addr> &addrs)\
 {
        std::string cmp = createCmpStreet(cmd);

        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                if (haveCommonStreet(*addr, cmp)) {
                        return true;
                }
        }
        return false;
}

bool                    ValidAddrs::haveOtherPartWordStreet(Addr &addr, std::string cmd) {
        for (std::vector<std::string>::iterator partOfCity = addr.getStreet().begin();
             partOfCity != addr.getStreet().end(); ++partOfCity) {
                if (!iequals(this->confAddrs.getCurrentStreet(), *partOfCity) &&
                    iequals(this->confAddrs.getCurrentStreet().substr(0, 1), cmd)) {
                        return true;
                }
        }
        return false;
}

void                    ValidAddrs::analyseMoreCmdStreet(std::string cmd, std::vector<Addr> &addrs, std::vector<std::string> &lines) {
        bool            already = false;

        if (isPossibleToCompleteStreet(cmd, addrs)) {
                analyseCmdStreet(cmd, addrs, lines);
                return;
        }
        int tmp = 0;
        for (std::vector<Addr>::iterator addr = addrs.begin();
             addr != addrs.end(); ++addr) {
                if (haveOtherPartWordStreet(*addr, cmd)) {
                        already = true;
                } else {
                        addr = addrs.erase(addr);
                        addr--;
                        lines.erase(lines.begin() + tmp);
                        tmp--;
                }
                tmp++;
        }
        if (already) {
                this->confAddrs.getStreet().push_back(cmd);
                this->confAddrs.updateCptStreet(1);
        }
        if (addrs.empty())
                exit(84);
}

void                    ValidAddrs::printConfPropStreet() {
        int             cpt = 0;

        for (std::vector<Addr>::iterator addr = confProp.begin();
             addr != confProp.end() && cpt != 2; ++addr) {
                cpt++;
                std::cout << "{" << cpt << " : ";
		for (std::vector<std::string>::iterator part = (*addr).getCity().begin();
		     part != (*addr).getCity().end(); ++part) {
			printMax(*part);
			if (part + 1 != (*addr).getCity().end())
                                std::cout << " ";
		}
		std::cout << ", " << (*addr).getNum() << " " << (*addr).getType() << " ";
for (std::vector<std::string>::iterator partOfCity = (*addr).getStreet().begin();
                     partOfCity != (*addr).getStreet().end(); ++partOfCity) {
                        if (iequals(*partOfCity, confAddrs.getCurrentStreet())) {
                                printMax(confAddrs.getCurrentStreet());
                        }
                        else {
                                printMin(*partOfCity);
                        }
                        if (partOfCity + 1 != (*addr).getStreet().end())
                                std::cout << " ";
                }
                std::cout << "}";
                if (cpt != 2)
                        std::cout << " ";
        }
        std::cout << std::endl;
}
