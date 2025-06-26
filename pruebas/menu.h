#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "niveles.h"  // Incluimos el header con los niveles
using namespace std;

void menuGame() {
    int option = 0, option2 = 0;

    while (option != 2) {
        cout << "-------- Menu ---------" << endl;
        cout << "1. Play" << endl;
        cout << "2. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "___________________________________" << endl;
            option2 = 0;
            while (option2 != 10) {
                cout << "\n-------- Levels ---------" << endl;
                cout << "1. Level 1" << endl;
                cout << "2. Level 2" << endl;
                cout << "3. Level 3" << endl;
                cout << "4. Level 4" << endl;
                cout << "5. Level 5" << endl;
                cout << "6. Level 6" << endl;
                cout << "7. Level 7" << endl;
                cout << "8. Level 8" << endl;
                cout << "9. Level 9" << endl;
                cout << "10. Return to Main Menu" << endl;
                cout << "Choose your level: ";
                cin >> option2;

                if (option2 >= 1 && option2 <= 9) {
                    playlevel(option2 - 1);
                } else if (option2 == 10) {
                    cout << "Returning to main menu..." << endl;
                } else {
                    cout << "Please enter a valid level number" << endl;
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
