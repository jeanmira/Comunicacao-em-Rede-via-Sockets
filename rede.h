#ifndef REDE_H
#define REDE_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

#define PORT 8080

class Rede
{
private:
    int sock = 0;                        // Valor do sock
    int servidorFd;                      // Servidor
    struct sockaddr_in endereco;         // Endereço
    int enderecoSize = sizeof(endereco); // Tamanho do endereço

public:
    void inicializacaoCliente();  // Faz a inicialização do cliente
    void inicializacaoServidor(); // Faz a inicialização do servidor
    int getSock();                // Retorna sock
    int getServidorFd();          // Retorna servidorFd
    sockaddr_in &getEndereco();   // Retorna endereco
    int &getEnderecoSize();       // Retorna enderecoSize
};
#endif
