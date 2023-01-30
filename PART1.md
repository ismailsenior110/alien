# Part 1

## Video Demo

The game is introduced via the [Video Demo](https://youtu.be/pi4HSVjnIeY)

## User Manual
1.	The game is played by launching the console app main.
2.	 Enter ‘y’ if want to continue with default game setting, the game board would be displayed, or ‘n’ if you want to customize. The game is customizing by entering the number of column and row of the game board in the game board which must be odd. 
3.	The alien is located in the game board center which is your character you can move in four directions by typing ‘right’ or ‘left’ or ‘up’ or ‘down’ respectively. 
4.	The objects ('^', 'V', '<', '>') change the alien movement based on the symbol direction and also adds 20 attacks to alien.
5.	The objects h adds 20 lives to the alien
6.	The objects p inflicts 10 damage to Zombie when hit by Alien
7.	The object r hides a game object you unveil the game object and use in your advantage 
8.	The space contains nothing you can move to the empty space freely
9.	.  objects represent the trails of the alien 
10.	Type ‘help’ for any help in the game 
11.	Type ‘save’ to save your game state
12.	Type ‘load’ to load your game state 
13.	Type ‘quit’ to quit the game
14.	Type ‘arrow’ to change any ('^', 'V', '<', '>') direction. You must enter the row, column of the object and finally your preferred direction press enter.

## Minimum Requirements
### Completed

List all the features completed.

1.	Game console app
2.	Game settings by the user
3.	Game settings automatic
4.	Generating the game board 
5.	Placing the alien in center
6.	Placing zombie randomly on the game board 
7.	Accepting user commands 

### To Do

List all the features not yet done. Remove this section if there is no incomplete requirements.

1.	Alien move in four directions
2.	Addition of life to alien through h game object
3.	Addition of life to alien through h game object
4.	Addition of attack to alien through p game object
5.	Alien attacking zombie
6.	Zombie attacking alien
7.	Multiple zombie 
8.	Unveiling the game objects under rock(r)
9.	Zombie movement
10.	Declaration of game Winner 
11.	Saving game state
12.	Load game state 

## Additional Features

Describe the additional features that has been implemented.
## Compilation Instructions 
1.	Type cmd in the search bar next to the Start menu.
2.	Right-click Command Prompt in the search results, then select Run As Administrator.
3.	Click Yes to allow changes.
4.	Navigate to the folder where the source code is saved
5.	Type the command gcc c –o main.exe then main.cpp and press enter 
## Contributions

### Muhammad Ismail Hamza 

Wrote the whole code

## Problems Encountered & Solutions

The problem encountered was the generation of game and palcing the alien in the middle of the game board.
The solution was using the loops to print the gameboard and finding the middle of the vector row and column to place the alien in the middle of the game board.
