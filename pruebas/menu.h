#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "niveles.h"  // Incluimos el header con los niveles
using namespace std;

void menuGame() {
    int option = 0, option2 = 0;

    while (option != 2) {
        cout << "-------- Menu ---------" << endl;
        cout << "1. Jugar" << endl;
        cout << "2. Salir" << endl;
        cout << "Escoge una opcion: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "___________________________________" << endl;
            option2 = 0;
            while (option2 != 10) {
                cout << "\n-------- Levels ---------" << endl;
                cout << "1. Nivel 1" << endl;
                cout << "2. Nivel 2" << endl;
                cout << "3. Nivel 3" << endl;
                cout << "4. Nivel 4" << endl;
                cout << "5. Nivel 5" << endl;
                cout << "6. Nivel 6" << endl;
                cout << "7. Nivel 7" << endl;
                cout << "8. Nivel 8" << endl;
                cout << "9. Nivel 9" << endl;
                cout << "10. Regresar al menu principal" << endl;
                cout << "Escoge el nivel: ";
                cin >> option2;

                if (option2 >= 1 && option2 <= 9) {
                    playlevel(option2 - 1);
                } else if (option2 == 10) {
                    cout << "Regresando al menu principal..." << endl;
                } else {
                    cout << "Porfavor ingrese un numero valido" << endl;
                }
            }
            break;
        case 2:
            cout << "Saliendo del programa" << endl;
            break;
        default:
            cout << "Ingresa una opcion valida del menu" << endl;
            break;
        }
        cout << endl;
    }
}

#endif
