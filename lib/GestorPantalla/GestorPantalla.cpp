#include "GestorPantalla.h"

GestorPantalla::GestorPantalla() : pantalla(ANCHO_PANTALLA, ALTO_PANTALLA, &Wire, RESET_OLED) {
    // Inicializamos las variables de animacion
    tiempoUltimaAnimacionZzz = 0;
    faseAnimacionZzz = 0;
}

void GestorPantalla::inicializar() {
    if(!pantalla.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("Fallo al iniciar SSD1306 OLED"));
        for(;;); // Bucle infinito si falla la pantalla
    }
    pantalla.clearDisplay();
    pantalla.display();
}

void GestorPantalla::actualizar(EstadoNodo estadoActual) {
    pantalla.clearDisplay();

    if (estadoActual == DURMIENDO) {
        dibujarCaraDurmiendo();
        // ** NUEVA LOGICA DE ANIMACION DE Zzz... **
        unsigned long tiempoActual = millis();
        if (tiempoActual - tiempoUltimaAnimacionZzz >= 500) { // Cada 0.5 segundos cambia la fase
            faseAnimacionZzz = (faseAnimacionZzz + 1) % 4; // Ciclo 0, 1, 2, 3
            tiempoUltimaAnimacionZzz = tiempoActual;
        }

        pantalla.setTextSize(1);      // Tamaño de letra
        pantalla.setTextColor(SSD1306_WHITE); // Color de letra

        if (faseAnimacionZzz == 1) {
            pantalla.setCursor(100, 10); // Posicion de la Z
            pantalla.print("Z");
        } else if (faseAnimacionZzz == 2) {
            pantalla.setCursor(95, 10);
            pantalla.print("Zz");
        } else if (faseAnimacionZzz == 3) {
            pantalla.setCursor(90, 10);
            pantalla.print("Zzz");
        }
        // Cuando es fase 0 no dibuja nada (simula el parpadeo de las Zzz...)

    } else if (estadoActual == FELIZ) {
        dibujarCaraFeliz();
        faseAnimacionZzz = 0; // Resetear animacion al despertar
    } else if (estadoActual == ENOJADO) {
        dibujarCaraEnojada();
        faseAnimacionZzz = 0; // Resetear animacion al despertar
    }

    pantalla.display();
}

void GestorPantalla::dibujarCaraDurmiendo() {
    // Dos lineas horizontales (Ojos cerrados)
    pantalla.drawLine(30, 32, 50, 32, SSD1306_WHITE);
    pantalla.drawLine(78, 32, 98, 32, SSD1306_WHITE);
}

void GestorPantalla::dibujarCaraFeliz() {
    // Dos rectangulos o circulos como ojos muy abiertos
    pantalla.fillCircle(40, 32, 10, SSD1306_WHITE);
    pantalla.fillCircle(88, 32, 10, SSD1306_WHITE);
}

void GestorPantalla::dibujarCaraEnojada() {
    // Cejas fruncidas hacia el centro (Diagonales)
    pantalla.drawLine(25, 20, 50, 35, SSD1306_WHITE); // Ceja izquierda \ .
    pantalla.drawLine(103, 20, 78, 35, SSD1306_WHITE); // Ceja derecha  /
    
    // Ojos (Puntos debajo de las cejas)
    pantalla.fillCircle(40, 40, 5, SSD1306_WHITE);
    pantalla.fillCircle(88, 40, 5, SSD1306_WHITE);
}