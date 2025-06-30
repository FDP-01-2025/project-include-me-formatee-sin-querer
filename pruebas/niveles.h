#ifndef NIVELES_H
#define NIVELES_H

#include <iostream>
#include "minijuegos.h"
using namespace std;

const int WORD_SIZE = 24;
const int WORDS_BY_LEVEL = 7;
const int TOTAL_LEVELS = 9;

char levels[TOTAL_LEVELS][WORDS_BY_LEVEL][WORD_SIZE] = {
    {"sol", "pan", "flor", "mar", "luz", "voz", "nube"},
    {"cielo", "perro", "libro", "silla", "nino", "verde", "dulce"},
    {"camino", "raton", "estrella", "jardin", "hojas", "puerta", "sonido"},
    {"ventana", "montana", "cuaderno", "caballo", "carretera", "invierno", "espejo"},
    {"murcielago", "dificultad", "crepusculo", "fosforo", "sabiduria", "albahaca", "caracter"},
    {"paralelepipedo", "murmullo", "hiperbole", "transversal", "holgazan", "efimero", "anfitrion"},
    {"otorrinolaringologo", "cauterizacion", "subconsciente", "anticonstitucional", "circunferencia", "desenlace", "incongruencia"},
    {"electroencefalograma", "desoxirribonucleico", "inconstitucionalidad", "invertebrado", "indestructible", "desenmascaramiento", "infalsificable"},
    {"anticonstitucionalmente", "ininteligibilidad", "desafortunadamente", "transustanciacion", "incomprehensibilidad", "otorrinolaringologia", "descontextualizacion"},
};

bool comparewords(const char word1[], const char word2[]) {
    for (int i = 0; word1[i] != '\0' || word2[i] != '\0'; i++) {
        if (word1[i] != word2[i]) {
            return false;
        }
    }
    return true;
}

int playlevel(int level) {
    char entry[WORD_SIZE];
    int points = 0;

    for (int i = 0; i < WORDS_BY_LEVEL; i++) {
        cout << "palabra: " << levels[level][i] << endl;
        cout << "escribe: ";
        cin >> entry;
        if (comparewords(levels[level][i], entry)) {
            points++;
            cout << "correcto" << endl;
        } else {
            cout << "incorrecto! era: " << levels[level][i] << endl;
        }
    }

    cout << "nivel " << (level + 1) << " completado. Puntos: " << points << " / " << WORDS_BY_LEVEL << "\n";

     // Mostrar minijuego después del nivel 3, 6 y 9
    if (level == 2) {
        minigame1();
    } else if (level == 5) {
        minigame2();
    } else if (level == 8) {
        minigame3();
    }
    
    return points;
}

#endif
