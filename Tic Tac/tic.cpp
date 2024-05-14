#include <iostream>
#include <vector>

using namespace std;

// For displaying the board
void displayingBoard(const vector<vector<char>>& board) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Who won the match
bool check_win(const vector<vector<char>>& board, char player) {
    // Check rows
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    }
    // Columns
    for (int j = 0; j < 3; ++j) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return true;
    }
    // Diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;
    return false;
}

// if the game is a draw
bool check_draw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

int main() {
    char Player = 'X';
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize empty board

    bool gameOver = false;
    while (!gameOver) {
        // Displaying the board
        displayingBoard(board);

        // Prompt the player to enter their move
        int row, col;
        cout << "Player " << Player << "'s turn. Enter row and column (1-3): ";
        cin >> row >> col;

        // Check if the input is valid
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            continue;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = Player;

        // Check for win
        if(check_win(board, Player)) {
            displayingBoard(board);
            cout << "Player " << Player << " wins!" << endl;
            gameOver = true;
        }
        // Check for draw
        else if (check_draw(board)) {
            displayingBoard(board);
            cout << "It's a draw!" << endl;
            gameOver = true;
        }
        // Switching players
        else {
            Player = (Player == 'X') ? 'O' : 'X';
        }
    }

    // Ask if the players want to play again
    char playAgain;
    cout << "Do you want to play again? (Y/N): ";
    cin >> playAgain;
    if (playAgain == 'Y' || playAgain == 'y') {
        main(); // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }

    return 0;
}
