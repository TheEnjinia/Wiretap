/*
Wiretap
An Arduino logic analyzer sketch
 
License: GNU General Public License V3        
(C) Copyright 2013 Le-Minh Pham-Dang

*/

// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button
long lasttime =0;
void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);


  // initialize serial communication:
  Serial.begin(9600);

  Serial.println("$date\n   Date text. For example: November 11, 2009.\n$end"); 
  Serial.println("$version\n   VCD generator tool version info text.\n$end"); 
  Serial.println("$timescale 1ms $end"); 
  Serial.println("$scope module logic $end"); 
  Serial.println("$var wire 1 # signal_tap $end"); 
  Serial.println("$upscope $end"); 
  Serial.println("$enddefinitions $end"); 
  Serial.println("$dumpvars"); 
  Serial.println("#0"); 
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {

    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:

      Serial.println("1#");

    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
      Serial.println("0#"); 
    }
    Serial.print("#"); 
    Serial.println(millis()); 

  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;
}










