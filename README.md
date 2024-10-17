Smart Thermostat Prototype

This repository contains the culmination of work from the CS350 course: Emerging System Architecture and Technology (Embedded Systems).

Project Overview

The project focuses on developing a prototype for a smart thermostat using the Texas Instruments CC3220S Launchpad. The goal was to create a device that:

	•	Measures room temperature with a TMP006 temperature sensor via I2C.
	•	Allows users to adjust the set-point temperature using GPIO buttons.
	•	Sends temperature data and system status to a server simulation via UART.
	•	Indicates heating status with an LED controlled by GPIO.

This prototype is an essential step for SysTec’s plans to enter the smart thermostat market.

Key Features

	•	Temperature Reading (I2C): Reads real-time room temperature using the TMP006 sensor.
	•	User Input (GPIO): Users can adjust the set-point temperature with two buttons (increase/decrease by 1°C).
	•	Heating Indicator (GPIO): An LED shows the heating status—on when heating, off when not.
	•	Server Communication (UART): Sends data to a simulated server every second in the format <AA,BB,S,CCCC>, where:
	•	AA = Room temperature
	•	BB = Set-point temperature
	•	S = Heater status (0 or 1)
	•	CCCC = Uptime in seconds

Task Scheduling

Implemented a task scheduler to ensure timely execution:

	•	Every 200 ms: Check button inputs to adjust the set-point.
	•	Every 500 ms: Read room temperature from the sensor.
	•	Every 1 second: Update LED status and transmit data via UART.

Achievements

	•	Hardware-Software Integration: Seamless interaction between the temperature sensor, user inputs, and server communication.
	•	State Machine Implementation: Managed precise timing for Morse code sequences (“SOS” and “OK”) using timers and GPIOs.
	•	Interrupt Handling: Used interrupts and timers to handle asynchronous events, ensuring real-time responsiveness.

Areas for Improvement

	•	Power Management: Enhance efficiency by optimizing the system’s power consumption.
	•	Error Handling: Implement more robust mechanisms to handle unexpected scenarios and hardware failures.
	•	Code Documentation: Add more detailed comments and documentation to improve clarity and ease future maintenance.

Tools and Resources

	•	TI Code Composer Studio (CCS): Gained proficiency in this IDE for embedded development and debugging.
	•	I2C and UART Protocols: Deepened understanding of these communication protocols essential for peripheral integration.
	•	TI Driver Libraries: Utilized libraries for GPIO, Timer, I2C, and UART to manage peripherals effectively.
	•	State Machine Design Patterns: Leveraged these patterns to handle complex sequences efficiently.

Transferable Skills

	•	Hardware-Software Integration: Applicable to IoT devices and embedded systems requiring seamless component interaction.
	•	State Machine Design: Crucial for managing complex sequences in real-time systems.
	•	Interrupt and Timer Management: Valuable for applications needing precise timing and responsiveness.
	•	Peripheral Communication: Proficiency with I2C and UART benefits projects involving sensor integration and data transmission.
	•	Embedded C Programming: Enhanced proficiency essential for firmware development and low-level programming.

Maintainability and Adaptability

	•	Modular Design: Each functionality is encapsulated in its own function, simplifying future modifications.
	•	Consistent Naming Conventions: Improved readability and organization of the codebase.
	•	Detailed Comments: Provided explanations for functions and complex logic to aid future developers.
	•	Parameterization: Used defined constants and parameters (e.g., timing durations) to make adjustments easy.

Conclusion

This project demonstrates the integration of hardware interrupts, timers, and peripheral communication within an embedded system. The skills and methodologies developed are highly transferable, enhancing both technical capabilities and project maintainability.
