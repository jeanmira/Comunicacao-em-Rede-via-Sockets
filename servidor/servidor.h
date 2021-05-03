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

#define PORT 8088

class Servidor
{
private:
    int qtd_cerveja;
    int qtd_agua;
    int qtd_refrigerante;
    int servidorFd;
    struct sockaddr_in endereco;
    int enderecoSize = sizeof(endereco);

public:
    Servidor(int cerveja, int agua, int refrigerante);
    ~Servidor();
    int conexao();
    void inicializacao();
};
#endif
