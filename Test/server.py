import socket

s = socket.socket()

s.bind(("localhost", 12000))
s.listen()

c, addr = s.accept()

print(c.recv(16))
c.send(b"Hello There")

s.close()
