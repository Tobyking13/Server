#include "TestServer.hpp"
#include "SimpleServer.hpp"
#include <netinet/in.h>
#include <sys/socket.h>

HDE::TestServer::TestServer() : SimpleServer(AF_INET, SOCK_STREAM, 0, 80, INADDR_ANY, 10 )
{
  launch();
}

void HDE::TestServer::accepter()
{
  struct sockaddr_in address = getSocket()->getAddress();
  int addrlen = sizeof(address);
  newSocket = accept(getSocket()->getSock(), (struct sockaddr *)& address, (socklen_t *)&addrlen);
  read(newSocket, buffer, 30000);
}

void HDE::TestServer::handler()
{
  std::cout << buffer << std::endl;
}

void HDE::TestServer::responder()
{
  std::string hello = "Hello from server";
  write(newSocket, hello.c_str(), hello.length());
  close(newSocket); 
}

void HDE::TestServer::launch()
{
  while (true)
  {
    std::cout << "==== Waiting ====" << std::endl;
    accepter();
    handler();
    responder();
    std::cout << "==== Done ====" << std::endl;
  }
}