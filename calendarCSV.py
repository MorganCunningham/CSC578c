import serial

#/Users/dalecunningham/Documents/2021:2022/578c
arduino_port = "/dev/cu.usbmodem14101"
baud = 9600
fileName="calendar.csv"

ser = serial.Serial(arduino_port, baud)
print("Connected to Arduino port:" + arduino_port)
file = open(fileName, "w")
print("Created file")

samples = 4 #how many samples to collect
print_labels = False

line = 0 #start at 0 because our header is 0 (not real data)
while line <= samples:
    # incoming = ser.read(9999)
    # if len(incoming) > 0:
    if print_labels:
        if line==0:
            print("Printing Column Headers")
        else:
            print("Line " + str(line) + ": writing...")
    getData=str(ser.readline())
    #print(getData)
    data=getData[2:][:-5]
    print(data)

    file = open(fileName, "a")
    file.write(data + "\n") #write data with a newline
    line = line+1

print("Data collection complete!")
file.close()
