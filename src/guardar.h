#ifndef SAVE_H
#define SAVE_H

#include <iostream>
#include <fstream>
using namespace std;

// Estructura que representa el estado de un jugador
struct Game
{
    string playerName; // Nombre del jugador
    int level;         // Nivel alcanzado
    int score;         // Puntaje actual
};

// Guarda una nueva partida en el archivo
void saveGame(const Game &g)
{
    ifstream inFile("games.txt"); // Archivo original con partidas
    ofstream outFile("temp.txt"); // Archivo temporal para reescribir
    Game existing;
    bool replaced = false;

    // Reescribe todo excepto si ya existe el jugador (se reemplaza)
    if (inFile.is_open() && outFile.is_open())
    {
        while (inFile >> existing.playerName >> existing.level >> existing.score)
        {
            if (existing.playerName == g.playerName)
            {
                // Reemplaza la partida existente del mismo jugador
                outFile << g.playerName << " " << g.level << " " << g.score << endl;
                replaced = true;
            }
            else
            {
                // Copia partidas de otros jugadores sin cambios
                outFile << existing.playerName << " " << existing.level << " " << existing.score << endl;
            }
        }

        // Si no había jugador con ese nombre, lo añade como nuevo
        if (!replaced)
        {
            outFile << g.playerName << " " << g.level << " " << g.score << endl;
        }

        // Finaliza escritura y reemplaza el archivo original
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
        // Lee y muestra cada partida guardada
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
        // Busca en el archivo una partida con el nombre ingresado
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
        // Busca y carga la partida del jugador
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

    // Si no se encuentra, devuelve valores por defecto
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
        // Copia todo excepto el jugador a eliminar
        while (file >> g.playerName >> g.level >> g.score)
        {
            if (g.playerName != search)
            {
                temp << g.playerName << " " << g.level << " " << g.score << endl;
            }
            else
            {
                deleted = true; // Marca que se eliminó
            }
        }
        file.close();
        temp.close();
        remove("games.txt");
        rename("temp.txt", "games.txt");

        // Informa si se eliminó correctamente o no se encontró
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
