#include "cliente.h"

//----- Construtor padrão
Cliente::Cliente()
{
}

//----- Destrutor padrão
Cliente::~Cliente()
{
}

//----- Inicializar os parâmetros do cliente na rede
void Cliente::inicializacao()
{
    struct sockaddr_in enderecoServidor;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cout << endl
             << "Erro de criação de Socket" << endl;
    }

    enderecoServidor.sin_family = AF_INET;
    enderecoServidor.sin_port = htons(PORT);

    // Converter endereços IPv4 e IPv6 de texto para formato binário
    if (inet_pton(AF_INET, "127.0.0.1", &enderecoServidor.sin_addr) <= 0)
    {
        cout << endl
             << "Endereço inválido / endereço não suportado" << endl;
    }

    if (connect(sock, (struct sockaddr *)&enderecoServidor, sizeof(enderecoServidor)) < 0)
    {
        cout << endl
             << "Falha na conexão" << endl;
    }
}

//----- Faz a troca de mensagens
void Cliente::conexao()
{
    int valorLeitura;
    char buffer[1024] = {0};
    char mensagem[15];

    cin.getline(mensagem, 15);
    send(sock, &mensagem, sizeof(mensagem), 0);
    cout << "Mensagem enviada" << endl;
    valorLeitura = read(sock, buffer, 1024);
    cout << buffer << endl;
}
