# How PIR Sensors Work:

## Detecting Infrared Radiation:

All objects with a temperature above absolute zero emit infrared radiation.
The PIR sensor has two slots made of a special material sensitive to IR.
These slots detect changes in IR levels when a warm object, like a human or animal, moves across the sensor's field of view.
Differential Detection:

The sensor measures the difference in infrared levels between its two slots.
A sudden change in IR levels (e.g., from a moving person) triggers the sensor output.

## Key Components:

- Pyroelectric Material: Senses IR radiation.
- Lens (often Fresnel): Focuses infrared radiation onto the sensor.
- Amplifier and Comparator Circuit: Processes the detected signal and outputs a usable electrical signal.
Features of PIR Sensors:
- Passive: They do not emit any energy for detection (unlike ultrasonic or radar sensors); they only detect IR radiation.
- Low Power: They consume minimal energy.
- Range: Typically detects motion within 5-12 meters, depending on the sensor model.
Field of View: Often covers a wide-angle area (e.g., 110° to 180° horizontally).

# Applications:

## Security Systems:

- Intruder alarms.
- Motion-activated CCTV cameras.
### Automation:

- Automatic lighting control in homes and offices.
- Smart home systems.

### Energy Efficiency:

- Controls devices like fans or lights based on occupancy.

## IoT (Internet of Things):

-  Used in smart devices for detecting human presence or activity.

### Example Use in Projects:

A typical application involves connecting the PIR sensor to a microcontroller like an Arduino or ESP32. When the sensor detects motion, it sends a signal to the microcontroller, which then triggers an action, such as lighting an LED, sounding an alarm, or sending a notification.