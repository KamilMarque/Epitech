//
// main.cpp for main in /home/cathal_n/EPITECH_YEAR_2/Trade
//
// Made by nicolas cathala
// Login   <cathal_n@epitech.net>
//
// Started on  Sun Jun 11 09:42:09 2017 nicolas cathala
// Last update Sun Jun 11 15:34:25 2017 nicolas cathala
//

#include "../include/trade.hh"

std::string	numb_tstr(int bought, std::string action)
{
  std::ostringstream sstr;

  sstr << bought;

  action = action + " " + sstr.str();
  if (bought == 0)
    return ("wait");
  return (action);
}

int	main()
{
  int		money = 0;
  unsigned int	day = 0;
  std::string	rent;

  std::cin >> money;

  Wallet	wallet(money);

  std::cin >> day;
  std::cin >> rent;
  wallet.bought = 0;
  wallet.append_rent(atol(rent.c_str()));
  std::cout << wallet.trade(atol(rent.c_str())) << std::endl;
  srandom(time(NULL));
  std::cin >> rent;
  day -= 1;

  while (rent != "--END--" && day > 0)
    {
      wallet.append_rent(atol(rent.c_str()));
      if (day == 1)
	{
	  std::cout << numb_tstr(wallet.bought, "sell") << std::endl;
	  break;
	}
      else
	std::cout << wallet.trade(atol(rent.c_str())) << std::endl;
      rent = "";
      std::cin >> rent;
      day--;
    }
  return (0);
}
