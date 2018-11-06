#include<SoftwareSerial.h>

int ledPin = 9;                // choose the pin for the LED
int inputPin = 7;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status

SoftwareSerial bt(0,1);

void setup() {
  bt.begin(9600);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  
  val = digitalRead(inputPin);
 // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED

     if(bt.available()){
      Serial.write(bt.read());
     }
//    if (pirState == LOW) {
//      // we have just turned on
//      
//      pirState = HIGH;
//      // We only want to print on the output change, not state
//      
//    }
//  } else if (val == LOW) {
//     digitalWrite(ledPin, LOW); // turn LED OFF// we have just turned of
//    if (pirState== HIGH){
//      
//       pirState = LOW;
//      
//      // We only want to print on the output change, not state
//     
//    }
  }


}
