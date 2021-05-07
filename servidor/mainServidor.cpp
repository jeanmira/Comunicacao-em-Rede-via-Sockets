#include "servidor.h"

int main(int argc, char const *argv[])
{
    // Servidor(cerveja, agua, refrigerante)
    Servidor s(3, 3, 3); // Construtor padrão

    int valor = 0; // Variável auxiliar para sair da execução do servidor

    // Executa enquanto o usuário desejar
    while (1)
    {
        // Faz a troca de mensagens
        valor = s.conexao();
        if (valor == -1)
        {
            break;
        }
    }
    return 0;
}
