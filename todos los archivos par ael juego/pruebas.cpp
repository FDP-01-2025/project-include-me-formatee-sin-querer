#include <iostream>
using namespace std;

int main(){
// Texto rojo
cout << "\033[31mTexto en rojo\033[0m" << endl;

// Texto verde brillante
cout << "\033[1;32m¡Correcto!\033[0m" << endl;

// Fondo azul con texto blanco
cout << "\033[44;37m  NIVEL 1  \033[0m" << endl;

cout << "\033[1;32mTexto verde brillante\033[0m" << endl;
cout << "\033[44;37mTexto blanco con fondo azul\033[0m" << endl;
cout << "\033[91mAlerta en rojo claro\033[0m" << endl;


    return 0;
}