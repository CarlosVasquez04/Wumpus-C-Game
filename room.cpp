#include <iostream>

#include "room.h"

using namespace std;


Room::Room(){
    this -> occupied = false; 
    this -> starting_room = false;
    this -> is_player_here = false;
    this -> event = nullptr;
}



Room::~Room(){
    if (event != nullptr){ // checks if event ptr is null
        delete event; // deleted event ptr 
    }
}



Event* Room::get_event() const{
    return this -> event; // returns event ptr
}



bool Room::get_occupied() const { 
    return this -> occupied; // return occupied bool 
}



bool Room::get_is_player_here() const {
    return this -> is_player_here; // returns is_player_here bool
}



void Room::set_event(Event* new_event){
    this -> occupied = true; // marks the room as occupied  
    this -> event = new_event; // sets the event
}



void Room::set_starting_room(){
    this -> starting_room = true; // sets starting_room to true 
}



bool Room::get_starting_room() const{
    return this -> starting_room; // returns starting room
}



void Room::set_player(){
    this -> is_player_here = true; // sets is_player_here to true
}



void Room::remove_player(){
    this -> is_player_here = false; // sets is_player_here to false
}


void Room::remove_event(){
    if (this != nullptr){
        delete this -> event; // deletes event ptr
        this -> event = nullptr; // sets event ptr to null
    }
    this -> occupied = false; // sets occupied to false
}