typedef struct VideoInit {
  uint8_t x, y, width, height, leds;
  bool rgb;
} VideoInit;

extern VideoInit videoInit;
extern uint8_t *videoFrame;
extern uint8_t *videoScreen;
extern uint8_t videoLeds[RGB_MATRIX_LED_COUNT];
