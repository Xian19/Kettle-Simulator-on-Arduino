#include <DHT.h>
#include <Servo.h>

Servo myservo; 

#define DHTPIN 7
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);
#define analogSound A0
#define digitalSound 5
int chk;
int hum;

void setup(){
  Serial.begin(9600);
  dht.begin();
  myservo.attach(3);
  pinMode(analogSound, INPUT);
  pinMode(digitalSound, INPUT);
  myservo.write(180);
}

void loop(){
  int anVal = analogRead(analogSound);
  int digVal = digitalRead(digitalSound);

  Serial.print("Humidity = ");
  hum = dht.readHumidity();
  Serial.println(hum);
  Serial.print("Analog Sound = ");
  Serial.println(anVal);

  if (hum > 97 && anVal > 80) {
    myservo.write(100);
  }
  
  delay(15);

  
}