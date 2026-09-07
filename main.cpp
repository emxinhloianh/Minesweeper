#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
// Constant for the maximum array size
const int MAX_SIZE = 10;
// Array 1: Stores mine locations (true = has mine, false = no mine)
bool isMine[MAX_SIZE][MAX_SIZE]; 
// Array 2: Stores the number of adjacent mines (0 to 8)
int adjacentMines[MAX_SIZE][MAX_SIZE]; 
// Array 3: Stores the display state of each cell
// '?' = hidden | 'r' = revealed 
char cellState[MAX_SIZE][MAX_SIZE]; 
// Game state variables
int boardSize;
int totalMines;
int gameState = 0; // Convention: 0 = Playing, 1 = Win, 2 = Lose
// 2. FUNCTION PROTOTYPES
void createBoard(); // Initializes the board arrays
void placeMines(); // Randomly places mines on the board
int countAdjacentMines(int row, int col); // Counts the number of mines adjacent to a given cell
void displayBoard();// Displays the current state of the board to the console
void revealTile(int row, int col);// Reveals a tile and updates the game state accordingly
bool checkWin(); // Checks if the player has won the game
// 3. MAIN FUNCTION - GAME LOOP
int main() {
    // Initialize random seed
    srand(time(0));
    // Get and validate board size (5-10)
    cout << "Enter board size (5-10): ";
    cin >> boardSize;
    while (boardSize < 5 || boardSize > 10) {
        cout << "Invalid size! Enter board size (5-10): ";
        cin >> boardSize;
    }
    totalMines = boardSize;// Set total mines equal to board size
    // Prepare the board
    createBoard();
    placeMines();
    // Main game loop
    while (gameState == 0) {
        displayBoard();
        // Ask the user for row and column to reveal
        int r, c;
        cout << "Enter row and column to reveal: ";
        cin >> r >> c;
        if (r < 0 || r >= boardSize || c < 0 || c >= boardSize) {
            cout << "Invalid coordinates! Enter row and column to reveal: ";
            continue;
        }
        // Check if r and c are valid (within board boundaries: >= 0 and < boardSize)
        // If valid, call revealTile(r, c)
        revealTile(r, c);
        // After revealing, check if the player has won using checkWin()
        // If checkWin() returns true, set gameState = 1
    }
    // End of game
    displayBoard(); // Print the board one last time
    if (gameState == 1) {
        cout << "\nCongratulations!\n";
    } else if (gameState == 2) {
        cout << "\nGame Over!\n";
    }
    return 0;
}
// 4. FUNCTION DEFINITIONS
void createBoard() {
    // Use 2 nested for loops (from 0 to boardSize - 1)
    for (int i=0; i<boardSize;i++) { 
        for (int j=0; j<boardSize;j++) {
            isMine[i][j] = false; // Initialize all cells to no mine
            adjacentMines[i][j] = 0;// Initialize all cells to 0 adjacent mines
            cellState[i][j] = '?'; // Initialize all cells to hidden state
        }
    }
}
void displayBoard() {
    // Use loops to print the board to the console
cout << "\nMinesweeper\n";
for (int i=0; i<boardSize;i++) {
    for (int j=0; j<boardSize;j++) {
        switch (cellState[i][j]) {
            case '?':
                cout << '?';
                break;
            case 'r':
                cout << adjacentMines[i][j];
                break;
        }
    }
    cout << "\n";
}    
    // - If cellState[i][j] == '?', print '?'
    // - If cellState[i][j] == 'r', print the number of adjacent mines (using the adjacentMines array)
}
void placeMines() {
    int minesPlaced = 0;
    // Use a while loop (while minesPlaced < totalMines)
    while (minesPlaced < totalMines) {
        // - Generate a random row 'r' and column 'c' using rand() % boardSize
        int r =rand()%boardSize;
        int c =rand()%boardSize;
    // - If isMine[r][c] is currently false, set it to true and increment minesPlaced
    if (!isMine[r][c]) {
        isMine[r][c] = true;
        minesPlaced++;
    }
}
}
int countAdjacentMines(int row, int col) {
    int count = 0;
    // Use 2 nested loops (from -1 to 1) to check the 8 surrounding cells
    for (int i=-1;i<=1;i++){
        for (int j=-1;j<=1;j++){
            int r= row+i;// Calculate the row of the surrounding cell
            int c= col+j;// Calculate the column of the surrounding cell
             // - Use an if statement to check if the surrounding coordinates are within bounds (r >= 0, r < boardSize, c >= 0, c < boardSize)
             if (r>=0 && r<boardSize && c>=0 && c<boardSize){
                // - If the cell is within bounds and has a mine (isMine[r][c] == true), increment 'count'
                if (isMine[r][c]==true){
                    count++;
                }
             }
        }
    }   
    return count;
}
void revealTile(int row, int col) {
    // - Change cellState[row][col] to 'r' (revealed)
    cellState[row][col] = 'r';
    // - If isMine[row][col] is true -> Hit a mine -> Set gameState = 2
    if (isMine[row][col]==true) {
        gameState = 2;
    }
    // - If it's safe (no mine) -> Call countAdjacentMines(row, col) and save the result into adjacentMines[row][col]
    else {
        adjacentMines[row][col] = countAdjacentMines(row, col);
    // Checks if the revealed tile has exactly zero adjacent mines, meaning the surrounding area is completely safe.
    if (adjacentMines[row][col] == 0) {
        // Use 2 nested loops (from -1 to 1) to check the 8 surrounding cells
        for (int i=-1;i<=1;i++){
        for (int j=-1;j<=1;j++){
            int r= row+i;// Calculate the row of the surrounding cell
            int c= col+j;// Calculate the column of the surrounding cell
        // - Use an if statement to check if the surrounding coordinates are within bounds (r >= 0, r < boardSize, c >= 0, c < boardSize)
        if (r>=0 && r<boardSize && c>=0 && c<boardSize){
        // - If the cell is within bounds and is still hidden (cellState[r][c] == '?'), call revealTile(r, c) recursively
        if (cellState[r][c]=='?'){
            revealTile(r,c);
                    }
                }
            }
        }
    }
}
}
bool checkWin() {  
    int revealedSafeTiles= 0;
    int totalSafeTiles=(boardSize*boardSize) - totalMines;
    // Loop through the whole board. If cellState[i][j] is 'r' AND isMine[i][j] is false, increase a counter.
    for (int i=0; i<boardSize; i++){
    for (int j=0; j<boardSize; j++){
    if (cellState[i][j]=='r' && isMine[i][j]==false){
                revealedSafeTiles++;
            }
        }
    }
    // If the total revealed safe cells equals (Total cells - total mines), return true. Otherwise, return false.
    if (revealedSafeTiles==totalSafeTiles){
        return true;
    }
    else{
    return false;
}}