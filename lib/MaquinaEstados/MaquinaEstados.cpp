#include "MaquinaEstados.h"

MaquinaEstados::MaquinaEstados() {
    estadoActual = DURMIENDO;
    tiempoUltimoCambio = 0;
    duracionFeliz = 3000; // Estará feliz por 3 segundos (3000 ms)
}

void MaquinaEstados::inicializar() {
    estadoActual = DURMIENDO;
    Serial.println("[ESTADO] NODO está DURMIENDO zzZ...");
}

// Esta función se llama cuando el micrófono detecta un ruido fuerte
void MaquinaEstados::procesarEventoAudio(bool escuchoFuerte) {
    // Si escucha algo fuerte y estaba durmiendo, se despierta feliz
    if (escuchoFuerte && estadoActual == DURMIENDO) {
        estadoActual = FELIZ;
        tiempoUltimoCambio = millis(); // Anotamos la hora exacta en la que se puso feliz
        Serial.println("[ESTADO] ¡NODO está FELIZ! :D");
    }
}

// Esta función debe ejecutarse todo el tiempo en el loop principal
void MaquinaEstados::actualizar() {
    // Si NODO está FELIZ, revisamos el reloj para ver si ya se cansó
    if (estadoActual == FELIZ) {
        // ¿Ya pasaron 3 segundos desde que se puso feliz?
        if (millis() - tiempoUltimoCambio >= duracionFeliz) {
            estadoActual = DURMIENDO; // Se vuelve a dormir
            Serial.println("[ESTADO] NODO se cansó. Volviendo a DORMIR zzZ...");
        }
    }
}

EstadoNodo MaquinaEstados::obtenerEstadoActual() {
    return estadoActual;
}