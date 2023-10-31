#include <Servo.h>

// Piano Keyboard Inputs
// ----------------------
#define GPIO1 23
#define GPIO2 22
#define GPIO3 24
#define GPIO4 26
#define GPIO5 28
#define GPIO6 30
#define GPIO7 32
#define GPIO8 34
#define GPIO9 36
#define GPIO10 38
#define GPIO11 40
#define GPIO12 42

// Wrist Joint/ Bow Positions
// ---------------------------
#define LEGATTO_UP_BOW_ANGLE 
#define STACCATO_UP_BOW_ANGLE 
#define LEGATTO_STACCATO_DOWN_BOW_ANGLE 

// Elbow Joint Angles corresponding to the Violin string
// ------------------------------------------------------
#define E_STRING_ELBOW_ANGLE
#define A_STRING_ELBOW_ANGLE
#define D_STRING_ELBOW_ANGLE
#define G_STRING_ELBOW_ANGLE

// Shoulder Joint Angles corresponding to the Violin string
// ------------------------------------------------------
#define E_STRING_SHOULDER_ANGLE
#define A_STRING_SHOULDER_ANGLE
#define D_STRING_SHOULDER_ANGLE
#define G_STRING_SHOULDER_ANGLE

// +------------------+
// | Global Variables |
// +------------------+

int val = 0;
int wrist_angle = 0;
int elbow_angle = 0;
int shoulder_angle = 0;

Servo wrist_servo;
Servo elbow_servo;
Servo shoulder_servo;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GPIO1, INPUT);
  pinMode(GPIO2, INPUT);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  wrist_servo.attach(2);
  elbow_servo.attach(3);
  shoulder_servo.attach(4);
}

int stateMachine() {
  //val = digitalRead(GPIO1);
  if (digitalRead(GPIO1) == 1) {
    Serial.println("c");
    return 1;
  } else if (digitalRead(GPIO2) == 1) {
    Serial.println("c#");
    return 2;
  } else if (digitalRead(GPIO3) == 1) {
    Serial.println("d");
    return 3;
  } else if (digitalRead(GPIO4) == 1) {
    Serial.println("d#");
    return 4;
  } else if (digitalRead(GPIO5) == 1) {
    Serial.println("e");
    return 5;
  } else if (digitalRead(GPIO6) == 1) {
    Serial.println("f");
    return 6;
  } else if (digitalRead(GPIO7) == 1) {
    Serial.println("f#");
    return 7;
  } else if (digitalRead(GPIO8) == 1) {
    Serial.println("g");
    return 8;
  } else if (digitalRead(GPIO9) == 1) {
    Serial.println("g#");
    return 9;
  } else if (digitalRead(GPIO10) == 1) {
    Serial.println("a");
    return 10;
  } else if (digitalRead(GPIO11) == 1) {
    Serial.println("a#");
    return 11;
  } else if (digitalRead(GPIO12) == 1) {
    Serial.println("b");
    return 12;
  }
}

void transmitt(int hex_input) {
 switch(hex_input) {
    case 0: 
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      break;
    case 1: 
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      break;
    case 2: 
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      break;
    case 3: 
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      digitalWrite(10, 0);
      digitalWrite(11, 0);
      break;
    case 4: 
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      break;
    case 5: 
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      break;
    case 6: 
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      break;
    case 7: 
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      digitalWrite(10, 1);
      digitalWrite(11, 0);
      break;
    case 8: 
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      break;
    case 9: 
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      break;
    case 10: 
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      break;
    case 11: 
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      digitalWrite(10, 0);
      digitalWrite(11, 1);
      break;
    case 12: 
      digitalWrite(8, 0);
      digitalWrite(9, 0);
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      break;
    case 13: 
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      break;
    case 14: 
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      break;
    case 15: 
      digitalWrite(8, 1);
      digitalWrite(9, 1);
      digitalWrite(10, 1);
      digitalWrite(11, 1);
      break;
  }
}

void moveMechatronicArm() {
  wrist_angle = wrist_servo.read();
  elbow_angle = elbow_servo.read();
  shoulder_angle = shoulder_servo.read();
  //Serial.print("wrist_angle: " + wrist_angle + " | elbow_angle: " + elbow_angle + " | shoulder_angle: " + shoulder_angle);
  /*Serial.print("wrist_angle: ");
  Serial.print(wrist_servo.read());
  Serial.print(" | elbow_angle: ");
  Serial.print(elbow_servo.read());
  Serial.print(" | shoulder_angle: ");
  Serial.println(shoulder_servo.read());*/
}


void loop() {
  // put your main code here, to run repeatedly:
  transmitt(stateMachine());
  //moveMechatronicArm();
  delay(100);
}

/*
if(val == 1) {
    digitalWrite(13, 1);
  } else {
    digitalWrite(13, 0);
  }
  delay(500);
*/
