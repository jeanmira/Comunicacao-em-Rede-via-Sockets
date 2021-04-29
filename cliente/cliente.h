#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

#define PORT 4312

class Cliente
{
private:
    int sock = 0;
    int valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

public:
    Cliente();
    ~Cliente();
    int conexao();
    int inicializacao();
};
#endif
