#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;
class Game_Commands
{
private:
string choice; // user choice
public:
string set_command();
void game_commands(string command);
string get_alien_direction(string path);
};
string Game_Commands :: get_alien_direction(string path){
	return path;
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
	if(command == "up"){
	    cout<<"up"<<endl;
	    //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "down"){
		cout<<"down"<<endl;
	     //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "left"){
		cout<<"left"<<endl;
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "right"){
		cout<<"right"<<endl;
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
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);;
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
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "save"){
		string filename;
		cout<<"Enter the file to save game: ";
		cin>>filename;
	     //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
	else if(command == "load"){
		string filename;
		cout<<"Enter the file to load game: ";
		cin>>filename;
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
	      //calling the function to allow user to perform another action
	      string select = game_command.set_command();
	       // processing the user command 
     	  game_command.game_commands(select);
		}
		else{
			cout<<"You enter wrong choice"<<endl;
		     //calling the function to allow user to perform another action
	        string select = game_command.set_command();
	        // processing the user command 
         	game_command.game_commands(select);
		}
	}
	else{
		cout<<"You enter wrong command"<<endl;
		 //calling the function to allow user to perform another action
	    string select = game_command.set_command();
	    // processing the user command 
     	game_command.game_commands(select);
	}
}
