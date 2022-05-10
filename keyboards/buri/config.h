// Copyright 2022 James Sa (@jamessa)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0076
#define PRODUCT_ID      0x0037
#define DEVICE_VER      0x0101
#define MANUFACTURER    tokimekey
#define PRODUCT         BURI

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { F4, F1, F0, F7, F6 }
#define MATRIX_COL_PINS { F7, B6, B5, D5, D3, D2, D1, D0, B4, D7, D6, D4 }
#define UNUSED_PINS

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
