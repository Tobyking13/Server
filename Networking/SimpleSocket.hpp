#ifndef SIMPLESOCKET_H
#define SIMPLESOCKET_H

#include <stdio.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

namespace HDE
{
class SimpleSocket
{
private:
  struct sockaddr_in address; 
  int sock;
  int connection;

public:
  // Constructor
  SimpleSocket(int domain, int service, int protocol, int port, u_long interface); 
  // Virtual function to connect to network 
  virtual int connectToNetwork(int sock, struct sockaddr_in address) = 0;
  // Test socket & connection function
  void testConnection(int);
  // Getter functions
  struct sockaddr_in getAddress();
  int getSock();
  int getConnection();
  // Setter functions
  void setConnection(int names);
};
}

#endif //SIMPLESOCKET_H