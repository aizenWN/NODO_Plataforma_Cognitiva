#include "MaquinaEstados.h"

MaquinaEstados::MaquinaEstados() {
    estadoActual = DURMIENDO;
}

void MaquinaEstados::inicializar() {
    estadoActual = DURMIENDO;
    tiempoUltimoCambio = 0;
    
    // Tiempos de las emociones
    duracionFeliz = 3000;   // Se queda feliz 3 segundos
    duracionEnojado = 5000; // Se queda enojado (haciendo berrinche) 5 segundos

    // Variables del estres
    contadorAplausos = 0;
    tiempoPrimerAplauso = 0;
    ventanaEstres = 5000;  // Tiene 10 segundos (10,000 ms) para acumular 3 aplausos
}

void MaquinaEstados::procesarEventoAudio(bool escuchoFuerte) {
    if (escuchoFuerte) {
        unsigned long tiempoActual = millis();

        // Si es el primer aplauso de la racha, guardamos la hora exacta
        if (contadorAplausos == 0) {
            tiempoPrimerAplauso = tiempoActual;
        }

        contadorAplausos++; // Sumamos un aplauso al historial

        // Evaluamos si ya lo estresamos (5 o mas aplausos dentro de la ventana de 10 seg)
        if (contadorAplausos >= 5 && (tiempoActual - tiempoPrimerAplauso) <= ventanaEstres) {
            estadoActual = ENOJADO;
            tiempoUltimoCambio = tiempoActual;
            contadorAplausos = 0; // Despues de explotar de enojo, su mente se resetea
        } 
        // Si no hemos llegado a 3 aplausos, y NODO no esta haciendo berrinche, se pone feliz
        else if (estadoActual != ENOJADO) {
            estadoActual = FELIZ;
            tiempoUltimoCambio = tiempoActual;
        }
    }
}

void MaquinaEstados::actualizar() {
    unsigned long tiempoActual = millis();

    // 1. Logica para calmarse si esta Feliz
    if (estadoActual == FELIZ) {
        if (tiempoActual - tiempoUltimoCambio >= duracionFeliz) {
            estadoActual = DURMIENDO;
        }
    }
    // 2. Logica para calmarse si esta Enojado
    else if (estadoActual == ENOJADO) {
        if (tiempoActual - tiempoUltimoCambio >= duracionEnojado) {
            estadoActual = DURMIENDO;
            contadorAplausos = 0; // Nos aseguramos de que despues del berrinche inicie limpio
        }
    }

    // 3. Olvidar aplausos viejos (Si pasaron mas de 10 seg y no lo estresaste, se le olvida)
    if (contadorAplausos > 0 && (tiempoActual - tiempoPrimerAplauso) > ventanaEstres) {
        contadorAplausos = 0;
    }
}

EstadoNodo MaquinaEstados::obtenerEstadoActual() {
    return estadoActual;
}