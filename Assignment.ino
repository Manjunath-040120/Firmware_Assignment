/*
Name : Manjunath M
Date : 16-03-2024
Description : Firmware Assignment
 */

 
const int lm35Pin = A0; // LM35 sensor connected to Analog pin A0
const int ledPin = 13;  // LED pin assigning to arduino board to pin 13

float temperature;
int loopCount = 0;
int lastToggle = 0;

void setup() 
{
    pinMode(ledPin, OUTPUT);
}

void loop() 
{
    int sensorValue = analogRead(lm35Pin);
    temperature = (sensorValue * 0.004882) * 100; // converting sensor value to temperature in Celsius

    int LED_blinkInterval; // Adjust LED blink interval based on the requirements of temperature.
    if (temperature < 30)  
    {
	LED_blinkInterval = 250;
    } 
    else if (temperature > 30)
    {
	LED_blinkInterval = 500;
    }

    if (loopCount - lastToggle >= LED_blinkInterval / 100) // To toggle the LED ON or OFF.
    {
	if (digitalRead(ledPin) == HIGH) 
	{
	    digitalWrite(ledPin, LOW); // Turn off LED
	} 
	else 
	{
	    digitalWrite(ledPin, HIGH); // Turn on LED
	}
	lastToggle = loopCount; // Update lastToggle
    }
    loopCount++; // Increment loop counter to maintain the loop 
}

