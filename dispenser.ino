#include <Arduino.h>
//declaración de las variables para los pines del motor
int motorPin1 = 2;    // Azul   - 28BYJ48 pin 1 motor
int motorPin2 = 3;    // Rosa   - 28BYJ48 pin 2 motor
int motorPin3 = 4;    // Amarillo - 28BYJ48 pin 3 motor
int motorPin4 = 5;    // Naranja - 28BYJ48 pin 4 motor
                     // Rojo   - 28BYJ48 pin 5 (VCC) motor
// Posiciones posibles segun los imagens del motor paso a paso
int positions[8] = {B01000, B01100, B00100, B00110, B00010, B00011, B00001, B01001};

int grados = 360;

void giroMotor();
void setPosition(int out);

void setup(){
  //declare the motor pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  Serial.begin(9600);
}

void loop(){
    if(grados > 0){
        Serial.println(grados);
        giroMotor(); //sentido agujas del reloj
        grados--;
    }else{
        grados = 360;
    }
}
//creación funciones giro horario y antihorario
void giroMotor(){
  for(int i = 0; i < 8; i++){
    Serial.println(i);
    setPosition(i);
    delayMicroseconds(1200);
  }
}

void setPosition(int out){//función secuencia giro
  digitalWrite(motorPin1, bitRead(positions[out], 0));
  digitalWrite(motorPin2, bitRead(positions[out], 1));
  digitalWrite(motorPin3, bitRead(positions[out], 2));
  digitalWrite(motorPin4, bitRead(positions[out], 3));
}
