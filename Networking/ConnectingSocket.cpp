#include "ConnectingSocket.hpp"
#include "BindingSocket.hpp"
#include <sys/socket.h>
#include <sys/types.h>

// Constructor
HDE::ConnectingSocket::ConnectingSocket(int domain, int service, int protocol, int port, u_long interface) :
  SimpleSocket(domain, service, protocol, port, interface)
{
  setConnection(connectToNetwork(getSock(), getAddress()));
  testConnection(getConnection());
}

// Definition of the connectToNetwork virtual function
int HDE::ConnectingSocket::connectToNetwork(int sock, struct sockaddr_in address)
{
  return connect(sock, (struct sockaddr *)&address, sizeof(address));
}