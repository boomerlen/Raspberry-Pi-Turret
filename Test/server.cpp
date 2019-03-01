#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 12000
#define HOST "localhost"

using namespace std;

int main()
{
  char* msg = "Hello\n";

  struct sockaddr_in dest; // Client info
  struct sockaddr_in serv; // Server info

  int sock;

  socklen_t socksize = sizeof(struct sockaddr_in);

  memset(&serv, 0, sizeof(serv)); // Zero it
  serv.sin_family = AF_INET; // Specify TCP/IP
  serv.sin_addr.s_addr = htonl(INADDR_ANY); // Set interface
  serv.sin_port = htons(PORT); // Set port

  sock = socket(AF_INET, SOCK_STREAM, 0); // Make the socket

  bind(sock, (struct sockaddr *)&serv, sizeof(struct sockaddr)); // Bind to socket

  listen(sock, 1); // Listen for connection
  int consock = accept(sock, (struct sockaddr *)&dest, &socksize); // Accept connecction

  cout << "Received connection from " << inet_ntoa(dest.sin_addr) << endl; // Connection established
  char buf[16];
  recv(consock, buf, 16, 0);
  cout << "Received " << buf << endl;
  send(consock, msg, strlen(msg), 0);
  close(consock);
  return 0;
}
