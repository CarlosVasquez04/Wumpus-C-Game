#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"


class Wumpus : public Event {
    protected:

    public:
        Wumpus();

        virtual ~Wumpus();

        /* 
		* name: get_event_symbol
		* description: returns the wumpus event symbol 
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual char get_event_symbol() const override;

        /* 
		* name: percepts
		* description: returns the wumpus event percept 
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual string percepts() const override;

        /* 
		* name: action 
		* description: runs the wumpus event actions
		* parameters: confused turns, has gold, died
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual void action(int&, bool&, bool&) override;

        /* 
		* name: is_it_wumpus 
		* description: checks if the event is wumpus 
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual bool is_it_wumpus() const override;
};
#endif