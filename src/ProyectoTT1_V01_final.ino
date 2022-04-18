#include <LiquidCrystal.h>
#include <Servo.h>
#include <dht.h>
#define DHT11_PIN 8 
dht DHT;

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
Servo barreraEntrada;
Servo barreraSalida;

int intensidadLuz = A0; 
int intensidad =0;

int pulsadorIngreso = 22;
int pulsadorSalida = 23;

int lucesExterior =28;

int echoSensorEntrada = 24;
int triggSensorEntrada = 25;

int echoSensorSalida = 26;
int triggSensorSalida = 27;

int lucesInternas =29;
int sensorMovimiento =30;

float distanciaCm =0;
float tiempoSensor =0;

int maxAutos =5;
int contAutos =0;

bool seAbrioBarreraEntrada = false;
bool seAbrioBarreraSalida = false;
bool estacionamientoLleno = false;

unsigned long tiempoTemp = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  
  barreraEntrada.attach(10);
  barreraSalida.attach(9);

  pinMode(pulsadorIngreso,INPUT);
  pinMode(pulsadorSalida,INPUT);
  pinMode(echoSensorEntrada, INPUT);
  pinMode(echoSensorSalida, INPUT);
  pinMode(sensorMovimiento, INPUT);
 
  pinMode(triggSensorEntrada, OUTPUT);
  pinMode(triggSensorSalida, OUTPUT);
  pinMode(lucesExterior, OUTPUT);
  pinMode(lucesInternas, OUTPUT);

  inicio();
}

void loop() {
  medirTemperatura();
  entradaAutos();
  salidaAutos();
  luzFrenteGaraje();
  luzInternaGaraje();
  verificarDisponibilidadEstacionamiento();
  delay (50);     
}

void inicio(){
  cerrarBarreraEntrada();
  cerrarBarreraSalida();
  mostrarCantidadAutos();
  apagarLuces();
}

void entradaAutos(){
  if (digitalRead(pulsadorIngreso)==HIGH && contAutos < maxAutos){
    seAbrioBarreraEntrada = true;
    abrirBarreraEntrada();
    delay (10);
  }
  if (seAbrioBarreraEntrada){
    realizarMedicion(triggSensorEntrada,echoSensorEntrada);
    }
    
  if (distanciaCm <= 5 && seAbrioBarreraEntrada){
    entroAuto();
   }
  delay (10);
}

void salidaAutos(){
  if (digitalRead(pulsadorSalida)==HIGH && contAutos >= 1){
    seAbrioBarreraSalida = true;
    abrirBarreraSalida();
    delay (10);
  }
  if (seAbrioBarreraSalida){
    realizarMedicion(triggSensorSalida, echoSensorSalida);
  }

  if (distanciaCm <= 5 && seAbrioBarreraSalida ){
    salioAuto();
  }
  delay (10);
}

void medirTemperatura(){
  if (millis() >tiempoTemp + 2000){
    DHT.read11(DHT11_PIN);
    tiempoTemp = millis();
    mostrarTemperatura();
  }
}

float realizarMedicion(int trigger, int echo ){
  digitalWrite (trigger, LOW);
  delayMicroseconds(5);
  digitalWrite (trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  tiempoSensor = pulseIn(echo, HIGH);
  distanciaCm =(0.01715*tiempoSensor);
  return distanciaCm;
}

void mostrarCantidadAutos(){
  lcd.setCursor(0, 0);
  if (estacionamientoLleno){
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("SIN LUGARES");
  }else{
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("AUTOS: ");
    lcd.print(contAutos);
  }
}

void mostrarTemperatura(){
  lcd.setCursor(0, 1);
  lcd.print("T(C)= ");
  lcd.print(DHT.temperature);
}

void entroAuto(){
  contAutos ++;
  mostrarCantidadAutos();
  delay (10);
  cerrarBarreraEntrada();
  seAbrioBarreraEntrada = false;
}

void salioAuto(){
  contAutos --;
  mostrarCantidadAutos();
  delay (10);
  cerrarBarreraSalida();
  seAbrioBarreraSalida = false;
}

void luzFrenteGaraje(){
  intensidad = analogRead (intensidadLuz); 

  if (intensidad >700){
    digitalWrite(lucesExterior,LOW);
  }else{
    digitalWrite(lucesExterior,HIGH);
  }
}

void luzInternaGaraje(){
  if (digitalRead(sensorMovimiento)==HIGH){
    digitalWrite (lucesInternas, HIGH);
    delay (10); 
  }else{
    digitalWrite (lucesInternas, LOW);
  }
}

void apagarLuces(){
  digitalWrite (lucesInternas, LOW);
  digitalWrite(lucesExterior,LOW);
}

void verificarDisponibilidadEstacionamiento(){
  if (contAutos == maxAutos){
    estacionamientoLleno = true;
    mostrarCantidadAutos();
  }else{
    estacionamientoLleno = false;
    mostrarCantidadAutos();
  }
}

void abrirBarreraEntrada(){
  barreraEntrada.write(61);
}

void cerrarBarreraEntrada(){
  barreraEntrada.write(151);
}

void abrirBarreraSalida(){
  barreraSalida.write(61);
}

void cerrarBarreraSalida(){
  barreraSalida.write(151);
}
