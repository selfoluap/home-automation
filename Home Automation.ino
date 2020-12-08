const int MotionSensorPin = 2;
int motionStateCurrent = LOW;
int motionStatePrevious = LOW;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(MotionSensorPin, INPUT);
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
  int analogValue = analogRead(A0);

  //Serial.print("Analog reading = ");
  //Serial.println(analogValue);
  

  motionStatePrevious = motionStateCurrent;             // store old state
  motionStateCurrent  = digitalRead(MotionSensorPin); // read new state

  if (motionStatePrevious == LOW && motionStateCurrent == HIGH) { // pin state change: LOW -> HIGH
    Serial.println("Motion detected!");
  }
  else if (motionStatePrevious == HIGH && motionStateCurrent == LOW) { // pin state change: HIGH -> LOW
    Serial.println("Motion stopped!");
  }

  //do something with it
  delay(500);
}
