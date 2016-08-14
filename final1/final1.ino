#include <NewPing.h> // sonic library 

#define TRIGGER_PIN  8 // Red Wire
#define ECHO_PIN     7  // Orange Wire 
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int steamSensor;
int ledR=5; int ledG=4; int buzzer = 13; 

void setup() 
{
  Serial.begin(9600);//basta 9600 
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
 
 //sonic
 Serial.print("Sonic Value= ");
 Serial.print(sonar.ping_cm());

 
 
 //end sonic

  //steam
  steamSensor = analogRead(A0);
  Serial.println(steamSensor);
  if (steamSensor < 500) {
    onRed();
    }else {
      offRed();
      }
 //end steam
 

 //waterLevel
 int wtrLevel = analogRead(A3);//
     Serial.print("Water Level");
      if(wtrLevel >= 700){
        Serial.println("No water ");Serial.println(wtrLevel);
        }else if (wtrLevel<=5){
          Serial.println("HIGH ");Serial.println(wtrLevel);
          }else if (wtrLevel >=6 && wtrLevel < 690){
            Serial.println("LOW ");Serial.println(wtrLevel);
            }
            
 //end waterLevel
 delay(5000);
}

void onRed (){
  digitalWrite(ledR, HIGH);  
  }
void offRed (){
  digitalWrite(ledR, LOW);  
  }
void b1 (){
  digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);  
  }
void b2 (){
  digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);  
  }
void b3 (){
  digitalWrite(buzzer, HIGH);
  delay(250);
  digitalWrite(buzzer, LOW);  
  }

