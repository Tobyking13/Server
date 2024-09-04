#ifndef TESTSERVER_H
#define TESTSERVER_H

#include <stdio.h>
#include <unistd.h>
#include <string>

#include "SimpleServer.hpp"

namespace HDE
{
class TestServer: public SimpleServer
{
private:
  char buffer[30000] = {0};
  int newSocket; 
  void accepter();
  void handler();
  void responder();
public:
  TestServer();
  void launch();
};
}

#endif // TESTSERVER_H