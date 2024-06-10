#include <Adafruit_CircuitPlayground.h>
#include <AsyncDelay.h>

bool pauseOn;
bool blueButtonOn;
bool yellowButtonOn;
bool greenButtonOn;
bool purpleButtonOn;
bool leftButtonPressed;
bool rightButtonPressed;
bool slideSwitch;
volatile int score = 0;
const byte leftButtonPin = 4;
const byte rightButtonPin = 5;
int lives = 3;
volatile int highscore = 0;
volatile bool stateForLeftB = 0;
volatile bool stateForRightB = 0;
volatile int mode = -1;
volatile int mode2 = -1;
volatile int mode3 = -1;
volatile int mode4 = -1;
volatile int mode5 = -1;
volatile int mode6 = -1;
volatile int mode7 = -1;

const uint8_t spDANGER[] PROGMEM = { 0x2D, 0xBF, 0x21, 0x92, 0x59, 0xB4, 0x9F, 0xA2, 0x87, 0x10, 0x8E, 0xDC, 0x72, 0xAB, 0x5B, 0x9D, 0x62, 0xA6, 0x42, 0x9E, 0x9C, 0xB8, 0xB3, 0x95, 0x0D, 0xAF, 0x14, 0x15, 0xA5, 0x47, 0xDE, 0x1D, 0x7A, 0x78, 0x3A, 0x49, 0x65, 0x55, 0xD0, 0x5E, 0xAE, 0x3A, 0xB5, 0x53, 0x93, 0x88, 0x65, 0xE2, 0x00, 0xEC, 0x9A, 0xEA, 0x80, 0x65, 0x82, 0xC7, 0xD8, 0x63, 0x0A, 0x9A, 0x65, 0x5D, 0x53, 0xC9, 0x49, 0x5C, 0xE1, 0x7D, 0x2F, 0x73, 0x2F, 0x47, 0x59, 0xC2, 0xDE, 0x9A, 0x27, 0x5F, 0xF1, 0x8B, 0xDF, 0xFF, 0x03 };
const uint8_t spOVER[] PROGMEM = { 0xA7, 0xD0, 0xAE, 0x2F, 0x50, 0xBA, 0x9D, 0x5C, 0xDB, 0xFA, 0x24, 0xCE, 0x3A, 0x72, 0x19, 0xFA, 0x15, 0x25, 0x73, 0xCB, 0x45, 0xAE, 0x67, 0xB4, 0x2E, 0xAD, 0x10, 0xB1, 0x4E, 0xC1, 0x3D, 0xB7, 0x3A, 0x1A, 0x57, 0x95, 0x70, 0xD4, 0x9A, 0x6C, 0x4C, 0x85, 0xCD, 0x4D, 0xAF, 0x5A, 0xA5, 0x7D, 0x9A, 0x9B, 0xBB, 0x1B, 0x8D, 0x69, 0x66, 0xE9, 0xDC, 0xAD, 0xB5, 0xA6, 0x84, 0xD8, 0xA8, 0xB6, 0xD4, 0xE9, 0x2E, 0x56, 0x23, 0x7E, 0x42, 0xAF, 0xBB, 0xC8, 0x94, 0x78, 0x76, 0xBD, 0x99, 0x2C, 0x59, 0xEC, 0xCB, 0xF5, 0xB2, 0x98, 0x64, 0xA6, 0xE4, 0x07, 0x00, 0x00 };
const uint8_t spGAMES[] PROGMEM = { 0xAA, 0x15, 0x24, 0x2A, 0xD6, 0xE4, 0xB6, 0xB6, 0x79, 0x13, 0xB1, 0x5C, 0xB2, 0xF3, 0x93, 0x97, 0xA4, 0x66, 0x3E, 0x75, 0x77, 0x3E, 0xF2, 0x52, 0x8D, 0xCD, 0x26, 0xF6, 0xCC, 0x7B, 0xDE, 0x8A, 0x9A, 0x14, 0x2D, 0xBA, 0xD2, 0xAC, 0x66, 0xDD, 0xEB, 0xDE, 0x8E, 0xB6, 0x7A, 0x47, 0x0D, 0xAF, 0x95, 0x3A, 0x6D, 0xB1, 0x9A, 0xDA, 0x8E, 0xED, 0x6C, 0x67, 0x3A, 0x6E, 0xA5, 0x46, 0x42, 0xB1, 0xED, 0x74, 0x27, 0x3A, 0x62, 0x32, 0xC2, 0x23, 0x76, 0xEA, 0x7F, 0x22, 0x36, 0x11, 0xF5, 0x06, 0x38, 0x1C, 0xC8, 0x00, 0xDF, 0x29, 0x39, 0xE0, 0x7B, 0x56, 0x03, 0x7C, 0xCD, 0xCA, 0x80, 0xCC, 0x83, 0x1E, 0x00, 0x00 };


AsyncDelay delay_2s;

void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(1);
  attachInterrupt(digitalPinToInterrupt(leftButtonPin), buttonInterruptLeft, RISING);
  attachInterrupt(digitalPinToInterrupt(rightButtonPin), buttonInterruptRight, RISING);

  randomSeed(analogRead(0));
}

void loop() {
  // put your main code here, to run repeatedly:
  leftButtonPressed = CircuitPlayground.leftButton();
  rightButtonPressed = CircuitPlayground.rightButton();
  slideSwitch = CircuitPlayground.slideSwitch();

  switch (mode) { // Level 1
    case 0:
      blueButton(1000);   // Sets blueButton and yellow button to a 1 econd
      break;
    case 1:
      yellowButton(1000);
      break;
  }
  switch (mode2) { // Level 2
    case 0:
      blueButton(750); // Sets blueButton and yellow button to 750 ms
      break;
    case 1:
      yellowButton(750);
      break;
  }
  switch (mode3) { // Level 3
    case 0:
      blueButton(750); // Keeps the time the same, but adds a green button
      break;
    case 1:
      yellowButton(750);
      break;
    case 2:
      greenButton(750);
      break;
  }
  switch (mode4) { // Level 4
    case 0:
      blueButton(600); // Adds purple button, and decreases the time for each function by 150 ms
      break;
    case 1:
      yellowButton(600);
      break;
    case 2:
      greenButton(600);
      break;
    case 4:
      purpleButton(600);
      break;
  }
  switch (mode5) { // Level 5
    case 0:
      blueButton(500); // Sets the time for each function to 500 ms
      break;
    case 1:
      yellowButton(500);
      break;
    case 2:
      greenButton(500);
      break;
    case 4:
      purpleButton(500);
      break;
  }
  switch (mode6) { // Level 6
    case 0:
      blueButton(350); // Sets the time for each function to 350 ms
      break;
    case 1:
      yellowButton(350);
      break;
    case 2:
      greenButton(350);
      break;
    case 4:
      purpleButton(350);
      break;
  }
  switch (mode7) { // Level 7
    case 0:
      blueButton(250);  // Sets the time for each function to 250 ms
      break;
    case 1:
      yellowButton(250);
      break;
    case 2:
      greenButton(250);
      break;
    case 4:
      purpleButton(250);
      break;
  }

  if (slideSwitch) { // Starts the game if the slide is switched to the right
    scoreFunction();
  } else { // Shows the menu screen if slide is switched to the left
    CircuitPlayground.clearPixels();
    deactivate();
    lives = 3; // Sets lives to 3 before the game begins
    score = 0; // Resets score before the game begins
    Serial.println(" ");
    Serial.println(" ");
    Serial.println("Jaydan's Beautiful, Beautiful game:");
    Serial.println("!! Flick the switch to play !!");
    Serial.println(" ");
    Serial.println(" ");
    Serial.println("Rules:");
    Serial.println("- Blue LED: Left Button");
    Serial.println("- Yellow LED: Right Button");
    Serial.println("- Green LED: No Input ");
    Serial.println("- Purple LED: Right and Left Button");
    Serial.println("- Game get harder every 10 points");
    delay(1000);
  }
}

void correct() { // Lights up all neopixels to white when the player gets an option correct
  delay(250);
  for (int i = 0; i < 10; i++) { 
    CircuitPlayground.setPixelColor(i, 0xFFFFFF);
  }
  CircuitPlayground.playTone(random(400, 2000), 20);
  delay(250);
  CircuitPlayground.clearPixels();
  stateForRightB = 0; 
  stateForLeftB = 0;
  score++; // Increments the score by 1 every time the correct() function is called
}
void error() {  // Lights up all neopixels to red when the player gets an option wrong
  delay(250);
  for (int i = 0; i < 10; i++) {
    CircuitPlayground.setPixelColor(i, 255, 0, 0);
  }
  CircuitPlayground.playTone(400, 500);
  delay(250);
  CircuitPlayground.clearPixels();
  stateForRightB = 0;
  stateForLeftB = 0;
  lives--; // Decreases the life count by 1 every time the error() function is called
}

void buttonInterruptLeft() { // ISR for the left button
  stateForLeftB = 1;
}

void buttonInterruptRight() { // ISR for the right button
  stateForRightB = 1; 
}

void blueButton(int delayTime) { // Lights up a random neopixel to blue for a specified amount of time 
  blueButtonOn = 1;
  CircuitPlayground.setPixelColor(random(10), 0, 0, 255);
  delay(delayTime);
  CircuitPlayground.clearPixels();

  if (stateForRightB && stateForLeftB && blueButtonOn) { // If left button and right button are pressed at the same time, error is called
    error();
    blueButtonOn = 0;
    stateForRightB = 0;
    stateForLeftB = 0;
  } else if (stateForLeftB && blueButtonOn) { // If left button is pressed, correct is called
    correct();
    blueButtonOn = 0;
    stateForLeftB = 0;
  } else if (stateForRightB && blueButtonOn) { // If right button is pressed, error is called
    error();
    blueButtonOn = 0;
    stateForRightB = 0;
  } else { // If no input is pressed, error is called
    error();
    blueButtonOn = 0;
  }
}

void yellowButton(int delayTime) { // Lights up a random neopixel to yellow for a specified amount of time 
  yellowButtonOn = 1;
  CircuitPlayground.setPixelColor(random(10), 255, 255, 0);
  delay(delayTime);
  CircuitPlayground.clearPixels();
  if (stateForRightB && stateForLeftB && yellowButtonOn) { // If left button and right button are pressed at the same time, error is called
    error();
    yellowButtonOn = 0;
    stateForRightB = 0;
    stateForLeftB = 0;
  } else if (stateForLeftB && yellowButtonOn) { // If left button is pressed, error is called
    error();
    yellowButtonOn = 0;
    stateForLeftB = 0;
  } else if (stateForRightB && yellowButtonOn) { // If right button is pressed, correct is called
    correct();
    yellowButtonOn = 0;
    stateForRightB = 0;
  } else { // If no input is pressed, error is called
    error();
    yellowButtonOn = 0;
  }
}

void greenButton(int delayTime) {
  greenButtonOn = 1;
  CircuitPlayground.setPixelColor(random(10), 0, 255, 0);
  delay(delayTime);
  CircuitPlayground.clearPixels();
  if (stateForRightB && greenButton != 0) { // If right button is pressed, error is called
    error();
    greenButtonOn = 0;
    stateForRightB = 0;
  } else if (stateForLeftB && greenButton != 0) { // If left button is pressed, error is called
    error();
    greenButtonOn = 0;
    stateForLeftB = 0;
  } else { // If no input is pressed, correct is called
    correct();
    greenButtonOn = 0;
  }
}

void purpleButton(int delayTime) {
  purpleButtonOn = 1;
  // CircuitPlayground.clearPixels();
  CircuitPlayground.setPixelColor(random(10), 255, 0, 255);
  delay(delayTime);
  CircuitPlayground.clearPixels();
  if (stateForRightB && stateForLeftB && purpleButton != 0) { // If left button and right button are pressed at the same time, correct is called
    correct();
    purpleButtonOn = 0;
    stateForRightB = 0;
    stateForLeftB = 0;
  } else { // If no input is pressed or only one of the buttons are pressed, error is called
    error();
    purpleButtonOn = 0;
  }
}

void deactivate() { // Sets all modes to -1 which deactivates the game
  mode = -1;
  mode2 = -1;
  mode3 = -1;
  mode4 = -1;
  mode5 = -1;
  mode6 = -1;
  mode7 = -1;
}

void scoreFunction() {

  if (score > highscore) { // Increases the highscore by 1 when the score integer is higher than the highscore integer
    highscore++;
  }

  if (score >= 5) { // If the score is 5 or more, level 2 executes
    mode2 = random(2);
    mode = -1;
  }
  if (score >= 10) { // If the score is 10 or more, level 3 executes
    mode3 = random(4);
    mode2 = -1;
  }
  if (score >= 20) { // If the score is 20 or more, level 4 executes
    mode4 = random(5);
    mode3 = -1;
  }
  if (score >= 30) { // If the score is 30 or more, level 5 executes
    mode5 = random(5);
    mode4 = -1;
  }
  if (score >= 40) { // If the score is 40 or more, level 6 executes
    mode6 = random(5);
    mode5 = -1;
  }
  if (score >= 50) { // If the score is 50 or more, level 7 executes
    mode7 = random(5);
    mode6 = -1;
  }
  if (score < 5) { // If the score is less than 5, the player is put on level 1
    mode = random(2);
    mode7 = -1;
  }

  if (lives > 0) { // If the life count is higher than 3, the score & life count & highscore is printed

    Serial.print("Score: ");
    Serial.println(score);

    Serial.print("Lives ");
    Serial.println(lives);

    Serial.print("High score: ");
    Serial.println(highscore);

    delay(100);
  } else { 
    if (lives <= 0) { // If the player runs out of lives, the game ends and the player is taken to the end screen
      CircuitPlayground.clearPixels();
      deactivate();
      CircuitPlayground.speaker.say(spGAMES);
	    CircuitPlayground.speaker.say(spOVER);
      for (int i = 0; i < 9; i++) {
        Serial.println("You lost!");
      }
      if (score == highscore) {
        Serial.println("New high score!");
      }
      Serial.print("High score: ");
      Serial.println(highscore);
    }
    delay(1000);
  }
}