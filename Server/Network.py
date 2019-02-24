# Class for communicating with turret over internet
# By Hugo Sebesta

import socket
import time
import threading 

class network:

    s = None # Set in init

    def __init__(self, p = 12000):
        self.s = socket.socket()
        self.host = socket.gethostname()
        self.port = 12000

        self.s.bind((self.host, self.port))

    def open():
        "Returns once the socket has a connection"
        self.s.listen()
        return True

    def receive():
