RGB_MATRIX_EFFECT(video)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static bool video(effect_params_t *params) {
  for (uint8_t i = 0; i < videoInit.leds; i += videoInit.rgb ? 3 : 1) {
    if (videoInit.rgb) rgb_matrix_set_color(
      videoLeds[i], videoScreen[i], videoScreen[i + 1], videoScreen[i + 2]
    );
    else rgb_matrix_set_color(
      videoLeds[i], videoScreen[i], videoScreen[i], videoScreen[i]
    );
  }

  return true;
}

#endif
