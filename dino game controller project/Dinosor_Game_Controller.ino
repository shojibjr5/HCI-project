#include <Keyboard.h>


const int switchh = 2;
const int buzzer = 6;
int buttonState = 1;

int forceThreshold = 900;

void setup() {


  Keyboard.begin();
  Serial.begin(9600);

  pinMode(switchh, INPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(switchh, HIGH);
  digitalWrite(buzzer, LOW);

}

void loop() {

  buttonState = digitalRead(switchh);
  //  Serial.println(buttonState);

  int forceValue = analogRead(A2);
  Serial.print(" force: ");
  Serial.println(forceValue);
  //Serial.print(" force: ");
  //   Serial.println(buttonState);

  if (buttonState == 0) {

    if (forceValue > forceThreshold) {
      Keyboard.press(' ');
      //      Keyboard.println("How are u?");
      digitalWrite(buzzer, HIGH);
      delay(200);

    }
    else {
      Keyboard.releaseAll();
      digitalWrite(buzzer, LOW);
    }

  }
  else {
    Keyboard.releaseAll();
    digitalWrite(buzzer, LOW);
  }

  Keyboard.releaseAll();
  digitalWrite(buzzer, LOW);

}
