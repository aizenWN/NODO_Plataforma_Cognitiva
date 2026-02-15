#include "ProcesadorAudio.h"

// Inicializamos las variables de la clase
ProcesadorAudio::ProcesadorAudio(int pin, int umbral) {
    pinMicrofono = pin;
    umbralDeteccion = umbral;
    ventanaTiempo = 50; // 50 milisegundos
}

void ProcesadorAudio::inicializar() {
    pinMode(pinMicrofono, INPUT);
}

// Nuestro algoritmo de "Cresta menos Valle"
int ProcesadorAudio::obtenerAmplitud() {
    unsigned long inicioMillis = millis();
    int valorMaximo = 0;
    int valorMinimo = 1024;

    while (millis() - inicioMillis < (unsigned long)ventanaTiempo) {
        int lectura = analogRead(pinMicrofono);
        if (lectura > valorMaximo) valorMaximo = lectura;
        if (lectura < valorMinimo) valorMinimo = lectura;
    }
    return (valorMaximo - valorMinimo);
}

// La función que usará la Máquina de Estados
bool ProcesadorAudio::detectarEventoFuerte() {
    int amplitudActual = obtenerAmplitud();
    
    // Si la amplitud es mayor a 250, devuelve un VERDADERO (hubo un evento)
    if (amplitudActual > umbralDeteccion) {
        return true;
    } else {
        return false;
    }
}