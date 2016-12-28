#ifndef COMPUTER_H
#define COMPUTER_H

#include "Player.h"


class Computer : public Player {
private:
    std::string direction;
    int turns;
    std::vector<std::string> tried;
public:
    Computer();
    void setShipLocations();
    std::vector<int> pick();
    void adjustBoard(std::vector<int>, bool);
};


#endif //COMPUTER_H