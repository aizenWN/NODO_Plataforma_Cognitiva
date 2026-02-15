#ifndef MAQUINA_ESTADOS_H
#define MAQUINA_ESTADOS_H

#include <Arduino.h>

// Definimos los posibles "estados de ánimo" de NODO
enum EstadoNodo {
    DURMIENDO,
    FELIZ
};

class MaquinaEstados {
  private:
    EstadoNodo estadoActual;
    unsigned long tiempoUltimoCambio; // Para saber a qué hora cambió de estado
    unsigned long duracionFeliz;      // Cuánto tiempo durará feliz (en milisegundos)

  public:
    MaquinaEstados();
    
    void inicializar();
    void procesarEventoAudio(bool escuchoFuerte); // NODO reacciona al audio
    void actualizar();                            // NODO piensa por sí mismo
    
    EstadoNodo obtenerEstadoActual();             // Para que otros módulos sepan cómo está NODO
};

#endif