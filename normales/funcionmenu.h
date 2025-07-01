#include <iostream>
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
            while (option2 != 7) {
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
                cout << "Choose your level: ";
                cin >> option2;

                switch (option2) {
                case 1: cout << " 1.  Level 1 "<<endl; break;
                case 2: cout << " 2.  Level 2 "<<endl; break;
                case 3: cout << " 3.  Level 3 "<<endl; break;
                case 4: cout << " 4.  Level 4 "<<endl; break;
                case 5: cout << " 5.  Level 5 "<<endl; break;
                case 6: cout << " 6.  Level 6 "<<endl; break;
                case 7: cout << " 7.  Level 7 "<<endl; break;
                case 8: cout << " 8.  Level 8 "<<endl; break;
                case 9: cout << " 9.  Level 9 "<<endl; break;
                default: cout << "Please enter a valid level number"<<endl; break;
                }
            }
            break;
        case 2:
            cout << "Saliendo del programa"<<endl;
            break;
        default:
            cout << "Ingresa una opcion valida del menu"<<endl;
            break;
        }
        cout << endl;
    }
}