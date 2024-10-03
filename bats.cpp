#include <iostream>

#include "bats.h"

using namespace std;


Bats::Bats(){

}



Bats::~Bats(){

}



char Bats::get_event_symbol() const {
    return 'B';
}



string Bats::percepts() const {
    return "You hear wings flapping.";
}



void Bats::action(int& confused_turns, bool& has_gold, bool& died){
    confused_turns = 5;
    cout << "You encountered super bats. You are confused for the next 5 turns." << endl;
}



bool Bats::is_it_wumpus() const {
    return false;
}