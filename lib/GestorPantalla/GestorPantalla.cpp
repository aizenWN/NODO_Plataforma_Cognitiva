#include "GestorPantalla.h"

// Configuramos la pantalla: 128x64 píxeles, usando I2C (Wire)
GestorPantalla::GestorPantalla() : display(128, 64, &Wire, -1) {
    // Iniciamos con un estado imposible para forzar el primer dibujo
    estadoAnterior = (EstadoNodo)-1; 
}

void GestorPantalla::inicializar() {
    // 0x3C es la dirección I2C estándar del 99% de estas pantallas
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("Fallo al iniciar la pantalla OLED"));
        for(;;); // Si falla, nos detenemos aquí
    }
    
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 30);
    display.println("Iniciando NODO...");
    display.display();
    delay(1000); // Pequeña pausa solo para ver el logo de inicio
}

void GestorPantalla::actualizar(EstadoNodo estadoActual) {
    // ¡Anti-Flicker! Solo dibujamos si el estado cambió
    if (estadoActual != estadoAnterior) {
        
        display.clearDisplay(); // Borramos la pantalla
        
        if (estadoActual == DURMIENDO) {
            dibujarCaraDurmiendo();
        } else if (estadoActual == FELIZ) {
            dibujarCaraFeliz();
        }
        
        display.display(); // Mandamos los datos a la pantalla
        estadoAnterior = estadoActual; // Actualizamos nuestro registro
    }
}

void GestorPantalla::dibujarCaraDurmiendo() {
    // Dibujamos dos líneas horizontales (ojos cerrados) zzZ
    // drawLine(x_inicio, y_inicio, x_fin, y_fin, color)
    display.drawLine(30, 32, 50, 32, SSD1306_WHITE);
    display.drawLine(78, 32, 98, 32, SSD1306_WHITE);
    
    // Una Z chiquita
    display.setCursor(100, 10);
    display.print("z");
}

void GestorPantalla::dibujarCaraFeliz() {
    // Dibujamos dos círculos rellenos (ojos bien abiertos)
    // fillCircle(x_centro, y_centro, radio, color)
    display.fillCircle(40, 32, 10, SSD1306_WHITE);
    display.fillCircle(88, 32, 10, SSD1306_WHITE);
    
    // Una boquita feliz
    display.drawPixel(64, 45, SSD1306_WHITE);
    display.drawPixel(63, 44, SSD1306_WHITE);
    display.drawPixel(65, 44, SSD1306_WHITE);
}