#include <iostream>
using namespace std;

void displayGrid(char grid[5][5]) {
    cout << "Word Search:\n\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWord(string word) {
    if (word == "CASA") {
        return true;
    } else {
        return false;
    }
}

int main() {
    char grid[5][5] = {
        {'A', 'O', 'M', 'E', 'X'},
        {'A', 'A', 'C', 'C', 'E'},
        {'F', 'G', 'A', 'I', 'J'},
        {'K', 'S', 'M', 'A', 'O'},
        {'A', 'Q', 'R', 'S', 'T'}
    };

    displayGrid(grid);

    string guess;
    cout << "Enter a word: "<<endl;
    cin >> guess;

    if (checkWord(guess)) {
        cout << "Congratulation you have guess the word"<<endl;
    } else {
        cout << "sorry better luck next time"<<endl;
    }

    return 0;
}
