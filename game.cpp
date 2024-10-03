#include <iostream>
#include <vector>



#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"


using namespace std;


Game::Game(){

}



Game::Game(int arrows, int confused_t) : cave(0, vector<Room>(0)){
	this -> length = 0;
	this -> width = 0;
	this -> num_arrows = arrows;
	this -> debug_view = false;
	this -> player_row = 0;
	this -> player_col = 0;
	this -> has_gold = false;
	this -> confused_turns = confused_t;
	this -> died = false;
	this -> wumpus_dead = false;
}



Game::~Game(){

}



void Game::length_width_inputs(int& l, int& w){
	do{
		cout << "Enter game board length: ";
		cin >> l; // user inputs length of game board 

		if (l > 50 || l < 1){// error message if input is out of bounds
			cout << "Invalid input" << endl;
		}
	} while (l > 50 || l < 1);// check user input is in bounds


	do{
		cout << "Enter game board width: ";
		cin >> w; // user inputs width of game board

		if (w > 50 || w < 1){// error message if input is out of bounds
			cout << "Invalid input" << endl;
		}
	} while (w > 50 || w < 1); // check user input is in bounds
}



void Game::game_inputs(int& l, int& w, bool& debug){
	this -> length_width_inputs(l,w); // call funtion to recieve length and width inputs

	int debug_input = 10; 

	do{
		cout << "Debug mode (1 - yes, 0 - no): ";
		cin >> debug_input; // user inputs choice of debug mode

		if (debug_input > 1 || debug_input < 0){// error message if input is 1 or 0
			cout << "Invalid input" << endl;
		}
	} while (debug_input > 1 || debug_input < 0);// check user input is 1 or 0

	debug = debug_input; // assigns either true (1) or false (0) to debug mode 
}



void Game::rand_insert_wumpus(int l, int w){
	int row, col;

	do{
		row = rand() % l; // generates random row
		col = rand() % w; // generates random column 
	} while (cave[row][col].get_occupied()); // checks to see if room has event already

	cave[row][col].set_event(new Wumpus()); // calls function within room to set up wumpus
}



void Game::rand_insert_gold(int l, int w){
	int row, col;

	do{
		row = rand() % l; // generates random row
		col = rand() % w; // generates random column 
	} while (cave[row][col].get_occupied()); // checks to see if room has event already

	cave[row][col].set_event(new Gold()); // calls function within room to set up gold
}



void Game::rand_insert_bats(int l, int w){
	for (int i = 0; i < 2; i++){
		int row, col;

		do{
			row = rand() % l; // generates random row
			col = rand() % w; // generates random column 
		} while (cave[row][col].get_occupied()); // checks to see if room has event already

		cave[row][col].set_event(new Bats()); // calls function within room to set up bats
	}
}



void Game::rand_insert_stalactites(int l, int w){
	for (int i = 0; i < 2; i++){
		int row, col;

		do{
			row = rand() % l; // generates random row
			col = rand() % w; // generates random column 
		} while (cave[row][col].get_occupied()); // checks to see if room has event already

		cave[row][col].set_event(new Stalactites()); // calls function within room to set up stalactites
	}
}



void Game::rand_insert_events(int l, int w){
	this -> rand_insert_wumpus(l, w);
	this -> rand_insert_gold(l, w);
	this -> rand_insert_bats(l, w);
	this -> rand_insert_stalactites(l, w);
}



void Game::set_player_location(int row, int col){
	this -> player_row = row;
	this -> player_col = col;
}



void Game::rand_insert_player(int l, int w){
	int row, col;

	do{
		row = rand() % l; // generates random row
		col = rand() % w; // generates random column 
	} while (cave[row][col].get_occupied()); // checks to see if room has an event
	cave[row][col].set_starting_room(); // calls function to mark starting room

	cave[row][col].set_player(); // calls function to set player in room
	this -> set_player_location(row, col); // calls function to set player_row and player_col
}



void Game::set_up(int l, int w){
	this->length = l;
	this->width = w;

	this->num_arrows = 3; 	//start with 3 arrows

	cave.resize(l, vector<Room>(w)); // rezize cave to have l rows, where each row is a vector of w columns

	for (int i = 0; i < l; i++){ // loops through rows of cave
		for (int j = 0; j < w; j++){ // loops through columns of cave
			this -> cave[i][j] = Room(); // creates a room in cave
		}
	}
	this -> rand_insert_events(l, w); // call function to insert events into random rooms
	this -> rand_insert_player(l, w); // calls function to insert player at random room with no events
}



void Game::display_symbols(int i, int j) const{
	if (cave[i][j].get_is_player_here()){ // check if player is in room
		cout << "*"; 
	}
	else {
		cout << " ";
	}

	if (cave[i][j].get_occupied()){ // checks if room has an event
		if (this -> debug_view){ // checks if game is in debug mode
			cout << cave[i][j].get_event() -> get_event_symbol(); // gets evnet type in that room and call corresponding function to return symbol 
		}
		else{
			cout << " ";
		}
	}
	else {
		cout << " ";
	}
	cout << " ||";
}



void Game::display_game() const{
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl; // ouputs remaining arrows
	
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";

	for (int i = 0; i < this->length; ++i){
		cout << line << endl;

		for (int j = 0; j < this->width; ++j)
		{
			this -> display_symbols(i, j); // calls function to display events and player locations
		}
		cout << endl;
	}
	cout << line << endl;
}



bool Game::check_win() const{
	if (this -> has_gold == true){
		bool starting_room;

		for (int i = 0; i < this -> length; i++){
			for (int j = 0; j < this -> width; j++){
				starting_room = cave[i][j].get_starting_room();

				if (starting_room == true && i == this -> player_row && j == this -> player_col){
					cout << endl <<"You have escaped the cave with the gold!!!! YOU WIN !!!!!" << endl;
					return true;
				}
			}
		}
	}

	if (this -> wumpus_dead){
		cout << endl << "You've slain the wumpus !!!! YOU WIN !!!!" << endl;
		return true;
	}

	return false;
}



void Game::output_percepts(){
	int row = this -> player_row;
	int col = this -> player_col;

	if (row - 1 >= 0 && row - 1 < this -> length){ // checks if adjacent room is within bounds/exists
		if (cave[row - 1][col].get_occupied()){ // checks if room above has an event
			cout << cave[row - 1][col].get_event() -> percepts() << endl; // gets event type and calls function to output percept 
		}
	}

	if (row + 1 >= 0 && row + 1 < this -> length) {
		if (cave[row + 1][col].get_occupied()){ // checks if room below has an event
			cout << cave[row + 1][col].get_event() -> percepts() << endl; // gets event type and calls function to output percept 
		}
	}

	if (col - 1 >= 0 && col -1 < this -> width){ 
		if (cave[row][col - 1].get_occupied()){ // checks if room to the left has an event
			cout << cave[row][col - 1].get_event() -> percepts() << endl; // gets event type and calls function to output percept 
		}
	}

	if (col + 1 >= 0 && col + 1 < this -> width){ 
		if (cave[row][col + 1].get_occupied()){ // checks if room to the right has an event
			cout << cave[row][col + 1].get_event() -> percepts() << endl; // gets event type and calls function to output percept 
		}
	}
}



void Game::event_actions(int& confused_turns, bool& has_gold, bool& died) {
	int row = this->player_row;
	int col = this->player_col;

	if (cave[row][col].get_occupied()){ // checks if the current room has an event
		cave[row][col].get_event() -> action(confused_turns, has_gold, died); // gets event type and calls corresponding action function
	}

	if (this -> has_gold == true){
		cave[row][col].remove_event();
	}
}



void Game::move_up() {
	this -> player_row -= 1; // moves player up a row

	if ((this -> player_row < 0) || (this -> player_row >= this -> length)){ // checks if new row is out of bouds
		cout << endl << "!! OUT OF BOUNDS !!" << endl;
		this -> player_row += 1; // returns player_row back to what it was
		return;
	}

	else {
		cave[player_row + 1][player_col].remove_player(); // removes player from old room
		cave[player_row][player_col].set_player(); // sets player in new room
	}

	return;
}



void Game::move_down() {
	this -> player_row += 1; //moves player down a row

	if ((this -> player_row < 0) || (this -> player_row >= this -> length)){ // checks if new row is out of bouds
		cout << endl << "!! OUT OF BOUNDS !!" << endl;
		this -> player_row -= 1; // returns player_row back to what it was
		return;
	}

	else {
		cave[player_row - 1][player_col].remove_player(); //removes player from old room 
		cave[player_row][player_col].set_player(); // sets player in new room
	}
	return;
}



void Game::move_left() {
	this -> player_col -= 1;

	if ((this -> player_col < 0) || (this -> player_col >= this -> width)){ // checks if new column is out of bouds
		cout << endl << "!! OUT OF BOUNDS !!" << endl;
		this -> player_col += 1; // returns player_col back to what it was
		return;
	}

	else {
		cave[player_row][player_col + 1].remove_player(); // removes player form old room
		cave[player_row][player_col].set_player(); // sets player in new room 
	}
	return;
}



void Game::move_right() {
	this -> player_col += 1;

	if ((this -> player_col < 0) || (this -> player_col >= this -> width)){ // checks if new column is out of bouds
		cout << endl << "!! OUT OF BOUNDS !!" << endl;
		this -> player_col -= 1; // returns player_col back to what it was
		return;
	}

	else {
		cave[player_row][player_col - 1].remove_player(); // removes player from old room 
		cave[player_row][player_col].set_player(); // sets player in new room
	}
	return;
}



char Game::get_dir(){
    char dir;

    do {
        cout << endl << "Fire an arrow...." << endl;
        cout << "w - up" << endl;
        cout << "a - left" << endl;
        cout << "s - down" << endl;
        cout << "d - right" << endl;

        cout << "Enter direction: ";
        cin >> dir; // receives input
        cin.ignore(256, '\n');

        if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd') { // checks if input is invalid
            cout << "Invalid direction. Please enter w, a, s, or d." << endl;
        }
    } while (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');

    return dir;
}



void Game::wumpus_movement(){
	int new_row, new_col;

	do{
		new_row = rand() % this -> length; // generates random row
		new_col = rand() % this -> width; // generates random column 
	} while (cave[new_row][new_col].get_occupied() && cave[new_row][new_col].get_is_player_here()); // checks to see if room has event already
	
	bool wumpus = false;

	for (int row = 0; row < this -> length; row++){
		for (int col = 0; col < this -> width; col++){
			if (cave[row][col].get_occupied()){ // checks if the current room has an event
				wumpus = cave[row][col].get_event() -> is_it_wumpus(); // checks if event is wumpus

				if (wumpus){
					cave[row][col].remove_event();
				}
			}
		}
	}

	cave[new_row][new_col].set_event(new Wumpus()); // calls function within room to set up wumpus
	cout << endl << "The Wumpus moved to a different room!" << endl;
}



void Game::wumpus_move(){
	int rand_num = rand() % 4; // generate random num from 0 - 3 and sets it to rand 

	if (rand_num != 0){ // 75% chance of making wumpus move
		this -> wumpus_movement(); // calls function to handle the wumpus movement
	}

	else {
		cout << endl << "The Wumpus did not move." << endl;
	}
	
	return;
}



void Game::arrow_up(int row, int col){
	for (int i = 1; i < 4; i++){
		row -= i;

		if (row >= 0){ // checks that row exists
			if (cave[row][col].get_occupied()){ // checks if the current room has an event
				this -> wumpus_dead = cave[row][col].get_event() -> is_it_wumpus(); // sets wumpus_dead to true if event in that room is wumpus
			}
		}
	}
}



void Game::arrow_down(int row, int col){
	for (int i = 1; i < 4; i++){
		row += i;

		if (row < this -> length){ // checks that row exists
			if (cave[row][col].get_occupied()){ // checks if the current room has an event
				this -> wumpus_dead = cave[row][col].get_event() -> is_it_wumpus(); // sets wumpus_dead to true if event in that room is wumpus
			}
		}
	}
}



void Game::arrow_left(int row, int col){
	for (int i = 1; i < 4; i++){
		col -= i;

		if (col >= 0){ // checks that row exists
			if (cave[row][col].get_occupied()){ // checks if the current room has an event
				this -> wumpus_dead = cave[row][col].get_event() -> is_it_wumpus(); // sets wumpus_dead to true if event in that room is wumpus
			}
		}
	}
}



void Game::arrow_right(int row, int col){
	for (int i = 1; i < 4; i++){
		col += i;

		if (col < this -> width){ // checks that row exists
			if (cave[row][col].get_occupied()){ // checks if the current room has an event
				this -> wumpus_dead = cave[row][col].get_event() -> is_it_wumpus(); // sets wumpus_dead to true if event in that room is wumpus
			}
		}
	}
}



void Game::arrow_movement(char d){
	int row = this -> player_row;
	int col = this -> player_col;
	
	if (d == 'w'){
		this -> arrow_up(row, col);
	}
	
	else if (d == 's'){
		this -> arrow_down(row, col);
	}

	else if (d == 'a'){
		this -> arrow_left(row, col);
	}

	else if (d == 'd'){
		this -> arrow_right(row, col);
	}

	if (this -> wumpus_dead == false){ // checks if arrow missed wumpus
		this -> wumpus_move(); // calls function to make wumpus move
	}
}



void Game::fire_arrow(){
	if (this -> num_arrows > 0){
		char dir = get_dir(); // calls get_dir function and sets it to dir variable
		this -> arrow_movement(dir); // calls function to handle the arrow movement
		this -> num_arrows -= 1;
	}

	else {
		cout << endl << "You are out of arrows" << endl;
	}

	return;

}



void Game::move(char c) {
	// Handle player's action: move or fire an arrow
	if (c == 'f'){
		Game::fire_arrow();
		return;
	}
	switch(c){
		case 'w':
			Game::move_up();
			break;
		case 'a':
			Game::move_left();
			break;
		case 's':
			Game::move_down();
			break;
		case 'd':
			Game::move_right();
			break;
	}
}



char Game::get_input(){
    char c;

    do {
        cout << endl << endl << "Player move..." << endl << endl;
        cout << "w - up" << endl;
        cout << "a - left" << endl;
        cout << "s - down" << endl;
        cout << "d - right" << endl;
        cout << "f - fire an arrow" << endl;

        cout << "Enter input: ";
        cin >> c; // receives input
        cin.ignore(256, '\n');

        if (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f') { //checks if invalid input 
            cout << endl << "Invalid input" << endl;
        }
    } while (c != 'w' && c != 'a' && c != 's' && c != 'd' && c != 'f');

    return c;
}



void Game::handle_confused(int& confused_turn, char& input){
	if (confused_turn > 0){
		if (input == 'w'){
			input = 's';
		}
		else if (input == 's'){
			input = 'w';
		}
		else if (input =='a'){
			input = 'd';
		}
		else if (input == 'd'){
			input = 'a';
		}
		confused_turns -= 1;
	}
}



void Game::play_game(int w, int l, bool d){
	Game::set_up(w, l); // calls game member function to set up the game object
	
	this->debug_view = d;
	char input, arrow_input;
	int x = 0;

	while (Game::check_win() == false){
		Game::display_game(); // calls function to display game

		this -> output_percepts(); // calls functin to check/output precepts

		this -> event_actions(this -> confused_turns, this -> has_gold, this -> died); // calls function to check/perform event actions

		if (this -> died == true){ // checks if the player died after the event
			break; // exits the loop if player did die
		}
		
		if (Game::check_win() == true){ // checks if player has won 
			break; // breaks from loop if player has won 
		}

		input = Game::get_input(); // uses function to receive and return the user input

		this -> handle_confused(confused_turns, input); // calls function to check/perform confused movement 

		Game::move(input);
		x++;
	}
	return;
}