#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NumberGuesser {

private:
    int secret_num;

public:
    NumberGuesser() {
        // random seed
        srand(time(0));
        // Generating random numbers between 1 and 100
        secret_num = rand() % 100 + 1;
    }

    void guess_number() {
        int guess;
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;

        while (guess != secret_num) {
            if (guess < secret_num) {
                cout << "Too low! Guess again: "<<endl;
            } else {
                cout << "Too high! Guess again: "<<endl;
            }
            cin >> guess;
        }

        cout << "Congratulations! You have guessed the right number " << secret_num << " correctly!!!" << endl;
    }
};

int main() {
    NumberGuesser game;
    game.guess_number();
    return 0;
}
