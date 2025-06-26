void minigame1() {
    char grid[5][5] = {
        {'A', 'O', 'M', 'E', 'X'},
        {'A', 'A', 'C', 'C', 'E'},
        {'F', 'G', 'A', 'I', 'J'},
        {'K', 'S', 'M', 'A', 'O'},
        {'A', 'Q', 'R', 'S', 'T'}
    };

    cout << "Bienvenido al primer minigame en donde podras ganar 100 puntos extra: "<<endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    string guess;
    cout << "Busca y adivina la palabra solo tienes un intento asi que buena suerte: "<<endl;
    cin >> guess;

    if (guess == "CASA") {
        cout << "Felicidades has recibido 100 puntos extras por adivinar la palabra"<<endl;

        guess=100;
    } else {
        cout << "Mas suerte para la proxima amigo"<<endl;
    }
}


/*segundo minijuego*/

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

#include <funciontime.h>
void minigame3(){
    cout<<"Vamos a usar los reflejos ahora para ver que tan rapido eres"<<endl;
    while (true)
    {
        int start;
        cout<<"presiona el numero 1 si estas listo"<<endl;
        cin>>start;

        switch (start)
        {
        case 1:
            /* code */
            break;
        
        default:
        cout<<"porfavor elija la opcion que se le indico"<<endl;
            break;
        }
    }
    
}