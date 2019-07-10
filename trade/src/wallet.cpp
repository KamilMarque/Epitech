//
// wallet.cpp for wallet in /home/cathal_n/EPITECH_YEAR_2/Trade
//
// Made by nicolas cathala
// Login   <cathal_n@epitech.net>
//
// Started on  Sun Jun 11 10:20:20 2017 nicolas cathala
// Last update Sun Jun 11 15:31:44 2017 nicolas cathala
//

#include "../include/trade.hh"


void					Wallet::append_rent(long rent){
  list.push_back(rent);
}

double					Wallet::avg_list()const
{
  long double				avg = 0.0;

  for(unsigned int i = 0; i <= list.size(); i++)
    avg += (list[i] / list.size());
  return (avg);
}

int					Wallet::max_buy(long rent)
{
  if (rent + ((0.15 * rent)) == 0 || money == 0 || (money / (rent + ((0.15 * rent) / 100))) == 0)
    return (1);
  return (money / (rent + ((0.15 * rent) / 100)));
}

std::string				Wallet::trade(long rent)
{
  double				average = 0;
  long int				numb = (random()) % (max_buy(rent) + 1);

  std::cerr << numb << std::endl;
  average = avg_list();
  if (average >= rent && money >= numb * (rent + ((0.15 * rent)) / 100))
    {
      money -= numb * (rent + ((0.15 * rent) / 100));
      bought += numb;
      return (numb_tstr(numb, "buy"));
    }
  else if (average < rent && bought > 0 && numb <= bought)
    {
      money += numb * (rent - ((0.15 * rent) / 100));
      bought -= numb;
      return (numb_tstr(numb, "sell"));
    }
  return ("wait");
}
