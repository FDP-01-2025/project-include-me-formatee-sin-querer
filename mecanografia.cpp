#include <iostream> // Para entrada y salida (cin, cout, endl)
#include <string>   // Para usar string
#include <vector>   // Para usar vector
#include <random>   // Para generar números aleatorios
#include <chrono>   // Mide el tiempo
#include <limits>   // Limpia el buffer de entrada

using namespace std;

// Función para limpiar el buffer de entrada después de leer un número o un carácter
void limpiarBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // 1. Palabras a Escribir: Un arreglo de palabras
    vector<string> palabras = {
        "casa", "perro", "gato", "arbol", "sol", "luna", "agua", "flor", "jugar", "libro"
    };

    // Las palabras por ronda son diferentes
    random_device rd;
    mt19937 generador(rd());

    int puntuacionTotal = 0;
    int palabrasCorrectas = 0;
    int palabrasIncorrectas = 0;
    const int NUMERO_PALABRAS_POR_RONDA = 5; // Limita a 5 palabras por ronda
    const double TIEMPO_LIMITE_POR_PALABRA_SEGUNDOS = 5.0; // 5 segundos por palabra

    cout << "¡Mecanografia Rapida!" << endl;
    cout << "Escribe cada palabra. " << TIEMPO_LIMITE_POR_PALABRA_SEGUNDOS << "s por palabra." << endl;
    cout << "Presiona Enter para iniciar..." << endl;

    // getline(cin, temp); // Si el buffer puede no estar vacío, usar esto para capturar una línea vacía.
    cin.ignore(); // Espera a que el usuario presione Enter para iniciar

    for (int i = 0; i < NUMERO_PALABRAS_POR_RONDA; ++i) {
        // Seleccionar palabra aleatoria
        uniform_int_distribution<> distribucion(0, palabras.size() - 1);
        string palabraActual = palabras[distribucion(generador)];

        cout << "\n--- Palabra " << (i + 1) << "/" << NUMERO_PALABRAS_POR_RONDA << " ---" << endl;
        cout << palabraActual << endl;
        cout << ">>> ";

        // Temporizador
        auto inicio = chrono::high_resolution_clock::now();
        string entradaUsuario;
        getline(cin, entradaUsuario);
        // 3. Temporizador: Finalizar
        auto fin = chrono::high_resolution_clock::now();
        chrono::duration<double> duracion = fin - inicio;


        // Comprobación de la palabra y el tiempo
        if (entradaUsuario == palabraActual && duracion.count() <= TIEMPO_LIMITE_POR_PALABRA_SEGUNDOS) {
            cout << "¡Correcto!" << endl;
            palabrasCorrectas++;
           
            int puntosObtenidos = 100; // Puntos base
          
            puntosObtenidos += static_cast<int>((TIEMPO_LIMITE_POR_PALABRA_SEGUNDOS - duracion.count()) * 20);
            puntuacionTotal += puntosObtenidos;
            cout << "Puntos: " << puntosObtenidos << endl;
        } else {
            cout << "¡Error o tiempo agotado! Era: " << palabraActual << endl;
            palabrasIncorrectas++;
        }
    }

    // 6. Finalización del Juego
    cout << "\n--- FIN DEL JUEGO ---" << endl;
    cout << "Correctas: " << palabrasCorrectas << endl;
    cout << "Incorrectas: " << palabrasIncorrectas << endl;
    cout << "Total: " << puntuacionTotal << " puntos." << endl;

    cout << "\n¿Jugar de nuevo? (s/n): ";
    char opcion;
    cin >> opcion;
    limpiarBuffer();

    if (opcion == 's' || opcion == 'S') {
        main(); // Recursión: ten cuidado con muchas partidas seguidas.
    } else {
        cout << "¡Adios!" << endl;
    }

    return 0;
}