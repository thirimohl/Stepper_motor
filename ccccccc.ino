//Declare pin functions on Arduino
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define MS3 6
#define EN  7
#define X_pin A0
//#define Y_pin A1
int i;
int j;

void setup() {
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(MS3, OUTPUT);
   pinMode(dir, OUTPUT);
   pinMode(stp, OUTPUT);
   pinMode(EN, OUTPUT);
   resetBEDPins();

//   digitalWrite(SLEEP, HIGH);  // Wake up EasyDriver
//   delay(5);  // Wait for EasyDriver wake up
   

/* Configure type of Steps on EasyDriver:
// MS1 MS2
//
// LOW LOW = Full Step //
// HIGH LOW = Half Step //
// LOW HIGH = A quarter of Step //
// HIGH HIGH = An eighth of Step //
*/

   digitalWrite(MS1, HIGH);      // Configures to Full Steps
   digitalWrite(MS2, HIGH);    // Configures to Full Steps
   digitalWrite(MS3, HIGH);
   
}

void loop() {  
  digitalWrite(EN, LOW);
 if (analogRead(X_pin) >= 0 && analogRead(X_pin) < 100) 
 {
  forward(); //CLOCKWISE
 }
else if (analogRead(X_pin) > 901 && analogRead(X_pin) <= 1023) 
{
  backward(); //ANTICLOCKWISE
}
 resetBEDPins();
}
//Reset Big Easy Driver pins to default states
void resetBEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, HIGH);
  digitalWrite(MS2, HIGH);
  digitalWrite(MS3, HIGH);
  digitalWrite(EN, HIGH);
}

 void forward()
  {  digitalWrite(dir, LOW);
  for (i = 0; i< 10 ; i++){
     digitalWrite(stp, HIGH);
     delay(10);
     digitalWrite(stp, LOW);
     delay(10);
   }   
  }
 void backward()
 {   digitalWrite(dir, HIGH);
   for (i = 0; i< 10 ; i++){
     digitalWrite(stp, HIGH);
     delay(10);
     digitalWrite(stp, LOW);
     delay(10);
     } 
         
 }

