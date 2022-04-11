from numpy import *
from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg
import serial

pic32 = serial.Serial('/dev/ttyUSB0', 115200);
app = QtGui.QApplication([])

while 1:
    line = pic32.readline()
    if(line == b'Insert the desired temperature setpoint: \r\n'):
        temp_setpoint = input("Insert the desired temperature setpoint: ")
        pic32.write(bytes(temp_setpoint + '\r', 'utf-8'))
        break

pg.setConfigOption('background', 'w')
win = pg.GraphicsWindow(title="Temperature Control")
p = win.addPlot(title="Realtime plot")

setpoint_curve = p.plot(pen=pg.mkPen('r', width=3))
ambient_curve = p.plot(pen=pg.mkPen('g', width=3))
resistor_curve = p.plot(pen=pg.mkPen('b', width=3))

windowWidth = 500
setpoint_data = linspace(0,0,windowWidth)
ambient_data = linspace(0,0,windowWidth)
resistor_data = linspace(0,0,windowWidth)
ptr = -windowWidth

f = open("temp_graph.csv", "w")

while 1:
    line = pic32.readline().decode('utf-8')

    try:
        splitted_list = line.split(' ')

        setpoint = float(splitted_list[1])
        ambient_temp = float(splitted_list[3])
        resistor_temp = float(splitted_list[5])
        duty_cycle = float(splitted_list[7])

        setpoint_data[:-1] = setpoint_data[1:]
        setpoint_data[-1] = setpoint

        ambient_data[:-1] = ambient_data[1:]
        ambient_data[-1] = ambient_temp

        resistor_data[:-1] = resistor_data[1:]
        resistor_data[-1] = resistor_temp

        ptr += 1

        setpoint_curve.setData(setpoint_data)
        setpoint_curve.setPos(ptr, 0)

        ambient_curve.setData(ambient_data)
        ambient_curve.setPos(ptr, 0)

        resistor_curve.setData(resistor_data)
        resistor_curve.setPos(ptr, 0)


        QtGui.QApplication.processEvents()

        print("Setpoint: " + str(setpoint) + " Ambient: " + str(ambient_temp) + " Resistor: " + str(resistor_temp))
        f.write(str(setpoint) + "," + str(ambient_temp) + "," + str(resistor_temp) + "," + str(duty_cycle) + "\n")
    except:
        pass

f.close()
pg.QtGui.QApplication.exec_()
