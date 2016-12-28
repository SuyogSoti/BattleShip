#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include <vector>
#include "Ships.h"
#include <fstream>


class Player{
protected:
	std::string name;//name
	int turn;//what turn number the player is on for when this gets useful
	std::vector <Ships> sh;
	Ships cruz;
	Ships destroyer;
	Ships sub;
	Ships battle;
	Ships carrier;
	std::vector< std::vector<std::string> > myBoard; //makes the ships and the myBoard
	std::vector< std::vector<std::string> > oppWord;
	std::vector< std::vector<int> > already;
	void setName(std::string name);
	void setPlayer();\
	bool alreadyPlayed(std::vector<int> p);


public:
	class FileIO;
	Player(std::string paramName);
	Player();
	std::string getName();
	void printMyBoard();
	void printOppBoard();
	bool pick(int x, int y, bool hit);
	bool isHit(int x,int y);
	void setShipLocations();
	friend bool compareBoard(const Player &p1, const Player &p2);
	friend int win(const Player &p1, const Player &p2);
	void outPutBoards(std::string name);
};

#endif //PLAYER_H
