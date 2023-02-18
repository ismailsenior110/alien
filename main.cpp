#include "helper/helper.cpp"
#include "Game_Board.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime> // for time() 
#include <iomanip> // for setw()
#include <fstream>


using namespace std;

void game_commands(string &command, int &dimY_, int &dimX_,int &num_zombie, vector<vector <char> > &map_, int &alien_life, int &alien_attack, int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10]);
string  set_command();
void init(int &dimY_,int &dimX_, int &zombie_, vector<vector <char> > &map_);
void show_game_board(int &dimY_, int &dimX_,vector<vector <char> > &map_);
bool  is_odd_number(int num);
void set_zombie_attribute(int (&zombie_life)[10], int (&zombie_attack)[10],int (&zombie_range)[10], int &num_zombie);
void print_alien_and_zombie(int &alien_life, int &alien_attack, int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10], int &num_zombie);


void  game_commands(string &command, int &dimY_, int &dimX_,int &num_zombie, vector<vector <char> > &map_, int &alien_life, int &alien_attack, int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10]){
	
	Helper helper; // helper class object to clear screen and pause program execution 
	Game_Board game_board;// game_board objects 
	string select;
	// user commands choice in the game respective action
	if(command == "up"){
     	helper.Pause();
        helper.ClearScreen();
        game_board.move_up(dimY_,dimX_, map_, alien_life, alien_attack, zombie_life);
        
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range); 	
	}
	else if(command == "down"){
	    helper.Pause();
        helper.ClearScreen();
        game_board.move_down(dimY_,dimX_, map_, alien_life, alien_attack, zombie_life);
        
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
	else if(command == "left"){
	    helper.Pause();
        helper.ClearScreen();
        game_board.move_left(dimY_,dimX_, map_, alien_life, alien_attack, zombie_life);
        
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
	else if(command == "right"){
	    helper.Pause();
        helper.ClearScreen();
        game_board.move_right(dimY_,dimX_, map_, alien_life, alien_attack, zombie_life);
        
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
	else if(command == "arrow"){
		int row,column;
		string direction;
		cout<<"Enter the row and column of arrow followed by direction to switch seprated by space"<<endl;
		cin>>row>>column>>direction;
     	helper.Pause();
        helper.ClearScreen();
        
        game_board.move_specified_direction(row, column, direction,map_);
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
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
        
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
	else if(command == "save"){
		string filename;
		cout<<"Enter the file to save game: ";
		cin>>filename;
		
		helper.Pause();
        helper.ClearScreen();
        //calling save function here with filename argument
		game_board.save(dimY_, dimX_, num_zombie, map_ ,filename, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
	else if(command == "load"){
		string filename;
		cout<<"Enter the file to load game: ";
		cin>>filename;
		helper.Pause();
        helper.ClearScreen();
		
		game_board.load(dimY_, dimX_, num_zombie, map_ ,filename, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
	else if(command == "quit"){
		char decision;
		cout<<"Are you sure you want to quit the game (y/n): ";
		cin>>decision;
		if(decision == 'y'){
			exit(1);
		}
		else if(decision =='n'){
		helper.Pause();
        helper.ClearScreen();
         show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	    
		}
		else{
			cout<<"You enter wrong choice"<<endl;
			//calling save function here with filename argument
	    	helper.Pause();
            helper.ClearScreen();
		     show_game_board(dimY_,dimX_, map_);
            print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
           //calling the function to allow user to perform another action
	       select = set_command();
	       // processing the user command
	      game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
		}
	}
	else{
		cout<<"You enter wrong command"<<endl;
		//calling save function here with filename argument
		helper.Pause();
        helper.ClearScreen();
        show_game_board(dimY_,dimX_, map_);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombie);
        
        //calling the function to allow user to perform another action
	    select = set_command();
	    // processing the user command
	    game_commands(select, dimY_,dimX_, num_zombie,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
	}
}

string  set_command(){
	string choice;
	cout<<"Enter Command: ";
	cin>>choice;
	return choice;
	
}

void  init(int &dimY_,int &dimX_, int &zombie_, vector<vector <char> > &map_){
 
   char objects[] = {' ',' ', ' ','^', 'V', '<', '>', 'p', 'r', 'h'}; 
   int noOfObjects = 10; // number of game objects in the objects array
   
   // create dynamic 2D array using vector for the game board
   map_.resize(dimY_); // create empty game  rows
   for (int i = 0; i < dimY_; ++i) 
   {
    map_[i].resize(dimX_); // resize each row
   }
   
   // put random characters into the game board with alien in the middle of the board
   for (int i = 0; i < dimY_; ++i){
   	
     for (int j = 0; j < dimX_; ++j){
     	
       int objNo = rand() % noOfObjects;
       map_[i][j] = objects[objNo];
     }
   } 
   
    // obtaining the  middle row and column  of the game board
   int middle_row = map_.size()/2;
   int middle_column = map_[0].size()/2;
   
   char zombie_objects[] = {'1','2', '3', '4', '5', '6', '7', '8','9'}; // zombie objects array
	
   
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
    
  
}


void show_game_board(int &dimY_, int &dimX_,vector<vector <char> > &map_){
	
    cout<<"Alien vs Zombies"<<endl;
     
       // for each row in game board
       for (int i = 0; i < dimY_; ++i){
            cout << "   ";
            for (int j = 0; j < dimX_; ++j){
                cout << "+-";
            }
            cout << "+" << endl;

            cout << setw(2) << i + 1<< " ";

            for (int j = 0; j < dimX_; ++j){
                cout << "|" << map_[i][j];
            }
            cout << "|" << endl;
        }

        cout << "   ";

        for (int j = 0; j < dimX_; ++j){
            cout << "+-";
        }

        cout << "+" << endl;
        cout << "   ";

        for (int j = 0; j < dimX_; ++j){
            int digit = (j + 1) / 10;
            cout << " ";
            if (digit == 0)
                cout << " ";
            else
                cout << digit;
        }

        cout << endl;
        cout << "   ";

        for (int j = 0; j < dimX_; ++j){
            cout << " " << (j + 1) % 10;
        }

        cout << "\n\n";
  }
  
bool  is_odd_number(int num){
	// function check row and column as odd numbers 
	return num % 2 != 0;	
}
void set_zombie_attribute(int (&zombie_life)[10], int (&zombie_attack)[10],int (&zombie_range)[10], int &num_zombie){
	for(int i=0;i<num_zombie;i++){
	   zombie_life[i] =  50 + (rand() % 100);
	   zombie_attack[i] = 50 + (rand() % 200);
	   zombie_range[i] = 1 + (rand() % 4);
	}
}
void print_alien_and_zombie(int &alien_life, int &alien_attack, int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10], int &num_zombie){
	
	cout<<"Alien_life:  "<<alien_life<<"  Attack: "<<alien_attack<<endl;
	
	for(int i=0;i<num_zombie;i++){
		cout<<"zombie_life"<<i+1<< ":  "<<zombie_life[i]<<"  Attack: "<<zombie_attack[i]<<"  "<<"zombie_range: "<<zombie_range[i]<<endl;
	}
}
int main(){
	
 	vector<vector<char > > map_;
	char choice; // user choice
	string select; // user selection 
    int num_rows, num_columns,num_zombies; // Required parameters of the game
    int alien_life = 1 + (rand() % 100); 
    int  alien_attack = 0; 
    int zombie_life[10], zombie_attack[10], zombie_range[10];
     
    Game_Board game_board; // object of game_board 
    Helper helper;  // object of helper class to pause game and clear screen
     
     
 cout<<"Welcome Alien Path Game"<<endl;
 cout<<"------------------------------"<<endl;
 cout<<endl;
 cout<<"Do you want to continue with the  defaut game setting (y/n)"<<endl;
  cin>>choice;
  
  helper.Pause();
  helper.ClearScreen();
 if(choice == 'y'){
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
    
    set_zombie_attribute(zombie_life, zombie_attack, zombie_range,num_zombies);
    srand(1); //fixed map 
    srand(time(NULL)); //random map
    init(num_rows,num_columns,num_zombies,map_);
    show_game_board(num_rows, num_columns, map_);
    set_zombie_attribute(zombie_life, zombie_attack, zombie_range, num_zombies);
    print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombies);
    select = set_command();
    game_commands(select,num_rows,num_columns,num_zombies,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
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
 		
    srand(1); //fixed map 
    srand(time(NULL)); //random map
    init(num_rows,num_columns,num_zombies,map_);
    show_game_board(num_rows, num_columns, map_);
    set_zombie_attribute(zombie_life, zombie_attack, zombie_range, num_zombies);
    print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombies);
    select = set_command();
    game_commands(select,num_rows,num_columns,num_zombies,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
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
    
	    srand(1); //fixed map 
        srand(time(NULL)); //random map
        init(num_rows,num_columns,num_zombies,map_);
        show_game_board(num_rows, num_columns, map_);
        set_zombie_attribute(zombie_life, zombie_attack, zombie_range, num_zombies);
        print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombies);
        select = set_command();
        game_commands(select,num_rows,num_columns,num_zombies,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
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
    init(num_rows,num_columns,num_zombies,map_);
    show_game_board(num_rows, num_columns, map_);
    set_zombie_attribute(zombie_life, zombie_attack, zombie_range, num_zombies);
    print_alien_and_zombie(alien_life, alien_attack, zombie_life, zombie_attack, zombie_range, num_zombies);
    select = set_command();
    game_commands(select,num_rows,num_columns,num_zombies,map_, alien_life, alien_attack, zombie_life, zombie_attack, zombie_range);
    
   }
  }
 
