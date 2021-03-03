#include QMK_KEYBOARD_H
#include "version.h"
#include "moonlander.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)
#define MOON_LED_LEVEL LED_LEVEL

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  HSV_0_255_255,
  HSV_27_255_255,
  HSV_86_255_128,
  HSV_172_255_255,
  HSV_215_255_128,
  ST_MACRO_0,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_moonlander(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_F11,                                         ST_MACRO_0,     KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_F10,                                         KC_LBRACKET,    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_EQUAL,       
    KC_CAPSLOCK,    KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_F5,                                                                          KC_RBRACKET,    KC_H,           KC_J,           KC_K,           KC_L,           KC_SCOLON,      KC_QUOTE,       
    KC_LSHIFT,      KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_RSHIFT,      
    KC_LCTRL,       MO(1),          KC_LALT,        KC_LEFT,        KC_RIGHT,       KC_ESCAPE,                                                                                                      KC_CALCULATOR,  KC_UP,          KC_DOWN,        KC_HOME,        KC_END,         LT(1,KC_BSLASH),
    KC_SPACE,       KC_BSPACE,      KC_LGUI,                        KC_RGUI,        KC_ENTER,       KC_SPACE
  ),
  [1] = LAYOUT_moonlander(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,                                          KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_NO,          LSFT(KC_F12),                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_SLASH,    KC_F12,         
    KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, LCTL(KC_F12),                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_ASTERISK, KC_TRANSPARENT, 
    KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_PLUS,     KC_RSHIFT,      
    KC_TRANSPARENT, KC_LCTRL,       KC_LALT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MY_COMPUTER,                                                 TG(2),          KC_KP_0,        KC_KP_0,        KC_KP_DOT,      KC_KP_MINUS,    KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT,                 KC_TRANSPARENT, KC_ENTER,       KC_TRANSPARENT
  ),
  [2] = LAYOUT_moonlander(
    KC_TRANSPARENT, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,RESET,          
    KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, WEBUSB_PAIR,    
    KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    HSV_0_255_255,  HSV_27_255_255, HSV_86_255_128, HSV_172_255_255,HSV_215_255_128,KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGB_VAI,        RGB_VAD,        TOGGLE_LAYER_COLOR,                RGB_SLD,        RGB_MOD,        RGB_TOG
  ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    // These are ordered from top key to bottom key of each column
    [0] = { {0,210,255}, {0,210,255}, {0,0,255}, {0,210,255}, {0,0,255},       // Left Column 1
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {32,176,255},  // Left Column 2
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {0,0,255},     // Left Column 3
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {255,0,209},   // Left Column 4
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {255,0,209},   // Left Column 5
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255},                // Left Column 6
            {100,0,255}, {100,0,255}, {100,0,255},                             // Left Column 7
            {0,210,255}, {0,210,255}, {0,0,255},                               // Left Thumb Buttons
            {255,0,90},                                                        // Left Triangle Button

            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {32,176,255},  // Right Column 7
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {255,0,209},   // Right Column 6
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {255,0,209},   // Right Column 5
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {255,0,209},   // Right Column 4
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, {255,0,209},   // Right Column 3
            {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255},                // Right Column 2
            {0,210,255}, {0,210,255}, {0,210,255},                             // Right Column 1
            {0,210,255}, {0,210,255}, {0,0,255},                               // Right Thumb Buttons
            {255,0,90} },                                                      // Right Triangle Button

    [1] = { {255,0,90}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {100,0,255}, {0,0,255}, {0,0,255}, {0,0,0}, {0,0,0}, 
            {100,0,255}, {0,0,255}, {255,0,209}, {0,0,0}, {0,0,0}, 
            {100,0,255}, {255,0,209}, {255,0,209}, {0,0,0}, {0,0,0}, 
            {100,0,255}, {0,0,255}, {255,0,209}, {0,0,0}, {0,0,0}, 
            {100,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,255}, {255,0,209}, {255,0,209}, 
            {0,0,0}, {146,224,255}, {0,0,0}, 
            {100,0,255}, 
            
            {100,0,255}, {100,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {100,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, 
            {100,0,255}, {0,210,255}, {0,210,255}, {0,210,255}, {0,0,255}, 
            {100,0,255}, {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, 
            {100,0,255}, {0,210,255}, {0,210,255}, {0,210,255}, {0,210,255}, 
            {100,0,255}, {0,0,255}, {0,0,255}, {0,0,255}, 
            {0,0,255}, {0,0,255}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,204,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, 
            {169,120,255}, 
            
            {0,0,0}, {15,166,195}, {0,0,0}, {169,120,255}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, 
            {0,0,0}, {0,0,0}, {0,0,0}, 
            {169,120,255} },
};

// Stuff for controlling the LED fading animation
int sign = -1;
const int BRIGHTNESS_STEPS = 500;
const int MIN_BRIGHTNESS = BRIGHTNESS_STEPS / 10;
const int KEYPRESS_INCREMENT = 20;
int currentBrightness = BRIGHTNESS_STEPS;

#ifdef AUDIO_ENABLE
float capsLockOnSong[][2] = SONG(MUSIC_ON_SOUND);
float capsLockOffSong[][2] = SONG(MUSIC_OFF_SOUND);
#endif

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    RGB rgb = {
      .r = pgm_read_byte(&ledmap[layer][i][0]),
      .g = pgm_read_byte(&ledmap[layer][i][1]),
      .b = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!rgb.r && !rgb.g && !rgb.b) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else if (layer == 0 && i == 2 && host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
      // Set caps lock button to bright color when caps lock is enabled.
      rgb_matrix_set_color(i, 255, 0, 90);
    } else {
      // float factor = currentBrightness / (float)BRIGHTNESS_STEPS;
      // rgb_matrix_set_color( i, ((int)rgb.r * factor), ((int)rgb.g * factor), ((int)rgb.b * factor) );
      float redFactor = currentBrightness / (float)BRIGHTNESS_STEPS;
      float otherFactor = (BRIGHTNESS_STEPS - currentBrightness) / (float)BRIGHTNESS_STEPS;
      int red = (255 - rgb.r) * redFactor + rgb.r;
      int green = otherFactor > 0 ? (rgb.g * otherFactor) : 0;
      int blue = otherFactor > 0 ? (rgb.b * otherFactor) : 0;

      if (otherFactor < 0)
      {
        red = 255;
        green = 0;
        blue = 0;
      }

      rgb_matrix_set_color( i, (int)red, (int)green, (int)blue );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  // Uncomment if you want a breathing pattern instead.
  // currentBrightness += 1 * sign;
  // if (currentBrightness >= BRIGHTNESS_STEPS || currentBrightness <= MIN_BRIGHTNESS)
  // {
  //   sign = -1 * sign;
  // }
  
  // Fade the brightness down to the min brightness
  if (currentBrightness > 0)
  {
    currentBrightness--;
  }

  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // // Go to full brightness on key press
  // currentBrightness = BRIGHTNESS_STEPS;

  if (currentBrightness < BRIGHTNESS_STEPS) {
    currentBrightness += KEYPRESS_INCREMENT;
  }
  
  #ifdef AUDIO_ENABLE
    // Too annoying when writing SQL. Maybe only enable for gaming profile or add button combo for toggling sounds.
    // if (keycode == KC_CAPSLOCK && record->event.pressed)
    // {
    //   if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
    //     PLAY_SONG(capsLockOffSong);
    //   } else {
    //     PLAY_SONG(capsLockOnSong);
    //   }
    // }
  #endif

  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(50) SS_LSFT(SS_TAP(X_DOT)));

    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_0_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(0,255,255);
      }
      return false;
    case HSV_27_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(27,255,255);
      }
      return false;
    case HSV_86_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(86,255,128);
      }
      return false;
    case HSV_172_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(172,255,255);
      }
      return false;
    case HSV_215_255_128:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(215,255,128);
      }
      return false;
  }
  return true;
}
