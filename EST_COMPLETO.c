#include <LiquidCrystal.h>
int num= 100;

const int botao = 1;
int estadoBotao = 0;
 
//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigPin = 6;

const int echoPin = 13;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);

  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  pinMode(botao,INPUT);
}
 
void loop(){
  estadoBotao = digitalRead(botao);
  
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(1, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("ESTACIONAMENTO");
  lcd.setCursor(4, 1);
  if(num>=0){
    lcd.print("VAGAS: ");
    lcd.print(num);
  }
  delay(500);
  
  if (estadoBotao == HIGH) {
    num--;
  }

  int vaga= 0;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);


if (distance > 13 && distance < 3200){
   digitalWrite(8, HIGH); 
   digitalWrite(9, LOW); 
   digitalWrite(10, LOW);     
   digitalWrite(7, LOW);    
  
  }
  else if(distance <13 && distance > 6){
    digitalWrite(9, HIGH);  
    digitalWrite(10, LOW); 
    digitalWrite(8, LOW);
    digitalWrite(7, LOW); 
    
    }
    else if(distance <= 4){
    digitalWrite(10, HIGH); 
    digitalWrite(8, LOW); 
    digitalWrite(9, LOW);  
    digitalWrite(7, HIGH);
    
    }  
}