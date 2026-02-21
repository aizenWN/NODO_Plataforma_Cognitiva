## Bitácora v0.2: Expansión Sensorial (Zumbador)
- **Logro 1:** Integración exitosa de un zumbador pasivo.
- **Hardware:** Conectado al pin `~3` del Arduino UNO. Descubrí que la tilde (`~`) significa PWM (Modulación por Ancho de Pulso), indispensable para generar las frecuencias de las notas musicales con la función `tone()`.
- **Software:** Se creó el módulo independiente `EmisorAudio` siguiendo la Clean Architecture. NODO ahora reproduce una melodía de inicio y un sonido al pasar al estado FELIZ.

## Finalización v0.2: Animaciones y Calibración
- **Ajuste de sensibilidad:** Se subió el cooldown del micrófono a 600ms para evitar falsos positivos con la voz humana.
- **Lógica de estrés:** NODO se enoja tras 5 sonidos fuertes en una ventana de 5 segundos.
- **Animación:** Se implementó un sistema de fases (0-3) para mostrar "Zzz..." de forma cíclica cada 500ms durante el estado DURMIENDO.
- **Audio:** Se integraron frecuencias graves (150Hz y 100Hz) para el estado ENOJADO.