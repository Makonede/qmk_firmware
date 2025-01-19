// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"

// clang-format off
enum _layers {
  _BASE,
  _FN,
  _FN_LOCK,
  _FM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
  * 14 keys │Esc  │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Del│
  *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
  * 14 keys │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp│
  *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
  * 14 keys │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \  │
  *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
  * 13 keys │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ Enter │
  *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
  * 12 keys │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │  Shift  │
  *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
  *         │    │   │   │   │                   │   │   │    │↑  │    │
  * 11 keys │Ctrl│FN │GUI│Alt│                   │Alt│Ctl│ ←  ├───┤  → │
  *         │    │   │   │   │                   │   │   │    │  ↓│    │
  *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
  * 78 total
  */
  [_BASE] = LAYOUT(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
    KC_LCTL, MO(_FN), KC_LGUI, KC_LALT,          KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT
  ),
  /*
  * Function layer
  *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
  * 14 keys │FN lk│Mut│vDn│vUp│Prv│Ply│Nxt│bDn│bUp│Scn│Air│Prt│App│Ins │
  *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
  * 14 keys │   │   │   │   │   │   │   │   │   │   │   │   │   │      │
  *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
  * 14 keys │     │   │RGB│Nxt│Hue│Sat│Spd│Brt│   │   │Pau│   │   │    │
  *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴────┤
  * 13 keys │      │   │SRq│Prv│Hue│Sat│Spd│Brt│ScL│   │   │   │       │
  *         ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┤
  * 12 keys │        │   │   │   │   │   │Brk│   │   │   │   │         │
  *         ├────┬───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
  *         │    │   │   │   │                   │   │   │    │PgU│    │
  * 11 keys │    │   │   │   │ Toggle Backlight  │   │   │Home├───┤End │
  *         │    │   │   │   │                   │   │   │    │PgD│    │
  *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
  * 78 total
  */
  [_FN] = LAYOUT(
    FN_LOCK, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, G(KC_P), KC_AIRP, KC_PSCR, KC_MSEL, KC_INS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, _______, _______, KC_PAUS, _______, _______, _______,
    _______, _______, KC_SYRQ, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, KC_SCRL, _______, _______, _______,          _______,
    _______,          _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,          BL_STEP,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
  ),
  // Function lock layer
  // Everything on F-row locked to function layer, except ESC and DEL
  [_FN_LOCK] = LAYOUT(
    _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, G(KC_P), KC_AIRP, KC_PSCR, KC_MSEL, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
    _______, MO(_FM), _______, _______,          _______,                   _______, _______, _______, _______, _______, _______
  ),
  [_FM] = LAYOUT(
    FN_LOCK, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_SPI, RGB_VAI, _______, _______, KC_PAUS, _______, _______, _______,
    _______, _______, KC_SYRQ, RGB_RMOD,RGB_HUD, RGB_SAD, RGB_SPD, RGB_VAD, KC_SCRL, _______, _______, _______,          _______,
    _______,          _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,          BL_STEP,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
  ),
};
// clang-format on

// Make sure to keep FN Lock even after reset
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case FN_LOCK:
      if (record->event.pressed) {
        if (layer_state_is(_FN)) set_single_persistent_default_layer(_FN_LOCK);
        if (layer_state_is(_FM)) set_single_persistent_default_layer(_BASE);
      }
      return false;
  }
  return true;
}

////////////////////////////////////////////////////////////////////////////////

typedef enum VideoCommand : uint8_t {
  VIDEO_INIT,
  VIDEO_FRAME,
  VIDEO_END,
} VideoCommand;

typedef struct VideoInit {
  uint8_t x, y, width, height, leds;
  bool rgb;
} VideoInit;

typedef struct VideoReport {
  VideoCommand command;
  union VideoData {
    VideoInit init;
    uint8_t frame[RAW_EPSIZE - 1];
  } data;
} VideoReport;

static uint8_t videoMode = RGB_MATRIX_NONE;
static VideoInit videoInit = {};
static uint8_t *videoFrame;
static size_t videoFrameSize = 0;
static size_t videoFrameReceived = 0;
static uint8_t videoLeds[RGB_MATRIX_LED_COUNT];

void raw_hid_receive(uint8_t *data, uint8_t length) {
  VideoReport report = *(VideoReport *)data;
  switch (report.command) {
    case VIDEO_INIT: {
      // Save current matrix mode and initialize video data
      videoMode = rgb_matrix_get_mode();
      rgb_matrix_mode(RGB_MATRIX_NONE);
      videoInit = report.data.init;
      videoFrameSize = videoInit.leds * (videoInit.rgb ? 3 : 1);
      videoFrame = (uint8_t *)malloc(videoFrameSize);
      videoFrameReceived = 0;

      // Enumerate LEDs in frame
      uint8_t ledIndex = 0;
      for (uint8_t i = 0; i < RGB_MATRIX_LED_COUNT; ++i) {
        if (
          videoInit.x <= g_led_config.point[i].x
          && g_led_config.point[i].x <= videoInit.x + videoInit.width
          && videoInit.y <= g_led_config.point[i].y
          && g_led_config.point[i].y <= videoInit.y + videoInit.height
        ) {
          videoLeds[ledIndex++] = i;
          if (ledIndex == videoInit.leds) break;
        }
      }

      break;
    }

    case VIDEO_FRAME: {
      // Write frame data until complete, may be split over several reports
      size_t remaining = videoFrameSize - videoFrameReceived;
      bool done = remaining <= sizeof report.data.frame;
      memcpy(
        videoFrame + videoFrameReceived, &report.data.frame,
        done ? remaining : sizeof report.data.frame
      );
      videoFrameReceived = done ? 0 : videoFrameReceived
        + sizeof report.data.frame;

      // Draw frame
      if (done) for (uint8_t i = 0; i < videoInit.leds; ++i) {
        if (videoInit.rgb) rgb_matrix_set_color(
          videoLeds[i], videoFrame[i * 3], videoFrame[i * 3 + 1],
          videoFrame[i * 3 + 2]
        );
        else rgb_matrix_set_color(
          videoLeds[i], videoFrame[i], videoFrame[i], videoFrame[i]
        );
      }

      break;
    }

    case VIDEO_END:
      // Free frame buffer and reset original matrix mode
      free(videoFrame);
      rgb_matrix_mode(videoMode);
      break;

    default: return;
  }

  // Acknowledge report
  uint8_t response[length];
  memset(response, 0, length);
  raw_hid_send(response, length);
}
