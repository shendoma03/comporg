
#include <NewPing.h>
#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
int steamSensor;
int ledR=5; int ledG=4; int buzzer = 13; 
void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
  pinMode(ledR, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
 //Sonic
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  int Sval = sonar.ping_cm();
  if(Sval <=5 && Sval != 0){onRed(); }else {offRed();}
  //Serial.print(Sval); // Send ping, get distance in cm and print result (0 = outside set distance range)
 // Serial.println("cm");
 //sonic

   //steam
  steamSensor = analogRead(A0);
  //Serial.println(steamSensor);
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
}
void onRed (){
  digitalWrite(ledR, HIGH);  
  }
void offRed (){
  digitalWrite(ledR, LOW);  
  }

