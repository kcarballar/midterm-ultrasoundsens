#define trigPin 13
#define echoPin 12
#define led 11
#define led2 10

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);

}

void loop() {
  long duration, distance;// sensor variables
  digitalWrite(trigPin, LOW); // sensor 
  delayMicroseconds(2); //sensor
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1; // HERE
  
  if (distance < 20) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Yellow LED should turn off
  digitalWrite(led2,LOW);

}
  else {
    digitalWrite(led,LOW); // red off
    digitalWrite(led2,HIGH); //yellow
  }
  if (distance >= 200 || distance <= 0){  // not sure what this is!
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println("cm");
  }
  delay(500);
}

