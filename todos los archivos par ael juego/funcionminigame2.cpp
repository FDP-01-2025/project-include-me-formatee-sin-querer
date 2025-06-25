#include <iostream> 

using namespace std;

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