#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#include "servidor.h"

#define REFRIGERANTE 3
#define AGUA 3
#define CERVEJA 3

using namespace std;

int main(int argc, char const *argv[])
{
    Servidor s(3, 3, 3);
    s.inicializacao();
    int valor = 0;

    while (1)
    {
        valor = s.conexao();
        if (valor == -1)
            break;
    }
    return 0;
}
