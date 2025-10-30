## Información del proyecto
Nombre del proyecto: Termostato Bluetooth

Autores: 
- 1499106 Efraín Treviño Garza 
- 1724347 José Francisco Jasso González
- 1817537 Carlos Alejandro Vázquez López  

Docente: Ing. Héctor Hugo Flores Moreno

Materia: Laboratorio de Controladores y Microcontroladores Programables

Fecha: [30/10/2025]

# Termostato Bluetooth

## Descripción general

El proyecto **Termostato Bluetooth** consiste en la implementación de un sistema de control térmico automatizado utilizando una placa **Arduino UNO R3**, sensores, actuadores y módulos de comunicación inalámbrica (Bluetooth y Wi-Fi). El sistema permite monitorear la temperatura ambiente, definir un umbral térmico deseado y activar dispositivos de ventilación o calefacción según las condiciones detectadas. Se simula en Tinkercad y está adaptado a las condiciones climáticas de Monterrey, Nuevo León.


## Que problema resuelve 

Un termostato es un dispositivo que regula la temperatura de un entorno activando sistemas de calefacción o ventilación según un umbral definido. Se utiliza comúnmente en hogares, oficinas, vehículos y equipos industriales para mantener condiciones térmicas óptimas y seguras.

Este proyecto resuelve la falta de herramientas accesibles para comprender cómo funciona un sistema de control térmico automatizado. Permite simular el comportamiento de un termostato real, mostrando cómo un microcontrolador puede tomar decisiones en tiempo real basadas en sensores, entradas del usuario y lógica programada.

Además, sirve como plataforma educativa para aprender sobre:

- Sensado de variables físicas (como temperatura)
- Procesamiento lógico con microcontroladores
- Activación de actuadores según condiciones ambientales
- Comunicación inalámbrica con dispositivos móviles

## Propósito 

El propósito principal es demostrar el funcionamiento de un sistema de control térmico en tiempo real. También busca reforzar el aprendizaje de programación, electrónica y comunicación serial, mostrando cómo integrar múltiples dispositivos en una arquitectura modular y funcional.

## Funcionamiento Interno

El sistema está dividido en cuatro bloques funcionales:

- Entrada: incluye el sensor TMP36, potenciómetro, pulsador y app móvil. Estos elementos definen el estado térmico y el umbral deseado.
- Comunicación: se realiza mediante los módulos Bluetooth HC-05 y Wi-Fi ESP8266, que permiten enviar y recibir datos desde una app móvil.
- Procesamiento: el Arduino UNO R3 interpreta las señales, ejecuta la lógica condicional y decide qué actuadores activar.
- Salida: el motor de CC simula el ventilador, el LED rojo representa el calefactor, y el LED RGB indica visualmente el estado térmico.

## Contexto 

El proyecto se desarrolla en el entorno de simulación Tinkercad, con componentes reales y simbología electrónica estandarizada. Está contextualizado para operar dentro de los rangos térmicos típicos de Monterrey, lo que refuerza su aplicabilidad práctica y académica.

### Requisitos de hardware
- **Placa:** Arduino UNO R3  
- **Componentes:**
  - Sensor de temperatura TMP36
  - Potenciómetro 250 kΩ
  - Pulsador
  - Motor de CC
  - LED rojo
  - LED RGB
  - Módulo Bluetooth HC-05
  - Módulo Wi-Fi ESP8266
  - Resistencias 220 Ω (x5)
  -  20 kΩ y 10 kΩ (divisor de voltaje)
  - Protoboard y cables de conexión

### Requisitos de software y librerías
Se requieren las siguientes librerías de Arduino:

| Librería | Función principal |

SoftwareSerial | Comunicación serial con Bluetooth y Wi-Fi
ESP8266WiFi | Conexión a red Wi-Fi y manejo de datos remotos
Adafruit NeoPixel | Control de LED RGB (opcional)
Servo	Control de servomotores | (si se extiende el proyecto)

## Cómo usarlo

### Ejecución básica
1. Abre el archivo del proyecto en Tinkercad o Arduino IDE.
2. Verifica que las librerías necesarias estén instaladas.
3. Conecta la placa Arduino UNO R3 al puerto USB.
4. Carga el código al microcontrolador.
5. Ajusta el potenciómetro o envía el umbral desde la app móvil.
6. Observa cómo el sistema responde activando el ventilador o el calefactor según la temperatura ambiente.

### Ejemplo de funcionamiento

- Girar el potenciómetro → define el umbral térmico local.
- Presionar el pulsador → activa modo o reinicia el sistema.
- Temperatura alta → se activa el motor (ventilador).
- Temperatura baja → se enciende el LED rojo (calefactor).
- LED RGB → indica el estado térmico general.
- App móvil → permite definir el umbral vía Bluetooth o Wi-Fi.

## Estructura del proyecto

```
📁 Proyecto-Termostato-Bluetooth/
├── README.md
├── termostato_bluetooth1.ino
├── /docs
│   ├── Actividad 6.pdf
│   └── Actividad 7.pdf
│   └── Actividad 8.pdf
├── /diagramas
│    ├── Diagrama de Bloques.png
│    └── Diagrama Esquematico.png
│    └── Diagrama Pictorico.png
│    └── Lista de Componentes.png
└── /lib
    ├── ESP8266WiFi/
    ├── SoftwareSerial/
    └── otras_librerías/
```

## Diagramas del proyecto

**Diagrama Pictórico: muestra la disposición física de todos los componentes.** ![Diagrama pictórico del proyecto](diagramas/Diagrama%20Pictorico.png)

**Diagrama de Bloques: explica la interacción entre los módulos principales (entrada, comunicación, procesamiento y salida).**![Diagrama de bloques del proyecto](diagramas/Diagrama%20de%20Bloques.png)

**Diagrama Esquemático: representa las conexiones eléctricas del sistema.** ![Diagrama esquematico del proyecto](diagramas/Diagrama%20Esquematico.png)

## Resumen Técnico 

El proyecto Termostato Bluetooth implementa una arquitectura Entrada–Comunicación–Procesamiento–Salida. Utiliza un Arduino UNO R3 como núcleo, gestionando sensores, actuadores y módulos de comunicación inalámbrica. El código está estructurado de forma modular, permitiendo la integración de lógica condicional, visualización y control remoto. Este diseño permite simular un sistema de climatización inteligente, aplicable en contextos educativos y domésticos.

## FAQ (Preguntas frecuentes)

- Por qué no se activa el motor? 
Verifica que la temperatura ambiente supere el umbral definido y que el motor esté conectado correctamente.

- ¿El LED RGB no cambia de color? 
Revisa las salidas PWM del Arduino y asegúrate de que el código esté asignando los colores según el estado térmico.

- ¿El ESP8266 no responde? 
Confirma que el divisor de voltaje esté correctamente conectado y que la red Wi-Fi esté disponible.

- ¿El Bluetooth no se conecta? 

Asegúrate de que el módulo HC-05 esté emparejado con la app móvil y que el puerto serial esté configurado correctamente.
