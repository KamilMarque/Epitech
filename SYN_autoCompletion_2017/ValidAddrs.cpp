//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

bool iequals(const std::string& str1, const std::string& str2)
{
    return std::equal(str1.begin(), str1.end(), str2.begin(), iequal());
}

ValidAddrs::ValidAddrs() {
}

ValidAddrs::~ValidAddrs() {
}

void		ValidAddrs::findLetter(std::string str) {
	size_t	pos = confAddrs.getCurrentCitySize();
	size_t	tmp = 0;

	if (pos > str.size() || str.empty() || isNotTheSameCityBegin(str)) {
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

void		ValidAddrs::resetLetter() {
	this->letter.clear();
	this->total.clear();
}

void			ValidAddrs::analyseCmd(std::string cmd, std::vector<Addr> &addrs, std::vector<std::string> &lines) {
	std::string	cmp = createCmpCity(cmd);

	int tmp = 0;
	for (std::vector<Addr>::iterator addr = addrs.begin();
	     addr != addrs.end(); ++addr)
	{
		if (!haveCommonCity(*addr, cmp)) {
			addr = addrs.erase(addr);
			--addr;
			lines.erase(lines.begin() + tmp);
			tmp--;
		}
		tmp++;
	}
	if (addrs.empty())
		exit(84);
	confAddrs.addCityLetter(cmd);
}

bool			ValidAddrs::haveOtherPartWordCity(Addr &addr, std::string cmd) {
	for (std::vector<std::string>::iterator partOfCity = addr.getCity().begin();
	     partOfCity != addr.getCity().end(); ++partOfCity) {
		if (!iequals(this->confAddrs.getCurrentCity(), *partOfCity) &&
		    iequals(this->confAddrs.getCurrentCity().substr(0, 1), cmd)) {
			return true;
		}
	}
	return false;
}

bool			ValidAddrs::isPossibleToCompleteCity(std::string cmd, std::vector <Addr> &addrs) {
	std::string cmp = createCmpCity(cmd);

	for (std::vector<Addr>::iterator addr = addrs.begin();
	     addr != addrs.end(); ++addr) {
		if (haveCommonCity(*addr, cmp)) {
			return true;
		}
	}
	return false;
}

void			ValidAddrs::analyseMoreCmd(std::string cmd, std::vector<Addr> &addrs, std::vector<std::string> &lines) {
	bool		already = false;

	if (isPossibleToCompleteCity(cmd, addrs)) {
		analyseCmd(cmd, addrs, lines);
		return;
	}
	int tmp = 0;
	for (std::vector<Addr>::iterator addr = addrs.begin();
	     addr != addrs.end(); ++addr) {
		if (haveOtherPartWordCity(*addr, cmd)) {
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
		this->confAddrs.getCity().push_back(cmd);
		this->confAddrs.updateCptCity(1);
	}
	if (addrs.empty())
		exit(84);
}
