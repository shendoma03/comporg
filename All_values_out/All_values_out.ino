#include <NewPing.h> // sonic library 

#define TRIGGER_PIN  8 // Red Wire
#define ECHO_PIN     7  // Orange Wire 
#define MAX_DISTANCE 200 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int steamSensor;

void setup() 
{
  Serial.begin(9600);//basta 9600 
}

void loop() {
 
 //sonic
 Serial.print("Sonic Value= ");
 Serial.print(sonar.ping_cm());//send to object
 Serial.println("cm");
 //end sonic

  //steam
  steamSensor = analogRead(A0);
  Serial.println(steamSensor);
  delay(3000);
 //end steam
 

 //waterLevel
 int wtrLevel = analogRead(A3);//
      if(wtrLevel >= 700){
        Serial.println("No water ");Serial.println(wtrLevel);
        }else if (wtrLevel<=5){
          Serial.println("HIGH ");Serial.println(wtrLevel);
          }else if (wtrLevel >=6 && wtrLevel < 690){
            Serial.println("LOW ");Serial.println(wtrLevel);
            }
            
 //end waterLevel


 

}
