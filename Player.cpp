#include "Player.h"

Player::Player(std::string paramName) : cruz("Cruiser", 3), destroyer("Destroyer", 2), carrier("Carrier", 5),
										battle("Battleship", 4), sub("Submarine", 3){
	setName(paramName);
	setPlayer();
}
// just returns player name
std::string Player::getName(){
	return this->name;
}

void Player::printMyBoard(){
	for (std::vector<std::string> v : this->myBoard){
		for(std::string s : v){
			std::cout << s << "  ";
		}
		std::cout << std::endl;
	}
}

bool compareBoard(const Player &p1, const Player &p2) {
	return p1.myBoard == p2.myBoard;
}

Player::Player() : Player::Player("John Doe"){
}

void Player::setName(std::string name) {
	this->name = name;
}

void Player::setShipLocations() {
	for(int i = 0; i < this->sh.size(); i++){
		Ships *temp = &this->sh[i];
		int x, y;
		std::string tempCoord;
//        runs until it gets a valid center that is not on top of another ship
        std::cout << "You are setting the location for " << temp->getName() << std::endl;
        std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
        std::vector<int> points(2);
        bool redo;
        while(true) {
            this->printMyBoard();
            redo = false;
            std::cout << "Please pick a start for the ship" << std::endl;
            std::cout << "In what row do you want this ship to start?" << std::endl;
            std::getline(std::cin, tempCoord);
            x = atoi(tempCoord.c_str());
            std::cout << "In what Column do you want this ship to start?" << std::endl;
            std::getline(std::cin, tempCoord);
            y = atoi(tempCoord.c_str());
            std::cout << "Please specify direction with the keywors 'up', 'left', 'right', 'down'" << std::endl;
            std::cout << "Please note that the entry has to match exactly the words from the line above" << std::endl;
            std::getline(std::cin, tempCoord);
            if(x <1 or y<1 or x> 10 or y>10){
                std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
                std::cout << "Please note that 1 <= x <= 10 and 1 <= y <= 10" << std::endl;
                continue;
            }
            if (tempCoord == "up") {
                std::cout << "You entered up!" << std::endl;
                if (x <= (temp->getSize() - 1)) {
                    std::cout << "Your ship does not fit on the myBoard if it start at this position and goes up"
                              << std::endl;
                    std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
                    continue;
                }
//                I have to do a double for loop and sacrifice efficiency so that it is not being witten as it is being checked
// TODO: What is wrong with adding the points here? --I forget
                for (int j = 0; j < (temp->getSize()); j++) {
                    if (this->myBoard[x - 1 - j][y - 1] == "S") {
                        redo = true;
                        break;
                    }
                }
                if (!redo){
                    for (int j = 0; j < (temp->getSize()); j++) {
                        points[0] = x - j;
                        points[1] = y;
                        this->myBoard[x - 1 - j][y - 1] = "S";
                    }
                }
            } else if (tempCoord == "down") {
                std::cout << "You entered down!" << std::endl;
                if (x > (11 - temp->getSize())) {
                    std::cout << "Your ship does not fit on the myBoard if it start at this position and goes down"  << std::endl;
                    std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
                    continue;
                }
                for (int j = 0; j < (temp->getSize()); j++) {
                    if (this->myBoard[x + j - 1][y - 1] == "S") {
                        redo = true;
                        break;
                    }
                }
                if(!redo){
                    for (int j = 0; j < (temp->getSize()); j++) {
                        points[0] = x + j;
                        points[1] = y;
                        this->myBoard[x + j - 1][y - 1] = "S";
                    }
                }
            } else if (tempCoord == "left") {
                std::cout << "You entered left!" << std::endl;
                if (y <= (temp->getSize() - 1)) {
                    std::cout << "Your ship does not fit on the myBoard if it start at this position and goes left"
                              << std::endl;
                    std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
                    continue;
                }
                for (int j = 0; j < (temp->getSize()); j++) {
                    if (this->myBoard[x - 1][y - 1 - j] == "S") {
                        redo = true;
                        break;
                    }
                }
                if(!redo){
                    for (int j = 0; j < (temp->getSize()); j++) {
                        points[0] = x;
                        points[1] = y - j;
                        this->myBoard[x - 1][y - 1 - j] = "S";
                    }
                }
            } else if (tempCoord == "right") {
                std::cout << "You entered right!" << std::endl;
                if (y > (11 - temp->getSize())) {
                    std::cout << "Your ship does not fit on the myBoard if it start at this position and goes right"
                              << std::endl;
                    std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
                    continue;
                }
                for (int j = 0; j < (temp->getSize()); j++) {
                    if (this->myBoard[x - 1][y - 1 + j] == "S") {
                        redo = true;
                        break;
                    }
                }
                if(!redo){
                    for (int j = 0; j < (temp->getSize()); j++) {
                        points[0] = x;
                        points[1] = y + j;
                        this->myBoard[x - 1][y - 1 + j] = "S";
                    }
                }

            } else {
                std::cout << "You did not specify one of the directions listed above...please enter your start again and specify the directions" << std::endl;
                continue;
            }
            if(!redo){
                break;
            }else{
                std::cout << "Either your center or the direction you chose makes it so that you overlap with another one for your own ships"
                          << std::endl;
                std::cout << "Remeber the " << temp->getName() << " has size: " << temp->getSize() << std::endl;
            }
        }
        temp->addPoints(points);
	}
    this->printMyBoard();
}

void Player::setPlayer() {
	int size = 10;
	this->turn = 0;
	for (int i = 0; i < size; i++){
		std::vector<std::string> a;
		for(int j = 0; j < size; j++){
			a.push_back("-");
		}
		this->myBoard.push_back(a);
        this->oppWord.push_back(a);
	}
	this->sh.push_back(this->destroyer);
	this->sh.push_back(this->sub);
	this->sh.push_back(this->cruz);
	this->sh.push_back(this->battle);
	this->sh.push_back(this->carrier);
}

bool Player::isHit(int x, int y){
	if(x > 0 and y>0 and x<=10 and y<= 10){
		if(this->myBoard[x-1][y-1] == "S"){
            this->myBoard[x-1][y-1] = "X";
			return true;
        }else if(this->myBoard[x-1][y-1] == "X"){

        }else{
            this->myBoard[x-1][y-1] = "0";
        }
	}
	return false;
}

int win(const Player &p1, const Player &p2) {
    int ans1 = 1, ans2 = 1;
    for(int i = 0; i < p2.myBoard.size(); i++){
        for(int j = 0; j < p2.myBoard.size(); j++){
            if(p2.myBoard[i][j] == "S")
                ans1 = 0;
            if(p1.myBoard[i][j] == "S")
                ans2 = 0;

        }
    }
    if(ans1 == 1){
        return 1;
    }
    if(ans2 == 1){
        return 2;
    }
    return 0;
}

bool Player::pick(int x, int y, bool hit) {
    std::vector<int> p;
    p.push_back(x);
    p.push_back(y);
    if(x<1 or y<1 or x>10 or y >10 or this->alreadyPlayed(p))
        return false;
    this->already.push_back(p);
    if(hit){
        this->oppWord[x - 1][y - 1] = "X";
    }else{
        this->oppWord[x - 1][y - 1] = "0";
    }
    return true;
}

void Player::printOppBoard() {
    for (std::vector<std::string> v : this->oppWord){
        for(std::string s : v){
            std::cout << s << "  ";
        }
        std::cout << std::endl;
    }
}

bool Player::alreadyPlayed(std::vector<int> p) {
    for(std::vector<int> v : this->already){
        if (v == p){
            return true;
        }
    }
    return false;
}
class Player::FileIO{
private:
    std::ofstream file;
public:
    FileIO(std::string name){
        file.open(name.c_str());
    }
    ~FileIO(){
        file.close();
    }
    void PrintBoard(std::vector<std::vector <std::string>> b){
        for (std::vector<std::string> v : b){
            for(std::string s : v){
                file << s << "  ";
            }
            file<< "\n" << std::endl;
        }
    }

};

void Player::outPutBoards(std::string name) {
    FileIO f(name.c_str());
    f.PrintBoard(this->myBoard);
}
