//Nacimiento de NODO (Nombre Clave) el 14/02/2026 "Plataforma Cognitiva Modular by Marquez Pínto Martin Alejandro

#include <Arduino.h>
#include <ProcesadorAudio.h>
#include <MaquinaEstados.h>
#include <GestorPantalla.h>

ProcesadorAudio oidoDeNodo(A0, 250); 
MaquinaEstados cerebroDeNodo;
GestorPantalla rostroDeNodo; // ¡Nuestro nuevo módulo!

void setup() {
  Serial.begin(115200);
  
  rostroDeNodo.inicializar(); // Iniciamos la pantalla primero
  oidoDeNodo.inicializar();
  cerebroDeNodo.inicializar();
}

void loop() {
  // 1. LEER SENSORES
  bool huboAplauso = oidoDeNodo.detectarEventoFuerte();

  // 2. PROCESAR LÓGICA
  cerebroDeNodo.procesarEventoAudio(huboAplauso);
  cerebroDeNodo.actualizar();

  // 3. ACTUALIZAR HARDWARE (Salida Visual)
  EstadoNodo humorActual = cerebroDeNodo.obtenerEstadoActual();
  rostroDeNodo.actualizar(humorActual);
}