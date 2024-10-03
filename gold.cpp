#include <iostream>

#include "gold.h"

using namespace std;


Gold::Gold(){

}



Gold::~Gold(){

}



char Gold::get_event_symbol() const{
    return 'G';
}



string Gold::percepts() const{
    return "You see a glimmer nearby."; // returns the gold percept
}



void Gold::action(int& confused_turns, bool& has_gold, bool& died){
    has_gold = true; // sets the has_gold bool to true 
    cout << "You've found the gold!!! Make it back to the escape rope to win." << endl; 
}



bool Gold::is_it_wumpus() const {
    return false;
}