//global variables
const int button1Pin = 2;
const int button2Pin = 3;
const int ledPin1 = 4;
const int ledPin2 = 5;

//!NEW! adding leds along the border because button led is not very bright
const int ledSide1=6;
const int ledSide2=7;
int startLED =0;


int buttonState1 = 0;
int buttonState2 = 0;
int counter = 0;
int buttonPressed=0;

void setup() {
  //initialize
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(ledSide1, OUTPUT);
  pinMode(ledSide2, OUTPUT);
}

int turnOnLED(int side){
  if(side==1){
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledSide1,HIGH);
  }
  else if(side==2){
    digitalWrite(ledPin2, HIGH);
     digitalWrite(ledSide2,HIGH);
  }
  
}

void blinkLEDS(){
  if(counter<1){
  //flash side 1 leds
  digitalWrite (ledSide1, HIGH);
  delay(50);
  digitalWrite (ledSide1, LOW);
  digitalWrite (ledSide2, HIGH);
  delay(50);
  digitalWrite (ledSide2, LOW);
  }
  
  if(digitalRead(button1Pin) ==HIGH){
    turnOnLED(1);
    counter++;
    buttonPressed++;
  }
  else if(digitalRead(button2Pin)==HIGH){
    turnOnLED(2);
    counter++;
    buttonPressed++;
  }
 
}

void loop() {
  if(buttonPressed<1){
  blinkLEDS();
  }
  //auto reset
  else if(buttonPressed==1){
  delay(1000);//wait 5 seconds
  counter =0;
  buttonPressed=0;
  digitalWrite(ledPin1,LOW);
  digitalWrite(ledPin2, LOW);
  }
     
}
