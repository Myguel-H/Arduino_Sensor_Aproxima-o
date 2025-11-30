const int trigPin = 9;
const int echoPin = 10;
const int Motor = 11;
const int buzzer = 13;
const int led = 8;
long duration;
float distance;

void setup()
{
    pinMode(buzzer, OUTPUT);
    pinMode(Motor, OUTPUT);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    measureAndControl();
    delay(100);
}

void measureAndControl()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
//
    duration = pulseIn(echoPin, HIGH);
    distance = duration * 0.0343 / 2;

    Serial.print("Distance: ");
    Serial.print(distance, 1);
    Serial.println(" cm");

    if (distance <= 20)
    {
        digitalWrite(Motor, HIGH);
        digitalWrite(buzzer, HIGH);
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(buzzer, LOW);
        digitalWrite(led, LOW);
        delay(200);
    }
    else
    {
        digitalWrite(buzzer, LOW);
        digitalWrite(led, LOW);
        digitalWrite(Motor, LOW);
    }
}
