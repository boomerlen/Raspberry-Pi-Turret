// This is the code for the Raspberry Pi component of the trret.

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <netdb.h>
#include <string.h>

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
#define TERMINATE_CONNECTION 5

#define RETURN_GOOD 0
#define RETURN_BAD 1

#define WEB_PORT 12000 // Port of server to be used
#define WEB_ADDRESS "localhost"// In reality this is just the address of a server

using namespace std;

// Code has to:
// Do whatever setup is necessary to output to GPIO
// Contact webserver to get commands
// Download commands and evaluate them

int executeCommand(char command[4] /*Whatever object is needed for GPIO logic*/)
{
  cout << command << endl;

  return RETURN_GOOD;
}

int main()
{
    cout << "Hello world!" << endl;
    cout << "Initialising Turret. Setting up internet connectivity." << endl;

    // Start with networking setup
    int sockfd, n, servlen, ret;
    struct sockaddr_un serv_addr;
    char buffer[4];
    //int buffer;

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sun_family = AF_UNIX;
    strcpy(serv_addr.sun_path, WEB_ADDRESS);
    servlen = strlen(serv_addr.sun_path) + sizeof(serv_addr.sun_family);

    if((sockfd = socket(AF_UNIX, SOCK_STREAM, 0)) < 0)
      cout << "Error coreating socket" << endl;

    if(connect(sockfd, (struct sockaddr *)&serv_addr, servlen) < 0)
    {
      cout << "Error connecting. Terminating." << endl;
    }

    cout << "Connected." << endl;
    while(1)
    {
      bzero(buffer, 4);
      n = read(sockfd, buffer, 4);
      if(n < 0)
      {
        //cout << "Error reading from socket" << endl;
        //return 1;
      }
      if(n == TERMINATE_CONNECTION)
      {
        n = write(sockfd, RETURN_GOOD, 1);
        cout << "Terminating Connection" << endl;
        break;
      }
      ret = executeCommand(buffer);
      n = write(sockfd, (char *)ret, sizeof(ret));
      if(n < 0)
      {
        //cout << "Error writing to socket" << endl;
        //return 1;
      }
    }
    return 0;
}
