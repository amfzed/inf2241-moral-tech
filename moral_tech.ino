int timer = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(11, OUTPUT);

  //for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:;
  int brightness = analogRead(5);
  // if the photosensor is in light, set timer to zero and keep the output off
  if (brightness > 300) {
    Serial.println(brightness);
    timer = 0;
    digitalWrite(11, LOW);
  } else {
    // otherwise start counting up
    delay(1000);
    timer++;
    //so we can see the counter on our end
    Serial.println(timer);

    // after 5 seconds, set off the sensor
    if (timer >= 5) {
      //the dimmer, the higher pitched the sound will be
      int pitch = map(brightness, 0, 1023, 255, 0);
      Serial.println(pitch);
      analogWrite(11, pitch);
    }
  }
}
