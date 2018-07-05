////First Motor 
#define stp 2
#define dir 3
#define MS1 4
#define MS2 5
#define MS3 6
#define EN  7
#define X_pin A0
//2nd motor
#define stp_pin 9
#define dir_pin 8
#define M1 10 
#define M2 11
#define M3 12
#define ENABLE  13
#define Y_pin A1

int i;
int j;

void setup() {
   pinMode(MS1, OUTPUT);
   pinMode(MS2, OUTPUT);
   pinMode(MS3, OUTPUT);
   pinMode(dir, OUTPUT);
   pinMode(stp, OUTPUT);
   pinMode(EN, OUTPUT);
//   resetBEDPins();
/////////// 2nd motor/////////
   pinMode(M1, OUTPUT);
   pinMode(M2, OUTPUT);
   pinMode(M3, OUTPUT);
   pinMode(dir_pin, OUTPUT);
   pinMode(stp_pin, OUTPUT);
   pinMode(ENABLE, OUTPUT);
   resetBEDPins();
//////////////////////////////

/* Configure type of Steps on EasyDriver:
// MS1 MS2 MS3
//
// LOW LOW LOW = Full Step //
// HIGH LOW LOW = Half Step //
// HIGH HIGH LOW= A quarter of Step //
// HIGH HIGH HIGH= An eighth of Step //
*/
   digitalWrite(MS1, HIGH);      // Configures to Full Steps
   digitalWrite(MS2, LOW);    // Configures to Full Steps
   digitalWrite(MS3, LOW);
   digitalWrite(M1, LOW);      // 
   digitalWrite(M2, LOW);    // 
   digitalWrite(M3, LOW);   //
//   
}

void loop() {  
    digitalWrite(EN, LOW);
 if (analogRead(X_pin) >= 0 && analogRead(X_pin) < 100) 
 {
  Clockwise(); 
 }
else if (analogRead(X_pin) > 901 && analogRead(X_pin) <= 1023) 
{
  AntiClockwise(); 
}
 else if (analogRead(Y_pin) >= 0 && analogRead(Y_pin) < 100) { digitalWrite(ENABLE,LOW);

  MotorCW();
}
else if (analogRead(Y_pin) > 901 && analogRead(Y_pin) <= 1023) { digitalWrite(ENABLE,LOW);

  MotorACW();
} else {
  }resetBEDPins();
}
//Reset Big Easy Driver pins to default states
void resetBEDPins()
{
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  digitalWrite(MS1, LOW);
  digitalWrite(MS2, LOW);
  digitalWrite(MS3, LOW);
  digitalWrite(EN, HIGH);
  digitalWrite(stp_pin, LOW);
  digitalWrite(dir_pin, LOW);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(ENABLE, HIGH);
  
}

 void Clockwise()
  {  digitalWrite(dir, LOW);
  for (i = 0; i< 40 ; i++){
     digitalWrite(stp, HIGH);
     delay(1);
     digitalWrite(stp, LOW);
     delay(1);
   }   
  }
 void AntiClockwise()
 {   digitalWrite(dir, HIGH);
   for (i = 0; i< 40 ; i++){
     digitalWrite(stp, HIGH);
     delay(1);
     digitalWrite(stp, LOW);
     delay(1);
     } 
         
 }

// 
 void MotorCW()
  {  digitalWrite(dir_pin, LOW);
  for (i = 0; i< 40 ; i++){
     digitalWrite(stp_pin, HIGH);
     delay(1);
     digitalWrite(stp_pin, LOW);
     delay(1);
   }  
  }
 void MotorACW()
 {   digitalWrite(dir_pin, HIGH);
   for (i = 0; i< 40 ; i++){
     digitalWrite(stp_pin, HIGH);
     delay(1);
     digitalWrite(stp_pin, LOW);
     delay(1);
     } 
         
 }

