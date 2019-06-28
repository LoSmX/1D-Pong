# 1D-Pong
The aim of this project is to develop a 1D-Pong-Game using a microcontoller as the heart of the system.

## Requirements ##
- [x] Solder Iron
- [x] Cable/ Jumper
- [x] Microcontroller (atleast 11 GPIO)
- [x] 2x Led red
- [x] 8x Led green
- [x] 6x Led yellow
- [x] 4x Shift register (CD74HCT164E)
- [x] 2x Buttons
- [x] 1x Buzzer
- [x] Seven-Segment-Dispaly
- [x] Resistors (many)

## Pins distribution ##
Score Display:
  - 4 Pins for the shift regs (clk1, clk2, AB1, AB2)
  
Field Display:
  - 3 Pins for the shift regs

1 Pin for the buzzer

2 Pins for the buttons

+5V:
  - Shift-regs (Clr, VCC)
  - Buttons

GND:
  - Shift-regs
  - all LEDs
  - Seven-seg
  - buzzer
  - pull down of the buttons
  
## Spec ##
### Musts ###
The System consists of a microcontroller as the main processor and controller of the peripherials.

An 16 LEDs which displays the playing field.
  - Red:     Point zone
  - Yellow:  Hit zone
  - Green:   Free zone
  
  | R | Y | Y | Y | G | G | G | G | G | G | G | G | Y | Y | Y | R |
  | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
  
Two buttons, one for each player. The player has to press the button when the "ball" reaches the hit zone, in order to send the ball back to their opponent.

A seven-segment display showing the current score.

### Shoulds ###
There should be a buzzer highlighting events like the starting of the game, hitting of the ball, scoring and winning.


### Nice-to-haves ###
It would be nice if the system was semi-portable e.g. a computer isn't needed but only an AC supply.
Also an I/O switch for turning the whole system on and off.
 
## Status Date ##

| DATE      | MILESTONES|
| --------- | --------- |
| 04.04.2019| Project Init|
| 11.04.2019| Got the all components|
|| Create the Schematic|
||Designe the casing|
|| DEvelope prototype|
|| Print the casing|
||Finalize the Product|

## Messurements and Pinouts ##

### Display ###

| Model | Common Anode |
| Length | 3.6 cm |
| width | 1.8 cm |
| Number of Pins | 12 |
| Pin distance | 2.5mm |
| - | - |

| PIN   | CONNECTION|
| --------- | --------- |
| 0 | E |
| 1 | D |
| 2 | DP |
| 3 | C |
| 4 | G |
| 5 | NC |
| 6 | B |
| 7 | K3 |
| 8 | K2 |
| 9 | F |
| 10 | A |
| 11 | K1 | 

### Buttons ###
Pin distance  = 0.5 mm

### LED ###
Pin distance  = 0.2 mm
Number = 16
