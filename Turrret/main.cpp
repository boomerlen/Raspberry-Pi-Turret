// This is the code for the Raspberry Pi component of the trret.

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

#define GPIO_GUN_MOTOR_SIGNAL_PIN 4 // GPIO4 or pin 7 - Firing mechanism
#define GPIO_BASE_MOTOR_SIGNAL_PIN 17 // GPIO 17 or pin 11 - Rotates base of gun
#define GPIO_TIP_MOTOR_SIGNAL_PIN 27 // GPIO 27 or pin 13 - Moves tip of gun vertically
#define GPIO_REAR_MOTOR_SIGNAL_PIN 22 // GPIO 22 or pin 15 - Moves back of gun vertically
#define GPIO_GROUND 14 // GND

#define COMMAND_FIRE 0
#define COMMAND_UP 1
#define COMMAND_DOWN 2
#define COMMAND_RIGHT 4
#define COMMAND_LEFT 3
#define COMMAND_PIC 5
#define TERMINATE_CONNECTION 6
#define SHUTDOWN_SERVER 7

#define RETURN_GOOD 0
#define RETURN_BAD 1

#define WEB_PORT 12000 // Port of server to be used
#define WEB_ADDRESS "localhost"// My address

using namespace std;

// Code has to:
// Do whatever setup is necessary to output to GPIO
// Establish web server
// Take commands from client and execute them

int executeCommand(char command[4] /*Whatever object is needed for GPIO logic*/)
{
  cout << command << endl;

  return RETURN_GOOD;
}

int main()
{
    cout << "Hello world!" << endl;
    cout << "Initialising Turret. Setting up internet connectivity." << endl;

    struct sockaddr_in dest; // Client info
    struct sockaddr_in serv; // Server info

    int sock, consock; // Our socket, the socket the client connects to

    socklen_t socksize = sizeof(struct sockaddr_in); // Size of sockets

    memset(&serv, 0, sizeof(serv)); // Zero
    serv.sin_family = AF_INET; // Specify TCP/IP
    serv.sin_addr.s_addr = htonl(INADDR_ANY); // Idc about the interface
    serv.sin_port = htons(WEB_PORT); // Set port

    sock = socket(AF_INET, SOCK_STREAM, 0); // Establish the socket

    bind(sock, (struct sockaddr *)&serv, sizeof(struct sockaddr)); // Bind the server details to the socket

    listen(sock, 1); // Listen for connection
    consock = accept(sock, (struct sockaddr *)&dest, &socksize); // Accept connection, establish socket

    char buf[4];
    int res;
    while(consock > 0)
    {

      while(1)
      {
        memset(&buf, 0, sizeof(buf));
        recv(consock, buf, 4, 0);
        if(atoi(buf) == SHUTDOWN_SERVER)
        {
          close(consock);
          return 0;
        }
        if(atoi(buf) == TERMINATE_CONNECTION)
        {
          close(consock);
          break;
        }
        res = executeCommand(buf);
        send(consock, (char *)res, sizeof((char *)res), 0);
      }
      consock = accept(sock, (struct sockaddr *)&dest, &socksize);
    }
}
