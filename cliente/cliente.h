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

#define PORT 8088

class Cliente
{
private:
    int sock = 0;

public:
    Cliente();            // Construtor padrão
    ~Cliente();           // Destrutor padrão
    void conexao();       // Inicializar os parâmetros do cliente na rede
    void inicializacao(); // Faz a troca de mensagens
};
#endif
