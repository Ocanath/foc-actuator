# Design Notes

Vendor the DRV8300 design and update the MCU to use the STM32G431 QFN32 with non-complementary PWM (inversion and DT insertion performed at chip level) rather than an F030. Remove additional RS485 transciever for direct UART for audio interface. Add full 3 phase current sensing. 

Add center bore with thru-hole terminations for primary power and ground, logic power, and RS485 (5 total - 2 power). Thru hole preferred over connector - relatively even distribution preferred.


Design an EVM for split, center aligned off-axis/2 phase hall effect angle sensing which is built for the ring magnets, which has a CONNTEC or AMS encoder in the center, to evaluate linearity/accuracy against a known standard. Use G431 for DARTT interface.

