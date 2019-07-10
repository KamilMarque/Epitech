//
// trade.hh for trade in /home/cathal_n/EPITECH_YEAR_2/Trade/include
//
// Made by nicolas cathala
// Login   <cathal_n@epitech.net>
//
// Started on  Sun Jun 11 09:46:26 2017 nicolas cathala
// Last update Sun Jun 11 15:11:44 2017 nicolas cathala

#ifndef TRADE_HH_//
# define TRADE_HH_

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <time.h>

class Wallet
{

private:
  long	money;
  std::vector<long> list;

public:
  int	bought;

  Wallet(long _money) : money(_money) {  }

  ~Wallet() { }

  void		append_rent(long);
  std::string   trade(long);
  double	avg_list()const;
  int		max_buy(long);
};

std::string		numb_tstr(int, std::string);

#endif /* !TRADE_HH_ */

