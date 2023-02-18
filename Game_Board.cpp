#include "Game_Board.h"
#include <vector>
#include <iostream>
#include <cstdlib> // for system()
#include <ctime> // for time() 
#include <iomanip> // for setw()
#include <fstream>
#include <sstream>
#include<bits/stdc++.h>


using namespace std;

void Game_Board :: move_up(int &dimY_, int &dimX_, vector<vector <char> > &map_,int &alien_life, int &alien_attack,int (&zombie_life)[10]){
	
	char object;
	
	for (int i = 0; i < dimY_; i++){
   	
     for (int j = 0; j < dimX_; j++){
     	
       if (map_[i][j] == 'A'){
       	
       	if(i-1 > 0){
       		object = map_ [i- 1][j];
       		game_object(object, alien_life, alien_attack, zombie_life);
       		 map_ [i][j] = '.';
		   map_ [i- 1][j] = 'A';
		   break;
		   } 
	   }
	   
     }
     
   } 
	
}

void Game_Board :: move_down(int &dimY_, int &dimX_, vector<vector <char> > &map_, int &alien_life, int &alien_attack, int (&zombie_life)[10]){
	
	char object;
	
	for (int i = 0; i < dimY_; i++){
   	
     for (int j = 0; j < dimX_; j++){
     	
       if (map_[i][j] == 'A'){
       	
       	   if((i+1) < (map_.size() -1)){
       	   	    
       	   	    object = map_ [i + 1][j];
       	    	game_object(object, alien_life, alien_attack, zombie_life);
       	   	    map_ [i][j] = '.';
		        map_ [i+1][j] = 'A';
		        break;
		        
			  } 
	   }
	   
     }
     
   } 
	
}


void Game_Board :: move_right(int &dimY_, int &dimX_, vector<vector <char> > &map_, int &alien_life, int &alien_attack, int (&zombie_life)[10]){
	
	char object;
	for (int i = 0; i < dimY_; i++){
   	
     for (int j = 0; j < dimX_; j++){
       if (map_[i][j] == 'A'){
       	   if((j+1) <= (map_[i].size() -1)){
       	   	    object = map_ [i][j + 1];
       	    	game_object(object, alien_life, alien_attack, zombie_life);
       	   	    map_ [i][j] = '.';
		        map_ [i][j+1] = 'A';
		        break;
			  }
		   
	   }
	   
     }
     
   } 
	
}
 
void Game_Board :: move_left(int &dimY_, int &dimX_, vector<vector <char> > &map_,int &alien_life, int &alien_attack, int (&zombie_life)[10]){
   
    char object;
		
	for (int i = 0; i < dimY_; i++){
   	
     for (int j = 0; j < dimX_; j++){
       if (map_[i][j] == 'A'){
       	   if((j+1) >= 0  && (j+1) < (map_[i].size() -1)){
       	   	    object = map_ [i][j-1];
       	    	game_object(object, alien_life, alien_attack, zombie_life);
       	   	    map_ [i][j] = '.';
		        map_ [i][j-1] = 'A';
		        break;
			  }
	   }
	   
     }
     
   } 
	
}


  void Game_Board :: move_specified_direction(int target_row,int target_column, string direction, vector<vector <char> > &map_){
  	target_row = target_row - 1;
  	target_column = target_column - 1;
  	
  if ( (target_row >= 0 && target_row < map_.size() - 1) && (target_column >= 0 && target_column < map_[target_row].size() - 1)){
  	
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
  
  
  void Game_Board :: save(int &dimY_, int &dimX_, int &num_zombie,std:: vector< std :: vector <char> > &map_ , std:: string filename, int &alien_life, int &alien_attack,int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10])
  {
  	std :: ofstream out("save.txt");
   for (int i = 0; i < dimY_; ++i)
   {
     for (int j = 0; j < dimX_; ++j)
     {
     	out <<map_[i][j] << ' ';
     }
     out <<"\n";
   }
   
   out<<alien_life<< ' '<<alien_attack<<"\n";
   
  for(int i = 0; i < num_zombie; ++i)
   {
   	out<<zombie_life[i]<<' '<<zombie_attack[i]<<' '<<zombie_range[i]<<"\n";
   }
   out.close();
  }
  void Game_Board :: load(int &dimY_, int &dimX_, int &num_zombie, vector< vector <char> > &map_ , string filename, int &alien_life, int &alien_attack,int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10]){
  
  string line;
  ifstream in("save.txt");
  
  while (getline(in, line)){
  	
    istringstream iss(line);
    std::vector<char> row;
    char x;
    while (iss >> x) {
      row.push_back(x);
    }
    cout<<line<<endl;
   map_.push_back(row);
  }
  in.close();
  cout<<endl;
  }
  
void Game_Board :: game_object(char object, int &alien_life, int &alien_attack, int (&zombie_life)[10]){
	
	char game_objects [] = {'^', 'V', '<', '>', 'p','h'}; 
    int noOfObjects = 6; // number of game objects in the objects array
    
	if(object == 'v' || object == '^' || object == '>'|| object == '<' ){
		alien_attack += 20;
	}
	else if(object == 'h'){
	   alien_life += 20;	
	}
	else if(object == 'r'){
		
        char randomobject = game_objects[rand() % noOfObjects];
        game_object(randomobject, alien_life, alien_attack, zombie_life);	
	}
	else if(object == 'p'){
		
		int zombie;
	   cout<<"Enter the number of Zombie you want attack"<<endl;
	   cin>>zombie;
	   zombie -= 1;
	   if(zombie_life[zombie] > 0){
	   	zombie_life [zombie] -= alien_attack;
		alien_attack -= alien_attack; 
	   }
	   else{
	   	
	   }
	}
	else{
	}
}




