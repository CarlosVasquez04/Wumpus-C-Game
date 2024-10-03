#ifndef GOLD_H
#define GOLD_H 

#include "event.h"

//Gold Interface
class Gold : public Event {
    protected:
    
    public:
        Gold();

        virtual ~Gold();

        /* 
		* name: get_event_symbol
		* description: return gold event symbol
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual char get_event_symbol() const override;

        /* 
		* name: percepts
		* description: returns gold event percept
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual string percepts() const override;
        
        /* 
		* name: action 
		* description: carries out gold event actions
		* parameters: condused turns, has_gold, died
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