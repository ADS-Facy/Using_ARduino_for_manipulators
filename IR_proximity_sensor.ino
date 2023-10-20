
// Define the pin for the FC-51 sensor
const int motionPin = 2;  // Connect the sensor's OUT pin to digital pin 2

unsigned long previousMillis = 0;  // will store the last time motion was detected
const long interval = 1;  // interval at which to print motion detection (in milliseconds)

void setup() {
  Serial.begin(9600); // Start serial communication
  pinMode(motionPin, INPUT);
}

void loop() {
  unsigned long currentMillis = millis();  // get the current time

  // Check if motion is detected
  if (digitalRead(motionPin) == HIGH) {
    // Only print if it's been more than the specified interval since the last detection
    if (currentMillis - previousMillis >= interval) {
      // Save the current time for the next interval
      previousMillis = currentMillis;

      // Print the timestamp to the serial monitor
      Serial.print("Motion Detected - Time: ");
      Serial.println(currentMillis);
    }
  }
}

/*
//This code is to use with FC51 IR proximity sensor, when it detects an obstacle it lights the internal LED
//of the Arduino Board, refer to http://www.Surtrtech.com for more information
 
const int ProxSensor = 2;  // Declaring where the Out pin from the sensor is wired

void setup() {
  pinMode(13, OUTPUT);        // setting the pin modes, the "13" stands for the internal Arduino uno internal LED
  pinMode(ProxSensor, INPUT);  // then we have the out pin from the module
  Serial.begin(9600);         // Start serial communication
}

void loop() {
  if (digitalRead(ProxSensor) == HIGH) {  // Check the sensor output if it's high
    digitalWrite(13, LOW);               // Turn the LED on (Yes by writing LOW)

    // Print the time in milliseconds when motion is detected
    Serial.print("Motion Detected - Time: ");
    Serial.println(millis());
  } else {
    digitalWrite(13, HIGH);  // Turn the LED OFF if there's no signal on the ProxSensor
  }
  delay(1);
}
*/


