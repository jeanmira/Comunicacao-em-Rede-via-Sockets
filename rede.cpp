#include "rede.h"

//----- Inicializar os parâmetros do cliente na rede
void Rede::inicializacaoCliente()
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

//----- Inicializar os parâmetros do cliente na rede
void Rede::inicializacaoServidor()
{
    int opt = 3;

    // Criando descritor de arquivo de socket
    if ((servidorFd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Falha socket");
        exit(EXIT_FAILURE);
    }

    // Conectando o socket a porta desejada
    if (setsockopt(servidorFd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Define sockopt");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(PORT);

    // Conectando o socket a porta desejada
    if (bind(servidorFd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0)
    {
        perror("Ligação falhou");
        exit(EXIT_FAILURE);
    }
    if (listen(servidorFd, 3) < 0)
    {
        perror("Esperando");
        exit(EXIT_FAILURE);
    }
}
//----- Retorna sock
int Rede::getSock()
{
    return this->sock;
}

//----- Retorna servidorFd
int Rede::getServidorFd()
{
    return this->servidorFd;
}

//----- Retorna endereco
sockaddr_in &Rede::getEndereco()
{
    return this->endereco;
}

//----- Retorna enderecoSize
int &Rede::getEnderecoSize()
{
    return enderecoSize;
}