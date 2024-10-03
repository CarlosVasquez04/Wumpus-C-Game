#ifndef BATS_H
#define BATS_H 


#include "event.h"

//Bats Interface
class Bats : public Event {
    protected:
    
    public:
        Bats();

        virtual ~Bats();

        /* 
		* name: get_event_type
		* description: virtual funciton to return bats event symbol
		* parameters: none 
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual char get_event_symbol() const override;

        /* 
		* name: percepts
		* description: virtual fucniton to return bats event percept
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual string percepts() const override;

        /* 
		* name: action 
		* description: virtual fucntion that carries out bats actions
		* parameters: confused_turns, has_gold, died
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual void action(int&, bool&, bool&) override;
        
        /* 
		* name: is_it_wumpus 
		* description: none 
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual bool is_it_wumpus() const override;

};

#endif