// codigo basico com display 7 segmentos
// Estacionamento

#include<Arduino.h>
#include <Servo.h> 
Servo servo;

#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8

int x = 0;

int number = 0;

#define pinEnt A0
#define pinSai A1

int valor;

#define ledVermelho 12
#define ledAmarelo 10
boolean estado = LOW;
unsigned long int tempoAnterior = 0;
unsigned long int tempoAnterior2 = 0;

void setup(){
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(pinEnt, INPUT);
  pinMode(pinSai, INPUT);
  
  servo.attach(11);
  Serial.begin(9600);
   servo.write(0);

pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);

digitalWrite(g, HIGH);
digitalWrite(ledVermelho, LOW);
digitalWrite(ledAmarelo, HIGH);

}

void loop() {
  //
  if(millis() - tempoAnterior >= 70){
    tempoAnterior = millis();
    digitalWrite(ledVermelho, estado);
    estado = !estado;
}
//
if(millis() - tempoAnterior2 >= 80){
    tempoAnterior2 = millis();
    digitalWrite(ledAmarelo, estado);
    estado = !estado;
}
//

  if(!digitalRead(pinEnt)){
    x++;
    if(x==1){
      um();
      cancela();
      delay(400);
    }
    else if(x==2){
      dois();
      cancela();
      delay(400);
    }
    else if(x==3){
      tres();
      cancela();
      delay(400);
    }
    else if(x==4){
      quatro();
      cancela();
      delay(400);
      
    }
    else if(x>4){
      letraF();
      delay(500);
      zero();
      delay(500);
      letraF();
      delay(500);
      quatro();
      x=4;
    }
   }
  /////// decrescente
    if(!digitalRead(pinSai)){
    x--;
    if(x==0){
      zero();
      cancela();
      delay(400);
    }
    if(x==1){
      um();
      cancela();
      delay(400);
    }
    else if(x==2){
      dois();
      cancela();
      delay(400);
    }
    else if(x==3){
      tres();
      cancela();
      delay(400);
    }
    else if(x==4){
      quatro();
      cancela();
      delay(400);
    }
    
Serial.println(x);
  }
  
}

 void um(){
  digitalWrite(a, HIGH);
   digitalWrite(b, LOW);
   digitalWrite(c, LOW);
   digitalWrite(d, HIGH);
   digitalWrite(e, HIGH);
   digitalWrite(f, HIGH);
   digitalWrite(g, HIGH);
   delay(100);
 }
 void dois(){
  digitalWrite(a, LOW);
   digitalWrite(b, LOW);
   digitalWrite(c, HIGH);
   digitalWrite(d, LOW);
   digitalWrite(e, LOW);
   digitalWrite(f, HIGH);
   digitalWrite(g, LOW);
   delay(100);
 }
void tres(){
  digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, HIGH);
digitalWrite(f, HIGH);
digitalWrite(g, LOW);
delay(100);
}
void quatro(){
  digitalWrite(a, HIGH);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, HIGH);
digitalWrite(e, HIGH);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(100);
}
void zero(){
  digitalWrite(a, LOW);
digitalWrite(b, LOW);
digitalWrite(c, LOW);
digitalWrite(d, LOW);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, HIGH);
delay(100);
}
void cancela(){
  servo.write(100);
  delay(2800);
  servo.write(0);
}
void letraF(){
  digitalWrite(a, LOW);
digitalWrite(b, HIGH);
digitalWrite(c, HIGH);
digitalWrite(d, HIGH);
digitalWrite(e, LOW);
digitalWrite(f, LOW);
digitalWrite(g, LOW);
delay(100);
}
