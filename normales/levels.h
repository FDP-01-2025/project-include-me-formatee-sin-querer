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
    {"cat", "dog", "sun", "red", "hat", "run", "pen"},                                                                          // nivel 1
    {"tree", "milk", "book", "fish", "game", "road", "jump"},                                                                   // nivel 2
    {"flower", "jungle", "yellow", "father", "magic", "house", "light"},                                                        // nivel 3
    {"crystal", "border", "laptop", "window", "secret", "bottle", "animal"},                                                    // nivel 4
    {"keyboard", "mountain", "freedom", "plastic", "evening", "blanket", "thunder"},                                            // nivel 5
    {"mixture", "awkward", "volcano", "blanket", "texture", "journey", "silence"},                                              // nivel 6
    {"reaction", "daughter", "pressure", "whisper", "luggage", "circus", "fortune"},                                            // nivel 7
    {"dangerous", "knowledge", "invisible", "discovery", "adventure", "triangle", "architect"},                                 // nivel 8
    {"misunderstanding", "responsibility", "international", "communication", "independence", "satisfaction", "transformation"}, // nivel 9
};

// Compara dos palabras carácter por carácter
bool comparewords(const char word1[], const char word2[])
{
   // Bucle hasta el final de cualquiera de las dos palabras
    for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; i++)
    {
        // Si los caracteres son diferentes, las palabras no coinciden
        if (word1[i] != word2[i])
        {
            return false;
        }
    }
    // Si el bucle termina, las palabras son iguales
    return true;
}

// Juega un nivel del juego de mecanografía

int playlevel(int level)
{
    char entry[WORD_SIZE]; // Almacena la entrada del jugador
    int points = 0;        // Lleva el control de las respuestas correctas

    // Iterar sobre todas las palabras en el nivel actual
    for (int i = 0; i < WORDS_BY_LEVEL; i++)
    {
        // Muestra la palabra a escribir
        cout << "incorrect! was: " << levels[level][i] << endl;

        // Pide al jugador que escriba la palabra
        cout << "write: " << endl;
        cin >> entry;

        // Verifica si la entrada coincide con la palabra
        if (comparewords(levels[level][i], entry))
        {
            points++;
            cout << "correct" << endl;
        }
        else
        {
            // Muestra la palabra correcta si la entrada fue incorrecta
            cout << "incorrect! was: " << levels[level][i] << endl;

        }
    }

    // Muestra el resultado del nivel
    cout << "level " << (level + 1) << " completed. Points: " << points << " / " << WORDS_BY_LEVEL << "\n";
    return points; // Devuelve la puntuación de este nivel
