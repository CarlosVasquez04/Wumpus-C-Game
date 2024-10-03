#include <iostream>

#include "stalactites.h"

using namespace std;


Stalactites::Stalactites(){

}



Stalactites::~Stalactites(){

}



char Stalactites::get_event_symbol() const {
    return 'S';
}



string Stalactites::percepts() const {
    return "You hear water dripping.";
}



void Stalactites::action(int& confused_turns, bool& has_gold, bool& died){
    cout << "You've encountered stalactites! Watch out!" << endl;
    
    int outcome = rand() % 2; // Generate a random number (0 or 1) to represent the 50% chance

    if (outcome == 0) {
        cout << "You narrowly avoided the stalactites. Lucky!" << endl;
    } else {
        died = true; // player death is true
        cout << "A stalactite fell on you. You didn't make it. Game Over!" << endl; 
    }
}



bool Stalactites::is_it_wumpus() const {
    return false;
}