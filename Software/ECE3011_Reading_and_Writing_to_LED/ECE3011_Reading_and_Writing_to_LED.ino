#define GPIO1 23


int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(GPIO1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(GPIO1);
  if(val == 1) {
    digitalWrite(13, 1);
  } else {
    digitalWrite(13, 0);
  }
  delay(500);
}