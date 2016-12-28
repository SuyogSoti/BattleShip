#include "Computer.h"

Computer::Computer() : Player("Computer") {
    this->turns = 0;
    this->direction = "";
}

void Computer::setShipLocations() {
    srand((unsigned int) time(NULL));
    for(int i = 0; i < this->sh.size(); i++){
        Ships *temp = &this->sh[i];
        temp->resetLocation();
        std::vector<int> points(2);
        while(true) {
            bool valid = true;
            std::cout << "Computer placing " << temp->getName() << " down" << std::endl;
            int x = rand() % 9;
            int y = rand() % 9;
            int direction = rand() % 3;
//            std::cout << "(" << x << ", " << y << ")" << std::endl;
//            std::cout << direction << std::endl;
            switch (direction) {
                case 0:
                    for (int j = 0; j < temp->getSize(); j++) {
                        int xDif = x-j;
                        if(xDif >= 10 or y >= 10 or xDif<0 or y<0 or this->myBoard[x - j][y] == "S"){
                            valid = false;
                        }
                    }
                    if(valid){
                        for (int j = 0; j < temp->getSize(); j++) {
                            points[0] = (x-j);
                            points[1] = (y);
                            this->myBoard[x-j][y] = "S";
                        }
                    }

                    break;
                case 1:
                    for (int j = 0; j < temp->getSize(); j++) {
                        int xDif = x+j;
                        if(xDif >= 10 or y >= 10 or xDif<0 or y<0 or this->myBoard[x + j][y] == "S"){
                            valid = false;
                        }
                    }
                    if(valid){
                        for (int j = 0; j < temp->getSize(); j++) {
                            points[0] = (x+j);
                            points[1] = (y);
                            this->myBoard[x+j][y] = "S";
                        }
                    }
                    break;
                case 2:
                    for (int j = 0; j < temp->getSize(); j++) {
                        int xDif = y-j;
                        if(xDif >= 10 or x >= 10 or xDif<0 or x<0 or this->myBoard[x][y-j] == "S"){
                            valid = false;
                        }
                    }
                    if(valid){
                        for (int j = 0; j < temp->getSize(); j++) {
                            points[0] = (x);
                            points[1] = (y-j);
                            this->myBoard[x][y-j] = "S";
                        }
                    }
                    break;
                case 3:
                    for (int j = 0; j < temp->getSize(); j++) {
                        int xDif = y+j;
                        if(xDif >= 10 or x >= 10 or xDif<0 or x<0 or this->myBoard[x][y+j] == "S"){
                            valid = false;
                        }
                    }
                    if(valid){
                        for (int j = 0; j < temp->getSize(); j++) {
                            points[0] = (x);
                            points[1] = (y+j);
                            this->myBoard[x][y+j] = "S";
                        }
                    }
                    break;
                default:
                    break;
            }
            if(valid) break;
        }
        temp->addPoints(points);
    }
}

std::vector<int> Computer::pick() {
//    TODO: go back to see if its can still go down if the program is going up
    std::vector<int> p;
    if((this->direction.length() == 0)){
        p.resize(2);
        srand((unsigned int) time(NULL));
        p[0] = (rand()%9);
        p[1] = (rand()%9);
        while(this->alreadyPlayed(p)){
            p[0] = (rand()%9);
            p[1] = (rand()%9);
        }
    }else if(this->direction == "up"){
        p = this->already.back();
        p[0] -= 1;
    }else if(this->direction == "down"){
        p = this->already.back();
        p[0] += 1;
    }else if(this->direction == "left"){
        p = this->already.back();
        p[1] -= 1;
    }else if(this->direction == "right"){
        p = this->already.back();
        p[1] += 1;
    }
    if (this->alreadyPlayed(p)){
        this->direction = "";
        p = pick();
    }
    this->already.push_back(p);
    return p;
}

void Computer::adjustBoard(std::vector<int> p, bool hit) {
    int x = p[0];
    int y = p[1];
    if(hit){
        if(turn == 0){
            turn += 1;
            if(x > 1){
                this->direction = "up";
            }else{
                this->direction = "down";
            }
            this->tried.push_back(this->direction);
        }else if(turn == 4){
            this->turn = 0;
            this->direction = "";
            this->tried.resize(0);
        }
    }else{
        if(this->direction == "up" and x < 8){
            this->direction = "down";
            this->tried.push_back(this->direction);
        }else if(this->direction == "down" and y>1){
            this->direction = "left";
            this->tried.push_back(this->direction);
        }else if(this->direction == "left" and y<8){
            this->direction = "right";
            this->tried.push_back(this->direction);
        }else{
            turn = 0;
            this->direction = "";
            this->tried.resize(0);
        }
    }
}
