import serial.tools.list_ports
import re
import webcolors
from gtts import gTTS
from playsound import playsound

language = 'en'

def closest_color(requested_color):
    min_colors = {}
    for key, name in webcolors.CSS3_HEX_TO_NAMES.items():
        r_c, g_c, b_c = webcolors.hex_to_rgb(key)
        rd = (r_c - requested_color[0]) ** 2
        gd = (g_c - requested_color[1]) ** 2
        bd = (b_c - requested_color[2]) ** 2
        min_colors[(rd + gd + bd)] = name
    return min_colors[min(min_colors.keys())]

def get_color_name(requested_color):
    try:
        closest_name = actual_name = webcolors.rgb_to_name(requested_color)
    except ValueError:
        closest_name = closest_color(requested_color)
        actual_name = None
    return actual_name, closest_name

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

rgb = []

while True:
    if serialInst.in_waiting:
        packet = serialInst.readline()

        result = packet.decode('utf').rstrip('\n')

        if re.search('ACTIVATE', result):
            dummy, name = get_color_name((rgb[0], rgb[1], rgb[2]))

            result = "The color you have selected is called " + name + ". This color has a red value of " + str(rgb[0]) + ", a green value of " + str(rgb[1]) + ", and a blue value of " + str(rgb[2])

            sound = gTTS(text=result, lang=language, slow=False)
            sound.save("output.mp3")
            playsound('output.mp3')

        else :
            rgb = [int(i) for i in (result).split() if i.isdigit()]
            print("r: " + str(rgb[0]) + ', g: ' + str(rgb[1]) + ', b: ' + str(rgb[2]))
    