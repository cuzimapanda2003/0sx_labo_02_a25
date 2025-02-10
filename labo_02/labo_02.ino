unsigned long currentTime = 0;
const int ledPins[] = {8, 9, 10, 11};
int button = 2;
int potentiometerPin = A1;           
int potentiometerValue = 0;   

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT); 
  }

  pinMode(button, INPUT_PULLUP);
  Serial.println("Setup completed");
}




void loop() {
  currentTime = millis();
  
  led();

}

void led(){

  potentiometerValue = analogRead(potentiometerPin);
  Serial.println(potentiometerValue);

if(potentiometerValue < 256){
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
} 
else if (potentiometerValue < 512) {
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], LOW);
}
else if (potentiometerValue < 768) {
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], HIGH);
    digitalWrite(ledPins[3], LOW);
}
else{
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], HIGH);
}
}


