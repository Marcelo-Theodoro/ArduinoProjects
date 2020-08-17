#include <Arduino.h>

const float SoundSpeed = 0.034;

const int trigPin = 4;
const int echoPin = 5;
const int buzzerPin = 12;

const int startBeepAt = 50;
const int startAlarmAt = 10;

int measureDistance()
{
  int distance;
  int waveDuration;

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  waveDuration = pulseIn(echoPin, HIGH);

  distance = waveDuration * SoundSpeed / 2;
  return distance;
}

void beepAtRate(int rate)
{
  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(rate);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(rate);
}

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  int distance;
  distance = measureDistance();

  if (distance <= startBeepAt && distance >= startAlarmAt)
  {
    int rate;
    rate = distance * 10000;
    beepAtRate(rate);
  }
  else if (distance <= startAlarmAt)
  {
    // Continous beeping
    digitalWrite(buzzerPin, HIGH);
  }
  else
  {
    // Rest beeping
    digitalWrite(buzzerPin, LOW);
  }
}
