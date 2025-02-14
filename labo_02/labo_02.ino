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
   

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
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
     
      }
      Serial.println("]");
    }
  }



  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;
}










