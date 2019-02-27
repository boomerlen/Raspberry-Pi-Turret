# CLass for managing the app, user interface and general logic of program
# By Hugo Sebesta



from tkinter import *

from Network import *
from Resolve import *

class app:
    root = None
    netHandler = None
    commandResolveHandler = None

    CAMERA_DISPLAY_HEIGHT = 480 #720 #720p
    CAMERA_DISPLAY_LENGTH = 640 #1280

    auto = False

    def __init__(self): # Do setup
        self.netHandler = network()
        self.commandResolveHandler = resolve(False)

    def restart(self):
        pass

    def settings(self):
        pass

    def run(self): # Run program
        root = Tk()
        root.title("Turret Control")

        # Populate root window
        # Menubar first
        menubar = Menu(root)

        conMenu = Menu(menubar, tearoff=0)
        conMenu.add_command(label="Reset Socket", command=self.restart)
        conMenu.add_command(label="Settings", command=self.settings)
        conMenu.add_separator()
        conMenu.add_command(label="Quit", command=quit)

        menubar.add_cascade(label="Connection", menu=conMenu)
        root.config(menu=menubar)

        mainFrame = Frame(root)
        mainFrame.pack()

        topFrame = Frame(mainFrame)
        bottomFrame = Frame(mainFrame)

        # Functions
        def up():
            try:
                self.netHandler.send(self.commandResolveHandler.up())
                print("up")
            except Exception as exception:
                print("Error @ line 60" + exception.__class__.__name__)
        def down():
            try:
                self.netHandler.send(self.commandResolveHandler.down())
                print("down")
            except Exception as exception:
                print("Error @ line 66: " + exception.__class__.__name__)
        def left():
            try:
                self.netHandler.send(self.commandResolveHandler.left())
                print("left")
            except Exception as exception:
                print("Error @ line 72" + exception.__class__.__name__)
        def right():
            try:
                self.netHandler.send(self.commandResolveHandler.right())
                print("right")
            except Exception as exception:
                print("Error @ line 78" + exception.__class__.__name__)
        def fire():
            try:
                self.netHandler.send(self.commandResolveHandler.fire())
                print("fire")
            except Exception as exception:
                print("Error @ line 84" + exception.__class__.__name__)
        def toggleAuto():
            pass

        # Top Frame First
        topFrameText = Label(topFrame, text="Display:")
        camDisplayCanvas = Canvas(topFrame, height=self.CAMERA_DISPLAY_HEIGHT, width=self.CAMERA_DISPLAY_LENGTH)

        # Bottom Frame

        # Text frame
        controlButtonFrame = LabelFrame(bottomFrame, text="Camera Controls")

        upControlButton = Button(controlButtonFrame, text="Up", command=up)
        downControlButton = Button(controlButtonFrame, text="Down", command=down)
        leftControlButton = Button(controlButtonFrame, text="Left", command=left)
        rightControlButton = Button(controlButtonFrame, text="Right", command=right)

        fireButton = Button(bottomFrame, text="FIRE", command=fire)
        autoToggle = Button(bottomFrame, text="Toggle Auto", command=toggleAuto)

        # Geometry
        topFrame.grid(row=0, column=0)
        bottomFrame.grid(row=1, column=0)

        # top
        topFrameText.grid(row=0, column=0, columnspan=2)
        camDisplayCanvas.grid(row=1, column=0)

        # bottom
        controlButtonFrame.grid(row=0, column=0, columnspan=3, rowspan=3)

        upControlButton.grid(row=0, column=1)
        downControlButton.grid(row=2, column=1)
        leftControlButton.grid(row=1, column=0)
        rightControlButton.grid(row=1, column=2)

        fireButton.grid(row=1, column=5)
        autoToggle.grid(row=2, column=5)

        # Camera Feed
        def updateCamera(): # do some update camera shiz
            try:
                camIMG = self.netHandler.cameraOutput
                self.netHandler.updateCamFeed() # Thread this?
                if auto:
                    self.commandResolveHandler.autoAim(camIMG)
                # do thing - display camIMG on canvas
            except:
                pass # this is to catch the self.nethandler =/= NoneType

        camDisplayCanvas.after(10, updateCamera)

        root.mainloop()
