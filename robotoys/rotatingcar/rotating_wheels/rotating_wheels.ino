char t;

void setup() {
  pinMode(10, OUTPUT);  //left motors forward
  pinMode(11, OUTPUT);  //left motors reverse
  pinMode(12, OUTPUT);  //right motors forward
  pinMode(13, OUTPUT);  //right motors reverse

  Serial.begin(9600);

}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }

  if (t == '1') {          //move forward(all motors rotate in forward direction)
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }

  else if (t == '2') {    //move reverse (all motors rotate in reverse direction)
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, HIGH);
  }

  else if (t == '3') {    //turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
  }

  else if (t == '4') {    //turn left (right side motors rotate in forward direction, left side motors doesn't rotate)
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
  }

  else if (t == '5') {    //STOP (all motors stop)
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
  }
  delay(100);
}
