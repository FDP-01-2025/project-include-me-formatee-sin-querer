#ifndef NIVELES_H
#define NIVELES_H

#include <iostream>
#include "minijuegos.h"
using namespace std;

const int WORD_SIZE = 17;
const int WORDS_BY_LEVEL = 7;
const int TOTAL_LEVELS = 9;

char levels[TOTAL_LEVELS][WORDS_BY_LEVEL][WORD_SIZE] = {
    {"cat", "dog", "sun", "red", "hat", "run", "pen"},
    {"tree", "milk", "book", "fish", "game", "road", "jump"},
    {"flower", "jungle", "yellow", "father", "magic", "house", "light"},
    {"crystal", "border", "laptop", "window", "secret", "bottle", "animal"},
    {"keyboard", "mountain", "freedom", "plastic", "evening", "blanket", "thunder"},
    {"mixture", "awkward", "volcano", "blanket", "texture", "journey", "silence"},
    {"reaction", "daughter", "pressure", "whisper", "luggage", "circus", "fortune"},
    {"dangerous", "knowledge", "invisible", "discovery", "adventure", "triangle", "architect"},
    {"misunderstanding", "responsibility", "international", "communication", "independence", "satisfaction", "transformation"},
};

bool comparewords(const char word1[], const char word2[]) {
    for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            return false;
        }
    }
    return true;
}

int playlevel(int level) {
    char entry[WORD_SIZE];
    int points = 0;

    for (int i = 0; i < WORDS_BY_LEVEL; i++) {
        cout << "word: " << levels[level][i] << endl;
        cout << "write: ";
        cin >> entry;
        if (comparewords(levels[level][i], entry)) {
            points++;
            cout << "correct" << endl;
        } else {
            cout << "incorrect! was: " << levels[level][i] << endl;
        }
    }

    cout << "level " << (level + 1) << " completed. Points: " << points << " / " << WORDS_BY_LEVEL << "\n";

     // Mostrar minijuego después del nivel 3, 6 y 9
    if (level == 2) {
        minigame1();
    } else if (level == 5) {
        minigame2();
    } else if (level == 8) {
        minigame3();
    }
    
    return points;
}

#endif
