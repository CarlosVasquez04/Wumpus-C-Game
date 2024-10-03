#include <iostream>

#include "wumpus.h"

using namespace std;


Wumpus::Wumpus(){

}



Wumpus::~Wumpus(){

}



char Wumpus::get_event_symbol() const{
    return 'W';
}



string Wumpus::percepts() const {
    return "You smell a terrible stench.";
}



void Wumpus::action(int& confused_turns, bool& has_gold, bool& died) {
    cout << "You entered the Wumpus' cave. You didn't make it. Game Over!" << endl; 
    died = true; // player death is true
}



bool Wumpus::is_it_wumpus() const {
    return true;
}