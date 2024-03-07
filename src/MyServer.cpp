#include "MyServer.h"
#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
// #include <netinet.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>


MyServer::MyServer()
{
    int client, server;
    int portNum = 1500;
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];

    struct sockaddr_in server_addr;
    socklen_t size;
}
