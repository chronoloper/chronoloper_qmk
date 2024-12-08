AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = yes  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = yes    # RGB underglow is supported, but not enabled by default

MCU = RP2040
BOOTLOADER = rp2040

SPLIT_KEYBOARD = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360
SERIAL_DRIVER = vendor
MOUSEKEY_ENABLE = yes	# Enables drag support with trackball on when using the non-trackball half as the master
VPATH += keyboards/gboards/
COMBO_ENABLE = yes	# Enables combos
