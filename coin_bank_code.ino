  #include <Servo.h>
#define trigPin 7
#define echoPin 6
Servo servo;
int sound = 250;
void setup() {
Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
servo.attach(8);
}
void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration*0.034)/2;
if (distance < 5) {
Serial.println("the distance is less than 5");
servo.write(0);
}
else {
servo.write(90);
}   
}
