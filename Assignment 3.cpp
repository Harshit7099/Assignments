#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }

        currentPlayer = 'O';
    }

    void printBoard() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) {
                    cout << " | ";
                }
            }
            cout << endl;
            if (i < 2) {
                cout << "---------" << endl;
            }
        }
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            return false;
        }

        board[row][col] = currentPlayer;

        currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';

        return true;
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                cout << "Player " << board[i][0] << " wins!" << endl;
                return true;
            }
            if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                cout << "Player " << board[0][i] << " wins!" << endl;
                return true;
            }
        }

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
            cout << "Player " << board[0][0] << " wins!" << endl;
            return true;
        }

        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
            cout << "Player " << board[0][2] << " wins!" << endl;
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    char getCurrentPlayer() const {
        return currentPlayer;
    }

    void setCurrentPlayer(char player) {
        currentPlayer = player;
    }
};

int main() {
    TicTacToe game;
    char playerChoice;
    cout << "Player 1, choose 'X' or 'O': ";
    cin >> playerChoice;

    if (playerChoice == 'X' || playerChoice == 'O') {
        game.setCurrentPlayer(playerChoice);  
    } else {
        cout << "Invalid choice. Defaulting to 'O'." << endl;
    }

    while (!game.isBoardFull() && !game.checkWin()) {
        game.printBoard();

        int row, col;
        cout << "Player " << game.getCurrentPlayer() << ", enter your move (row and column): ";
        cin >> row >> col;

        game.makeMove(row, col);
    }
    game.printBoard();
    if (game.isBoardFull() && !game.checkWin()) {
        cout << "It's a tie!" << endl;
    }
    return 0;
}
