#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
using namespace std;

struct Game {
    string playerName;
    int level;
    int score;
};

void saveGame(const Game& g) {
    ifstream inFile("src/games.txt");
    ofstream outFile("src/temp.txt");
    Game existing;
    bool replaced = false;

    if (inFile && outFile) {
        while (inFile >> existing.playerName >> existing.level >> existing.score) {
            if (existing.playerName == g.playerName) {
                outFile << g.playerName << " " << g.level << " " << g.score << endl;
                replaced = true;
            } else {
                outFile << existing.playerName << " " << existing.level << " " << existing.score << endl;
            }
        }
        if (!replaced) {
            outFile << g.playerName << " " << g.level << " " << g.score << endl;
        }
        inFile.close();
        outFile.close();
        remove("src/games.txt");
        rename("src/temp.txt", "src/games.txt");

        cout << "Progreso guardado para el jugador: " << g.playerName << endl;
    } else {
        // Si no existe games.txt, lo crea
        ofstream createFile("src/games.txt", ios::app);
        if (createFile) {
            createFile << g.playerName << " " << g.level << " " << g.score << endl;
            createFile.close();
            cout << "Progreso guardado para el jugador: " << g.playerName << endl;
        } else {
            cout << "Error al abrir los archivos para guardar." << endl;
        }
    }
}

void showGames() {
    ifstream file("src/games.txt");
    Game g;

    if (file.is_open()) {
        cout << "\n--- Lista de Partidas ---\n";
        bool empty = true;
        while (file >> g.playerName >> g.level >> g.score) {
            cout << "Jugador: " << g.playerName 
                 << ", Nivel: " << g.level
                 << ", Puntaje: " << g.score << endl;
            empty = false;
        }
        if (empty) cout << "(No hay partidas guardadas)\n";
        file.close();
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

void searchGame() {
    ifstream file("src/games.txt");
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
            cout << "Partida no encontrada.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

Game loadGame() {
    ifstream file("src/games.txt");
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

    if (!found) {
        cout << "No se encontró la partida. Se devolverán valores por defecto.\n";
        g.playerName = search;
        g.level = 1;
        g.score = 0;
    }

    return g;
}

void deleteGame() {
    ifstream file("src/games.txt");
    ofstream temp("src/temp.txt");
    Game g;
    string search;
    bool deleted = false;

    cout << "Ingrese nombre del jugador a eliminar: ";
    cin >> search;

    if (file.is_open() && temp.is_open()) {
        while (file >> g.playerName >> g.level >> g.score) {
            if (g.playerName != search) {
                temp << g.playerName << " " << g.level << " " << g.score << endl;
            } else {
                deleted = true;
            }
        }
        file.close();
        temp.close();
        remove("src/games.txt");
        rename("src/temp.txt", "src/games.txt");

        if (deleted)
            cout << "Partida eliminada correctamente.\n";
        else
            cout << "Jugador no encontrado.\n";
    } else {
        cout << "Error al abrir los archivos.\n";
    }
}

#endif
