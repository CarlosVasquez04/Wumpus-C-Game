#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 

#include "room.h"



using namespace std;


class Game {
	private:
		int length; 			//length of the board
		int width;  			//width of the board
		int num_arrows; 		//keep track of number of errors remaining
		bool debug_view;		//debug mode or not

		int player_row;			//current player row	
		int player_col;			//current player column

		bool has_gold;			//keeps track whether player has gold
		int confused_turns;		//keeps track of number of confused turns
		bool died;				//kkeps track if player has died
		bool wumpus_dead;		//keeps track whether player killed wumpus

		vector <vector <Room> > cave; 		//cave of rooms (grid of rooms)
		
	public:
		Game();

		Game(int, int);
		
		~Game();
		
		/* 
		* name: length_width_inputs
		* description: asks users for length/width inputs and handles any errors in input
		* parameters: length, width
		* pre-condition: none
		* post-conditon: none 
		*/
		void length_width_inputs(int& , int& );

		/* 
		* name: game_inputs
		* description: calls length_width_inputs function. Then asks player for debug choice input
				and handles any errors in the input
		* parameters: length, width, debug choice
		* pre-condition: none 
		* post-conditon: none 
		*/
		void game_inputs(int&, int&, bool&);

		/* 
		* name:rand_insert_wumpus, rand_insert_gold, rand_insert_bats, rand_insert_stalactites 
		* description: receives cave length/width and generates a random room coordinate. It then checks 
				if the room if is empty. If the room is empty it then creates the event object in that room.
				If room has an event then it generates another random coordinate.
		* parameters: cave lenth, cave width
		* pre-condition: 2d cave vector has been allocated
		* post-conditon: wumpus object is created in a room within the cave
		*/
		void rand_insert_wumpus(int, int);
		void rand_insert_gold(int, int);
		void rand_insert_bats(int, int);
		void rand_insert_stalactites(int, int);

		/* 
		* name: rand_insert_events
		* description: calls fucntions to insert events into random empty rooms within the 2d vector cave 
		* parameters: cave length, cave width
		* pre-condition: 2d vector has been allocated
		* post-conditon: all events are inserted within the cave
		*/
		void rand_insert_events(int, int);

		/* 
		* name: set_player_location
		* description: sets player_row and player_col game class member variables
		* parameters: row, column
		* pre-condition: none 
		* post-conditon: player_row and player_col are set
		*/
		void set_player_location(int, int);

		/* 
		* name: rand_insert_player
		* description: generates random coordinate within the cave that doesnt contain an event. It then calls 
				room class member function to set player in that room. Then it calls the se_player_location 
				game class menber function to set player_row  and player_col
		* parameters: cave length, cave width
		* pre-condition: 
		* post-conditon: 
		*/
		void rand_insert_player(int, int);

		/* 
		* name: set_up
		* description: sets sets length and width game class member varibles. Then it resizes the 2D vector to have row = length
				and col = width. It then creates a room object in every place. After this it calls fucntions to set the events and 
				then the player. 
		* parameters: cave length, cave width
		* pre-condition: user has inputed length and width
		* post-conditon: cave 2d vector contains rooms with events and players set
		*/
		void set_up(int, int);

		/* 
		* name: display_symbols
		* description: checks if a room contains an event. If it does it displays the corresponding symbol
		* parameters: row, col
		* pre-condition: player and events are set
		* post-conditon:  none
		*/
		void display_symbols(int, int) const;

		/* 
		* name: display_game
		* description: dysplays the game board
		* parameters: none 
		* pre-condition: cave 2d vector contains rooms, and player and evets are set
		* post-conditon: none 
		*/
		void display_game() const;

		/* 
		* name: check_win
		* description: Checks if players has either killed the wumpus or retrived the gold and made it to the escape rope
		* parameters: none
		* pre-condition: none
		* post-conditon:  none
		*/
		bool check_win() const;

		/* 
		* name: output_percepts
		* descripiton: checks all rooms adjacent to current player locations for any events. If there are any events then it 
				calls the function to diplay the corresponding percept.
		* parameters: none
		* pre_conditions: none
		* post-conditon: none
		*/
		void output_percepts();

		/* 
		* name: event_actions
		* description: checks if current player location contains any events. If it does then it calls the fucntion to carry out 
				the corresponding actions
		* parameters: confused turns, has gold, and died
		* pre-condition: none
		* post-conditon:  none
		*/
		void event_actions(int &, bool&, bool&);

		/* 
		* name: move_up, move_down, move_left, move_right
		* description: moves player and check that the new locations is within the boundaries. If the new row is within
				the bounds then it calls function to remove player from old room and the calls the fucntion to set player in 
				the new room
		* parameters: none 
		* pre-condition: user has inputted valid movement input 
		* post-conditon: none
		*/
		void move_up();
		void move_down();
		void move_left();
		void move_right();

		/* 
		* name: move
		* description: recieves user movement input and calls coresponding function
		* parameters: movement input
		* pre-condition: user inputted movement input
		* post-conditon:  none
		*/
		void move(char);

		/* 
		* name: get_dir
		* description: asks user to input direction for arrow and makes sure the input is valid. If its not it outputs 
				an error message and asks for a new input. 
		* parameters: none 
		* pre-condition: user has chosen to shoot an arrow
		* post-conditon: user inputs valid arrow direction
		*/
		char get_dir();

		/* 
		* name: wumpus_movement
		* description: GEnerates random coordinate wihtin cave that is empty. Then it creates a new wumpus in the new room and deletes the 
				wumpus in the old room. 
		* parameters: none
		* pre-condition: none
		* post-conditon: none
		*/
		void wumpus_movement();

		/* 
		* name: wumpus_movement
		* description: generates a number from 0 - 3. If the number is not 0 the it calls a function to move the wumpus
		* parameters: nont 
		* pre-condition: user has missed an arrow shot
		* post-conditon: none
		*/
		void wumpus_move();

		/* 
		* name: arrow_up, arrow_down, arrow_left, arrow_right
		* description: shoots arrow through 3 rooms and checks if the wumpus is in any of those rooms. If it is then it sets the the 
				wumpus_dead game class member variable to true
		* parameters: player row, player col 
		* pre-condition: none
		* post-conditon: none
		*/
		void arrow_up(int, int);
		void arrow_down(int, int);
		void arrow_left(int, int);
		void arrow_right(int, int);

		/* 
		* name: arrow_movement
		* description: receives arrow direction and calls corresponding function
		* parameters: arrow diresction
		* pre-condition: user has inputted arrow direction
		* post-conditon: noen
		*/
		void arrow_movement(char);

		/* 
		* name: fire_arrow
		* description: checks if user still has arrows. If they do then it calls funciton to get arrow direction and 
				the calls funciton to handle arrow movement
		* parameters: none
		* pre-condition: user chose to fire an arrow
		* post-conditon: none
		*/
		void fire_arrow();

		/* 
		* name: get_input
		* description: gets user movement input and calls corresponding fucntion
		* parameters: none
		* pre-condition: user inputted movement input
		* post-conditon: none
		*/
		char get_input();

		/* 
		* name: handle_confused
		* description: flips movement input
		* parameters: confused_turns, movemnt input
		* pre-condition: none
		* post-conditon: none
		*/
		void handle_confused(int& , char&);

		/* 
		* name: play_game
		* description: calls fucntion to set up the game. Then it loops through game functions until user either wins or dies. 
		* parameters: length, width, debug choice
		* pre-condition: none 
		* post-conditon: player died or won
		*/
		void play_game(int, int, bool);



};

#endif