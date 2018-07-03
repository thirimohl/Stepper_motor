struct Motor
{
  // Pins 
  int MS1, MS2, MS3;
  int ENABLE;
  int STEP, DIR;

  void SetPins(int MS1_, int MS2_, int MS3_, int ENABLE_, int STEP_, int DIR_)
  {
    MS1 = MS1_; MS2 = MS2_; MS3 = MS3_;
    ENABLE = ENABLE_;
    STEP = STEP_; DIR = DIR_;
  }

  void SetStepMode(int MS1_, int MS2_, int MS3_)
  {
    digitalWrite(MS1, MS1_);
    digitalWrite(MS2, MS2_);
    digitalWrite(MS3, MS3_);
  }

  void Setup()
  {
    pinMode(MS1, OUTPUT);
    pinMode(MS2, OUTPUT);
    pinMode(MS3, OUTPUT);
    pinMode(ENABLE, OUTPUT);
    pinMode(STEP, OUTPUT);
    pinMode(DIR, OUTPUT);
  }
} motor1, motor2;

void setup()
{
  motor1.SetPins(4, 5, 6, 
                 7,
                 2, 3);
  motor2.SetPins(28, 26, 24, 
                 22,
                 32, 30);               
  motor1.Setup();
  motor2.Setup();

  /* Configure type of Steps on EasyDriver:
// MS1 MS2 MS3 
//
// LOW LOW LOW= Full Step //
// HIGH LOW LOW= Half Step //
// LOW HIGH LOW= A quarter of Step //
// HIGH HIGH LOW= An eighth of Step //
// HIGH HIGH HIGH= A sixteenth of Step*/
  //digitalWrite(dir_pin, LOW);
  //digitalWrite(step_pin, LOW);
  motor1.SetStepMode(HIGH, HIGH, HIGH);
  //digitalWrite(dir, LOW);
  //digitalWrite(stp, LOW);
  motor2.SetStepMode(HIGH, HIGH, HIGH);
}

void loop()
{
  digitalWrite(motor1.DIR, LOW);
  for(int i = 0; i < 3; ++i)  
  {
    digitalWrite(motor1.STEP, HIGH); 
    delay(60);
    digitalWrite(motor1.STEP, LOW); 
    delay(60);
  }
  
  digitalWrite(motor1.DIR, HIGH);
  for(int i = 0; i < 3; ++i)  
  {
    digitalWrite(motor1.STEP, HIGH); 
    delay(60);
    digitalWrite(motor1.STEP, LOW); 
    delay(60);
  }
}
