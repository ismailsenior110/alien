#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include <string>
class Game_Board{

 public:
 	 
   void move_up(int &dimY_, int &dimX_, std:: vector< std :: vector <char> > &map_, int &alien_life, int &alien_attack,int (&zombie_life)[10]);
   void move_down(int &dimY_, int &dimX_, std:: vector< std :: vector <char> > &map_, int  &alien_life, int  &alien_attack, int (&zombie_life)[10]);
   void move_right(int &dimY_, int &dimX_, std:: vector< std :: vector <char> > &map_, int &alien_life, int  &alien_attack, int (&zombie_life)[10]);
   void move_left(int &dimY_, int &dimX_, std:: vector< std :: vector <char> > &map_, int  &alien_life, int &alien_attack, int (&zombie_life)[10]);
   void move_specified_direction(int target_row,int target_column, std:: string direction, std:: vector< std :: vector <char> > &map_);
   void save(int &dimY_, int &dimX_, int &num_zombie,std:: vector< std :: vector <char> > &map_ , std:: string filename, int &alien_life, int &alien_attack,int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10]);
   void load(int &dimY_, int &dimX_, int &num_zombie,std:: vector< std :: vector <char> > &map_ , std:: string filename, int &alien_life, int &alien_attack,int (&zombie_life)[10],int (&zombie_attack)[10], int (&zombie_range)[10]);
   void game_object(char object,int &alien_life, int &alien_attack, int (&zombie_life)[10]);
};
#endif
