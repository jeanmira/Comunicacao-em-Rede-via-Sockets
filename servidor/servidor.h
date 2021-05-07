#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#include "../rede.h"

using namespace std;

class Servidor
{
private:
    int qtd_cerveja;      // Quantidade de cerveja da loja
    int qtd_agua;         // Quantidade de água da loja
    int qtd_refrigerante; // Quantidade de refrigerante da loja
    Rede r;               // Instância da classe rede

public:
    Servidor(int cerveja, int agua, int refrigerante); // Construtor padrão
    ~Servidor();                                       // Destrutor padrão
    int conexao();                                     // Inicializar os parâmetros do servidor na rede
};
#endif
