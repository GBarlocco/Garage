# Garage - Universidad ORT

## Obligatorio N°2 - Proyecto Arduino.

1) Introducción.
Pensando en la cantidad de estacionamientos manuales y antiguos existentes en Montevideo, se nos ocurrió la idea de mejorar, modernizar y actualizar su automatismo para hacerlo más prácticos y útiles adaptándolos a los tiempos que corren.

2) Descripción del sistema actual.
Al hablar de un estacionamiento manual, básico, convencional, nos estamos refiriendo a los siguientes puntos:
- El ingreso y la salida del cliente se realiza con apertura de puerta/barrera manual.
- La iluminación interna y externa se comanda mediante una llave ON/OFF.
- El cliente no puede visualizar ningún aviso de lugares disponibles, entonces, se generan pérdidas de tiempo a la hora de buscar estacionar un vehículo en zonas transitadas.

3) Propuesta de solución.
A continuación, presentaremos la automatización completa del estacionamiento, para ello se tendrán en cuenta los siguientes puntos:

 - Se instalará un panel principal al frente del garaje para indicar la cantidad de lugares disponibles, también mostrará la temperatura actual. Las luces frontales se encenderán con ausencia de luz.

 - La entrada de los vehículos será permitida mediante un pulsador, al accionar el mismo la barrera permite su paso (si existen lugares disponibles), cuando el vehículo se encuentra efectivamente dentro del garaje se actualiza el conteo de lugares disponibles.

 - Se instalarán sensores de movimiento para activar la iluminación del garaje.

- La salida de los vehículos se realizará de la misma manera que la entrada (pulsador + sensor + barrera), cuando se confirme la salida efectiva de un vehículo se incrementarán los lugares disponibles.

4) Listado de materiales:
- 1- Arduino MEGA.
- 2- Pulsadores.
- 2- Servomotores – SG90
- 2- Sensores ultrasónicos – HC-SR04
- 1 Sensor de temperatura y humedad – DHT-11
- 1- Pantalla LCD 16 x 2.
- 1- Sensor de movimiento – HC-SR-501
- 1- LDR.
- 1 – Lámpara 220 VAC.
- 1 – Relé.
- 1- Leds color blanco.
- 2- Resistencias pull down – 10k ohms.
- 1- Resistencia para LDR – 10k ohms.
- 1 Resistencia para LED - 220 ohms.
- 1- Protoboard
- Cables.

5) Mas información...
Para ver el proeycto completo dirigirse al documento "Obligatorio 2 - Taller de tecnologías .pdf"

## Universidad
> [Universidad ORT](https://fi.ort.edu.uy/ingenieria-en-sistemas)

## Curso
> <p>Taller de tecnologías I</p>

## Profesor
> <p>Profesor: Tomás De Angelis Rodríguez</p>

## Author
> <p>Tatiana Mostovaya</p>
> <p>Guillermo López</p>
> <p>Gast�n Barlocco. </p>


## Extra
[Documentation](https://www.arduino.cc) Arduino.
