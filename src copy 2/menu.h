#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "niveles.h"
#include "guardar.h"

using namespace std;

// Función principal del menú del juego
void menuGame() {
    Game player;
    string inputName;
    bool loaded = false;

    int option = 0;
    int option2 = 0;

    while (option != 5) {
        // Menú principal del juego
        cout << "\n-------- Menu Principal ---------" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Guardar partida" << endl;
        cout << "3. Mostrar partidas guardadas" << endl;
        cout << "4. Eliminar partida" << endl;
        cout << "5. Salir" << endl;
        cout << "Escoge una opcion: ";
        cin >> option;

        switch (option) {
            case 1: {
                // Preguntar si desea cargar una partida guardada
                cout << "¿Deseas cargar una partida guardada? (1 = si, 0 = no): ";
                int loadOpt;
                cin >> loadOpt;

                if (loadOpt == 1) {
                    player = loadGame();
                    loaded = true;
                } else {
                    // Solicitar nombre del jugador si no carga
                    cout << "Nombre del jugador (sin espacios): ";
                    cin >> inputName;
                    player.playerName = inputName;
                    player.level = 1;
                    player.score = 0;
                }

                // Menú de selección de niveles
                option2 = 0;
                while (option2 != 10) {
                    cout << "\n-------- Niveles ---------" << endl;
                    for (int i = 1; i <= TOTAL_LEVELS; i++) {
                        cout << " " << i << ". Nivel " << i << endl;
                    }
                    cout << "10. Regresar al menu principal" << endl;
                    cout << "Escoge el nivel: ";
                    cin >> option2;

                    if (option2 >= 1 && option2 <= TOTAL_LEVELS) {
                        int points = playlevel(option2 - 1); // Ejecutar nivel seleccionado
                        player.score += points;

                        // Si el nivel superado es mayor al anterior, actualizar nivel alcanzado
                        if (player.level < option2 + 1)
                            player.level = option2 + 1;
                    } else if (option2 == 10) {
                        cout << "Regresando al menu principal..." << endl;
                    } else {
                        cout << "Por favor ingresa un numero valido." << endl;
                    }
                }
                break;
            }

            case 2:
                // Guardar manualmente el progreso del jugador
                cout << "Guardando partida..." << endl;
                saveGame(player);
                cout << "Partida guardada correctamente." << endl;
                break;

            case 3:
                // Mostrar todas las partidas guardadas
                showGames();
                break;

            case 4:
                // Eliminar partida por nombre
                deleteGame();
                break;

            case 5:
                cout << "Gracias por jugar. ¡Hasta la proxima!" << endl;
                break;

            default:
                cout << "Por favor selecciona una opcion valida." << endl;
                break;
        }
    }
}

#endif
