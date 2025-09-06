import RPi.GPIO as GPIO
import time

# Pin configeration
relays = [17, 27, 22]  # GPIO pins for relays
sensor_pin = 4  # Example GPIO pin for solar sensor

GPIO.setmode(GPIO.BCM)
for pin in relays:
    GPIO.setup(pin, GPIO.OUT)
GPIO.setup(sensor_pin, GPIO.IN)

try:
    while True:
        solar_available = GPIO.input(sensor_pin)
        if solar_available:
            GPIO.output(relays[0], GPIO.HIGH)
            GPIO.output(relays[1], GPIO.HIGH)
            GPIO.output(relays[2], GPIO.HIGH)
            print("Solar available → Loads ON")
        else:
            GPIO.output(relays[0], GPIO.LOW)
            GPIO.output(relays[1], GPIO.LOW)
            GPIO.output(relays[2], GPIO.LOW)
            print("No solar → Loads OFF")
        time.sleep(1)

except KeyboardInterrupt:
    GPIO.cleanup()
