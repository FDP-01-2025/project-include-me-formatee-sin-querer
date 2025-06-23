#include <iostream>
using namespace std;

// Función del temporizador
void temporizador(int segundos) {
    for (int i = segundos; i > 0; i--) {
        cout << "Faltan " << i << " segundos..." << endl;

        // Espera simulada
        for (int j = 0; j < 100000000; j++) {
            // Bucle vacío para simular tiempo
        }
    }
    cout << "¡Tiempo terminado!" << endl;
}

int main() {
    int segundos;

    cout << "Ingresa los segundos del temporizador: ";
    cin >> segundos;

    // Llamamos a la función
    temporizador(segundos);

    return 0;
}
g++