from tkinter import *
import tkinter.messagebox

import tkinter as tk
from tkinter import simpledialog

import serial.tools.list_ports
import re
import webcolors
import pyttsx3
import threading

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

def rgb_to_hex(r, g, b):
    return '#{:02x}{:02x}{:02x}'.format(r, g, b)

openPorts = serial.tools.list_ports.comports()
serialInst = serial.Serial()

openPortsList = []
ans = ' '
for port in openPorts: 
    openPortsList.append(str(port))
    ans = ans+ '\n '+ str(port)

ROOT = tk.Tk()

ROOT.withdraw()
# the input dialog
portSelect = simpledialog.askstring(title="Port Select",
                                  prompt="Enter Port Number: "+ ans)

for index in range(0, len(openPortsList)):
    if openPortsList[index].startswith("COM" + str(portSelect)):
        portVar = "COM" + str(portSelect)
        print(portVar)

serialInst.baudrate = 115200
serialInst.port = portVar
serialInst.open()

rgb = []

def scale(value) :
    r = red_scale.get()
    g = green_scale.get()
    b = blue_scale.get()

    rgb = f'{r},{g},{b}'

    hexadecimal = "#%02x%02x%02x" % (r, g, b)

    screen['bg'] = hexadecimal

    color_entry.delete(0, END)
    color_entry.insert(0, hexadecimal)

def onclick():
    tkinter.messagebox.showinfo('Color', "Copied Succesfully")
    clip = Tk()
    clip.withdraw()
    clip.clipboard_clear()
    clip.clipboard_append(color_entry.get())
    clip.destroy()

def startscan() :
    breaker = True
    rgb = []
    while (breaker):
        if serialInst.in_waiting:
            packet = serialInst.readline()

            result = packet.decode('utf').rstrip('\n')
            print(result)
            if re.search('ACTIVATE', result):
                dummy, name = get_color_name((rgb[0], rgb[1], rgb[2]))
                hex = rgb_to_hex(rgb[0], rgb[1], rgb[2])
                result = "The color you have selected is called " + name + ". This color has a red value of " + str(rgb[0]) + ", a green value of " + str(rgb[1]) + ", and a blue value of " + str(rgb[2]) + ". The hex value of this colors is " + str(hex)

                color_name.config(text= name)
                red_scale.set(rgb[0])
                green_scale.set(rgb[1])
                blue_scale.set(rgb[2])

                scale(1)
                breaker = False
                # engine = pyttsx3.init()
                # engine.say(result)
                # engine.runAndWait()

            elif (re.search('Red', result)) :
                rgb = [int(i) for i in (result).split() if i.isdigit()]
                print("r: " + str(rgb[0]) + ', g: ' + str(rgb[1]) + ', b: ' + str(rgb[2]))

col0 = "#444466"
col1 = "#feffff"
col2 = "#004338"

window = Tk()
window.geometry("650x205")
window.configure(bg=col1)
window.resizable(width=False, height=False)

screen = Label(window, bg = col0, width=40, height=10)
screen.grid(row=0, column=0)

right_frame = Frame(window, bg = col1)
right_frame.grid(row = 0, column = 1, padx = 5)

down_frame = Frame(window, bg=col1)
down_frame.grid(row = 1, column = 0, columnspan = 2, padx = 15)

red = Label(right_frame, text = "Red", bg = col1, width = 7, fg = 'red', anchor= NW, font=("Ivy", 12, "bold"))
red.grid(row=0, column=0)

red_scale = Scale(right_frame, bg= col1, fg= 'red', from_= 0, to= 255, orient= HORIZONTAL, command= scale)
red_scale.grid(row=0, column=1)

green = Label(right_frame, text = "Green", bg = col1, width = 7, fg = 'green', anchor= NW, font=("Ivy", 12, "bold"))
green.grid(row=1, column=0)

green_scale = Scale(right_frame, bg= col1, fg= 'green', from_= 0, to= 255, orient= HORIZONTAL, command= scale)
green_scale.grid(row=1, column=1)

blue = Label(right_frame, text = "Blue", bg = col1, width = 7, fg = 'blue', anchor= NW, font=("Ivy", 12, "bold"))
blue.grid(row=2, column=0)

blue_scale = Scale(right_frame, bg= col1, fg= 'blue', from_= 0, to= 255, orient= HORIZONTAL, command= scale)
blue_scale.grid(row=2, column=1)

rgb_label = Label(down_frame, text = "Hex Code: ", bg = col1, anchor= NW, font=("Ivy", 10, "bold"))
rgb_label.grid(row=0, column=0, pady= 15)

color_entry = Entry(down_frame, width= 12, font=("Ivy", 10, "bold"), justify=CENTER)
color_entry.grid(row=0, column=1, padx=5)

copy_button = Button(down_frame, text="Copy Color", bg=col1, width= 12, font=("Ivy", 10, "bold"), command= onclick)
copy_button.grid(row=0, column=2, padx=5)

copy_button = Button(down_frame, text="Start Scan", bg=col1, width= 12, font=("Ivy", 10, "bold"), command= startscan)
copy_button.grid(row=0, column=3, padx=5)

color_name = Label(down_frame, text = "Color Name Here", bg= col1, font=("Ivy", 15, "bold"))
color_name.grid(row=0, column=4)

window.mainloop()

