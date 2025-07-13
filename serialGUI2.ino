const int ledPin = LED_BUILTIN;


const int btn0 = 0;
const int btn1 = 1;

int lastBtn0 = HIGH;
int lastBtn1 = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(btn0, INPUT);
  pinMode(btn1, INPUT);

  Serial.begin(9600);
  while (!Serial);
  Serial.println("Ready!");
}

void loop() {
  // Handle incoming serial commands
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    if (input == "a") {
      Serial.println("Received A");
    } else if (input == "b") {
      Serial.println("Received B");
    } else if (input == "c") {
      Serial.println("Received C");
    } else if (input == "on") {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED:ON");
    } else if (input == "off") {
      digitalWrite(ledPin, LOW);
      Serial.println("LED:OFF");
    } else if (input == "e") {
      digitalWrite(4, HIGH);
      delay(500);
      digitalWrite(4, LOW);
    }
     else if (input == "d") {
      digitalWrite(5, HIGH);
      delay(500);
      digitalWrite(5, LOW);
    }
     else {
      Serial.println("Unknown command: " + input);
    }
  }

  // Read current button states
  int currentBtn0 = digitalRead(btn0);
  int currentBtn1 = digitalRead(btn1);

  // Report state changes
  if (currentBtn0 != lastBtn0) {
    lastBtn0 = currentBtn0;

    if (currentBtn0 == LOW) {
      Serial.print('\a'); // Bell on press
      Serial.println("btn0_1");
    }
     else if (currentBtn1 == HIGH){
       Serial.println("btn0_0");
    }
  }

  if (currentBtn1 != lastBtn1) {
    lastBtn1 = currentBtn1;
    if(currentBtn1 == LOW){
       Serial.println("btn1_1");
    } else if (currentBtn1 == HIGH){
       Serial.println("btn1_0");
    }
    
  }

  delay(10); // Small debounce delay
}
