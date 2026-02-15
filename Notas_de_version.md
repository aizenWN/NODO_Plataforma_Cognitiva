## Bitácora v0.2: Expansión Sensorial (Zumbador)
- **Logro 1:** Integración exitosa de un zumbador pasivo.
- **Hardware:** Conectado al pin `~3` del Arduino UNO. Descubrí que la tilde (`~`) significa PWM (Modulación por Ancho de Pulso), indispensable para generar las frecuencias de las notas musicales con la función `tone()`.
- **Software:** Se creó el módulo independiente `EmisorAudio` siguiendo la Clean Architecture. NODO ahora reproduce una melodía de inicio y un sonido al pasar al estado FELIZ.