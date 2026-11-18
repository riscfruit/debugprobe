/*
 * Debugprobe configuration for a custom RP2354 board with a Schmitt-trigger
 * level-shifted SWDIO input (same topology as the official Raspberry Pi
 * Debug Probe, different pins and MCU).
 *
 * Copyright (c) 2026 Tan Siret Akinci Riscfruit Laboratory
 *
 * Derived from board_debug_probe_config.h
 * Copyright (c) 2023 Raspberry Pi (Trading) Ltd. - MIT License
 */

#ifndef BOARD_FRAMEPICO2_DEBUG_PROBE_CONFIG_H_
#define BOARD_FRAMEPICO2_DEBUG_PROBE_CONFIG_H_

#define PROBE_CDC_UART
// No target reset pin. If your board has one, add e.g.:
// #define PROBE_PIN_RESET 29

// PIO config
#define PROBE_SM 0
#define PROBE_PIN_SWCLK 27
#define PROBE_PIN_SWDIO 28

// 1 = DEBUG TEST: ignore the Schmitt trigger and read SWDIO directly on GPIO28
//     (works because GPIO28 reaches the SWDIO net through only R17, 100 ohm).
// 0 = NORMAL: read SWDIO back through the Schmitt trigger on GPIO26.
#define PROBE_BYPASS_SCHMITT 1

#if PROBE_BYPASS_SCHMITT
  // RAW mode needs SWCLK and SWDIO on consecutive GPIOs starting at the offset
  #define PROBE_IO_RAW
  #define PROBE_PIN_OFFSET 27
#else
  #define PROBE_IO_SWDI
  // Level-shifted input (output of the Schmitt trigger U1)
  #define PROBE_PIN_SWDI 26
#endif

// UART config (UART0 on GPIO16 TX / GPIO17 RX)
#define PROBE_UART_TX 16
#define PROBE_UART_RX 17
#define PROBE_UART_INTERFACE uart0
#define PROBE_UART_BAUDRATE 115200

// LEDs to specify
// #define PROBE_USB_CONNECTED_LED 
// #define PROBE_DAP_CONNECTED_LED
// #define PROBE_DAP_RUNNING_LED  
// #define PROBE_UART_RX_LED
// #define PROBE_UART_TX_LED

#define PROBE_PRODUCT_STRING "FramePico2 Debug Probe (CMSIS-DAP)"

#endif
