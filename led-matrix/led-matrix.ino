#include "frames.h"
#include <avr/wdt.h>

#define BUTTON 2
#define SER 6 //port d 6
#define SCK 3
#define RCK 4
#define OE  5
#define HALT 7

#define BSER 8
#define BSCK 9
#define BRCK 10

#define UP 69   //for shifting
#define DOWN 15
#define RIGHT 96
#define LEFT 123


#define SCREEN_WIDTH 31
#define SCREEN_HEIGHT 11
#define N  0
#define NE 1
#define E  2
#define SE 3
#define S  4
#define SW 5
#define W  6
#define NW 7

#define INVERTED 69 //nice



//uint32_t led[] = {
//  0x00000000,
//  0x00000000,
//  0x00000000,
//  0x00000000,
//  0x00000000, //0 for all characters top row
//  0x633C6060,
//  0x63186060,
//  0x63186060,
//  0x6B186060,
//  0x7F186060,
//  0x77186060,
//  0x633C7E7E
//};
uint32_t led[12];
uint32_t renderDelay = 50;
int potVal = 0, upperTimer = 100;
void setup() {
  DDRD |= (1 << SER) | (1 << RCK) | (1 << SCK) | (1 << OE); //make button input pullup
  PORTD = 0;
  potVal = analogRead(A5);
  potVal = map(potVal, 0, 1023, 1, upperTimer);
  setTimer(potVal, upperTimer);
  PORTD &= ~(1 << OE); //disable output, turn on LEDs
  pinMode(BSER, INPUT_PULLUP);
  pinMode(BSCK, INPUT_PULLUP);
  pinMode(BRCK, INPUT_PULLUP);
  pinMode(BUTTON, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonMethod, FALLING);
  //for (int i = 0; i < 500; i++)render();
  wdt_enable(WDTO_4S);
}
uint8_t timer = 0;
uint8_t buttonCount = 0;
uint8_t ballDir = NW;
uint8_t textTime = 20, sinTime = 20, amongUsTime = 75, jumpTime = 20, asteroidsTime = 20, brickBreakerTime = 5, crazyTime = 50, rainTime = 50;
int brightnessUpdate = 100;
bool halted = false, initial = true;
//char str [] = "led matrix rev a   you can write whatever you want here ";
char str[] = "katelyn sucks ";
unsigned long time = millis();
void loop() {
  if (digitalRead(HALT) == 1) { //if the jumper is in, check brightness and nothing else
    while (digitalRead(HALT) == 1) {
      if (digitalRead(BSCK) == 0) digitalWrite(SCK, HIGH);
      else digitalWrite(SCK, LOW);
      if (digitalRead(BRCK) == 0) digitalWrite(RCK, HIGH);
      else digitalWrite(RCK, LOW);
      if (digitalRead(BSER) == 0) digitalWrite(SER, HIGH);
      else digitalWrite(SER, LOW);
      delay(2); //debounce

      if (millis() - time > brightnessUpdate) {
        time = millis();
        potVal = analogRead(A5);
        potVal = map(potVal, 0, 1024, 1, upperTimer);
        setTimer(potVal, upperTimer);
      }
    }
  }

  if (millis() - time > brightnessUpdate) { //update brightness every 100ms
    time = millis();
    potVal = analogRead(A5);
    potVal = map(potVal, 0, 1024, 1, upperTimer);
    setTimer(potVal, upperTimer);
    //renderDelay = map(potVal, 0, 1024, 100, 300000);
  }
  wdt_reset();
  /////////////////////////////////////////////////////////////////////////////////
  switch (buttonCount) {
    case 0: text(0); break;
    case 1: text(INVERTED); break;
    case 2: amongUs(); break;
    case 3: sineWave(); break;
    case 4: pencil(); break;
    case 5: rain(); break;
  }
  //brickBreaker();
  //crazy();
  //rain();
  render();
  timer++;
}

unsigned long lastMill = 0;
void buttonMethod() {
  unsigned long m = millis();
  if (m - lastMill > 500) {
    lastMill = millis();
    buttonCount++;
    if (buttonCount > 5) {
      buttonCount = 0;
      initial = true;
    }
  }
}

//void countDown

byte paddlePos = 16, paddleLength = 4, bulletPos;
void asteroids() {
  if (timer > asteroidsTime) {
    timer = 0;
    //left shoot right
    //ser  sck   rck
    if (digitalRead(BSER) == 0 && paddlePos < 28)paddlePos++;
    else if (digitalRead(BRCK) == 0 && paddlePos > 0)paddlePos--;
  }
}
double bx = 18, by = 4, spd = 1;
byte sz = 1;
void brickBreaker() {
  if (timer > brickBreakerTime) {
    timer = 0;
    clearLED();
    setDir();
    //
    //    if (digitalRead(BSER) == 0 && paddlePos < 28)paddlePos++;
    //    else if (digitalRead(BRCK) == 0 && paddlePos > 0)paddlePos--;
    //    led[11] = ((uint32_t)pow(2, paddleLength) - 1) << paddlePos;
    //    led[(int)round(by)] |= (uint32_t)1 << (uint32_t)round(bx);


  }
}
bool isOnLeft = true;
uint8_t dropSize = 0;
void rain() {
  if (timer > rainTime) {
    timer = 0;
    shift(DOWN);
    if (isOnLeft) {
      led[0] = (uint32_t)0x4020 << 16 | 0x1008;
      dropSize++;
      if (dropSize > 2) {
        isOnLeft = !isOnLeft;
        dropSize = 0;
      }
    }
    else {
      led[0] = (uint32_t)0x2010 << 16 | 0x804;
      dropSize++;
      if (dropSize > 2) {
        isOnLeft = !isOnLeft;
        dropSize = 0;
      }
    }
    //led[0] = random(0, 0xffff) | (uint32_t)random(0, 0xf000) << 16;
  }
}
void crazy() {
  if (timer > crazyTime) {
    timer = 0;
    clearLED();
    for (int i = 0; i < 12; i++) {
      led[i] |= random(0, 0xffff) | (uint32_t)random(0, 0xffff) << 16;
    }
  }
}
void pencil() {
  if (initial) {
    clearLED();
    initial = false;
  }
  if (timer > brickBreakerTime) {
    timer = 0;

    setDir();
    //    led[(int)round(by)] |= (uint32_t)1 << (uint32_t)round(bx);
    clearLED();
    led[(int)round(by)] = (uint32_t)1 << (uint32_t)round(bx);
  }
}

int stringIndex = 0, charIndex = 0;
char charPos = 0; //first bit from left
void text(byte inv) {
  if (timer > textTime) {
    timer = 0;
    shift(LEFT);
    int len = sizeof(str) / sizeof(str[0]);
    char textLetter = str[stringIndex];
    if (textLetter == ' ') textLetter = 37;
    else if (textLetter <= '9' && textLetter >= '0') textLetter -= 48;
    else textLetter -= 87;
    for (int i = 0; i < 8; i++) {
      if (inv == INVERTED) {
        if (i < 4)led[i] |= 1;
        if (((128 >> (charPos))&characters[textLetter][i]) != (128 >> (charPos))) led[i + 4] |= 1;
      }
      else if (((128 >> (charPos))&characters[textLetter][i]) == (128 >> (charPos))) led[i + 4] |= 1;
    }
    charPos++;
    if (charPos > 7) {
      charPos = 0;
      stringIndex++;
      if (stringIndex > len) {
        stringIndex = 0;
      }
    }
  }
}
int amongFrame = 0, amongUpOrDown = 1;
void amongUs() {
  if (timer > amongUsTime) {
    timer = 0;
    for (int i = 0; i < 12; i++) {
      led[i] = amongUsFrames[amongFrame][i];

    }
    amongFrame += amongUpOrDown;
    if (amongFrame == 15)amongUpOrDown = -1;
    if (amongFrame == 0)amongUpOrDown = 1;
  }
}
int jumpFrame = 0;
void jumpAnim() {
  if (timer > jumpTime) {
    timer = 0;
    for (int i = 0; i < 12; i++) {
      led[i] = jumpFrames[jumpFrame][i];
    }
    jumpFrame++;
    if (jumpFrame == 23) {
      jumpFrame = 0;
    }
  }
}

float rad = 0, inc = PI / 20;
void sineWave() {
  if (timer > sinTime) {
    timer = 0;
    shift(LEFT);
    int sPos = round(5 * sin(rad) + 5);
    int cPos = round(5 * cos(rad) + 5);
    led[sPos + 1] |= 1;
    //    for(int i = 0; i <= sPos; i++){
    //      led[i]|=1;
    //    }

    //led[cPos+1] |= 1;
    //    for(int i = 0; i < 12; i++){
    //      if(i!=sPos)led[i]|=1;
    //    }
    rad += inc;
    if (rad > 6.28)rad = 0;
  }
}

void clearLED() {
  for (int i = 0; i < 12; i++) {
    led[i] = 0;
  }
}
void _delay(int ms) {
  ms /= 17;
  for (int i = 0; i < ms; i++) {
    render();
  }
}


void render() {
  for (uint32_t i = 0; i < 12; i++) {
    shiftData((uint32_t)pow(2, 11) >> i, 12);  //shift one byte to connect cathode row
    shiftData(led[i], 32);  //shift 32 bits of LED data
    PORTD |= (1 << RCK);
    //delayMicroseconds(renderDelay);
    //delay(50);
    PORTD &= ~(1 << RCK);
  }
}
void shiftData(uint32_t data, uint32_t bits) {
  if (bits == 32) {
    for (uint32_t i = 0; i < bits; i++) {
      uint32_t firstHalf = (data & 0xffff), secondHalf = (data & 0xffff0000) >> 16;
      uint32_t current = 0;
      current = (1 & data);
      data = data >> 1;
      if (current == 1) PORTD |= (1 << SER);
      else PORTD &= ~(1 << SER);
      //delayMicroseconds(2);
      PORTD |= (1 << SCK);
      //delayMicroseconds(2);
      PORTD &= ~(1 << SCK);
      PORTD &= ~(1 << SER);
    }
  }
  else {
    for (uint32_t i = 0; i < bits; i++) {
      uint32_t current = 0;
      current = (data & (1 << i)) >> i;
      if (current == 1) PORTD |= (1 << SER);
      else PORTD &= ~(1 << SER);
      delayMicroseconds(2);
      PORTD |= (1 << SCK);
      delayMicroseconds(2);
      PORTD &= ~(1 << SCK);
      PORTD &= ~(1 << SER);
    }
  }
}
void shift(char dir) {
  if (dir == RIGHT) {
    for (int i = 0; i < 12; i++) {
      if (led[i] & 1 == 1)led[i]--;
      led[i] = (led[i] >> 1);
    }
  }
  else if (dir == LEFT) {
    for (int i = 0; i < 12; i++) {
      if (led[i] & 0x80000000 == 0x80000000); led[i] &= ~(0x80000000); //led[i]-=0x80000000
      led[i] = (led[i] << 1);
    }
  }
  else if (dir == DOWN) {
    for (int i = 11; i > 0; i--) {
      led[i] = led[i - 1];
    }
    led[0] = 0;
  }
  else if (dir == UP) {
    for (int i = 0; i < 11; i++) {
      led[i] = led[i + 1];
    }
    led[11] = 0;
  }
}
void setTimer(int b, int a) {
  cli();

  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  TCCR1B |= (1 << WGM12) | (1 << CS11); //ctc mode, prescaler of 8 -> 2MHz -> 500ns
  OCR1A = a;
  OCR1B = b;
  TIMSK1 |= (1 << OCIE1A) | (1 << OCIE1B);

  sei();
}
ISR(TIMER1_COMPA_vect) {
  PORTD &= ~(1 << OE); //disable output, turn on LEDs
}
ISR(TIMER1_COMPB_vect) {
  PORTD |= (1 << OE);  //enable output, turn off LEDs
}
void setDir() {
  switch (ballDir) {
    case N: {
        if (by > 0) by -= spd;
        break;
      }
    case NE: {
        if (by > 0) {
          if (bx <= 0) {
            ballDir = NW;
            setDir();
          }
          else {
            bx -= spd;
            by -= spd;
          }
        }
        else ballDir = SE;
        break;
      }
    case E: {
        bx += spd;
        break;
      }
    case SE: {
        if (by < (SCREEN_HEIGHT)) {
          if (bx <= 0) {
            ballDir = SW;
            setDir();
          }
          else {
            by += spd;
            bx -= spd;
          }
        }
        else ballDir = NE;
        break;
      }
    case S: {
        if (by < (SCREEN_HEIGHT)) {
          by += spd;
        }
        break;
      }
    case SW: {
        if (by < (SCREEN_HEIGHT)) {
          if (bx >= 31) {
            ballDir = SE;
            setDir();
          }
          else {
            by += spd;
            bx += spd;
          }
        }
        else ballDir = NW;
        break;
      }
    case W: {
        bx -= spd;
        break;
      }
    case NW: {
        if (by > 0) {
          if (bx >= 31) {
            ballDir = NE;
            setDir();
          }
          else {
            by -= spd;
            bx += spd;
          }
        }
        else ballDir = SW;
        break;
      }
  }
}
