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
    int qtd_cerveja;                     // Quantidade de cerveja da loja
    int qtd_agua;                        // Quantidade de água da loja
    int qtd_refrigerante;                // Quantidade de refrigerante da loja
    int servidorFd;                      // Servidor
    struct sockaddr_in endereco;         // Endereço
    int enderecoSize = sizeof(endereco); // Tamanho do endereço

public:
    Servidor(int cerveja, int agua, int refrigerante); // Construtor padrão
    ~Servidor();                                       // Destrutor padrão
    int conexao();                                     // Inicializar os parâmetros do servidor na rede
    void inicializacao();                              // Faz a troca de mensagens
};
#endif
