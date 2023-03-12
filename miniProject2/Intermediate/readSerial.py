import serial.tools.list_ports
from pynput.keyboard import Key, Controller

keyboard = Controller()

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

portsList = []

for port in ports: 
    portsList.append(str(port))
    print(str(port))

val = input("Select Port: COM")

for x in range(0, len(portsList)):
    if portsList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portVar)

serialInst.baudrate = 9600
serialInst.port = portVar
serialInst.open()

while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()
        if packet.decode('utf').rstrip('\n'):
            keyboard.press('a')
            keyboard.release('a')