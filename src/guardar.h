#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
using namespace std;

// Estructura que representa el estado de una partida de juego
struct Game {
    string playerName;
    int level;
    int score;
};

// Guarda la partida del jugador, reemplazándola si ya existe
void saveGame(const Game& g) {
    ifstream inFile("games.txt");
    ofstream outFile("temp.txt");
    Game existing;
    bool replaced = false;

    // Copia todas las partidas, actualizando la del jugador si ya existe
    if (inFile.is_open() && outFile.is_open()) {
        while (inFile >> existing.playerName >> existing.level >> existing.score) {
            if (existing.playerName == g.playerName) {
                // Reemplaza la partida existente
                outFile << g.playerName << " " << g.level << " " << g.score << endl;
                replaced = true;
            } else {
                // Copia las partidas que no coinciden
                outFile << existing.playerName << " " << existing.level << " " << existing.score << endl;
            }
        }

        // Si el jugador no existía, agrega su partida
        if (!replaced) {
            outFile << g.playerName << " " << g.level << " " << g.score << endl;
        }

        // Finaliza el proceso de reemplazo
        inFile.close();
        outFile.close();
        remove("games.txt");
        rename("temp.txt", "games.txt");

        cout << "Progreso guardado para el jugador: " << g.playerName << endl;
    } else {
        cout << "Error al abrir los archivos para guardar." << endl;
    }
}

// Muestra todas las partidas guardadas en el archivo
void showGames() {
    ifstream file("games.txt");
    Game g;

    if (file.is_open()) {
        cout << "\n--- Lista de Partidas ---\n";
        while (file >> g.playerName >> g.level >> g.score) {
            cout << "Jugador: " << g.playerName 
                 << ", Nivel: " << g.level
                 << ", Puntaje: " << g.score << endl;
        }
        file.close();
    } else {
        cout << "Error al abrir el archivo."<<endl;
    }
}

// Busca e imprime una partida según el nombre del jugador
void searchGame() {
    ifstream file("games.txt");
    Game g;
    string search;
    bool found = false;

    cout << "Ingrese nombre del jugador a buscar: ";
    cin >> search;

    if (file.is_open()) {
        while (file >> g.playerName >> g.level >> g.score) {
            if (g.playerName == search) {
                cout << "Partida encontrada: " << g.playerName 
                     << ", Nivel: " << g.level 
                     << ", Puntaje: " << g.score << endl;
                found = true;
                break;
            }
        }
        file.close();
        if (!found)
            cout << "Partida no encontrada."<<endl;
    } else {
        cout << "Error al abrir el archivo."<<endl;
    }
}

// Carga una partida desde el archivo o devuelve valores por defecto
Game loadGame() {
    ifstream file("games.txt");
    Game g;
    string search;
    bool found = false;

    cout << "Ingrese el nombre del jugador para cargar su partida: ";
    cin >> search;

    if (file.is_open()) {
        while (file >> g.playerName >> g.level >> g.score) {
            if (g.playerName == search) {
                cout << "Partida cargada exitosamente.\n";
                found = true;
                break;
            }
        }
        file.close();
    }

    // Si no se encuentra, se retorna una partida inicializada
    if (!found) {
        cout << "No se encontró la partida. Se devolverán valores por defecto.\n";
        g.playerName = search;
        g.level = 1;
        g.score = 0;
    }

    return g;
}

// Elimina la partida correspondiente al jugador especificado
void deleteGame() {
    ifstream file("games.txt");
    ofstream temp("temp.txt");
    Game g;
    string search;
    bool deleted = false;

    cout << "Ingrese nombre del jugador a eliminar: ";
    cin >> search;

    if (file.is_open() && temp.is_open()) {
        while (file >> g.playerName >> g.level >> g.score) {
            if (g.playerName != search) {
                // Copia las partidas distintas al nombre buscado
                temp << g.playerName << " " << g.level << " " << g.score << endl;
            } else {
                // Marca como eliminada
                deleted = true;
            }
        }
        file.close();
        temp.close();
        remove("games.txt");
        rename("temp.txt", "games.txt");

        if (deleted)
            cout << "Partida eliminada correctamente."<<endl;
        else
            cout << "Jugador no encontrado."<<endl;
    } else {
        cout << "Error al abrir los archivos."<<endl;
    }
}

#endif
