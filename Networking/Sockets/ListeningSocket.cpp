#include "ListeningSocket.hpp"
#include <sys/types.h>

HDE::ListeningSocket::ListeningSocket(int domain, int service, int protocol, int port, u_long interface, int bklg):
  BindingSocket(domain, service, protocol, port, interface)
{
  backlog = bklg;
  startListening();
  testConnection(listening);
}

void HDE::ListeningSocket::startListening()
{
  listening = listen(getSock(), backlog);
}

