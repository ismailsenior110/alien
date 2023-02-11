#include "Game_Board.cpp"
#include "helper/helper_menu.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime> // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;
class Menu
{
private:
char choice; // user choice
int num_rows, num_columns,num_zombies; // Required parameters of the game
public:
void welcome_msg();
//void set_row_column_zombies(int _row, int _column, int _zombies);
void display();
bool is_odd_number(int num);
};

void Menu:: welcome_msg()
{
 cout<<"Welcome Alien Path Game"<<endl;
 cout<<"------------------------------"<<endl;
 cout<<endl;
 cout<<"Do you want to continue with the  defaut game setting (y/n)"<<endl;
 display();
}
void Menu::display()
{
  // object of game command to get user command 
  Game_Commands game_command;
  Menu menu;
  // object of helper class to pause game and clear screen
  Helper_Menu helper;
  cin>>choice;
  helper.Pause();
  helper.ClearScreen();
 if(choice == 'y'){
 	
 	// generate random number of rows and column for game board
 	// both the row and column must be odd number respectively;
 	do{
 		num_rows =  1 + (rand() % 10);
		num_columns = 1 + (rand() % 10);
		num_zombies = 1 + (rand() % 9);
	 }
	 while(is_odd_number(num_rows) == 0 || is_odd_number(num_columns) == 0);
	 
	cout<<"Default Game Setting"<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"Number of columns: "<<num_rows<<endl;
    cout<<"Number of rows: "<<num_columns<<endl;
    cout<<"Number of zombies: "<<num_zombies<<endl;
    cout<<endl;
    helper.Pause();
    helper.ClearScreen();
 	srand(1); //fixed map 
    srand(time(NULL)); //random map
 	Game_Board game_board;
    game_board.init(num_rows,num_columns,num_zombies);
    game_board.show_game_board();
    string command = game_command.set_command();
   	game_command.game_commands(command);
 }
 else if(choice == 'n'){
 	cout<<endl;
 	cout<<"Game Board Settings"<<endl;
 	cout<<"Enter the number of columns:  ";
 	cin>>num_rows;
 	cout<<"Enter the number of rows: ";
 	cin>>num_columns;
 	cout<<"Enter the number of zombies:  ";
 	cin>>num_zombies;
 	helper.Pause();
    helper.ClearScreen();
 	if(is_odd_number(num_rows) && is_odd_number(num_columns)){
 		srand(1); 
        srand(time(NULL)); 
        // create game board if both column and row numbers are odd
 	    Game_Board game_board;
        game_board.init(num_rows,num_columns,num_zombies);
        game_board.show_game_board();
        string command = game_command.set_command();
     	game_command.game_commands(command);
	 }
	 else{
	    cout<<"The number of rows and columns must be odd"<<endl;
	    do{
		  cout<<"Enter the number of columns:  ";
     	  cin>>num_rows;
    	  cout<<"Enter the number of rows: ";
          cin>>num_columns;
          cout<<"The number of rows and columns must be odd"<<endl;
		}
		while(is_odd_number(num_rows) == 0 || is_odd_number(num_columns) == 0);
		helper.Pause();
        helper.ClearScreen();
		srand(1); 
        srand(time(NULL)); 
        // create game board if both column and row numbers are odd
 	    Game_Board game_board;
        game_board.init(num_rows,num_columns,num_zombies);
        game_board.show_game_board();
        string command = game_command.set_command();
    	game_command.game_commands(command);
	 }
 }
 else{
 	cout<<"Wronged input play with default settings"<<endl;
 	cout<<"------------------------------"<<endl;
    cout<<"Number of columns: "<<num_rows<<endl;
    cout<<"Number of rows: "<<num_columns<<endl;
    cout<<"Number of zombies: "<<num_zombies<<endl;
    cout<<endl;
 	helper.Pause();
    helper.ClearScreen();
 	srand(1); //fixed map 
    srand(time(NULL)); //random map
 	Game_Board game_board;
    game_board.init(num_rows,num_columns,num_zombies);
    game_board.show_game_board();
    string command = game_command.set_command();
	game_command.game_commands(command);
 }
}

bool Menu:: is_odd_number(int num){
	// function check row and column as odd numbers 
	return num % 2 != 0;	
}
