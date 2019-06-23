
const int red = 9;
const int green = 10;
const int blue = 11;
const int btnPin = 2;

int lightMode = 0;

int buttonState;
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // put your setup code here, to run once:
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(btnPin, INPUT);

  digitalWrite(red, HIGH);
  digitalWrite(blue,HIGH);
  digitalWrite(green,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(btnPin);
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (reading == HIGH) {
        if (lightMode <= 3) {
          lightMode += 1;
          Serial.println(lightMode);
        }
        else {
          lightMode = 0;
          Serial.println(lightMode);
        } 
      }
    }
  }
  lastButtonState = reading;
 switch (lightMode) {
  case 0:
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    Serial.println("Light mode #0 activated: Red");
    break;
  case 1:
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    Serial.println("Light mode #1 activated: Violet");
    break;
  case 2:
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,HIGH);
    Serial.println("Light mode #2 activated: Blue");
    break;
  case 3:
    digitalWrite(red,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(blue,HIGH);
    Serial.println("Light mode #3 activated: White");
    break;
  case 4:
    digitalWrite(red,LOW);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    Serial.println("Light mode #4 activated: Off");
    break;  
 }
}
