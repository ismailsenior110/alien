#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include <vector>
#include <string>
class Game_Board{
private:
	  // The alien life and zombie respectively
	 int alien_life, alien_attack;
	 const static int zombie_life [10];
	 const static int zombie_attack[10];
	 const static int zombie_range[10];
	 
	 int middle_row, middle_column;
	 int target_row, target_column;
	 std :: vector< std :: vector<char> > map_; // a map to conatain the game board
	 
	 int  dimX_, dimY_ , zombie_; // game board dimension
	 std :: string choice; // user choice and path
 public:
   void init(int dimX, int dimY,int zombie);
   void show_game_board();
   void move_up();
   void move_down();
   void move_right();
   void move_left();
   void move_specified_direction(int target_row,int target_column, std:: string direction);
   void set_target_row_column();
   void save(std:: string filename);
};

 class Game_Commands : Game_Board{
	private:
	std :: string choice; // user choice and path
	public:
	std:: string set_command();
	void game_commands(std:: string command);
	int get_column(int col);
 
 };

#endif
