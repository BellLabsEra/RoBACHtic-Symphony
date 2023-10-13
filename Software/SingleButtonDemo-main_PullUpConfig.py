# +------------------+
# | SingleButtonDemo |
# +------------------+
# This program tests the functionaility of the microbit reading in 
# the status of 1 push button (ON or OFF, 1 or 0). The button circuit is configured
# with a pull-up resistor, so the default logic level will be 1, which will be displayed
# on the microbit's LED matrix.

# Imports go at the top
from microbit import *


# Code in a 'while True:' loop repeats forever
while True:
    if pin0.read_digital():
        display.show(1)
    else:
        display.show(0)