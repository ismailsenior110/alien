#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime> // for time() 
#include <iomanip> // for setw()
using namespace std;
class Game_Board{
private:
  // The alien life and zombie respectively
 int alien_life, alien_attack, zombie_life, zombie_attack,zombie_range; 
 vector< vector<char> > map_; // a map to conatain the game board
 int dimX_, dimY_ , zombie_; // game board dimension
 public:
   void init(int dimX, int dimY,int zombie);
   void show_game_board() const;
   void place_game_chracters(int dimX, int dimY,int zombie);
 };
 void Game_Board::init(int dimX, int dimY,int zombie)
 {
 	
   dimX_ = dimX;
   dimY_ = dimY;
   zombie_ = zombie;
   char objects[] = {' ','^', 'V', '<', '>', 'p', 'r', 'h'}; 
   int noOfObjects = 8; // number of game objects in the objects array
   
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
   int middle_row = map_.size()/2;
   int middle_column = map_[0].size()/2;
   map_[middle_row][middle_column] = 'A';
   // placing zombie on game board
   map_[middle_row + 1][middle_column + 1] = '1'; 
   alien_life =  1 + (rand() % 100); 
   zombie_life = 1 + (rand() % 100); 
   alien_attack = 0; 
   zombie_attack = 1 + (rand() % 200);
   zombie_range = 1 + (rand() % dimX_); 
}
  void Game_Board::show_game_board() const
  {
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
        cout<<"Zombie life: "<<zombie_life<<"   "<<"Zombie attack: "<<zombie_attack<<" "<<"Range: "<<zombie_range<<endl;
        cout<<endl;
  }
