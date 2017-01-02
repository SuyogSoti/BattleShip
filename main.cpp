#include <iostream>
#include <cstdlib>
#include "Player.h"
#include "Computer.h"

using namespace std;

int main(){
    cout << "Welcome to the BattleShip" << endl;
    cout << "Would you like to give your name or remain Anonymous" << endl;
    string ans;
    cout << "Type 0 to be anonymous and 1 to give your name" << endl;
    getline(cin, ans);
    vector<Player> p;
    if(ans == "0"){
        cout << "You chose to be anonymous!" << endl;
        Player human;
        p.push_back(human);
    }else if (ans == "1"){
        cout << "Type your name" << endl;
        getline(cin, ans);
        Player human(ans);
        p.push_back(human);
    }else{
        cout << "Please answer properly" << endl;
        main();
    }
    Player human = p[0];
    cout << human.getName() << endl;
    cout << "This is what your myBoard looks like" << endl;
    human.printMyBoard();
    human.setShipLocations();
    Computer comp;
    comp.setShipLocations();
    if(compareBoard(human, comp)){
        comp.setShipLocations();
    }
    cout << "The computer is ready to play you" << endl;
    int turn = 0;
//    comp.printMyBoard();
    while(win(human, comp) == 0){
        bool valid = false;
        bool hit = false;
        while(!valid) {
            cout << turn << endl;
            cout << "Pick the row that you want to attck" << endl;
            string temp;
            int x, y;
            getline(cin, temp);
            x = atoi(temp.c_str());
            cout << "Pick the column that you want to attck" << endl;
            getline(cin, temp);
            y = atoi(temp.c_str());
            hit = comp.isHit(x, y);
            valid = human.pick(x, y, hit);
            if(!valid){
                cout << "Your entry was out of bounds or you have already entered these coordinates.. Please try again..." << endl;
            }
        }
        if(hit){
            cout << "Congrats! You hit a ship!" << endl;
        }else{
            cout << "Sorry you missed, but try again after your opponent!" << endl;
        }
        vector<int> p = comp.pick();
        cout << "the Computer picked: ("<<p[0] << ", " << p[1] << ")" << endl;
        comp.adjustBoard(p,human.isHit(p[0]+1, p[1]+1));
        cout << "Here is your Board!" << endl;
        human.printMyBoard();
        cout << "Here is your Opponent's Board!" << endl;
        human.printOppBoard();
//        comp.printMyBoard();
        turn++;

    }
    if(win(human, comp) == 1){
        cout << "Congrats! you beat the game!" << endl;
    }else{
        cout << "Sorry, you lost the game! Better luck next time!" << endl;
    }
    cout << "Here is your Board!" << endl;
    human.printMyBoard();
    cout << "Here is your Opponent's Board from your point of view!" << endl;
    human.printOppBoard();
    cout << "Here is your Opponent's Board!" << endl;
    comp.printMyBoard();
    cout << "This board is saved to the results file" << endl;
    comp.outPutBoards("results.txt");
    if(win(human, comp) == 1){
        cout << "Congrats! you beat the game!" << endl;
    }else{
        cout << "Sorry, you lost the game! Better luck next time!" << endl;
    }
    return 0;
}