
#define step_pin 2  // Pin 3 connected to Steps pin on EasyDriver
#define dir_pin 3   // Pin 2 connected to Direction pin
#define MS1 4       // Pin 4 connected to MS1 pin
#define MS2 5       // Pin 5 connected to MS2 pin
#define MS3 6       // Pin 6 connected to MS3 pin
#define ENABLE 7     // Pin 7 connected to SLEEP pin
#define X_pin A0    // Pin A0 connected to joystick x axis
#define DISTANCE 1
//2nd motor
#define stp 32
#define dir 30 
#define M1 28 
#define M2 26
#define M3 24
#define EN 22
#define Y_pin A1
 
int StepCounter = 0;
int StepCounter1 = 0;
int Stepping = false;
int Stepping1 = false;


//int direction;    // Variable to set Rotation (CW-CCW) of the motor
//int steps = 1025; // Assumes the belt clip is in the Middle

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
*/ //digitalWrite(dir_pin, LOW);
   //digitalWrite(step_pin, LOW);
   digitalWrite(MS1, HIGH);      // Configures to Full Steps
   digitalWrite(MS2, HIGH);      // Configures to Full Steps    
   digitalWrite(MS3, HIGH);      // Configures to Full Steps
///////SECOND MOTOR
   pinMode(M1, OUTPUT);
   pinMode(M2, OUTPUT);
   pinMode(M3, OUTPUT);
   pinMode(dir, OUTPUT);
   pinMode(stp, OUTPUT);
   pinMode(EN, OUTPUT);   
   //digitalWrite(dir, LOW);
   //digitalWrite(stp, LOW);
   digitalWrite(M1, HIGH);      // Configures to Full Steps
   digitalWrite(M2, HIGH);      // Configures to Full Steps    
   digitalWrite(M3, HIGH);
   
}

void loop() {
  if (analogRead(X_pin) >= 0 && analogRead(X_pin) <= 100) {digitalWrite(dir_pin, LOW);
  { 
    //digitalWrite(dir_pin, LOW);
    Stepping = true;
    digitalWrite(step_pin, HIGH);
    delay(90);          
    digitalWrite(step_pin, LOW); 
    delay(90);

    StepCounter = StepCounter + 1;

    if (StepCounter == DISTANCE)
    {
      StepCounter = 0;
      Stepping = false;
    }
  }  
  }

    if (analogRead(X_pin) >= 800 && analogRead(X_pin) <= 1025) {digitalWrite(dir_pin, HIGH);
  { 
    
    Stepping = true;
    digitalWrite(step_pin, HIGH);
    delay(90);       
    digitalWrite(step_pin, LOW); 
    delay(90);

    StepCounter = StepCounter + 1;

    if (StepCounter == DISTANCE)
    {
      StepCounter = 0;
      Stepping = false;
//    }
  }  
  }
    }    
    ////////////////////////////////////////////////////
 //////////second motor//////////////////////////
 ////////////////////////////////////////////////////
    if (analogRead(Y_pin) >= 0 && analogRead(Y_pin) <= 100) {digitalWrite(dir, LOW);
  { 
    Stepping1 = true;
    digitalWrite(stp, HIGH);
    delay(90);          
    digitalWrite(stp, LOW); 
    delay(90);

    StepCounter = StepCounter + 1;

    if (StepCounter1 == DISTANCE)
    {
      StepCounter1 = 0;
      Stepping1 = false;
    }
  }  
  }

    if (analogRead(Y_pin) >= 800 && analogRead(Y_pin) <= 1025) {digitalWrite(dir, HIGH);
  { 
    
    Stepping1 = true;
    digitalWrite(stp, HIGH);
    delay(90);       
    digitalWrite(stp, LOW); 
    delay(90);
    StepCounter1 = StepCounter1 + 1;

    if (StepCounter == DISTANCE)
    {
      StepCounter1 = 0;
      Stepping1 = false;
//    }
  }  
  }
    }      
    
    
    }
  
  
