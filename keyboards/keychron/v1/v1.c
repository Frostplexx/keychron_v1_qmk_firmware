/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

const matrix_row_t matrix_mask[] = {
    0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111111111, 0b1111111111101111,
};

// DIP switcht the the thing for swithcing between macos and windows mode
// Disabled so I can use the layers for other things because I don't use windows

// #ifdef DIP_SWITCH_ENABLE
//
// bool dip_switch_update_kb(uint8_t index, bool active) {
//     if (!dip_switch_update_user(index, active)) {
//         return false;
//     }
//     if (index == 0) {
//         default_layer_set(1UL << (active ? 2 : 0));
//     }
//     return true;
// }
//
// #endif

#if defined(RGB_MATRIX_ENABLE) && defined(CAPS_LOCK_LED_INDEX)
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
#    ifdef RGB_MATRIX_ENABLE
        case RGB_TOG:
            if (record->event.pressed) {
                switch (rgb_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        rgb_matrix_set_flags(LED_FLAG_NONE);
                        rgb_matrix_set_color_all(0, 0, 0);
                    } break;
                    default: {
                        rgb_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!rgb_matrix_is_enabled()) {
                rgb_matrix_set_flags(LED_FLAG_ALL);
                rgb_matrix_enable();
            }
            return false;
#    endif
    }
    return true;
}

// Function that sets the color of configured keys on this layer to a specific color
void custom_set_color_for_layer_keys(uint8_t highest_layer, uint8_t led_min, uint8_t led_max, uint8_t for_layer, uint8_t red, uint8_t green, uint8_t blue) {
    if (highest_layer == for_layer) {
        uint8_t layer = highest_layer;
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED && keymap_key_to_keycode(layer, (keypos_t){col, row}) > KC_TRNS) {
                    rgb_matrix_set_color(index, red, green, blue);
                }
            }
        }
    }
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (!rgb_matrix_indicators_advanced_user(led_min, led_max)) {
        return false;
    }
    // RGB_MATRIX_INDICATOR_SET_COLOR(index, red, green, blue);

    // Layer indicator only on keys with configured keycodes
    custom_set_color_for_layer_keys(get_highest_layer(layer_state), led_min, led_max, 1, 64, 160, 43);
    custom_set_color_for_layer_keys(get_highest_layer(layer_state), led_min, led_max, 2, 223, 142, 29);
    custom_set_color_for_layer_keys(get_highest_layer(layer_state), led_min, led_max, 3, 210, 15, 5);

    // Capslock indicator
    if (host_keyboard_led_state().caps_lock) {
        RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 255, 0, 0);
    } else {
        if (!rgb_matrix_get_flags()) {
            RGB_MATRIX_INDICATOR_SET_COLOR(CAPS_LOCK_LED_INDEX, 0, 0, 0);
        }
    }

    return true;
}

#endif // CAPS_LOCK_LED_INDEX
