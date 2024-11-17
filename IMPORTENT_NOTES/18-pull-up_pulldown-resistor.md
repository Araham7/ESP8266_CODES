### Pins That Support `INPUT_PULLUP` on ESP8266:
- **GPIO 0 (D3)**
- **GPIO 2 (D4)**
- **GPIO 4 (D2)**
- **GPIO 5 (D1)**
- **GPIO 12 (D6)**
- **GPIO 13 (D7)**
- **GPIO 14 (D5)**

### Special Cases:
- **GPIO 15 (D8)**:
  - Has an internal **pull-down resistor**, not a pull-up.
  - Used for boot mode selection and should be handled with care.

- **GPIO 16 (D0)**:
  - Does not support internal pull-up or pull-down.
  - External resistors are required for reliable operation.

- **GPIO 0 (D3)** and **GPIO 2 (D4)**:
  - Connected to internal pull-up resistors by default but also have boot-related functions.
  - Avoid using these if it might interfere with the boot process.

### General Notes:
- The ESP8266 pins have multiple functions, and some are used during boot. Using the wrong pin configuration can cause boot failures.
- Always check the ESP8266 datasheet or your specific development board's documentation for detailed information about pin behavior.

### Recommendation:
If you're using a door lock sensor, GPIOs like **D1**, **D2**, or **D7** are good choices, as they are less likely to interfere with the ESP8266's boot process and support `INPUT_PULLUP`.
