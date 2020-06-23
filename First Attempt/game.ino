//global variables
const int button1Pin = 2;
const int button2Pin = 3;
const int ledPin1 = 4;
const int ledPin2 = 5;

int buttonState1 = 0;
int buttonState2 = 0;
int counter = 0;

void setup() {
  //initialize
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
}

void loop() {
  //read state of pushbutton
  buttonState1 = digitalRead(button1Pin);
  buttonState2 = digitalRead(button2Pin);
  if (counter == 0) {
    if (buttonState1 == HIGH) {
      digitalWrite(ledPin1, HIGH);
      counter++;
    }
    else if (buttonState2 == HIGH) {
      digitalWrite(ledPin2, HIGH);
      counter++;
    }
    }
  }
