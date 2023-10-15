// Define the pins for the ultrasonic sensor
const int trigPin = 9;  // Trig pin of the sensor
const int echoPin = 10; // Echo pin of the sensor

// Variables to store the duration, distance, and time
long duration;
int distance;
unsigned long previousMillis = 0;  // will store last time a measurement was taken
const long interval = 700;  // interval at which to take measurements (in milliseconds)

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();  // get the current time

  // Check if it's time to take a new measurement
  if (currentMillis - previousMillis >= interval) {
    // Save the current time for the next interval
    previousMillis = currentMillis;

    // Generate a pulse on the trigger pin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the duration of the echo signal
    duration = pulseIn(echoPin, HIGH);

    // Calculate the distance based on the speed of sound (343 meters/second)
    // distance = duration * speed of sound / 2
    distance = duration * 0.0343 / 2;

    // Print the distance and timestamp to the serial monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm\t");

    // Print the current time in milliseconds
    Serial.print("Time: ");
    Serial.println(currentMillis);
  }
}