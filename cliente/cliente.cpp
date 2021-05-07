#include "cliente.h"

//----- Construtor padrão
Cliente::Cliente()
{
    // Inicializar os parâmetros do cliente na rede
    r.inicializacaoCliente();
}

//----- Destrutor padrão
Cliente::~Cliente()
{
}

//----- Faz a troca de mensagens
void Cliente::conexao()
{

    int valorLeitura;
    char buffer[1024] = {0};
    char mensagem[15];

    cin.getline(mensagem, 15);
    send(r.getSock(), &mensagem, sizeof(mensagem), 0);
    cout << "Mensagem enviada" << endl;
    valorLeitura = read(r.getSock(), buffer, 1024);
    cout << buffer << endl;
}
