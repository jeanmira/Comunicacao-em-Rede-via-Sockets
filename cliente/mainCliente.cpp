#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>

#include "cliente.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Cliente c;
    c.inicializacao();
    c.conexao();
    return 0;
}
