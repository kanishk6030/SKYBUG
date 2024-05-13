#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NumberGuesser {
private:
    int secretNumber;
public:
    NumberGuesser() {
        // Initialize random seed
        srand(time(0));
        // Generate random number between 1 and 100
        secretNumber = rand() % 100 + 1;
    }

    void guessNumber() {
        int guess;
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;

        while (guess != secretNumber) {
            if (guess < secretNumber) {
                cout << "Too low! Guess again: "<<endl;
            } else {
                cout << "Too high! Guess again: "<<endl;
            }
            cin >> guess;
        }

        cout << "Congratulations! You guessed the number " << secretNumber << " correctly!!!" << endl;
    }
};

int main() {
    NumberGuesser game;
    game.guessNumber();
    return 0;
}
