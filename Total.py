import Main
import serial
import cv2

c = serial.Serial("COM4", 9600) #Change first arg for terminal COM
cap = cv2.VideoCapture(0)
while True:
    m = serial.read()
    ret, frame = cap.read()
    cv2.imshow("frame",frame)
    if m==1:
        placa = Main.entrada(frame)
        cv2.destroyAllWindows()
        serial.write('s'.encode())
        print (placa)
