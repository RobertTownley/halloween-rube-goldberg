const int BUTTON_PIN = 11; 
int priorState = 0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void handlePress() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(3000);
  digitalWrite(LED_BUILTIN, LOW);
}


void loop() {
  int buttonState = digitalRead(BUTTON_PIN);
  if(buttonState != priorState){
    priorState = buttonState;
    if(buttonState == 0){
      Serial.println("Button Press!!!");
      handlePress();
    }
  };
}
