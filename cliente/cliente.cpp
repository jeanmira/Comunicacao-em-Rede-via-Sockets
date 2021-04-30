#include "cliente.h"

Cliente::Cliente() {}
Cliente::~Cliente() {}

int Cliente::inicializacao()
{
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cout << endl
             << "Erro de criação de Socket" << endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Converter endereços IPv4 e IPv6 de texto para formato binário
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        cout << endl
             << "Endereço inválido / endereço não suportado" << endl;
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << endl
             << "Falha na conexão" << endl;
        return -1;
    }

    return 0;
}

int Cliente::conexao()
{
    char mensagem[15];
    cin.getline(mensagem, 15);
    send(sock, &mensagem, sizeof(mensagem), 0);
    cout << "Mensagem enviada" << endl;
    valread = read(sock, buffer, 1024);
    cout << buffer << endl;

    return 0;
}
