#ifndef BINDINGSOCKET_H
#define BINDINGSOCKET_H

#include <stdio.h>

#include "SimpleSocket.hpp"

namespace HDE
{

class BindingSocket: public SimpleSocket
{
public:
  // Constructor
  BindingSocket(int domain, int service, int protocol, int port, 
                u_long interface);
  // Virtual function from parent
  int connectToNetwork(int sock, struct sockaddr_in address);
};
}

#endif // BINDINGSOCKET_H