int timer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);

  //for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:;

  // if the photosensor is in light, set timer to zero and keep the output off
  if (analogRead(5) > 600) {
    timer = 0;
    digitalWrite(12, LOW);
  } else {
    // otherwise start counting up
    delay(1000);
    timer++;
    //so we can see the counter on our end
    Serial.println(timer);

    // after 5 seconds, set off the sensor
    if (timer >= 5) {
      digitalWrite(12, HIGH);
    }
  }
}
