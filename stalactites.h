#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"


class Stalactites : public Event {
    protected:
       
    public:
        Stalactites();

        virtual ~Stalactites();
        
        /* 
		* name: get_event_symbol 
		* description: returns stalactites event symbol
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual char get_event_symbol() const override;

        /* 
		* name: percepts
		* description: returns the stalactites evnent percept 
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual string percepts() const override;

        /* 
		* name: action 
		* description: runs the stacltites event actions
		* parameters: confused turns, has gold, died
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
