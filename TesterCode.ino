#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define button1 2
#define button2 7

#define RGBPin 9

Servo Servo1;
Servo Servo2;
Servo Servo3;
Servo Servo4;

Adafruit_NeoPixel pixels(2, RGBPin, NEO_GRB + NEO_KHZ800);

int step = 0;
int pos = 0;
bool button1checked = 0;
bool button2checked = 0;
int pinsCount = 17;
int ledpins[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 20, 21, 38};
int melody[] = {262, 196, 196, 220, 196, 0, 247, 262};
int durations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void setup() {
  SerialUSB.begin(9600);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  attachInterrupt(digitalPinToInterrupt(button1), ISR1, FALLING);
  attachInterrupt(digitalPinToInterrupt(button2), ISR2, FALLING);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(38, OUTPUT);
  pixels.begin();


}

void ISR1() {
  if ((button1checked) && (button2checked) && (step > 0)) {
    step--;
    tone(8, 150, 50);
    delay(150);
  }
  else {
    tone(8, 150, 250);
  }
  button1checked = 1;
}

void ISR2() {
  button2checked = 1;
  if ((button1checked) && (button2checked) && (step < 7)) {
    step++;
    tone(8, 150, 50);
    delay(150);
  }
  else {
    tone(8, 150, 250);
  }
  button2checked = 1;
}

void loop() {
  SerialUSB.println(step);

  if (SerialUSB.available()) {
    int inByte = SerialUSB.read();
    SerialUSB.write(inByte);
  }

  switch (step) {
    case 0: ALLLED(); break;
    case 1: R(); break;
    case 2: G(); break;
    case 3: B(); break;
    case 4: RGB(); break;
    case 5: RUNLED(); break;
    case 6: BUZZER(); break;
    case 7: SERVO(); break;
  }
}

void ALLLED() {
  Servo1.detach();
  Servo2.detach();
  Servo3.detach();
  Servo4.detach();

  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
  digitalWrite(20, HIGH);
  digitalWrite(21, HIGH);
  digitalWrite(38, HIGH);

  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(255, 255, 255));
  pixels.setPixelColor(1, pixels.Color(255, 255, 255));
  pixels.show();
}

void RUNLED() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  pixels.clear();
  pixels.show();

  for (int i = 0; i < pinsCount; i = i + 1) {
    digitalWrite(ledpins[i], HIGH);
    delay(100);
    digitalWrite(ledpins[i], LOW);
    if (step != 5) {
      break;
    }
  }
  for (int i = pinsCount - 1; i > 0; i = i - 1) {
    digitalWrite(ledpins[i], HIGH);
    delay(100);
    digitalWrite(ledpins[i], LOW);
    if (step != 5) {
      break;
    }
  }
}

void R() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(255, 0, 0));
  pixels.setPixelColor(1, pixels.Color(255, 0, 0));
  pixels.show();
}

void G() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.setPixelColor(1, pixels.Color(0, 255, 0));
  pixels.show();
}

void B() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.setPixelColor(1, pixels.Color(0, 0, 255));
  pixels.show();
}

void RGB() {
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(255, 255, 255));
  pixels.setPixelColor(1, pixels.Color(255, 255, 255));
  pixels.show();
}

void BUZZER() {
  Servo1.detach();
  Servo2.detach();
  Servo3.detach();
  Servo4.detach();

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / durations[thisNote];
    tone(8, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    delay(10);
    if (step != 6) {
      break;
    }
  }

  pixels.clear();
  pixels.show();
}

void SERVO() {
  Servo1.attach(3);
  Servo2.attach(4);
  Servo3.attach(5);
  Servo4.attach(6);

  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(20, LOW);
  digitalWrite(21, LOW);
  digitalWrite(38, LOW);

  noTone(8);

  pixels.clear();
  pixels.show();

  for (pos = 0; pos <= 180; pos += 1) {
    Servo1.write(pos);
    Servo2.write(pos);
    Servo3.write(pos);
    Servo4.write(pos);
    delay(15);
    if (step != 7) {
      break;
    }
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    Servo1.write(pos);
    Servo2.write(pos);
    Servo3.write(pos);
    Servo4.write(pos);
    delay(15);
    if (step != 7) {
      break;
    }
  }
}
