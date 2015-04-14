// Do not remove the include below
#include "ArduinoRobot.h"
#include "NewPing.h"

const int PWRA = 3;
const int PWRB = 11;
const int DIRA = 12;
const int DIRB = 13;
const int BRA = 9;
const int BRB = 8;

const char DIR_FRWD = 'w';
const char DIR_BACK = 's';
const char DIR_LEFT = 'a';
const char DIR_RIGHT = 'd';
const char DIR_STOP = 'x';
const char DIR_BACK_LEFT = 'q';
const char DIR_BACK_RIGHT = 'e';
const char TURN_AROUND_C = '8';
const char TURN_AROUND_CC = '9';




char INBYTE;
#define TRIGGER_PIN 6 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 7 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

bool stand_by = true;



void setup()
{
  pinMode(BRA, OUTPUT);
  pinMode(BRB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

Serial.begin(9600);
Serial.println("Connected");
}
  void goForward()
{
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, HIGH);
  digitalWrite(BRA, LOW);
  digitalWrite(BRB, LOW);

  analogWrite(PWRA, 255);
  analogWrite(PWRB, 255);
}

  void goBackward()
{
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
  digitalWrite(BRA, LOW);
  digitalWrite(BRB, LOW);

  analogWrite(PWRA, 255);
  analogWrite(PWRB, 255);
}

  void goRight()
  {
   digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, HIGH);
  digitalWrite(BRA, LOW);
  digitalWrite(BRB, HIGH);

  analogWrite(PWRA, 255);
}

  void goLeft()
   {
   digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, HIGH);
  digitalWrite(BRA, HIGH);
  digitalWrite(BRB, LOW);

  analogWrite(PWRB, 255);
}

  void Stop()
 {
   digitalWrite(BRA, HIGH);
   digitalWrite(BRB, HIGH);
 }

 void goBackLeft()
 {
   digitalWrite(DIRA, LOW);
   digitalWrite(DIRB, LOW);
   digitalWrite(BRA, HIGH);
   digitalWrite(BRB, LOW);

   analogWrite(PWRB, 255);
 }

 void goBackRight()
 {
   digitalWrite(DIRA, LOW);
   digitalWrite(DIRB, LOW);
   digitalWrite(BRA, LOW);
   digitalWrite(BRB, HIGH);

   analogWrite(PWRA, 255);
 }

 void turnClockwise()
{
  digitalWrite(DIRA, HIGH);
  digitalWrite(DIRB, LOW);
  digitalWrite(BRA, LOW);
  digitalWrite(BRB, LOW);

  analogWrite(PWRA, 255);
  analogWrite(PWRB, 255);

}

void turnCounterClockwise()
{
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, HIGH);
  digitalWrite(BRA, LOW);
  digitalWrite(BRB, LOW);

  analogWrite(PWRA, 255);
  analogWrite(PWRB, 255);
}

void loop()
{
INBYTE = Serial.read();

  switch (INBYTE) {
   case DIR_STOP:
    Serial.print("stop "); Stop(); stand_by = true; break;
   case DIR_FRWD:
    Serial.print("going forward "); goForward(); stand_by = false; break;
   case DIR_BACK:
    Serial.print("going backward "); goBackward(); stand_by = false;  break;
   case DIR_LEFT:
    Serial.print("going left "); goLeft(); stand_by = false; break;
   case DIR_RIGHT:
    Serial.print("going right "); goRight(); stand_by = false; break;
   case DIR_BACK_LEFT:
    Serial.print("going backwards left "); goBackLeft(); stand_by = false; break;
   case DIR_BACK_RIGHT:
    Serial.print("going backwards right "); goBackRight(); stand_by = false; break;
   case TURN_AROUND_C:
    Serial.print("turning clockwise "); turnClockwise(); stand_by = false; break;
   case TURN_AROUND_CC:
    Serial.print("turning counterclockwise "); turnCounterClockwise(); stand_by = false; break;
   default:
     break;
  }

delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
unsigned int uS = sonar.ping(); // Send ping, get ping time in microseconds (uS).
Serial.print("Ping: ");
Serial.print(uS / US_ROUNDTRIP_CM); // Convert ping time to distance in cm and print result (0 = outside set distance range)
Serial.println("cm");

if (uS / US_ROUNDTRIP_CM < 20 && stand_by) {
  Stop();
  delay(1000);
  goRight();
}
else if (uS / US_ROUNDTRIP_CM < 5 && stand_by) {
  goBackward();
  delay(500);
  Stop();
}

}

