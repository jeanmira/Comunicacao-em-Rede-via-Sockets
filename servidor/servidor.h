#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

using namespace std;

#define PORT 7900

class Servidor
{
private:
    int qtd_cerveja;
    int qtd_agua;
    int qtd_refrigerante;
    int server_fd;
    int new_socket;
    int valread;
    struct sockaddr_in address;
    int opt = 3;
    int addrlen = sizeof(address);
    char buffer[15] = {0};

public:
    Servidor(int cerveja, int agua, int refrigerante);
    ~Servidor();
    int conexao();
    void inicializacao();
};
#endif
