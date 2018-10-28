#include <iostream>

#define GPIO_GUN_MOTOR_SIGNAL_PIN 4 // GPIO4 or pin 7
#define GPIO_BASE_MOTOR_SIGNAL_PIN 17 // GPIO 17 or pin 11
#define GPIO_TIP_MOTOR_SIGNAL_PIN 27 // GPIO 27 or pin 13
#define GPIO_REAR_MOTOR_SIGNAL_PIN 22 // GPIO 22 or pin 15
#define GPIO_GROUND 14 // GND

#define COMMAND_FIRE 1
#define COMMAND_UP 2
#define COMMAND_DOWN 3
#define COMMAND_RIGHT 4
#deinfe COMMAND_LEFT 5

#define RETURN_GOOD 0
#define RETURN_BAD 1

using namespace std;

// Code has to:
// Do whatever setup is necessary to output to GPIO
// Contact webserver to get commands
// Download commands and evaluate them

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
