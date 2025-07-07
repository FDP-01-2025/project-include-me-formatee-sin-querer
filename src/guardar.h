#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
using namespace std;

// Estructura que representa el estado de un jugador
struct Game
{
    string playerName;
    int level;
    int score;
};

// Guarda una nueva partida en el archivo
void saveGame(const Game &g)
{
    ifstream inFile("games.txt");
    ofstream outFile("temp.txt");
    Game existing;
    bool replaced = false;

    // Reescribe todo excepto el jugador duplicado
    if (inFile.is_open() && outFile.is_open())
    {
        while (inFile >> existing.playerName >> existing.level >> existing.score)
        {
            if (existing.playerName == g.playerName)
            {
                outFile << g.playerName << " " << g.level << " " << g.score << endl;
                replaced = true;
            }
            else
            {
                outFile << existing.playerName << " " << existing.level << " " << existing.score << endl;
            }
        }

        // Si no lo reemplazó, es un jugador nuevo
        if (!replaced)
        {
            outFile << g.playerName << " " << g.level << " " << g.score << endl;
        }

        inFile.close();
        outFile.close();
        remove("games.txt");
        rename("temp.txt", "games.txt");

        cout << "Progreso guardado para el jugador: " << g.playerName << endl;
    }
    else
    {
        cout << "Error al abrir los archivos para guardar." << endl;
    }
}

// Muestra todas las partidas guardadas
void showGames()
{
    ifstream file("games.txt");
    Game g;

    if (file.is_open())
    {
        cout << "\n--- Lista de Partidas ---\n";
        while (file >> g.playerName >> g.level >> g.score)
        {
            cout << "Jugador: " << g.playerName
                 << ", Nivel: " << g.level
                 << ", Puntaje: " << g.score << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error al abrir el archivo.\n";
    }
}

// Busca una partida por nombre
void searchGame()
{
    ifstream file("games.txt");
    Game g;
    string search;
    bool found = false;

    cout << "Ingrese nombre del jugador a buscar: ";
    cin >> search;

    if (file.is_open())
    {
        while (file >> g.playerName >> g.level >> g.score)
        {
            if (g.playerName == search)
            {
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
    }
    else
    {
        cout << "Error al abrir el archivo.\n";
    }
}

// Carga una partida por nombre y devuelve el objeto Game
Game loadGame()
{
    ifstream file("games.txt");
    Game g;
    string search;
    bool found = false;

    cout << "Ingrese el nombre del jugador para cargar su partida: ";
    cin >> search;

    if (file.is_open())
    {
        while (file >> g.playerName >> g.level >> g.score)
        {
            if (g.playerName == search)
            {
                cout << "Partida cargada exitosamente.\n";
                found = true;
                break;
            }
        }
        file.close();
    }

    if (!found)
    {
        cout << "No se encontró la partida. Se devolverán valores por defecto.\n";
        g.playerName = search;
        g.level = 1;
        g.score = 0;
    }

    return g;
}

// Elimina una partida por nombre de jugador
void deleteGame()
{
    ifstream file("games.txt");
    ofstream temp("temp.txt");
    Game g;
    string search;
    bool deleted = false;

    cout << "Ingrese nombre del jugador a eliminar: ";
    cin >> search;

    if (file.is_open() && temp.is_open())
    {
        while (file >> g.playerName >> g.level >> g.score)
        {
            if (g.playerName != search)
            {
                temp << g.playerName << " " << g.level << " " << g.score << endl;
            }
            else
            {
                deleted = true;
            }
        }
        file.close();
        temp.close();
        remove("games.txt");
        rename("temp.txt", "games.txt");

        if (deleted)
            cout << "Partida eliminada correctamente.\n";
        else
            cout << "Jugador no encontrado.\n";
    }
    else
    {
        cout << "Error al abrir los archivos.\n";
    }
}

#endif
