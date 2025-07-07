#ifndef MINIJUEGOS_H
#define MINIJUEGOS_H

#include <iostream>
#include <string>
#include <chrono>
#include "entero.h"
#include "funciontiempo.h" // Para usar waitASecond en minijuego 3

using namespace std;
using namespace std::chrono; // Para medir tiempo en minijuego 3

// Primer minijuego: sopa de letras simple
int minigame1()
{
    // Matriz 5x5 con letras para la sopa de letras
    char grid[5][5] = {
        {'A', 'O', 'M', 'E', 'X'},
        {'A', 'A', 'C', 'C', 'E'},
        {'F', 'G', 'A', 'I', 'J'},
        {'K', 'S', 'M', 'A', 'O'},
        {'A', 'Q', 'R', 'S', 'T'}};

    // Presentación del juego
    cout << "Bienvenido al primer minijuego en donde podras ganar 100 puntos extra: " << endl;

    // Muestra la sopa de letras
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    // Pide al usuario adivinar la palabra escondida
    string guess;
    cout << "Busca y adivina la palabra solo tienes un intento asi que buena suerte (escribe la respuesta en MAYUSCULAS): " << endl;
    cin >> guess;

    // Verifica si la palabra es correcta
    if (guess == "CASA")
    {
        cout << "\033[1;32mFelicidades has recibido 100 puntos extras por adivinar la palabra\033[0m" << endl;
        return 100;
    }
    else
    {
        cout << "\033[31mMas suerte para la proxima amigo\033[0m" << endl;
        return 0;
    }
}

// Segundo minijuego: adivina dos palabras según pistas
int minigame2()
{
    // Muestra las pistas
    cout << "Horizontal:" << endl;
    cout << "Es lo que usas para entrar en tu automovil" << endl;

    cout << "Vertical:" << endl;
    cout << "El primer apellido del ingeniero Miguel" << endl;

    string horiz, vert;

    // Pide al usuario las respuestas
    cout << "Escribe la palabra en horizontal" << endl;
    cin >> horiz;
    cout << "Escribe tu palabra en vertical ";
    cin >> vert;

    // Verifica si ambas respuestas son correctas
    if (horiz == "llaves" && vert == "Rivas")
    {
        cout << "\033[1;32mFelicidades ! has recibido 100 puntos extra\033[0m" << endl;
        return 100;
    }
    else
    {
        cout << "\033[31mBuena suerte para la proxima!\033[0m" << endl;
        return 0;
    }
}

// Tercer minijuego: rapidez al escribir palabras
int minigame3()
{
    // Lista de palabras a escribir
    string words[5] = {
        "desarrollo",
        "computadora",
        "programacion",
        "matematicas",
        "universidad"};

    // Introducción del juego
    cout << "Vamos a usar los reflejos ahora para ver qué tan rápido eres." << endl;

    while (true)
    {
        // Espera que el usuario indique que está listo
        cout << "Presiona el número 1 si estás listo: ";
        int start = readInteger();
        cin.ignore(); // Limpia el buffer de entrada

        if (start == 1)
        {
            bool allCorrect = true; // Bandera para verificar si todas las respuestas fueron correctas

            // Recorre las 5 palabras
            for (int j = 0; j < 5; j++)
            {
                cout << "Prepárate..." << endl;
                for (int i = 3; i > 0; i--)
                {
                    cout << i << endl;
                    waitASecond(); // Espera 1 segundo entre cada número de cuenta regresiva
                }

                // Pide al usuario escribir la palabra mostrada
                cout << "¡Escribe la palabra: " << words[j] << "!" << endl;

                // Mide el tiempo que tarda el usuario en escribir
                auto start_time = high_resolution_clock::now();
                string answer2;
                getline(cin, answer2);
                auto end_time = high_resolution_clock::now();
                auto duration1 = duration_cast<milliseconds>(end_time - start_time).count();

                // Verifica si la palabra escrita es correcta
                if (answer2 == words[j])
                {
                    cout << "\033[1;32mCorrecto. Tiempo:\033[0m " << duration1 << " ms.\n"
                         << endl;
                }
                else
                {
                    // Informa que la palabra es incorrecta
                    cout << "\033[31mIncorrecto. La palabra correcta era: \033[0m" << words[j] << endl;
                    cout << "Tu respuesta: " << answer2 << endl;
                    cout << "Tiempo: " << duration1 << " ms.\n"
                         << endl;
                    allCorrect = false; // Marca que hubo un error
                }
            }

            // Verifica si todas las respuestas fueron correctas
            if (allCorrect)
            {
                cout << "\033[1;32m¡Excelente! Completaste todo correctamente. Recibes 100 puntos extra.\033[0m" << endl;
                return 100;
            }
            else
            {
                cout << "\033[31mNo completaste todas las palabras correctamente. No ganas puntos esta vez.\033[0m" << endl;
                return 0;
            }
        }
        else
        {
            // El usuario no presionó 1 como se indicó
            cout << "Por favor elige la opción que se te indicó" << endl
                 << endl;
        }
    }
}

#endif
