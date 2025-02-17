#include <iostream> 
 
using namespace std; 
 
class TicTacToe { 
private: 
    char board[3][3]; // 3x3 board 
    char currentPlayer; 
 
public: 
    // Constructor to initialize the board 
    TicTacToe() { 
        currentPlayer = 'X'; // X always starts first 
        resetBoard(); 
    } 
 
    // Reset board with empty spaces 
    void resetBoard() { 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                board[i][j] = ' '; 
            } 
        } 
    } 
 
    // Display the board 
    void displayBoard() { 
        cout << "\n"; 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                cout << " " << board[i][j] << " "; 
                if (j < 2) cout << "|"; 
            } 
            cout << "\n"; 
            if (i < 2) cout << "---|---|---\n"; 
        } 
        cout << "\n"; 
    } 
 
    // Check if the position is valid 
    bool isValidMove(int row, int col) { 
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' '); 
    } 
 
    // Place player's move 
    void makeMove(int row, int col) { 
        if (isValidMove(row, col)) { 
            board[row][col] = currentPlayer; 
            if (checkWin()) { 
                displayBoard(); 
                cout << "Player " << currentPlayer << " wins!\n"; 
                resetBoard(); 
            } else if (isDraw()) { 
                displayBoard(); 
                cout << "It's a draw!\n"; 
                resetBoard(); 
            } else { 
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch turns 
            } 
        } else { 
            cout << "Invalid move! Try again.\n"; 
        } 
    } 
 
    // Check if a player has won 
    bool checkWin() { 
        // Check rows, columns, and diagonals 
        for (int i = 0; i < 3; i++) { 
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) 
||  
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) 
{ 
                return true; 
            } 
        } 
        if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) 
||  
            (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) 
{ 
            return true; 
        } 
        return false; 
    } 
 
    // Check if the game is a draw 
    bool isDraw() { 
        for (int i = 0; i < 3; i++) { 
            for (int j = 0; j < 3; j++) { 
                if (board[i][j] == ' ') return false; // There's an empty spot 
            } 
        } 
        return true; // No empty spots, so it's a draw 
    } 
 
    // Start the game loop 
    void play() { 
        int row, col; 
        while (true) { 
            displayBoard(); 
            cout << "Player " << currentPlayer << ", enter row (1-3) and column (1-3): "; 
            cin >> row >> col; 
            makeMove(row - 1, col - 1); 
        } 
    } 
}; 
 
int main() { 
    TicTacToe game; 
    game.play(); 
return 0; 
}