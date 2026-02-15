#ifndef PROCESADOR_AUDIO_H
#define PROCESADOR_AUDIO_H

#include <Arduino.h>

class ProcesadorAudio {
  private:
    int pinMicrofono;
    int umbralDeteccion;
    int ventanaTiempo;

  public:
    // Constructor: nos permite configurar el pin y el umbral al inicio
    ProcesadorAudio(int pin, int umbral);
    
    void inicializar();           // Configura los pines
    int obtenerAmplitud();        // El cálculo matemático que acabamos de hacer
    bool detectarEventoFuerte();  // Devuelve 'true' si el sonido superó el umbral
};

#endif