# CLass for managing the app, user interface and general logic of program
# By Hugo Sebesta



from tkinter import *

from Network import *
from Resolve import *

class app:
    root = None
    netHandler = None

    CAMERA_DISPLAY_HEIGHT = 720 #720p
    CAMERA_DISPLAY_LENGTH = 1280

    def __init__(): # Do setup
        netHandler = network()

    def restart():
        pass

    def settings():
        pass

    def run(): # Run program
        root = Tk()
        root.title("Turret Control")

        # Populate root window
        # Menubar first
        menubar = Menu(root)

        conMenu = Menu(menubar, tearoff=0)
        conMenu.add_command(label="Reconnect", command=self.restart)
        conMenu.add_command(label="Settings", command=self.settings)
        conMenu.add_seperator()
        conMenu.add_command(label="Quit", command=quit)

        menubar.add_cascade(label="Connection", menu=conMenu)

        mainFrame = Frame(root)
        mainFrame.pack()

        topFrame = Frame(mainFrame)
        bottomFrame = Frame(mainFrame)

        # Functions
        def up():
            pass
        def down():
            pass
        def left():
            pass
        def right():
            pass
        def fire():
            pass
        def toggleAuto():
            pass

        # Top Frame First
        topFrameText = Label(topFrame, text="Display:")
        camDisplayCanvas = Canvas(topFrame, height=self.CAMERA_DISPLAY_HEIGHT, width=self.CAMERA_DISPLAY_LENGTH)

        # Bottom Frame
        upControlButton = Button(bottomFrame, text="Up", command=up)
        downControlButton = Button(bottomFrame, text="Down", command=down)
        leftControlButton = Button(bottomFrame, text="Left", command=left)
        rightControlButton = Button(bottomFrame, text="Right", command=right)

        fireButton = Button(bottomFrame, text="FIRE", command=fire)
        autoToggle = Button(bottomFrame, text="Toggle Auto", command=toggleAuto)
