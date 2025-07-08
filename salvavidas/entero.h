#ifndef UTILS_H
#define UTILS_H

#include <iostream>
using namespace std;

// Reads an integer from user input and handles invalid input
// Lee un número entero y evita errores por entradas inválidas
int readInteger() {
    int value;
    cin >> value;
    while (cin.fail()) {
        cout << "Entrada inválida. Intenta de nuevo: ";
        cin.clear();               // Limpia estado de error
        cin.ignore(1000, '\n');    // Ignora lo ingresado incorrectamente
        cin >> value;
    }
    return value;
}

#endif
