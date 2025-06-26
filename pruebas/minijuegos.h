#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include <iostream>
#include <string>
#include <chrono>
#include "funciontiempo.h"// para minigame3

using namespace std;
using namespace std::chrono;

void minigame1() {
    char grid[5][5] = {
        {'A', 'O', 'M', 'E', 'X'},
        {'A', 'A', 'C', 'C', 'E'},
        {'F', 'G', 'A', 'I', 'J'},
        {'K', 'S', 'M', 'A', 'O'},
        {'A', 'Q', 'R', 'S', 'T'}
    };

    cout << "Bienvenido al primer minigame en donde podras ganar 100 puntos extra: "<<endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    string guess;
    cout << "Busca y adivina la palabra solo tienes un intento asi que buena suerte: "<<endl;
    cin >> guess;

    if (guess == "CASA") {
        cout << "Felicidades has recibido 100 puntos extras por adivinar la palabra"<<endl;
    } else {
        cout << "Mas suerte para la proxima amigo"<<endl;
    }
}

void minigame2() {
    cout << "Horizontal:" << endl;
    cout << "Es una cosa que utilizas en tu automovil" << endl;

    cout << "Vertical:" << endl;
    cout << "El primer apellido del ingeniero Miguel" << endl;

    string horiz, vert;
    cout << "Escribe la palabra en horizontal"<<endl;
    cin >> horiz;
    cout << "Escribe tu palabra en vertical ";
    cin >> vert;

    if(horiz == "llaves" && vert == "Rivas") {
        cout << "Felicidades ! has recibido 100 puntos extra" << endl;
    } else {
        cout << "Buena suerte para la proxima!" << endl;
    }
}

void minigame3() {
    string palabras[5] = {
        "desarrollo",
        "computadora",
        "programacion",
        "matematicas",
        "universidad"
    };

    cout << "Vamos a usar los reflejos ahora para ver qué tan rápido eres.\n" << endl;

    while (true) {
        int start;
        cout << "Presiona el número 1 si estás listo: ";
        cin >> start;
        cin.ignore();

        if (start == 1) {
            for (int j = 0; j < 5; j++) {
                cout << "Prepárate..." << endl;
                for (int i = 3; i > 0; i--) {
                    cout << i << endl;
                    waitASecond();
                }

                cout << "¡Escribe la palabra: " << palabras[j] << "!" << endl;

                auto start_time = high_resolution_clock::now();
                string respuesta;
                getline(cin, respuesta);
                auto end_time = high_resolution_clock::now();
                auto duracion = duration_cast<milliseconds>(end_time - start_time).count();

                if (respuesta == palabras[j]) {
                    cout << "Correcto. Tiempo: " << duracion << " ms.\n" << endl;
                } else {
                    cout << "Incorrecto. La palabra correcta era: " << palabras[j] << endl;
                    cout << "Tu respuesta: " << respuesta << endl;
                    cout << "Tiempo: " << duracion << " ms.\n" << endl;
                }
            }
            break;
        } else {
            cout << "Por favor, elige la opción que se te indicó.\n" << endl;
        }
    }
}

#endif
