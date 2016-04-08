#include <Smartcar.h>

Odometer encoderLeft(180), encoderRight(180); //Βάλτε τους δικούς σας παλμούς ανά μέτρο
Gyroscope gyro(13); //Βάλτε την κατάλληλη τιμή σύμφωνα με το γυροσκόπιό σας
Car folkracer;
boolean state1Done = false;
boolean state2Done = false;

void setup() {
  gyro.attach();
  encoderLeft.attach(3); //Χρησιμοποιήστε τα σωστά pins!
  encoderRight.attach(2);
  encoderLeft.begin();
  encoderRight.begin();
  gyro.begin();
  folkracer.begin(encoderLeft, encoderRight, gyro);
  folkracer.enableCruiseControl();
  folkracer.setSpeed(0.5);
}

void loop() {
  folkracer.updateMotors();
  unsigned long distance = encoderLeft.getDistance();
  distance = distance + encoderRight.getDistance();
  distance = distance / 2;
  if (distance > 20 && distance < 30 && state1Done == false) {
    folkracer.stop();
    folkracer.rotate(180);
    folkracer.setSpeed(0.5);
    state1Done = true;
  }
  if (distance > 80 && distance < 90 && state2Done == false) {
    folkracer.stop();
    folkracer.rotate(90);
    folkracer.setSpeed(0.5);
  }
  if (distance > 150) {//TO-DO
    folkracer.stop();
  }
}
