#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class GuessTheNumber {
private:
    int computerGeneratedNumber;
    int userGuessedNumber;
    int attempts;

public:
    GuessTheNumber() : attempts(0) {
        srand(static_cast<unsigned int>(time(NULL))); 
        computerGeneratedNumber = rand() % 100 + 1; 
    }

    void playGame() {
        cout << "Welcome to Guess the Number Game!" << endl;
        cout << "I have selected a number between 1 and 100. Try to guess it." << endl;

        do {
            getUserGuess();
            checkGuess();
            attempts++;
        } while (userGuessedNumber != computerGeneratedNumber);
        cout << "Congratulations! You won the game in " << attempts << " attempts." << endl;
    }

private:
    void getUserGuess() {
        cout << "Guess The Number: ";
        cin >> userGuessedNumber;
    }
    void checkGuess() {
        if (userGuessedNumber < computerGeneratedNumber) {
            cout << "Guessed number is smaller than computer generated number." << endl;
        } else if (userGuessedNumber > computerGeneratedNumber) {
            cout << "Guessed number is greater than computer generated number." << endl;
        }
        cout << "Attempt:" << attempts + 1 << endl;
    }
};
int main() {
    GuessTheNumber game;
    game.playGame();
    return 0;
}
