/******************************************************
** Program: wumpus.cpp
** Author: Carlos vasquez
** Date: 11/30/2023
** Description: This program simulates a game called hunt the wumpus. In this game the player needs to 
		navigate a cave with obstacles in order to either kill the wumpus or retrive the gold and escape 
		the cave before being killed. 
** Input: cave lrngth, cave width, debug mode choice, shoot arrow, directiton, movement
** Output: none
******************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>


#include "game.h"

using namespace std;


int main(){
	srand(time(NULL)); //set the random seed
	
	int wid, len;
	bool debug;
	
	Game g(3, 0); // create game object using non default constructor

	g.game_inputs(wid, len, debug); // calls game member funciton to receive width, length, and debug inputs
	g.play_game(wid, len, debug); // calls game member function to run the game

	return 0;
}