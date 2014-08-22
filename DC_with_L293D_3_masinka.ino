int pin_motor_enable = 2;
int pin_motor_in1 = 3;
int pin_motor_in2 = 4;

int pin_in_fwd  = 7;
int pin_in_back = 8;

int dig_fwd;
int dig_back;

int pin_led_red = 12;
int pin_led_green = 13;

char direction1 = 'X';

void setup() {                
  // initialize the motor digital pins as outputs.
  pinMode(pin_motor_enable, OUTPUT);     
  pinMode(pin_motor_in1, OUTPUT);     
  pinMode(pin_motor_in2, OUTPUT);
  // initialize input pins for buttons
  pinMode(pin_in_fwd,  INPUT_PULLUP);
  pinMode(pin_in_back, INPUT_PULLUP);
  direction1 = 'X';
  pinMode(pin_led_red,   OUTPUT);     
  pinMode(pin_led_green, OUTPUT);
}

void motor1( int val_1, int val_2, int val_3 ) {
  digitalWrite(pin_motor_enable, val_1);
  digitalWrite(pin_motor_in1, val_2);
  digitalWrite(pin_motor_in2, val_3);
}

void stopMotor1() {
  motor1( LOW, LOW, LOW );
}

void goForward() {
  motor1( HIGH, HIGH, LOW );
}

void goForwardTimed(int delayInMs) {
  motor1( HIGH, HIGH, LOW );
  delay(delayInMs);
}

void goBackward() {
  motor1( HIGH, LOW, HIGH );
}

void goBackwardTimed(int delayInMs) {
  motor1( HIGH, LOW, HIGH );
  delay(delayInMs);
}

void led_red(int val) {
  digitalWrite(pin_led_red,val);
}

void led_green(int val) {
  digitalWrite(pin_led_green,val);
}

// the loop routine runs over and over again forever:
void loop() {
  if (direction1 == 'X') {
    stopMotor1();
  }
  if (direction1 == 'F') {
    goForward();
  }
  if (direction1 == 'B') {
    goBackward();
  }
  ////////////////////
  dig_fwd  = digitalRead(pin_in_fwd);
  dig_back = digitalRead(pin_in_back);
  if (dig_fwd  == LOW  &&  dig_back == HIGH)  {
    direction1 = 'F';
    led_red(LOW);
    led_green(HIGH);
  }
  if (dig_fwd  == HIGH   &&  dig_back == LOW) {
    direction1 = 'B';
    led_red(HIGH);
    led_green(LOW);
  }
  if (dig_fwd  == LOW  &&  dig_back == LOW) {
    direction1 = 'X';
    led_red(HIGH);
    led_green(HIGH);
  }
}

