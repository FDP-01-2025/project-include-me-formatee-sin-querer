#include <iostream>

using namespace std;
//funcion para esperar un segundo
void waitASecond() {
    for (int i = 0; i < 1000000000; i++) {
        
    }
}
//va disminuyendo haciendo una espera por el waitASecond
void countdown() {
    for (int i = 10; i > 0; i--) {
        cout << "seconds " << i << endl;
        waitASecond();
    }
    cout << "Its time!" << endl;
}

