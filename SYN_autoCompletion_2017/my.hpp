//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

struct iequal
{
        bool operator()(int c1, int c2) const
    {
        return std::toupper(c1) == std::toupper(c2);
    }
};

class Addr
{
private:
	std::vector<std::string>	_City;
	std::string			_Num;
	std::string			_Type;
	std::vector<std::string>	_Addr;

public:
	Addr();
	~Addr();
	void parsCity(std::string);
	void printCity();
	void printNum();
	void printType();
	void printAddr();
	void parsNum(std::string);
	void parsType(std::string);
	void parsAddr(std::string);
	std::vector<std::string> &getCity();
	std::string getNum();
	std::string getType();
	std::vector<std::string> &getStreet();
};

class confirmedAddrs
{
	std::vector<std::string>	_City;
	std::vector<std::string>	_Street;
	size_t				cptCity;
	size_t				cptStreet;
public:
	confirmedAddrs();
	~confirmedAddrs();
	std::vector<std::string> &getCity();
	std::vector<std::string> &getStreet();
	void updateCptCity(size_t);
	void updateCptStreet(size_t);
	void addCityLetter(std::string);
	void addStreetLetter(std::string);
	size_t getCurrentCitySize();
	size_t getCurrentCityStreet();
	size_t getCptCity();
	size_t getCurrentStreetSize();
	std::string &getCurrentStreet();
	std::string &getCurrentCity();
};


class ValidAddrs
{
	std::vector<std::string>	letter;
	std::vector<size_t>		total;
	confirmedAddrs			confAddrs;
	std::vector<Addr>		confProp;

public:
	ValidAddrs();
	~ValidAddrs();
	void findLetter(std::string);
	void findLetterStreet(std::string);
	void launchValidation(std::vector<Addr>&, std::vector<std::string>&);
	void completCity(Addr);
	void completStreet(Addr);
	void divideCity(std::vector<Addr>&);
	void divideStreet(std::vector<Addr>&);
	void launchCity(std::vector<Addr>&, std::vector<std::string>&);
	void printChoice(std::vector<std::string>, std::string);
	void launchStreet(std::vector<Addr>&, std::vector<std::string>&);
	void resetLetter();
	int isSameCity(std::vector<Addr>&);
	int isSameStreet(std::vector<Addr>&);
	void bubbleSort();
	void bubbleSortCity(size_t);
	void printFirstProp();
	void printFirstStreetProp(std::vector<std::string>&);
	std::string createCmpCity(std::string);
	std::string createCmpStreet(std::string);
	int haveCommonCity(Addr &, std::string);
	int haveCommonStreet(Addr &, std::string);
	void analyseCmd(std::string, std::vector<Addr>&, std::vector<std::string>&);
	void analyseCmdStreet(std::string, std::vector<Addr>&, std::vector<std::string>&);
	void printLastCity(std::vector<std::string>&);
	int isNotTheSameCityBegin(std::string);
	int isNotTheSameStreetBegin(std::string);
	bool checkFullName(std::vector<Addr>&);
	bool checkFullNameStreet(std::vector<Addr>&);
	std::string listFullName(std::vector<Addr>&, std::vector<std::string>&);
	std::string listFullNameStreet(std::vector<Addr>&, std::vector<std::string>&);
	void printChoice(std::vector<std::string>, std::string, size_t);
	bool isPossibleToCompleteCity(std::string, std::vector <Addr> &);
	bool isPossibleToCompleteStreet(std::string, std::vector <Addr> &);
	void analyseMoreCmd(std::string, std::vector <Addr> &, std::vector<std::string>&);
	void analyseMoreCmdStreet(std::string, std::vector <Addr> &, std::vector<std::string>&);
	bool haveOtherPartWordCity(Addr &, std::string);
	bool haveOtherPartWordStreet(Addr &, std::string);
	void printConfPropCity();
	void printConfPropStreet();
	void printMin(std::string);
	void printMax(std::string);
	void initConfProp(std::vector<Addr>&);
	void initConfPropStreet(std::vector<Addr>&);
	void eraseSameCityConfProp();
	void eraseSameStreetConfProp();
	bool isExactlyTheSameCity(std::vector<std::string>&, std::vector<std::string>&);
	void eraseCityNotConf(size_t, std::vector<Addr>&, std::vector<std::string>&);
	void eraseStreetNotConf(size_t, std::vector<Addr>&, std::vector<std::string>&);
	bool isAlpha(std::string);
};


class Root
{
private:
	std::vector<std::string>	err_add;
	std::vector<std::string>	lines;
	std::vector<Addr>		addrs;
	ValidAddrs			validAddrs;
	int				ver;
public:
	Root();
	~Root();
	int openFile(const char *);
	int checkLine(std::string);
	int printErr();
	int checkCity(std::string);
	int checkNum(std::string);
	int checkType(std::string);
	void createAddrs();
	Addr createAddr(std::string);
	void addCity(std::string);
};

bool iequals(const std::string& str1, const std::string& str2);
