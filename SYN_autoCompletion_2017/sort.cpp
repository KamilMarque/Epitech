//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include "my.hpp"

void				ValidAddrs::bubbleSortCity(size_t i) {
        std::string		tmp;

        if (letter[i][0] > letter[i + 1][0]) {
                tmp = letter[i].substr(0, letter[i].size());
                total[i] += total[i + 1];
                letter[i] = letter[i + 1];
                total[i + 1] = total[i] - total[i + 1];
                letter[i + 1] = tmp;
                total[i] -= total[i + 1];
        }
}

void				ValidAddrs::bubbleSort() {
        bool			swap = true;
        std::string		tmp = "";

        while(swap) {
                swap = false;
                for (size_t i = 0; i < this->total.size() -1; i++) {
                        if (total[i] < total[i + 1]) {
                                tmp = letter[i].substr(0, letter[i].size());
                                total[i] += total[i + 1];
                                letter[i] = letter[i + 1];
                                total[i + 1] = total[i] - total[i + 1];
                                letter[i + 1] = tmp;
                                total[i] -= total[i + 1];
                                swap = true;
                        }
                        if (total[i] == total[i + 1]) {
                                bubbleSortCity(i);
                        }
                }
        }
}
