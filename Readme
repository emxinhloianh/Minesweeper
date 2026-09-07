This is my C++ learning project. 
Minesweeper (Simplified Version)
Overview
Create a console-based Minesweeper game in C++.
The game should allow the player to reveal tiles on a board while avoiding hidden mines. The goal is to reveal all non-mine tiles without revealing a mine.
This project is intended for beginners and focuses on the use of:
Variables
Arrays/Vectors
Loops
Functions
Conditional Statements
Random Number Generation
Requirements
1. Game States
The game must support three states:
Play: The game is currently running.
Win: All non-mine tiles have been revealed.
Lose: The player reveals a mine.
2. Dynamic Board Size
At the start of the game, the player chooses the board size.
Example:
Enter board size (5-10): 7
Show more lines
The game will create a board of:
7 x 7
3. Mine Placement
Mines should be placed randomly.
The number of mines should equal the board size.
Examples:
5x5 board -> 5 mines
6x6 board -> 6 mines
8x8 board -> 8 mines
Optional Bonus:
Ensure the first tile selected by the player is never a mine.
4. Display Board
Hidden tiles should be displayed as:
?
Show more lines
Example:
? ? ? ? ?
? ? ? ? ?
? ? ? ? ?
? ? ? ? ?
? ? ? ? ?
5. Reveal Tile
The player selects a tile by entering its row and column.
Example:
Enter row: 2
Enter column: 3
6. Adjacent Mine Count
When a safe tile is revealed, display the number of surrounding mines.
Example:
1
2
0
Where:
0 = no surrounding mines
1 = one surrounding mine
2 = two surrounding mines
...
7. Lose Condition
If the selected tile contains a mine:
The game enters the Lose state.
All mines are revealed.
Display a Game Over message.
Example:
Game Over!
You hit a mine.
8. Win Condition
The player wins when all non-mine tiles have been revealed.
Example:
Congratulations!
You cleared the board.
Optional Bonus Features
Implement these only if the basic game is complete.
Bonus 1: First Click Safe
The first tile selected by the player can never contain a mine.
Bonus 2: Flags
Allow players to place flags on suspected mines.
Example:
f 2 3
Bonus 3: Flag Counter
Display:
Flags Remaining: 5
Suggested Functions
void createBoard();
void placeMines();
int countAdjacentMines(int row, int col);
void revealTile(int row, int col);
void displayBoard();
bool checkWin();
Success Criteria
A successful project should:
✅ Allow the user to choose a board size
✅ Generate a board dynamically
✅ Place mines randomly
✅ Display hidden and revealed tiles
✅ Show adjacent mine counts
✅ Detect win and lose conditions
✅ Continue running until the player wins or loses
Bonus
✅ First-click-safe mine placement
✅ Flags and flag counter