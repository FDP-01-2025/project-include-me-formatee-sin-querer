[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Type Master]

## Tematica del juego
Este juego está ambientado en un entorno educativo y de entrenamiento mental. El objetivo es mejorar la velocidad y precisión al escribir en teclado, con un estilo tipo consola, diseñado para estudiantes o cualquier persona que quiera practicar mecanografía, cada nivel representa un reto con palabras cada vez más difíciles. Entre ciertos niveles, el jugador accede a minijuegos sorpresa que ponen a prueba otros aspectos como lógica y reflejos.

## 🕹️ Mecánica Principal
- El jugador selecciona desde un menú el nivel que desea jugar.
- Cada nivel contiene 7 palabras que deben ser escritas correctamente.
- Por cada acierto, el jugador gana un punto.
- Al completar el nivel, se muestra el total de aciertos.
- Cada 3 niveles (nivel 3, 6 y 9), se activa un **minijuego** que puede otorgar puntos adicionales o simplemente servir de entretenimiento.

## 🎯 Idea General de la Jugabilidad
- Juego de consola basado en **entrada de texto**.
- Interfaz simple e intuitiva para navegar por el menú y elegir niveles.
- Los niveles aumentan progresivamente en dificultad, comenzando con palabras básicas como "sol" o "nube" y terminando con términos complejos y largos como "anticonstitucionalmente".
- Incluye **3 minijuegos** distintos:
- **Minijuego 1:** Adivinar una palabra oculta en una sopa de letras.
- **Minijuego 2:** Resolver una pista horizontal y vertical tipo crucigrama.
- **Minijuego 3:** Escribir palabras lo más rápido posible, midiendo el tiempo con un cronómetro.

## 🛠️ Consideraciones Técnicas del Desarrollo
- Lenguaje: **C++**
- Estructura modular con múltiples archivos `.h`:
- `menu.h`: Controla la navegación y selección de niveles.
- `niveles.h`: Contiene las palabras por nivel y la lógica de evaluación.
- `minijuegos.h`: Incluye los tres minijuegos.
- `funciontiempo.h`: Implementa funciones de tiempo como la cuenta regresiva.
- Lógica central agrupada en `main.cpp`, que solo llama a `menuGame()` para mantener el código limpio y organizado.
- No se utilizan librerías externas, lo que permite su compilación en cualquier entorno estándar de C++.
- Asegura portabilidad y legibilidad del código con comentarios claros en cada archivo.

## 📄 Descripción del Proyecto

Este proyecto consiste en un juego de mecanografía por consola titulado **Type Master**, cuyo propósito es ayudar al jugador a mejorar su precisión y velocidad al escribir. El jugador debe escribir correctamente las palabras que se le presentan en pantalla, organizadas en 9 niveles de dificultad creciente. 

Cada nivel contiene 7 palabras, y al completar ciertos niveles (3, 6 y 9), el jugador accede a un minijuego sorpresa que prueba otras habilidades como memoria, lógica o reflejos. Estos minijuegos son una forma divertida de romper la rutina y agregar variedad al reto.

El juego hace uso de estructuras de control como `if`, `switch`, y bucles `while` y `for` para manejar el flujo del menú, los niveles, la entrada del usuario y la lógica de los minijuegos. La arquitectura del código se organiza en múltiples archivos `.h` para mantener una buena estructura modular y facilitar el mantenimiento del código.

Este proyecto es ideal para principiantes en programación que desean aplicar conceptos básicos de C++ en un contexto práctico, entretenido y educativo.

## 🖼️ Imágenes o Mockups del Juego

A continuación se presentan ejemplos de cómo se ve el juego en la consola en distintos momentos del juego.

### 📋 Menú Principal

-------- Menu ---------

Jugar

Salir
Escoge una opcion:

### 🎯 Selección de Nivel

-------- Levels ---------

Nivel 1

Nivel 2

Nivel 3

Nivel 4

Nivel 5

Nivel 6

Nivel 7

Nivel 8

Nivel 9

Regresar al menu principal
Escoge el nivel:

### ✍️ Juego en Acción (Ejemplo de Nivel)

palabra: nube
escribe: nube
correcto

palabra: pan
escribe: pam
incorrecto! era: pan

nivel 1 completado. Puntos: 6 / 7

### 🧠 Minijuego 1 – Adivina la palabra

Bienvenido al primer minijuego en donde podras ganar 100 puntos extra:
A O M E X
A A C C E
F G A I J
K S M A O
A Q R S T

Busca y adivina la palabra solo tienes un intento asi que buena suerte (escribe la respuesta en MAYUSCULAS):

### ⏱️ Minijuego 3 – Escribe rápido

¡Escribe la palabra: programacion!
desarrollo
Incorrecto. La palabra correcta era: programacion
Tu respuesta: desarrollo
Tiempo: 3184 ms.

## ⚙️ Explicación del Funcionamiento del Juego

El juego **"Desafío de Palabras"** está desarrollado en C++ y funciona completamente en consola. A continuación, se detalla cómo funciona internamente:

### 1. Inicio del Programa
Al ejecutar el programa, el `main.cpp` llama directamente a la función `menuGame()`, ubicada en `menu.h`. Esto abre el menú principal del juego.

---

### 2. Menú Principal (`menuGame`)
El jugador puede elegir entre:
- **Jugar**: Muestra un submenú con los 9 niveles disponibles.
- **Salir**: Termina el programa.

La selección se maneja con estructuras `while` y `switch`.

---

### 3. Niveles (`niveles.h`)
Cada nivel contiene **7 palabras** almacenadas en un arreglo tridimensional `levels[TOTAL_LEVELS][WORDS_BY_LEVEL][WORD_SIZE]`.  
Cuando el jugador selecciona un nivel:
- Se muestra una palabra.
- El jugador debe escribirla correctamente.
- Se comparan los caracteres ingresados con la palabra original mediante la función `comparewords()`.
- Por cada coincidencia exacta, se suma 1 punto.

Al final del nivel, se muestra el total de puntos obtenidos (máximo 7).

---

### 4. Minijuegos (`minijuegos.h`)
Cada 3 niveles (específicamente después de los niveles 3, 6 y 9), se ejecuta un minijuego diferente:

- **Minijuego 1:** Adivinar una palabra en una cuadrícula de letras.
- **Minijuego 2:** Resolver dos pistas tipo crucigrama.
- **Minijuego 3:** Medición de reflejos escribiendo palabras rápidamente, usando la librería `<chrono>` para calcular el tiempo.

Los minijuegos aparecen automáticamente desde `playlevel()` según el número de nivel.

---

### 5. Tiempo y Espera
Se incluye `funciontiempo.h`, que define la función `waitASecond()`, utilizada para hacer pausas simuladas de 1 segundo, especialmente en las cuentas regresivas del Minijuego 3.

---

### 6. Organización del Código
- Todo el proyecto está dividido en archivos `.h` para modularidad:
  - `menu.h`: menú y navegación.
  - `niveles.h`: lógica de juego y niveles.
  - `minijuegos.h`: minijuegos integrados.
  - `funciontiempo.h`: funciones de tiempo.
- `main.cpp` simplemente ejecuta `menuGame()` para mantener la lógica principal centralizada.

---

### 7. Estructuras de control usadas
- `if`, `else`, `switch` y `while` para controlar la lógica del juego.
- Bucles `for` para recorrer palabras y mostrar contenido.
- Arreglos tridimensionales para almacenar palabras por nivel.
- Uso de `chrono` y `cin/cout` para entrada/salida y temporización.

---

Este diseño modular y organizado facilita el mantenimiento y ampliación del juego en el futuro, por ejemplo, para añadir más niveles, minijuegos o incluso guardar puntajes.


## Equipo

- **Nombre del equipo:** [ME FORMATEE SIN QUERER]

### Integrantes del equipo

1. **Nombre completo:** [Diego Leonardo Melara Munguia]  
   **Carnet:** [00180825]

2. **Nombre completo:** [Robert Stanley Colocho Andrade]  
   **Carnet:** [00054625]
   
3. **Nombre completo:** [Devora Michel Galicia Castro]  
   **Carnet:** [00097325]

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
