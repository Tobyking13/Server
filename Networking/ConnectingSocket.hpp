#ifndef CONNECTINGSOCKET_H
#define CONNECTINGSOCKET_H

// This class implements a call to the connect() function of
// sockets as a definition to the connectToNetwork() virtual
// function from SimpleSocket.

#include <stdio.h>
#include <sys/types.h>

#include "SimpleSocket.hpp"

namespace HDE
{

class ConnectingSocket: public SimpleSocket
{
public:
  ConnectingSocket(int domain, int service, int protocol, int port, u_long interface);
  int connectToNetwork(int sock, struct sockaddr_in address);
};
}
#endif // CONNECTINGSOCKET_H