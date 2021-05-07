#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>

#include "../rede.h"

using namespace std;

class Cliente
{
private:
    Rede r; // Instância da classe rede

public:
    Cliente();      // Construtor padrão
    ~Cliente();     // Destrutor padrão
    void conexao(); // Inicializar os parâmetros do cliente na rede
};
#endif
