#ifndef MINIGAME3_H
#define MINIGAME3_H

#include <iostream>
#include <string>
#include <chrono>       // Para medir tiempos
#include "funciontime.h"  // Para usar waitASecond()

using namespace std;
using namespace std::chrono;

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
        cin.ignore(); // Para limpiar el buffer

        if (start == 1) {
            for (int j = 0; j < 5; j++) {
                cout << "Prepárate..." << endl;

                // Cuenta regresiva 3...2...1 con espera
                for (int i = 3; i > 0; i--) {
                    cout << i << endl;
                    waitASecond();
                }

                cout << "¡Escribe la palabra: " << palabras[j] << "!" << endl;

                // Medir tiempo
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
            break; // Termina el minijuego después de las 5 palabras
        } else {
            cout << "Por favor, elige la opción que se te indicó.\n" << endl;
        }
    }
}

#endif

