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
    Servidor s(REFRIGERANTE, AGUA, CERVEJA);
    s.inicializacao();
    int valor = 0;
    while (valor != -1)
    {
        valor = s.conexao();
    }

    return 0;
}
