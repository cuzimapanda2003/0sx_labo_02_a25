unsigned long currentTime = 0;
const int ledPins[] = {8, 9, 10, 11};
int button = 2;
int potentiometerPin = A1;           
int potentiometerValue = 0;   
int buttonState;           
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;  


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
  buttonPress();
}

void led(){

  potentiometerValue = analogRead(potentiometerPin);
  
  


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


void buttonPress(){
    potentiometerValue = analogRead(potentiometerPin);
    int reading = digitalRead(button);
   int valeur_converti = map(potentiometerValue, 0, 1023, 0, 20);
   int max = 20;
   int mult = 100;
   int pourcentage = (valeur_converti * mult) / max;
   

  if (reading != lastButtonState) {
   
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != buttonState) {
      buttonState = reading;

      if (buttonState == HIGH) {
       Serial.print(pourcentage);
        Serial.print("% [");

        for(int i = 0; i < max; i++)
        if(i < valeur_converti){
          Serial.print("@");
        }
        else{
          Serial.print("-");
        }
      Serial.println("]");
      }
     
       
    }
   
  }



 
  lastButtonState = reading;
}










