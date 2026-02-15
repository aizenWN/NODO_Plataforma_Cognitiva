#ifndef EMISOR_AUDIO_H
#define EMISOR_AUDIO_H
#include <Arduino.h>

// Frecuencias basicas para las notas (en Hertz)
#define NOTA_DO  261
#define NOTA_MI  329
#define NOTA_SOL 392
#define NOTA_SI  493
#define NOTA_DO_ALTO 523

class EmisorAudio {
  private:
    int pinBuzzer;

  public:
    // Constructor: Le decimos en que pin esta conectado
    EmisorAudio(int pin);
    
    // Configura el pin como salida
    void inicializar();
    
    // Las dos funciones que pediste
    void reproducirCancionInicio();
    void reproducirSonidoFeliz();
    void reproducirSonidoEnojado();
};
#endif