# File for resolving commands to send to turret
# This is used for the turret to operate autonomously, or simply to resolve input to commands
# By Hugo Sebesta

class resolve:
    FIRE = 0
    UP = 1
    DOWN = 2
    LEFT = 3
    RIGHT = 4
    TERMINATE = 5

    auto = False

    def __init__(self, a = False):
        self.auto = a

    def left(self):
        return self.LEFT # no issues here

    def right(self):
        return self.RIGHT

    def fire(self):
        return self.FIRE

    def end(self):
        return self.TERMINATE

    def up(self):
        return self.UP

    def down(self):
        return self.DOWN

    def autoAim(self, input):
        pass
