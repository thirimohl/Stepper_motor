
#define step_pin 2  // Pin 3 connected to Steps pin on EasyDriver
#define dir_pin 3   // Pin 2 connected to Direction pin
#define MS1 4       // Pin 4 connected to MS1 pin
#define MS2 5       // Pin 5 connected to MS2 pin
#define MS3 6       // Pin 6 connected to MS3 pin
#define ENABLE 7     // Pin 7 connected to SLEEP pin
#define X_pin A0    // Pin A0 connected to joystick x axis
#define DISTANCE 1

int i;

void setup() {
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(MS3, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(step_pin, OUTPUT);
   pinMode(ENABLE, OUTPUT);
/* Configure type of Steps on EasyDriver:
// MS1 MS2 MS3 
//
// LOW LOW LOW= Full Step //
// HIGH LOW LOW= Half Step //
// LOW HIGH LOW= A quarter of Step //
// HIGH HIGH LOW= An eighth of Step //
// HIGH HIGH HIGH= A sixteenth of Step
*/ digitalWrite(dir_pin, LOW);
   digitalWrite(step_pin, LOW);
   digitalWrite(MS1, HIGH);      // Configures to Full Steps
   digitalWrite(MS2, HIGH);      // Configures to Full Steps    
   digitalWrite(MS3, HIGH);      // Configures to Full Steps
   Serial.begin(9600);
   
}
void loop() {
  Serial.println(analogRead(X_pin));
  if (analogRead(X_pin) >= 0 && analogRead(X_pin) <= 100) 
  { digitalWrite(dir_pin, LOW);
//    for(i=0 ; i <= 3 ; ++i)
    digitalWrite(step_pin, HIGH);
    delay(90);          
    digitalWrite(step_pin, LOW); 
    delay(90);
  }  
 
//    if (analogRead(X_pin) >= 800 && analogRead(X_pin) <= 1025) 
//    {digitalWrite(dir_pin,HIGH);
////    for (i=0 ; i <= 3 ; ++i)
//    digitalWrite(step_pin, HIGH);
//    delay(90);       
//    digitalWrite(step_pin, LOW); 
//    delay(90);
//  }  
  }
        
  
