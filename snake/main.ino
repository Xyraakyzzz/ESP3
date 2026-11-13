#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

constexpr uint8_t LCD_ADDRESS = 0x27;
constexpr uint8_t LCD_COLUMNS = 16;
constexpr uint8_t LCD_ROWS = 2;
constexpr uint8_t PIXEL_COLUMNS = LCD_COLUMNS * 5;
constexpr uint8_t PIXEL_ROWS = LCD_ROWS * 8;
constexpr uint8_t MAX_SNAKE_LENGTH = 25;
constexpr uint8_t MAX_GAME_SPEED = 25;
constexpr uint8_t INITIAL_GAME_SPEED = 8;
constexpr uint8_t CUSTOM_CHAR_COUNT = 8;
constexpr uint8_t JOYSTICK_X_PIN = A0;
constexpr uint8_t JOYSTICK_Y_PIN = A1;
constexpr uint8_t JOYSTICK_Z_PIN = A2;
constexpr uint8_t JOYSTICK_RELEASED = 255;
constexpr uint16_t JOYSTICK_DEADZONE = 150;
constexpr uint16_t JOYSTICK_LOW_THRESHOLD = 350;
constexpr uint16_t JOYSTICK_HIGH_THRESHOLD = 674;
constexpr unsigned long JOYSTICK_DEBOUNCE_MS = 35;
constexpr unsigned long BUTTON_DEBOUNCE_MS = 35;

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLUMNS, LCD_ROWS);

const uint16_t WALL_MASKS[4][2] = {
  {0x0000, 0x0000},
  {0x8001, 0x8001},
  {0x8811, 0x8101},
  {0x2205, 0x8890}
};

enum Direction : uint8_t {
  DIR_UP = 0,
  DIR_DOWN = 1,
  DIR_RIGHT = 2,
  DIR_LEFT = 3
};

enum GameState : uint8_t {
  STATE_MENU,
  STATE_PLAYING,
  STATE_GAME_OVER
};

struct SnakeSegment {
  uint8_t row;
  uint8_t column;
};

GameState gameState = STATE_MENU;
SnakeSegment snake[MAX_SNAKE_LENGTH];
uint8_t snakeLength = 0;
uint8_t selectedLevel = 0;
uint8_t currentDirection = DIR_LEFT;
uint8_t pendingDirection = DIR_LEFT;
uint8_t gameSpeed = INITIAL_GAME_SPEED;
uint8_t foodRow = 0;
uint8_t foodColumn = 0;
bool foodExists = false;
unsigned long collected = 0;
unsigned long lastMoveTime = 0;

uint8_t field[PIXEL_ROWS * 16];
uint8_t customGlyphs[CUSTOM_CHAR_COUNT][8];

uint8_t lastJoystickRaw = JOYSTICK_RELEASED;
uint8_t stableJoystickDirection = JOYSTICK_RELEASED;
unsigned long joystickRawChangedAt = 0;

uint8_t lastButtonReading = HIGH;
uint8_t stableButtonState = HIGH;
unsigned long buttonRawChangedAt = 0;

bool isObstacleCell(uint8_t row, uint8_t column) {
  if (row >= PIXEL_ROWS || column >= PIXEL_COLUMNS) {
    return true;
  }

  uint8_t displayRow = row / 8;
  uint8_t displayColumn = column / 5;
  return (WALL_MASKS[selectedLevel][displayRow] & (uint16_t(1) << displayColumn)) != 0;
}

void setPixel(uint8_t row, uint8_t column) {
  if (row >= PIXEL_ROWS || column >= PIXEL_COLUMNS) {
    return;
  }

  uint16_t index = uint16_t(row) * 16 + column / 5;
  field[index] |= uint8_t(1U << (column % 5));
}

void clearField() {
  memset(field, 0, sizeof(field));
}

bool snakeContains(uint8_t row, uint8_t column) {
  for (uint8_t i = 0; i < snakeLength; i++) {
    if (snake[i].row == row && snake[i].column == column) {
      return true;
    }
  }
  return false;
}

bool spawnFood() {
  for (uint16_t attempt = 0; attempt < 256; attempt++) {
    uint8_t row = random(PIXEL_ROWS);
    uint8_t column = random(PIXEL_COLUMNS);

    if (!isObstacleCell(row, column) && !snakeContains(row, column)) {
      foodRow = row;
      foodColumn = column;
      foodExists = true;
      return true;
    }
  }

  for (uint8_t row = 0; row < PIXEL_ROWS; row++) {
    for (uint8_t column = 0; column < PIXEL_COLUMNS; column++) {
      if (!isObstacleCell(row, column) && !snakeContains(row, column)) {
        foodRow = row;
        foodColumn = column;
        foodExists = true;
        return true;
      }
    }
  }

  foodExists = false;
  return false;
}

uint8_t glyphDistance(const uint8_t *first, const uint8_t *second) {
  uint8_t distance = 0;

  for (uint8_t row = 0; row < 8; row++) {
    uint8_t bits = first[row] ^ second[row];
    while (bits != 0) {
      distance += bits & 1U;
      bits >>= 1;
    }
  }

  return distance;
}

void drawMatrix() {
  clearField();

  for (uint8_t i = 0; i < snakeLength; i++) {
    setPixel(snake[i].row, snake[i].column);
  }

  if (foodExists) {
    setPixel(foodRow, foodColumn);
  }

  uint8_t customCount = 0;

  for (uint8_t displayRow = 0; displayRow < LCD_ROWS; displayRow++) {
    for (uint8_t displayColumn = 0; displayColumn < LCD_COLUMNS; displayColumn++) {
      uint8_t glyph[8] = {0};
      bool hasPixels = false;

      for (uint8_t pixelRow = 0; pixelRow < 8; pixelRow++) {
        uint8_t absoluteRow = displayRow * 8 + pixelRow;

        for (uint8_t pixelColumn = 0; pixelColumn < 5; pixelColumn++) {
          uint8_t absoluteColumn = displayColumn * 5 + pixelColumn;
          uint16_t index = uint16_t(absoluteRow) * 16 + absoluteColumn / 5;
          uint8_t mask = uint8_t(1U << (absoluteColumn % 5));

          if (field[index] & mask) {
            glyph[pixelRow] |= uint8_t(1U << (4 - pixelColumn));
            hasPixels = true;
          }
        }
      }

      lcd.setCursor(displayColumn, displayRow);

      if (!hasPixels) {
        lcd.write(uint8_t(isObstacleCell(displayRow * 8, displayColumn * 5) ? 255 : ' '));
        continue;
      }

      int8_t selectedGlyph = -1;

      for (uint8_t i = 0; i < customCount; i++) {
        if (memcmp(customGlyphs[i], glyph, sizeof(glyph)) == 0) {
          selectedGlyph = i;
          break;
        }
      }

      if (selectedGlyph < 0 && customCount < CUSTOM_CHAR_COUNT) {
        memcpy(customGlyphs[customCount], glyph, sizeof(glyph));
        lcd.createChar(customCount, customGlyphs[customCount]);
        selectedGlyph = customCount;
        customCount++;
      }

      if (selectedGlyph < 0) {
        uint8_t bestDistance = 255;
        uint8_t bestGlyph = 0;

        for (uint8_t i = 0; i < CUSTOM_CHAR_COUNT; i++) {
          uint8_t distance = glyphDistance(customGlyphs[i], glyph);
          if (distance < bestDistance) {
            bestDistance = distance;
            bestGlyph = i;
          }
        }

        selectedGlyph = bestGlyph;
      }

      lcd.setCursor(displayColumn, displayRow);
      lcd.write(uint8_t(selectedGlyph));
    }
  }
}

void showMenu() {
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("ARDUINO SNAKE");
  lcd.setCursor(0, 1);
  lcd.print("LEVEL: ");
  lcd.print(selectedLevel + 1);
  lcd.print("  PRESS");
}

void showGameOver() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("GAME OVER");
  lcd.setCursor(0, 1);
  lcd.print("SCORE: ");
  lcd.print(collected);
}

void startGame() {
  snakeLength = 3;
  snake[0] = {7, 40};
  snake[1] = {7, 39};
  snake[2] = {7, 38};
  collected = 0;
  gameSpeed = INITIAL_GAME_SPEED;
  currentDirection = DIR_LEFT;
  pendingDirection = DIR_LEFT;
  foodExists = false;
  gameState = STATE_PLAYING;

  if (!spawnFood()) {
    gameState = STATE_GAME_OVER;
    showGameOver();
    return;
  }

  lastMoveTime = millis();
  drawMatrix();
}

bool isOppositeDirection(uint8_t first, uint8_t second) {
  return (first == DIR_UP && second == DIR_DOWN) ||
         (first == DIR_DOWN && second == DIR_UP) ||
         (first == DIR_LEFT && second == DIR_RIGHT) ||
         (first == DIR_RIGHT && second == DIR_LEFT);
}

void finishGame() {
  gameState = STATE_GAME_OVER;
  showGameOver();
}

void moveSnake() {
  currentDirection = pendingDirection;

  int16_t nextRow = snake[snakeLength - 1].row;
  int16_t nextColumn = snake[snakeLength - 1].column;

  switch (currentDirection) {
    case DIR_UP:
      nextRow--;
      break;
    case DIR_DOWN:
      nextRow++;
      break;
    case DIR_RIGHT:
      nextColumn++;
      break;
    case DIR_LEFT:
      nextColumn--;
      break;
  }

  if (nextRow < 0) {
    nextRow = PIXEL_ROWS - 1;
  } else if (nextRow >= PIXEL_ROWS) {
    nextRow = 0;
  }

  if (nextColumn < 0) {
    nextColumn = PIXEL_COLUMNS - 1;
  } else if (nextColumn >= PIXEL_COLUMNS) {
    nextColumn = 0;
  }

  uint8_t targetRow = uint8_t(nextRow);
  uint8_t targetColumn = uint8_t(nextColumn);
  bool eating = foodExists && targetRow == foodRow && targetColumn == foodColumn;
  bool willGrow = eating && snakeLength < MAX_SNAKE_LENGTH;

  if (isObstacleCell(targetRow, targetColumn)) {
    finishGame();
    return;
  }

  uint8_t firstBodySegment = willGrow ? 0 : 1;

  for (uint8_t i = firstBodySegment; i < snakeLength; i++) {
    if (snake[i].row == targetRow && snake[i].column == targetColumn) {
      finishGame();
      return;
    }
  }

  if (willGrow) {
    snake[snakeLength].row = targetRow;
    snake[snakeLength].column = targetColumn;
    snakeLength++;
  } else {
    for (uint8_t i = 0; i + 1 < snakeLength; i++) {
      snake[i] = snake[i + 1];
    }
    snake[snakeLength - 1].row = targetRow;
    snake[snakeLength - 1].column = targetColumn;
  }

  if (eating) {
    collected++;
    if (gameSpeed < MAX_GAME_SPEED) {
      uint16_t nextSpeed = uint16_t(gameSpeed) + 3;
      if (nextSpeed > MAX_GAME_SPEED) {
        nextSpeed = MAX_GAME_SPEED;
      }
      gameSpeed = uint8_t(nextSpeed);
    }

    if (!spawnFood()) {
      finishGame();
      return;
    }
  }

  drawMatrix();
}

uint8_t readJoystickDirection() {
  int xValue = analogRead(JOYSTICK_X_PIN);
  int yValue = analogRead(JOYSTICK_Y_PIN);
  uint16_t xDistance = abs(xValue - 512);
  uint16_t yDistance = abs(yValue - 512);

  if (xDistance < JOYSTICK_DEADZONE && yDistance < JOYSTICK_DEADZONE) {
    return JOYSTICK_RELEASED;
  }

  if (xDistance >= yDistance) {
    if (xValue < JOYSTICK_LOW_THRESHOLD) {
      return DIR_UP;
    }
    if (xValue > JOYSTICK_HIGH_THRESHOLD) {
      return DIR_DOWN;
    }
  } else {
    if (yValue < JOYSTICK_LOW_THRESHOLD) {
      return DIR_RIGHT;
    }
    if (yValue > JOYSTICK_HIGH_THRESHOLD) {
      return DIR_LEFT;
    }
  }

  return JOYSTICK_RELEASED;
}

uint8_t readJoystickEvent(unsigned long now) {
  uint8_t rawDirection = readJoystickDirection();

  if (rawDirection != lastJoystickRaw) {
    lastJoystickRaw = rawDirection;
    joystickRawChangedAt = now;
  }

  if (now - joystickRawChangedAt >= JOYSTICK_DEBOUNCE_MS && rawDirection != stableJoystickDirection) {
    stableJoystickDirection = rawDirection;
    if (stableJoystickDirection != JOYSTICK_RELEASED) {
      return stableJoystickDirection;
    }
  }

  return JOYSTICK_RELEASED;
}

bool readButtonEvent(unsigned long now) {
  uint8_t reading = digitalRead(JOYSTICK_Z_PIN);

  if (reading != lastButtonReading) {
    lastButtonReading = reading;
    buttonRawChangedAt = now;
  }

  if (now - buttonRawChangedAt >= BUTTON_DEBOUNCE_MS && reading != stableButtonState) {
    stableButtonState = reading;
    return stableButtonState == LOW;
  }

  return false;
}

void setup() {
  pinMode(JOYSTICK_Z_PIN, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();

  randomSeed((static_cast<unsigned long>(analogRead(JOYSTICK_X_PIN)) << 20) ^
             (static_cast<unsigned long>(analogRead(JOYSTICK_Y_PIN)) << 10) ^ micros());

  unsigned long now = millis();
  joystickRawChangedAt = now;
  buttonRawChangedAt = now;
  lastButtonReading = digitalRead(JOYSTICK_Z_PIN);
  stableButtonState = lastButtonReading;
  showMenu();
}

void loop() {
  unsigned long now = millis();
  uint8_t directionEvent = readJoystickEvent(now);
  bool switchPressed = readButtonEvent(now);

  if (gameState == STATE_MENU) {
    bool levelChanged = false;

    if (directionEvent == DIR_UP && selectedLevel < 3) {
      selectedLevel++;
      levelChanged = true;
    } else if (directionEvent == DIR_DOWN && selectedLevel > 0) {
      selectedLevel--;
      levelChanged = true;
    }

    if (levelChanged) {
      showMenu();
    }

    if (switchPressed) {
      startGame();
    }
  } else if (gameState == STATE_PLAYING) {
    if (directionEvent != JOYSTICK_RELEASED && !isOppositeDirection(directionEvent, currentDirection)) {
      pendingDirection = directionEvent;
    }

    unsigned long moveInterval = 1000UL / gameSpeed;
    if (now - lastMoveTime >= moveInterval) {
      lastMoveTime = now;
      moveSnake();
    }
  } else if (gameState == STATE_GAME_OVER && directionEvent != JOYSTICK_RELEASED) {
    gameState = STATE_MENU;
    showMenu();
  }
}
