#include "SimpleSocket.hpp"
// Default constructor
HDE::SimpleSocket::SimpleSocket(int domain, int service, int protocol, int port, u_long interface)
{
  // Define address strucure
  address.sin_family = domain;
  address.sin_port = htons(port);
  address.sin_addr.s_addr = htonl(interface);
  // Establish socket
  sock = socket(domain, service, protocol);
  testConnection(sock);
}

// Test connection virtual function
void HDE::SimpleSocket::testConnection(int itemToTest)
{
  // Confirm that the socket or connection has been properly established
  if (itemToTest < 0)
  {
    perror("Failed to connect...");
    exit(EXIT_FAILURE);
  }
}

// Getter functions
struct sockaddr_in HDE::SimpleSocket::getAddress()
{
  return address;
}

int HDE::SimpleSocket::getSock()
{
  return sock;
}

int HDE::SimpleSocket::getConnection()
{
  return connection;
}

// Setter functions

void HDE::SimpleSocket::setConnection(int con)
{
  connection = con;
}