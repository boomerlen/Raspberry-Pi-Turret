# Net test script
import socket

s = socket.socket()
h = socket.gethostname()
p = 12000

s.bind((h, p))

s.listen()
s.accept()
s.send(b"1")

s.close()
