//This code uses ultrasonic sensor to detect objects, the result will be sent via Bluetooth
//This project uses Hc-05 as Bluetooth module

int trigPin=9;
int echoPin = 10;

void setup() {
Serial.begin(9600);
pinMode (trigPin, OUTPUT);
pinMode (echoPin, INPUT);
}

void loop() {
    int duration, distance;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2; 
  
    if (distance <= 5) 
    {
      Serial.println("1"); //String 1 will be sent via Bluetooth
      delay(100); //to ensure Bluetooth only sends one line at a time
    }
    else 
    {
      Serial.println("0"); //String 0 will be sent via Bluetooth
      delay(100); //to ensure Bluetooth only sends one line at a time
    }

}
