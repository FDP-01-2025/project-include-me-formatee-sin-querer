[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/mi1WNrHU)
# Proyecto de C++ - [Type Master]

## Tematica del juego
Este juego está ambientado en un entorno educativo y de entrenamiento mental. El objetivo es mejorar la velocidad y precisión al escribir en teclado, con un estilo amigable, tipo consola, diseñado para estudiantes o cualquier persona que quiera practicar mecanografía, cada nivel representa un reto con palabras cada vez más difíciles. Entre ciertos niveles, el jugador accede a minijuegos sorpresa que ponen a prueba otros aspectos como lógica y reflejos.

## 🕹️ Mecánica Principal
- El jugador selecciona desde un menú el nivel que desea jugar.
- Cada nivel contiene 7 palabras que deben ser escritas correctamente.
- Por cada acierto, el jugador gana un punto.
- Al completar el nivel, se muestra el total de aciertos.
- Cada 3 niveles (nivel 3, 6 y 9), se activa un **minijuego especial** que puede otorgar puntos adicionales o simplemente servir de entretenimiento.

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

## Descripción del Proyecto

Breve descripción del juego, su propósito, cómo se juega y cualquier otro detalle importante que describa la idea general del proyecto.

**Por ejemplo:**
Este proyecto consiste en un juego de aventuras donde el jugador debe explorar un mundo virtual, recoger objetos, resolver acertijos y enfrentar enemigos. El juego utiliza estructuras de control como `if`, `switch`, y bucles `while` y `for` para generar interacciones dinámicas.

## Equipo

- **Nombre del equipo:** [ME FORMATEE SIN QUERER]

### Integrantes del equipo

1. **Nombre completo:** [Diego Leonardo Melara Munguia]  
   **Carnet:** [00180825]

2. **Nombre completo:** [Robert Stanley Colocho Andrade]  
   **Carnet:** [00054625]

## Instrucciones de Ejecución

1. Clona este repositorio en tu máquina local:
   ```bash
   git clone [URL del repositorio]
