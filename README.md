# STM32-7-Segment-Automatic-Counter
## Overview
This project is an embedded application for an STM32 microcontroller that implements an automatic single-digit decimal counter (0-9) using a 7-segment display. Instead of relying on user input, the counter automatically increments every 2 seconds. Once the display reaches 9, it wraps around and starts over from 0.

## Hardware Requirements
* **Microcontroller:** STM32 Development Board (e.g., STM32F4 series).
* **Display:** Single-digit 7-segment display.
* **Components:** Jumper wires and current-limiting resistors for the 7-segment display connections.

## Software Architecture
The project follows a standard layered architecture for embedded systems:
* **MCAL (Microcontroller Abstraction Layer):**
    * `RCC` (Reset and Clock Control): Used to configure the system clock and enable peripheral clocks.
    * `STK` (SysTick) / Delay Logic: Used to generate the precise 2-second delay between increments.
* **HAL (Hardware Abstraction Layer):**
    * `7_SEGMENT`: Custom driver to initialize the display, handle the pin mappings, and output the numerical values.
* **LIB (Libraries):** Standard custom libraries for bitwise operations (`BIT_MATH.h`) and standard data types (`STD_TYPES.h`).

## How It Works
1.  **Initialization:** The system clock is initialized, and the necessary port clocks for the 7-segment display are enabled. The display is initialized to start at `0`.
2.  **Super Loop:** The program enters a continuous `while(1)` loop where the core logic resides.
3.  **Display Update:** The `segment_show()` function is called to display the current value of the `counter` variable.
4.  **Delay:** A 2-second blocking delay (via software loop or SysTick timer) halts execution, keeping the current number illuminated.
5.  **Increment & Wrap-Around:** After the delay, the `counter` variable increments by 1. A conditional check ensures that if the counter exceeds 9, it immediately resets to 0 before the loop repeats.

## Future Improvements
* Transition from a blocking delay (which halts the CPU) to a non-blocking hardware timer interrupt to handle the 2-second intervals, allowing the CPU to perform other tasks.
* Add multiplexing support to expand the project to multiple 7-segment displays.
