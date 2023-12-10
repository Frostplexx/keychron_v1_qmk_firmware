# Keychron V1 ISO Keyboard Firmware

Welcome to the custom firmware for the Keychron V1 ISO keyboard, based on the QMK firmware. This fork is tailored for the ISO Encoder version and comes with several enhancements to provide a personalized and improved user experience.

## Original Firmware Source

The original QMK firmware for the Keychron V1 ISO keyboard can be found [here](https://github.com/qmk/qmk_firmware/keyboards/keychron/v1).

## Changes from Original Firmware

-   **Caps Lock Indicator Color:** Changed caps lock indicator color to red for better visibility.
-   **Layer Activation Highlight:** When switching to any layer greater than 0, the keys bound to an action will be highlighted.
-   **Windows Layer Removal:** The Windows layer has been removed for users who don't use Windows.
-   **Caps Word Mode:** Press Left Shift + Right Shift to enable Caps Word mode for enhanced functionality.
-   **Mouse Autoclicker:** Added mouse autoclicker, check here for details.
-   **Wide Text Mode:** Added a wide text mode for versatile text manipulation.
-   **TaUnt TeXt MoDe:** Added a fun and playful text mode for a unique typing experience.
-   **Key Lock Mode:** Key Lock mode is added, though not configured in VIA yet.

## VIA Keymap

The VIA keymap includes various features on layer 1, such as media keys and volume control.

### VIA Configuration Steps

-   Open [VIA](https://usevia.app) in your browser.
-   Enable "Design Tab" in the settings.
-   Load the keymap definition from via/custom_keymap.json in the design tab.
-   Optionally, load the layout from via/keychron_v1_iso_knob_layout.json.
-   Building Instructions
-   Clone this repository using `qmk clone Frostplexx/keychron_v1_qmk_firmware.git`.
-   Navigate to `keyboards/keychron/v1/iso_encoder/keymaps/frostplexx` and customize it to your preferences.
-   Run `qmk compile -kb keychron/v1/iso_encoder` -km frostplexx to compile the firmware.
-   Install the firmware using [QMK Toolbox](htts://github.com/qmk/qmk_toolbox/releases).

For more detailed instructions, refer to the [QMK Documentation](https://docs.qmk.fm).

Feel free to explore and enjoy your enhanced Keychron V1 ISO keyboard experience!
