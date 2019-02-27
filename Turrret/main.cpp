// This is the code for the Raspberry Pi component of the trret.

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define GPIO_GUN_MOTOR_SIGNAL_PIN 4 // GPIO4 or pin 7 - Firing mechanism
#define GPIO_BASE_MOTOR_SIGNAL_PIN 17 // GPIO 17 or pin 11 - Rotates base of gun
#define GPIO_TIP_MOTOR_SIGNAL_PIN 27 // GPIO 27 or pin 13 - Moves tip of gun vertically
#define GPIO_REAR_MOTOR_SIGNAL_PIN 22 // GPIO 22 or pin 15 - Moves back of gun vertically
#define GPIO_GROUND 14 // GND

#define COMMAND_FIRE 0
#define COMMAND_UP 1
#define COMMAND_DOWN 2
#define COMMAND_RIGHT 4
#deinfe COMMAND_LEFT 3
#define TERMINATE_CONNECTION 5

#define RETURN_GOOD 0
#define RETURN_BAD 1

#define WEB_PORT 12000 // Port of server to be used
#define WEB_ADDRESS // In reality this is just the address of a server

using namespace std;

// Code has to:
// Do whatever setup is necessary to output to GPIO
// Contact webserver to get commands
// Download commands and evaluate them

void executeCommand(int command /*Whatever object is needed for GPIO logic*/)
{

}

int main()
{
    cout << "Hello world!" << endl;
    cout << "Initialising Turret. Setting up internet connectivity." << endl;

    // Start with networking setup
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        cout << "ERROR opening socket" << endl;

    server = gethostbyname(WEB_ADDRESS);
    if(server == NULL)
    {
        cout << "ERROR no such host. Terminating the program." << endl;
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(WEB_PORT);

    if(connect(sockfd,&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << "ERROR connecting. Terminating the program." << endl;
        return 1;
    }

    // Initialise GPIO here

    // Read from server, take whatever command is being processed and execute it
    int n;
    while(1)
    {
        n = read(sockfd, buffer, 16);
        if(n < 0)
        {
            cout << "ERROR reading socket. Terminating program." << endl;
            return 1;
        }
        if(n == TERMINATE_CONNECTION)
        {
            cout << "Goodbye!" << endl;
            return 0;
        }
        executeCommand(n);
    }
    return 0;
}
