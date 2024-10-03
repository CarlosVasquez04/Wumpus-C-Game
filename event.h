#ifndef EVENT_H
#define EVENT_H 

using namespace std;


class Event{
    protected:
   
    public:
        Event();

        virtual ~Event();

        /* 
		* name: get_event_fucntion
		* description: pure virutal fucntion to return corresponding event symbol
		* parameters: noen 
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual char get_event_symbol() const = 0;

        /* 
		* name: percepts
		* description: pure virtual fucntion to return correspoinding event percept
		* parameters: noen 
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual string percepts() const = 0;

        /* 
		* name: action
		* description: pure virtual fucntion to run corresponding event actions
		* parameters: confused_turns, has_gold, died 
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual void action(int&, bool&, bool&) = 0;

        /* 
		* name: is_it_wumpus
		* description: pure virtual fucntion to see if event is wumpus 
		* parameters: none
		* pre-condition: none
		* post-conditon: none 
		*/
        virtual bool is_it_wumpus() const = 0;
	
};
#endif