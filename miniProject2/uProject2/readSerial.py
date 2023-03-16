import serial.tools.list_ports
import re
from pynput.keyboard import Key, Controller

keyboard = Controller()

openPorts = serial.tools.list_ports.comports()
serialInst = serial.Serial()

openPortsList = []

for port in openPorts: 
    openPortsList.append(str(port))
    print(str(port))

portSelect = input("Select Port: COM")

for index in range(0, len(openPortsList)):
    if openPortsList[index].startswith("COM" + str(portSelect)):
        portVar = "COM" + str(portSelect)
        print(portVar)

serialInst.baudrate = 9600
serialInst.port = portVar
serialInst.open()

while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()
        print(packet.decode('utf').rstrip('\n'))
        if re.search('Z', packet.decode('utf').rstrip('\n')):
            keyboard.press('z')
            keyboard.release('z')
        if re.search('X', packet.decode('utf').rstrip('\n')):
            keyboard.press('x')
            keyboard.release('x')
        if re.search('C', packet.decode('utf').rstrip('\n')):
            keyboard.press('c')
            keyboard.release('c')
    