#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;


class Room {
    private: 
        bool occupied;              // bool to keep track of if event is in this room 
        bool starting_room;         // bool to keep track of starting room 
        bool is_player_here;        // bool to keep track of if player is in this room
        Event* event;               // Pointer to the associated event
    public:
        Room();

        ~Room();
        
        /* 
		* name: get_event
		* description: returns event ptr
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        Event* get_event() const;

        /* 
		* name: get_occupied
		* description: returns occupied bool
		* parameters: none 
		* pre-condition: none
		* post-conditon: none 
		*/
        bool get_occupied() const;

        /* 
		* name: get_is_player_here
		* description: returns is_player_here
		* parameters: none 
		* pre-condition: none
		* post-conditon: none 
		*/
        bool get_is_player_here() const;

        /* 
		* name:set_event 
		* description: sets event ptr to event passed and then sets occupied bool to true
		* parameters: new_event
		* pre-condition: none
		* post-conditon: none 
		*/
        void set_event(Event* new_event);

        /* 
		* name: set_starting_room
		* description: sets staritng_room to true
		* parameters: noen 
		* pre-condition: none
		* post-conditon: none 
		*/
        void set_starting_room();
        
        /* 
		* name: get_starting_room  
		* description: returns starting_room bool
		* parameters: noen 
		* pre-condition: none
		* post-conditon: none 
		*/
        bool get_starting_room() const ;

        /* 
		* name: set_player
		* description: sets is_player_here to true
		* parameters: noen 
		* pre-condition: none
		* post-conditon: none 
		*/
        void set_player();

        /* 
		* name: remove_player 
		* description: sets is_player_herr to false
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        void remove_player();

        /* 
		* name: remove_event
		* description: deletes event ptr and sets it to null. Then is sets occupied bool to false 
		* parameters: none 
		* pre-condition: none
		* post-conditon: none 
		*/
        void remove_event();

};


#endif