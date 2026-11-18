#ifndef _BOARDS_FRAMEPICO2_DEBUG_PROBE_H
#define _BOARDS_FRAMEPICO2_DEBUG_PROBE_H

// Tell CMake this is an RP2350 (Arm, secure) board
pico_board_cmake_set(PICO_PLATFORM, rp2350)

// For board detection in include/board_config.h
#define FRAMEPICO2_DEBUG_PROBE

// 1 = RP2354A (60-pin QFN, GPIO0-29). Use 0 for RP2354B (80-pin QFN).
#define PICO_RP2350A 1

#ifndef PICO_DEFAULT_UART
#define PICO_DEFAULT_UART 0
#endif
#ifndef PICO_DEFAULT_UART_TX_PIN
#define PICO_DEFAULT_UART_TX_PIN 16
#endif
#ifndef PICO_DEFAULT_UART_RX_PIN
#define PICO_DEFAULT_UART_RX_PIN 17
#endif

// RP2354 has 2 MB of flash stacked in the package
pico_board_cmake_set_default(PICO_FLASH_SIZE_BYTES, (2 * 1024 * 1024))
#ifndef PICO_FLASH_SIZE_BYTES
#define PICO_FLASH_SIZE_BYTES (2 * 1024 * 1024)
#endif

pico_board_cmake_set_default(PICO_RP2350_A2_SUPPORTED, 1)
#ifndef PICO_RP2350_A2_SUPPORTED
#define PICO_RP2350_A2_SUPPORTED 1
#endif

#endif
