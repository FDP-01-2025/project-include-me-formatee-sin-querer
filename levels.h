#include <iostream>
using namespace std;

// Definir constantes para el tamaño de palabra, palabras por nivel y niveles totales
const int WORD_SIZE = 17;
const int WORDS_BY_LEVEL = 7;
const int TOTAL_LEVELS = 9;

// Arreglo con palabras agrupadas por nivel
// Cada fila es un nivel con 7 palabras
// Las palabras se vuelven progresivamente más difíciles en cada nivel
char levels[TOTAL_LEVELS][WORDS_BY_LEVEL][WORD_SIZE] = {
    {"cat", "dog", "sun", "red", "hat", "run", "pen"},                                                                          // level 1
    {"tree", "milk", "book", "fish", "game", "road", "jump"},                                                                   // level 2
    {"flower", "jungle", "yellow", "father", "magic", "house", "light"},                                                        // level 3
    {"crystal", "border", "laptop", "window", "secret", "bottle", "animal"},                                                    // level 4
    {"keyboard", "mountain", "freedom", "plastic", "evening", "blanket", "thunder"},                                            // level 5
    {"mixture", "awkward", "volcano", "blanket", "texture", "journey", "silence"},                                              // level 6
    {"reaction", "daughter", "pressure", "whisper", "luggage", "circus", "fortune"},                                            // level 7
    {"dangerous", "knowledge", "invisible", "discovery", "adventure", "triangle", "architect"},                                 // level 8
    {"misunderstanding", "responsibility", "international", "communication", "independence", "satisfaction", "transformation"}, // level 9
};

// Compara dos palabras carácter por carácter
bool comparewords(const char word1[], const char word2[])
{
    // Loop until the end of either word
    for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; i++)
    {
        // If characters are different, the words don't match
        if (word1[i] != word2[i])
        {
            return false;
        }
    }
    // If loop ends, words are equal
    return true;
}

// Plays one level of the typing game
int playlevel(int level)
{
    char entry[WORD_SIZE]; // Stores player's input
    int points = 0;        // Tracks correct answers

    // Iterate over all words in the current level
    for (int i = 0; i < WORDS_BY_LEVEL; i++)
    {
        // Show the word to type
        cout << "word: " << levels[level][i] << endl;

        // Ask the player to type the word
        cout << "write: " << endl;
        cin >> entry;

        // Check if input matches the word
        if (comparewords(levels[level][i], entry))
        {
            points++;
            cout << "correct" << endl;
        }
        else
        {
            // Show correct word if input was wrong
            cout << "incorrect! was:" << levels << levels[level][i];
        }
    }

    // Display result for the level
    cout << "level " << (level + 1) << " completed. Points: " << points << " / " << WORDS_BY_LEVEL << "\n";
    return points; // Return score for this level
