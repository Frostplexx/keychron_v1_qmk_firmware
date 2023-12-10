# Firmware for the Keychron V1 ISO keyboard

This is a fork of the QMK firmware for the Keychron V1 ISO keyboard. The original firmware is available at
https://github.com/qmk/qmk_firmware/tree/master/keyboards/keychron/v1. This is my personal keymap specifically for the ISO Encoder version.

## Changes from original firmware

-   Change caps lock indicator color to red
-   When switching to any layer > 0, highlight the keys that are bound to an action
-   Remove Windows layer because I don't use Windows
-   Press Left Shift + Right Shift to switch to enable Caps Word mode
-   Added mouse Autoclicker https://getreuer.info/posts/keyboards/mouse-turbo-click/index.html
-   Added w i d e t e x t m o d e
-   Added TaUnt TeXt MoDe
-   Added Key Lock mode -- Not configured yet in VIA

## Keymap

Included is also my VIA keymap. It has a bunch of stuff on layer 1 like media keys, volume control.

-   Open https://usevia.app/ in your browser
-   Go to settings an enable "Design Tab"
-   In the design tab load the keymap definition from via/custom_keymap.json
-   If you want you can load the layout from via/keychron_v1_iso_knob_layout.json

## Building

-   Clone this repo using `qmk clone Frostplexx/keychron_v1_qmk_firmware.git`
-   Go into keyboards/keychron/v1/iso_encoder/keymaps/frostplexx and edit it to your liking
-   Run `qmk compile -kb keychron/v1/iso_encoder -km frostplexx` to compile the firmware
-   Install the firmware using QMK Toolbox: https://github.com/qmk/qmk_toolbox/releases

For instructions see https://docs.qmk.fm
