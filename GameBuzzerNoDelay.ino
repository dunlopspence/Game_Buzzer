//global variables

//pins
const int button1Pin = 2;//button 1
const int button2Pin = 3;//button 2
const int ledPin1 = 4;//button 1 LED
const int ledPin2 = 5;//button 2 LED
const int ledSide1 = 6;//LED row for side 1
const int ledSide2 = 7;//LED row for side 2

//variables for no delay
unsigned long previousMillis = 0;
unsigned long previousMillis2 = 0;
const long interval = 300;

//set LED states to LOW
int led1State = LOW;
int led2State = LOW;

//set button states to low
int buttonState1 = LOW;
int buttonState2 = LOW;

//button pressed boolean
boolean buttonPressed = false;



void setup() {
  //initialize
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(ledSide1, OUTPUT);
  pinMode(ledSide2, OUTPUT);

}

//functions

void blinkLED() {
  unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval) {
      //save last blinked time
      previousMillis = currentMillis;

      if (led1State == LOW && led2State == HIGH) {
        led1State = HIGH;
        led2State = LOW;
      }
      else {
        led1State = LOW;
        led2State = HIGH;
      }
      digitalWrite(ledSide2, led2State);
      digitalWrite(ledSide1, led1State);
    }
}


void pressButton(int side) {
  if (side == 1) {
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledSide1, HIGH);
    digitalWrite(ledSide2, LOW);
    digitalWrite(ledPin2, LOW);
  }
  if (side == 2) {
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledSide2, HIGH);
    digitalWrite(ledSide1, LOW);
    digitalWrite(ledPin1, LOW);
  }
  else {
    return;
  }
}
//main loop
void loop() {

  blinkLED();

  if (buttonPressed == false) {
    if (digitalRead(button1Pin) == HIGH) {
      pressButton(1);
      buttonPressed = true;
    }
    else if (digitalRead(button2Pin) == HIGH) {
      pressButton(2);
      buttonPressed = true;
    }
  }
  if (buttonPressed == true) { //reset
    delay(5000);
    buttonPressed = false;
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);

  }
}
