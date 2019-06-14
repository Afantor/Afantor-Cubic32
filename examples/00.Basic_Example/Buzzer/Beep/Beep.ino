/*
	Buzzer - Regular Beep Example
	This example shows the different beeps methods.
	Copyright (c) 2019, Afantor
	MIT License
*/

#include <Cubic32.h>

unsigned int frequency = 4000;
unsigned int beeps = 10;

void done() {
	Serial.println("Done!");
}

void setup() {
	Cubic.begin(false,false);

	/* Beep continuously at a given frequency. */
	// Cubic.Buzzer.beep(frequency);

	/* Beep at a given frequency an specific number of times. */
	Cubic.Buzzer.beep(frequency, beeps);
	
	/* Beep at a given frequency an specific number of times, with callback functionality. */
	// Cubic.Buzzer.beep(frequency, beeps, done);

	/* Use this function to stop the beeping. You may call this function at all time, everywhere in the code. */
	// Cubic.Buzzer.stopBeep();
}

void loop() {
	/* Always call this function in the loop for EasyBuzzer to work. */
	Cubic.Buzzer.update();
}
