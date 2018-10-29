// This is the code for the Raspberry Pi component of the trret.

#include <iostream>
#incluce <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

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

#define WEB_PORT 80
#define WEB_ADDRESS

using namespace std;

// Code has to:
// Do whatever setup is necessary to output to GPIO
// Contact webserver to get commands
// Download commands and evaluate them

int main()
{
    cout << "Hello world!" << endl;
    cout << "Initialising Turret. Setting up internet connectivity." << endl;


    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        cout << "ERROR opening socket" << endl;

    server = gethostbyname(WEB_ADDRESS);
    if(server == NULL)
    {
        cout << "ERROR no such host. Terminate the program." << endl;
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(WEB_PORT);

    return 0;
}
