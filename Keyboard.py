import serial
import keyboard as k

ser = serial.Serial('COM3', baudrate=9600, timeout=None)

def decode(x,y,z):
    if x == 'l':
        k.press("left")
    elif x == 'r':
        k.press("right")
    elif x == 'o':
        k.release("left")
        k.release("right")
    
    if y == 'u':
        k.press("up")
    elif y == 'd':
        k.press("down")
    elif y == 'o':
        k.release("up")
        k.release("down")

    if z == 'l':
        k.press_and_release("space")

while True:
    try:
        x,y,z = [i for i in ser.readline().decode('ascii').strip()]
        decode(x,y,z)
    except:
        pass