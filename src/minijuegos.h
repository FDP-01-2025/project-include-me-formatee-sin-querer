#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include <iostream>
#include <string>
#include <chrono>
#include "funciontiempo.h" // Para usar waitASecond en minijuego 3

using namespace std;
using namespace std::chrono; // Para medir tiempo en minijuego 3

// Primer minijuego: sopa de letras simple
void minigame1()
{
    char grid[5][5] = {
        {'A', 'O', 'M', 'E', 'X'},
        {'A', 'A', 'C', 'C', 'E'},
        {'F', 'G', 'A', 'I', 'J'},
        {'K', 'S', 'M', 'A', 'O'},
        {'A', 'Q', 'R', 'S', 'T'}};

    cout << "Bienvenido al primer minijuego en donde podras ganar 100 puntos extra: " << endl;

    // Muestra la cuadrícula de letras
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    string guess;
    cout << "Busca y adivina la palabra solo tienes un intento asi que buena suerte (escribe la respuesta en MAYUSCULAS): " << endl;

    // Usuario adivina una palabra
    cin >> guess;

    // Verifica si la respuesta es correcta
    if (guess == "CASA")
    {
        cout << "\033[1;32mFelicidades has recibido 100 puntos extras por adivinar la palabra\033[0m" << endl;
    }
    else
    {
        cout << "\033[31mMas suerte para la proxima amigo\033[0m" << endl;
    }
}

// Segundo minijuego: adivina dos palabras según pistas
void minigame2()
{
    cout << "Horizontal:" << endl;
    cout << "Es lo que usas para entrar en tu automovil" << endl;

    cout << "Vertical:" << endl;
    cout << "El primer apellido del ingeniero Miguel" << endl;

    string horiz, vert;

    // Entrada de palabras
    cout << "Escribe la palabra en horizontal" << endl;
    cin >> horiz;
    cout << "Escribe tu palabra en vertical ";
    cin >> vert;

    // Verifica ambas respuestas
    if (horiz == "llaves" && vert == "Rivas")
    {
        cout << "\033[1;32mFelicidades ! has recibido 100 puntos extra\033[0m" << endl;
    }
    else
    {
        cout << "\033[31mBuena suerte para la proxima!\033[0m" << endl;
    }
}

// Tercer minijuego: rapidez al escribir palabras
void minigame3()
{
    string palabras[5] = {
        "desarrollo",
        "computadora",
        "programacion",
        "matematicas",
        "universidad"};

    cout << "Vamos a usar los reflejos ahora para ver qué tan rápido eres.\n"
         << endl;

    while (true)
    {
        // Espera confirmación del jugador
        int start;
        cout << "Presiona el número 1 si estás listo: ";
        cin >> start;
        cin.ignore();

        if (start == 1)
        {
            for (int j = 0; j < 5; j++)
            {
                cout << "Prepárate..." << endl;

                // Cuenta regresiva
                for (int i = 3; i > 0; i--)
                {
                    cout << i << endl;
                    waitASecond(); // Espera 1 segundo
                }

                // Muestra palabra a escribir
                cout << "¡Escribe la palabra: " << palabras[j] << "!" << endl;

                // Mide tiempo de escritura
                auto start_time = high_resolution_clock::now();
                string respuesta;
                getline(cin, respuesta);
                auto end_time = high_resolution_clock::now();
                auto duracion = duration_cast<milliseconds>(end_time - start_time).count();

                // Verifica si la palabra es correcta
                if (respuesta == palabras[j])
                {
                    cout << "\033[1;32mCorrecto. Tiempo:\033[0m " << duracion << " ms.\n"
                         << endl;
                }
                else
                {
                    cout << "\033[31mIncorrecto. La palabra correcta era: \033[0m" << palabras[j] << endl;
                    cout << "Tu respuesta: " << respuesta << endl;
                    cout << "Tiempo: " << duracion << " ms.\n"
                         << endl;
                }
            }
            break; // Sale del ciclo
        }
        else
        {
            cout << "Por favor elige la opción que se te indicó \n"
                 << endl;
        }
    }
}

#endif
