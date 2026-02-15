#include "EmisorAudio.h"

EmisorAudio::EmisorAudio(int pin) {
    pinBuzzer = pin;
}

void EmisorAudio::inicializar() {
    pinMode(pinBuzzer, OUTPUT);
}

void EmisorAudio::reproducirCancionInicio() {
    // Un arpegio ascendente rapido y alegre
    tone(pinBuzzer, NOTA_DO, 150);
    delay(150); // Pausa entre notas
    tone(pinBuzzer, NOTA_MI, 150);
    delay(150);
    tone(pinBuzzer, NOTA_SOL, 150);
    delay(150);
    tone(pinBuzzer, NOTA_DO_ALTO, 300); // Nota final mas larga
    delay(300);
}

void EmisorAudio::reproducirSonidoFeliz() {
    // Dos pitidos rapidos y agudos (estilo R2-D2)
    tone(pinBuzzer, NOTA_SI, 100);
    delay(120);
    tone(pinBuzzer, NOTA_DO_ALTO, 150);
    delay(150);
}