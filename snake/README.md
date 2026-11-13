# Arduino Snake Game

A classic Snake Game implementation for Arduino, featuring a 16×2 I2C
LCD display and an analog joystick controller. The game uses custom LCD
characters to render a compact pixel-based playfield, providing a retro
gaming experience on embedded hardware.

## Features

-   **16×2 LCD Support** --- Uses an I2C LCD display with a 16-column
    and 2-row layout.
-   **Custom Pixel Rendering** --- Generates custom LCD characters to
    represent the snake and game elements.
-   **Joystick Controls** --- Supports directional movement through an
    analog joystick.
-   **Four Difficulty Levels** --- Includes progressively challenging
    levels with different obstacle layouts.
-   **Dynamic Difficulty** --- Automatically increases the game speed as
    the player collects food.
-   **Snake Growth** --- The snake grows when it collects food.
-   **Collision Detection** --- Detects collisions with obstacles and
    the snake's own body.
-   **Score Tracking** --- Displays the final score when the game ends.
-   **Wrapping Movement** --- Allows movement across opposite edges of
    the playfield where no obstacle prevents it.

## Hardware Requirements

  Component         Description
  ----------------- ------------------------------------------
  Arduino Board     Arduino Uno or compatible board
  LCD Display       16×2 LCD with I2C interface
  Joystick Module   Analog joystick with X, Y, and Z outputs
  Jumper Wires      For hardware connections
  Breadboard        Optional, for prototyping

## Dependencies

The project requires the following Arduino library:

-   `LiquidCrystal_I2C`

Install the library through the Arduino IDE Library Manager or your
preferred Arduino library installation method.

## Wiring

### I2C LCD Display

  LCD Pin   Arduino Uno
  --------- -------------
  VCC       5V
  GND       GND
  SDA       A4
  SCL       A5

### Joystick Module

  Joystick Pin   Arduino Pin
  -------------- -------------
  VRx            A0
  VRy            A1
  SW             A2
  VCC            5V
  GND            GND

**Note:** The joystick switch uses the internal pull-up configuration.
The display is configured with I2C address `0x27`. Depending on your LCD
module, the address may need to be adjusted.

## Installation

1.  Install the Arduino IDE.
2.  Install the `LiquidCrystal_I2C` library.
3.  Connect the LCD and joystick according to the wiring tables.
4.  Open the Arduino sketch.
5.  Select the appropriate Arduino board and serial port.
6.  Upload the sketch to your Arduino board.
7.  Power on the board to start the game.

## How to Play

### Starting the Game

1.  Power on the Arduino.
2.  The startup screen will appear.
3.  Select a difficulty level using the joystick.
4.  Press the joystick switch to start the game.

### Controls

  Joystick Direction   Action
  -------------------- -------------------------
  Up                   Move the snake upward
  Down                 Move the snake downward
  Left                 Move the snake left
  Right                Move the snake right
  Switch               Start the game

The snake cannot immediately reverse its current direction, preventing
direct movement into its own body.

### Difficulty Levels

The game provides four difficulty levels:

  Level   Description
  ------- ----------------------------------
  1       Open playfield without obstacles
  2       Border obstacles
  3       Additional internal obstacles
  4       Advanced obstacle configuration

Higher levels introduce more obstacles and require more careful
movement.

## Gameplay Mechanics

-   The snake moves continuously in the selected direction.
-   Collecting food increases the score and extends the snake.
-   The movement speed increases as the score grows.
-   The game ends when the snake collides with an obstacle or its own
    body.
-   After a game-over state, move the joystick to restart.

## Configuration

Several constants can be modified to customize the game.

  Constant               Default Description
  -------------------- --------- -----------------------------
  `MAX_SNAKE_LENGTH`        `25` Maximum snake length
  `levels`                   `4` Number of difficulty levels
  `ROWS`                     `2` Number of LCD display rows
  `gameSpeed`                `8` Initial movement speed
  LCD Address             `0x27` I2C address of the LCD

The LCD dimensions and custom character rendering are designed around a
16×2 display. Changing the display dimensions requires corresponding
modifications to the rendering and playfield logic.

## Technical Overview

The game uses a linked-list data structure to represent the snake's
body. Each segment stores its row, column, movement direction, and
pointer to the next segment.

The playfield is represented by a bit-packed array, allowing individual
pixel states to be stored efficiently. During rendering, the program
converts groups of five horizontal pixels into custom LCD characters
using `lcd.createChar()`.

This approach allows the game to simulate a higher-resolution graphical
display despite the limitations of a character-based LCD.

## Limitations

-   The graphical resolution is limited by the LCD's custom character
    system.
-   The game is designed for a 16×2 I2C LCD.
-   Joystick analog thresholds may require calibration depending on the
    module.
-   The maximum snake length is limited by the configured value.
-   The implementation uses dynamic memory allocation for snake
    segments.

## License

Specify your preferred open-source license before distributing this
project publicly.

------------------------------------------------------------------------

**Arduino Snake Game**\
A lightweight embedded gaming project built with Arduino, an I2C LCD,
and an analog joystick.
