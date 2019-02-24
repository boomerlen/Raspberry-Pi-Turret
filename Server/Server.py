# Server side code for Turret
# Python because the UI is much easier
# And speed matters less on the server side
# Especially if I get it to run autonomously in any way
# Unless I decide that my computer could handle that better than my Rasp. Pi
# Which I actually have decided plot twist.

# Entry Point for server
# By Hugo Sebesta

from App import *

application = app()
app.run()
