#ifndef GESTOR_PANTALLA_H
#define GESTOR_PANTALLA_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MaquinaEstados.h"

#define ANCHO_PANTALLA 128
#define ALTO_PANTALLA 64
#define RESET_OLED -1

class GestorPantalla {
  private:
    Adafruit_SSD1306 pantalla;
    
    // Variables para la animacion "Zzz..."
    unsigned long tiempoUltimaAnimacionZzz;
    int faseAnimacionZzz; // 0: nada, 1: Z, 2: Zz, 3: Zzz

    // Funciones privadas de dibujo
    void dibujarCaraDurmiendo();
    void dibujarCaraFeliz();
    void dibujarCaraEnojada();

  public:
    GestorPantalla();
    void inicializar();
    void actualizar(EstadoNodo estadoActual);
};
#endif