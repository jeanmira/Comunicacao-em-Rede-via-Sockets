#include "cliente.h"

int main(int argc, char const *argv[])
{
    // Construtor padrão
    Cliente c;
    // Inicializar os parâmetros do cliente na rede
    c.inicializacao();
    // Faz a troca de mensagens
    c.conexao();
    return 0;
}
