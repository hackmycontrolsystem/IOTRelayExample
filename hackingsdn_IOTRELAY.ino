
// Arduino Mega 2560 alternating power on/off as a result of photoelectric sensor output
// Does not require an external 5v power source, USB power is adequate.
// Serial connection (9600 baud rate)

int Relay1 = 52;                              //Connect wire from pin 52 to positive (+) terminal on IOT relay.
                                              //Connect ground from Arduino to negative (-) terminal on IOT relay.
                                              //Connect 5V (red wire) and second ground (black wire) to Keyes K853518 LDR Module
int OUT_Pin = A0;                             //Connect Arduino A0 to third Keyes module (yellow) wire

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                         //Declare serial baud rate of 9600
  pinMode(Relay1, OUTPUT);                    //Relay1 (pin 52) will send output signal (to IOT Relay).
  Serial.println("Keyes K853518 LDR Module"); //Print module info.
}

void loop() {                                 //Do this forever!
  if (analogRead(OUT_Pin) <= 630){            //If analog reading is less than or equal t0 800 (i.e., windows' shades closed)...
    Serial.println(analogRead(OUT_Pin));      //Print photosensitive sensor's analog reading 
    Serial.println("Powering On...");         //Print debug message, e.g. send power on signal to IOT Relay.
    digitalWrite(Relay1, HIGH);               //Send 'power off' signal to IOT Relay.
    delay(2000);
  }
  else if (analogRead(OUT_Pin) >= 800){       //If analog reading is greater than or equal to 800 (i.e., flashlight on sensor)...
    Serial.println(analogRead(OUT_Pin));      //Print display photosensitive sensor's analog reading 
    Serial.println("Powering Off...");        //Print debug message
    digitalWrite(Relay1, LOW);                //Send 'power off' signal to IOT Relay.
    delay(2000);
  }
  else {                                      //Otherwise...
    Serial.println("Standby...");             //Print message, e.g. wait for a condition to match.
    Serial.println(analogRead(OUT_Pin));      //Print photosensitive sensor's analog reading 
    delay(1000);
  }
  delay(2000);  //2000 ms = 2 seconds
}
