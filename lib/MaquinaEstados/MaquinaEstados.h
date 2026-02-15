#ifndef MAQUINA_ESTADOS_H
#define MAQUINA_ESTADOS_H
#include <Arduino.h>

// 1. Agregamos la nueva emocion al diccionario
enum EstadoNodo {
    DURMIENDO,
    FELIZ,
    ENOJADO  // <--- ESTO ES LO QUE EL COMPILADOR NO ENCONTRABA
};

class MaquinaEstados {
  private:
    EstadoNodo estadoActual;
    
    // Temporizadores de estados
    unsigned long tiempoUltimoCambio;
    unsigned long duracionFeliz;
    unsigned long duracionEnojado; // <--- Faltaba esto

    // 2. LA MEMORIA DE NODO (Variables para el estres)
    int contadorAplausos;              // <--- Faltaba esto
    unsigned long tiempoPrimerAplauso; // <--- Faltaba esto
    unsigned long ventanaEstres;       // <--- Faltaba esto

  public:
    MaquinaEstados();
    void inicializar();
    void procesarEventoAudio(bool escuchoFuerte);
    void actualizar();
    EstadoNodo obtenerEstadoActual();
};
#endif