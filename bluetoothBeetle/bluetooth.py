import serial.tools.list_ports
import re
import webcolors
from gtts import gTTS
from playsound import playsound

openPorts = serial.tools.list_ports.comports()
serialInst = serial.Serial()

openPortsList = []

for port in openPorts: 
    openPortsList.append(str(port))
    print(str(port))

# Working with port 7 on Desktop Bluetooth

portSelect = input("Select Port: COM")

for index in range(0, len(openPortsList)):
    if openPortsList[index].startswith("COM" + str(portSelect)):
        portVar = "COM" + str(portSelect)
        print(portVar)

serialInst.baudrate = 115200
serialInst.port = portVar
serialInst.open()

while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()

        result = packet.decode('utf').rstrip('\n')

        print(result)
    