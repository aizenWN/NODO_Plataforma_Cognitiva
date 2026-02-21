# Arquitectura de Hardware: NODO v0.2
**Plataforma Principal:** Arduino UNO R3

**Descripción:** Mapeo de conexiones físicas entre los periféricos de entrada/salida y el microcontrolador.

## 1. Módulo de Entrada: Procesador de Audio (Micrófono)
*Tipo de señal: Analógica*
El micrófono captura las ondas sonoras y las convierte en variaciones de voltaje que el Arduino lee y convierte en números mediante su ADC (Convertidor Analógico a Digital). Alimentarlo a 3.3V reduce el ruido eléctrico (estática) y mejora la precisión de la lectura.

| Pin del Micrófono | Pin del Arduino | Función |
| :--- | :--- | :--- |
| **VCC / +** | `3.3V` | Alimentación eléctrica limpia para reducir ruido analógico. |
| **GND / G** | `GND` | Tierra (Cierra el circuito). |
| **AO (Analog Out)**| `A0` | Envía la lectura exacta del volumen de audio al cerebro. |
| *DO (Digital Out)* | *No conectado* | *No lo usamos. Solo envía un pulso fijo si supera un umbral ajustado con el potenciómetro físico.* |

## 2. Módulo de Salida Visual: Gestor de Pantalla (OLED SSD1306)
*Protocolo de comunicación: I2C (Inter-Integrated Circuit)*
Utiliza solo dos cables de datos para comunicarse. Es un protocolo de tipo "Maestro-Esclavo", donde el Arduino (Maestro) le dice a la pantalla (Esclavo en la dirección `0x3C`) qué píxeles encender.

| Pin de la OLED | Pin del Arduino | Función |
| :--- | :--- | :--- |
| **VCC** | `5V` (o `3.3V`) | Alimentación eléctrica. |
| **GND** | `GND` | Tierra. |
| **SCL (Serial Clock)** | `A5` | Reloj que sincroniza la velocidad a la que viajan los datos. |
| **SDA (Serial Data)** | `A4` | El cable por donde viajan los dibujos y las instrucciones. |

## 3. Módulo de Salida Auditiva: Emisor de Audio (Zumbador Pasivo)
*Tipo de señal: PWM (Pulse Width Modulation)*
A diferencia de un pin digital normal (que solo da 0V o 5V estáticos), el pin PWM se enciende y apaga cientos de veces por segundo para crear "frecuencias". Así es como generamos notas musicales (Ej. 261Hz para la nota DO).

| Pin del Zumbador | Pin del Arduino | Función |
| :--- | :--- | :--- |
| **Positivo (+ / Largo)**| `~3` | Recibe los pulsos PWM generados por la función `tone()`. |
| **Negativo (- / Corto)**| `GND` | Tierra. |

---
*Nota de Arquitectura:* Todos los `GND` en electrónica deben estar conectados entre sí ("Ground Común") para que los voltajes tengan la misma referencia.