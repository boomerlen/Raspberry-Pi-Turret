# Class for communicating with turret over internet
# This is the client
# By Hugo Sebesta

import socket

class network:

    s = None # Set in init

    cameraOutput = None # Most recent camera output (bit array or something idk)

    def __init__(self, p = 12000):
        self.s = socket.socket()

    def receive(self):
        ret = self.s.recv(4)
        return ret

    def send(self, command):
        self.s.send(bytes(command)) # TypeError for some reason...
        return None

    def updateCamFeed(self):
        self.s.send(bytes(5))
        self.cameraOutput = self.s.receive(self) # Careful for threading issues
        return None

    def __del__(self):
        self.s.close()
