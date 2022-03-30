# SteeringWheelCan
##Victor Rowello

Uses AVR_CAN library for CAN functionality
https://github.com/thomasonw/avr_can


Uses Al Thomason's ATmega16M1 library for Arduino IDE compatibility
https://github.com/thomasonw/ATmegaxxM1-C1

##Purpose
The purpose of this code is to provide the software implementation for the first node of a planned CAN network around our car.

As of right now, the current code provides support for transmitting button/knob inputs from the steering wheel to the ECU through a single CAN bus, rather than hard wiring each input directly.

If this first phase is successful, the current codebase is currently modular enough to extend this capability accross the various subsystems of the car.
