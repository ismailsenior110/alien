#include "Game_Board.h"
#include "helper/helper.cpp"
#include <vector>
#include <iostream>
#include <cstdlib> // for system()
#include <ctime> // for time() 
#include <iomanip> // for setw()
#include <fstream>


using namespace std;

 void Game_Board::init(int dimX, int dimY,int zombie)
 {
 	
   dimX_ = dimX;
   dimY_ = dimY;
   zombie_ = zombie;
   char objects[] = {' ','^', 'V', '<', '>', 'p', 'r', 'h'}; 
   int noOfObjects = 8; // number of game objects in the objects array
   
   char zombie_objects[] = {'1','2', '3', '4', '5', '6', '7', '8','9'}; // zombie objects array
   
   // create dynamic 2D array using vector for the game board
   map_.resize(dimY_); // create empty game  rows
   for (int i = 0; i < dimY_; ++i) 
   {
    map_[i].resize(dimX_); // resize each row
   }
   
   // put random characters into the game board with alien in the middle of the board
   for (int i = 0; i < dimY_; ++i)
   {
     for (int j = 0; j < dimX_; ++j)
     {
       int objNo = rand() % noOfObjects;
       map_[i][j] = objects[objNo];
     }
   }
   
   // place the alien in the middle of the game board
   middle_row = map_.size()/2;
   middle_column = map_[0].size()/2;
   
   

   // generating the rows an columns to place the zombie on the game board
   int row, column;
   int counter = 0;
   for(int k = 0; k<zombie_;k++){
   	do{
   	  do{
   	  	 
   	     column = 0 + (rand() % dimX_);
   	     row = 0 +  (rand() % dimY_);
	   }
	   while(row != middle_row && column != middle_column);
	   counter++;
	   }
	   while(counter<zombie_);
   
       // placing zombie on game board
      map_[row][column] = zombie_objects[k];
      
   }
   //placing the in the middle of the gamboard 
   map_[middle_row][middle_column] = 'A';
   
   // Generating the alien life and attack and zombies life, attack and range randomly respectively. 
   alien_life =  1 + (rand() % 100); 
   alien_attack = 0; 
   
}

void Game_Board:: show_game_board(){
	
    cout<<"Alien vs Zombies"<<endl<<endl;
    // for each row in game board 
    int counter =1;
    for (int i = 0; i < dimY_; ++i)
    {
     // display upper border of the row
      cout << " ";
      for (int j = 0; j < dimX_; ++j)
     {
       cout << "+-";
     }
      cout << "+" << endl;
      // display row number
      cout<< setw(2) << counter;
      // display cell content and border of each column
      for (int j = 0; j < dimX_; ++j)
       {
           cout << "|" << map_[i][j];
       }
         cout << "|" << endl;
         counter++;
       }
        // display lower border of the last row
         cout << " ";
       for (int j = 0; j < dimX_; ++j)  
       {
        cout << "+-";
       }
         cout << "+" << endl;
         // display column number
         cout<<" ";
        for (int j = 1; j <=  dimX_; ++j)
        {
        	cout<<j;
        }  
        cout<<endl<<endl;
        cout<<"Alien life: "<<alien_life<<"   "<<"Alien attack: "<<alien_attack<<endl;
//        for(int i=0; i<zombie_; i++){
//           	cout<<"Zombie life"<< i + 1 <<":  "<<zombie_life[i]<<"   "<<"Zombie attack: "<<zombie_attack[i]<<"   "<<"Range: "<<zombie_range[i]<<endl;
//		}       
        cout<<endl;
  }
  void Game_Board :: move_up(){
  	if(target_row > 0 ){
  	map_[target_row][target_column] = '.';
  	map_[target_row - 1][target_column] = 'A';
   }	
  }
  
  void Game_Board :: move_down(){
  if (target_row < map_.size() - 1) {
  	map_[target_row][target_column] = '.';
  	map_[target_row + 1][target_column] = 'A';
  }	
  }
  
 void Game_Board :: move_right(){
  if (target_column < map_[target_row].size() - 1) {
  	map_[target_row][target_column] = '.';
  	map_[target_row][target_column + 1] = 'A';
  }
  	
  }
   void Game_Board :: move_left(){
  if (target_column> 0 && target_column < map_[target_row].size() - 1) {
  	map_[target_row][target_column] = '.';
  	map_[target_row][target_column - 1] = 'A';
   }	
  }
  
  
  void Game_Board :: move_specified_direction(int target_row,int target_column, string direction){
  	target_row = target_row - 1;
  	target_column = target_column - 1;
  if ( (target_row >= 0 && target_row < map_.size() - 1) && (target_column >= 0 && target_column < map_[target_row].size() - 1)) {
  	if(direction == "up"){
  		 map_[target_row][target_column] = '^';
	  }
	  else if(direction == "down"){
	  	map_[target_row][target_column] = 'V';
	  }
	  else if(direction == "right"){
	  	map_[target_row][target_column] = '>';	
	  	cout<< map_[target_row][target_column]<<"at row and column"<<target_row + 1<<"     "<<target_column + 1<<"  change to right "<<endl;
	  }
	  else if(direction == "left"){
	  	 map_[target_row][target_column] = '<';
	  }
	  else{
	  	cout << "Invalid direction" << endl;
	  }
	  }
   else{
   	cout<<"The number of row and column exceeds the game board "<<endl;
   }
  }
  
  
void  Game_Board :: set_target_row_column(){
  	 for (int i = 0; i < dimY_; ++i)
     {
     for (int j = 0; j < dimX_; ++j)
     {
       if(map_[i][j] == 'A'){
       	  target_row = i;
       	  target_column = j;
	   }
     }
   }
  }
  void Game_Board :: save (string filename){
  	std :: ofstream out("save.txt");
   for (int i = 0; i < dimY_; ++i)
   {
     for (int j = 0; j < dimX_; ++j)
     {
     	out << i << ' ';
      
     }
     out <<"\n";
   }
   out.close();
  }
  
  
  
string Game_Commands :: set_command()
{
	cout<<"Enter Command: ";
	cin>>choice;
	return choice;
	
}

void  Game_Commands :: game_commands(string command){
//object of th e class to always display the menu for user
	Game_Commands game_command; // creating the class object
	// user commands choice in the game respective action 
	Helper helper; // helper class object to clear screen and pause program execution 
	Game_Board game_board;
	if(command == "up"){
	    game_board.set_target_row_column();
     	game_board.move_up();
     	helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "down"){
	    game_board.set_target_row_column();
     //	game_board.move_down();
     	helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "left"){
	    game_board.set_target_row_column();
     	//game_board.move_left();
     	helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "right"){
	    game_board.set_target_row_column();
     	//game_board.move_right();
     	helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "arrow"){
		int row,column;
		string direction;
		cout<<"Enter the row and column of arrow followed by direction to switch seprated by space"<<endl;
		cin>>row>>column>>direction;
     	helper.Pause();
        helper.ClearScreen();
       // game_board.move_specified_direction(row, column, direction);
        game_board.show_game_board();
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "help"){
		cout<<"Below are the game commands with meaning: "<<endl;
		cout<<"up :  Alien to move up"<<endl;
		cout<<"down: Alien to move down"<<endl;
		cout<<"left: Alien to move left"<<endl;
		cout<<"right: Alien to move right"<<endl;
		cout<<"arrow: Switch the direction of an arrow object in the game board"<<endl;
		cout<<"help: List and describe the commands that the player can use in the game"<<endl;
		cout<<"save: Save the current game to a file"<<endl;
		cout<<"load: Load a saved game from a file"<<endl;
		cout<<"quit: Quit the game while still in play."<<endl;
		helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "save"){
		string filename;
		cout<<"Enter the file to save game: ";
		cin>>filename;
		//calling save function here with filename argument
		helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
	     //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "load"){
		string filename;
		cout<<"Enter the file to load game: ";
		cin>>filename;
		game_board.save(filename);
		//calling load function here with filename argument
		helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "quit"){
		char decision;
		cout<<"Are you sure you want to quit the game (y/n): ";
		cin>>decision;
		if(decision == 'y'){
			exit(1);
		}
		else if(decision =='n'){
		//calling save function here with filename argument
		helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
		}
		else{
			cout<<"You enter wrong choice"<<endl;
			//calling save function here with filename argument
	    	helper.Pause();
            helper.ClearScreen();
            game_board.show_game_board();
		     //calling the function to allow user to perform another action
	        string select = game_command.set_command();
	        // processing the user command 
         	game_command.game_commands(select);
		}
	}
	else{
		cout<<"You enter wrong command"<<endl;
		//calling save function here with filename argument
		helper.Pause();
        helper.ClearScreen();
        game_board.show_game_board();
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
}
 

  
  
  
