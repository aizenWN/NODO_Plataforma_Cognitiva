// Nacimiento de NODO (Nombre Clave) el 14/02/2026 "Plataforma Cognitiva Modular" by Marquez Pinto Martin Alejandro.
// v0.2 - Integracion de modulo de audio (Zumbador)

#include <Arduino.h>
#include <ProcesadorAudio.h>
#include <MaquinaEstados.h>
#include <GestorPantalla.h>
#include <EmisorAudio.h> // 1. INCLUIMOS LA NUEVA LIBRERIA

ProcesadorAudio oidoDeNodo(A0, 250); 
MaquinaEstados cerebroDeNodo;
GestorPantalla rostroDeNodo;
EmisorAudio vozDeNodo(3); // 2. CREAMOS EL OBJETO EN EL PIN 3

// Variable para recordar el estado anterior y no repetir el sonido infinitamente
EstadoNodo estadoAnterior = DURMIENDO; 

void setup() {
  Serial.begin(115200);
  
  // 3. INICIALIZAMOS TODO
  rostroDeNodo.inicializar(); 
  vozDeNodo.inicializar();
  oidoDeNodo.inicializar();
  cerebroDeNodo.inicializar();

  // 4. CANCION DE BIENVENIDA AL ENCENDER
  vozDeNodo.reproducirCancionInicio();
}

void loop() {
  // --- INPUT ---
  bool huboAplauso = oidoDeNodo.detectarEventoFuerte();
  
  // --- PROCESS ---
  cerebroDeNodo.procesarEventoAudio(huboAplauso);
  cerebroDeNodo.actualizar();

  // --- OUTPUT ---
  EstadoNodo humorActual = cerebroDeNodo.obtenerEstadoActual();
  
  // Actualizamos la pantalla
  rostroDeNodo.actualizar(humorActual);

  // 5. LOGICA DEL SONIDO FELIZ (Solo suena una vez al cambiar de estado)
  if (humorActual == FELIZ && estadoAnterior == DURMIENDO) {
      vozDeNodo.reproducirSonidoFeliz();
  }
  
  // Guardamos el estado para el siguiente ciclo de loop
  estadoAnterior = humorActual;
}