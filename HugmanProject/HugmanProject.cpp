#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

vector<string> words = {
    "cat", "dog", "fish", "bird", "cow", "horse", "sheep", "goat", "lion", "tiger",
    "elephant", "giraffe", "zebra", "monkey", "bear", "fox", "wolf", "rabbit", "deer", "panda",
    "kangaroo", "koala", "owl", "frog", "snake", "eagle", "parrot", "dolphin", "shark", "whale",
    "penguin", "seal", "bat", "bee", "ant", "butterfly", "spider", "crab", "lobster", "octopus",
    "squid", "shrimp", "clam", "starfish", "seahorse", "peacock", "turkey", "chicken", "duck", "goose",
    "sparrow", "flamingo", "woodpecker", "crow", "swan", "hedgehog", "hamster", "rat", "mouse", "lizard"
};

string wordToGuess;
set<char> guessedLetters;
set<char> usedLetters;

void printWord(const string& word, const set<char>& guessedLetters) {
    cout << "\nWord: ";
    for (char c : word) {
        if (guessedLetters.count(c)) {
            cout << c << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
}

bool isWordGuessed(const string& word, const set<char>& guessedLetters) {
    for (char c : word) {
        if (!guessedLetters.count(c)) {
            return false;
        }
    }
    return true;
}

void showUsedLetters(const set<char>& usedLetters) {
    cout << "Used letters: ";
    for (char c : usedLetters) {
        cout << c << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));

    cout << "*****************************" << endl;
    cout << "*        HANGMAN GAME       *" << endl;
    cout << "*****************************" << endl;

    wordToGuess = words[rand() % words.size()]; // Случайное слово
    int attemptsLeft = 12;
    char guess;

    while (attemptsLeft > 0 && !isWordGuessed(wordToGuess, guessedLetters)) {
        cout << "\n*****************************" << endl;
        cout << "Attempts left: " << attemptsLeft << endl;
        printWord(wordToGuess, guessedLetters);
        showUsedLetters(usedLetters);
        cout << "*****************************" << endl;

        cout << "Enter a letter: ";
        cin >> guess;

        // Convert to lowercase for case insensitivity
        guess = tolower(guess);

        if (usedLetters.count(guess)) {
            cout << "\nYou already guessed that letter! Try a different one." << endl;
            continue;
        }

        usedLetters.insert(guess);

        if (wordToGuess.find(guess) != string::npos) {
            cout << "\nCorrect!" << endl;
            guessedLetters.insert(guess);
        }
        else {
            cout << "\nWrong!" << endl;
            attemptsLeft--;
        }
    }

    cout << "\n*****************************" << endl;
    if (isWordGuessed(wordToGuess, guessedLetters)) {
        cout << "Congratulations! You guessed the word: " << wordToGuess << endl;
    }
    else {
        cout << "You lost! The word was: " << wordToGuess << endl;
    }
    cout << "*****************************" << endl;

    return 0;
}
