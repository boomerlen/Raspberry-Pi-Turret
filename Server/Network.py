# Class for communicating with turret over internet
# By Hugo Sebesta

import socket
import time
import threading

class network:

    s = None # Set in init
    c = None

    cameraOutput = None # Most recent camera output (bit array or something idk)

    def __init__(self, p = 12000):
        self.s = socket.socket()
        self.host = socket.gethostname()
        self.port = 12000

        self.s.bind((self.host, self.port))

    def open(self):
        "Returns once the socket has a connection"
        def list():
            self.s.listen()
            self.s.send(10)
            return True

        threading.Thread(target=list).start()
        time.sleep(5)
        return False

    def receive(self):
        def list():
            ret = self.s.recv()
            return ret # Hope this works

        threading.Thread(target=list).start() #
        time.sleep(3)
        return False

    def send(self, command):
        self.s.send(command) # TypeError for some reason...
        return None

    def updateCamFeed(self):
        self.cameraOutput = receive(self) # Careful for threading issues
        return None
