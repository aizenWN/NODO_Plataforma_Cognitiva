#ifndef GESTOR_PANTALLA_H
#define GESTOR_PANTALLA_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <MaquinaEstados.h> // Necesitamos saber los estados de NODO

class GestorPantalla {
  private:
    Adafruit_SSD1306 display;
    EstadoNodo estadoAnterior; // Para no dibujar la pantalla a lo loco
    
    void dibujarCaraDurmiendo();
    void dibujarCaraFeliz();

  public:
    GestorPantalla();
    void inicializar();
    void actualizar(EstadoNodo estadoActual);
};

#endif