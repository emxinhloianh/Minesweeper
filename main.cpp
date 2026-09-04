#include <iostream>
using namespace std;

class Minesweeper { // Classs Minesweeper for game
private: // private members of the class
    int boardSize; // boardSize
    bool revealed[10][10]; // create a 2D array to keep track of revealed cells (maximum size 10x10)

public:
   // Constructor to initialize the board size and revealed cells
    Minesweeper(int size) { 
        boardSize = size; 
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                revealed[i][j] = false; // initialize all cells as unrevealed
            }
        }
    }

    // Function to display the game board
    void displayBoard() {
        cout << "\n  ";
        // print column indices at the top of the board
        for (int j = 0; j < boardSize; j++) {
            cout << j << " ";
        }
        cout << endl;

        // Print each row of the board with row indices on the left
        for (int i = 0; i < boardSize; i++) {
            cout << i << " "; // Row index on the left
            for (int j = 0; j < boardSize; j++) {
                cout << "? ";
            }
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter board size (5-10): "; // choose size of the board
    cin >> size; // collect user input for board size

    
    Minesweeper game(size); 

    // Display the game board for testing
    game.displayBoard();

    return 0;
}