import socket

s = socket.socket()

s.connect(("localhost", 12000))
s.send(b"Hello")
print(s.recv(16))

s.close()
