#include "servidor.h"

Servidor::Servidor(int cerveja, int agua, int refrigerante)
{
    this->qtd_cerveja = cerveja;
    this->qtd_agua = agua;
    this->qtd_refrigerante = refrigerante;
}

Servidor::~Servidor() {}

void Servidor::inicializacao()
{

    // Criando descritor de arquivo de socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Falha socket");
        exit(EXIT_FAILURE);
    }

    // Conectando o socket a porta desejada
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Define sockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Conectando o socket a porta desejada
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Ligação falhou");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("Esperando");
        exit(EXIT_FAILURE);
    }
}

int Servidor::conexao()
{
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Aceitar");
        exit(EXIT_FAILURE);
    }

    char const *mensagem;

    valread = read(new_socket, buffer, 15);
    //printf("%c\n", buffer[0]);

    string frase(buffer);
    int qtd = 0;
    string nome{};
    cout << frase.data() << endl;
    if (!strcmp(frase.data(), "sair"))
    {
        return -1;
    }
    sscanf(frase.data(), "%d%s", &qtd, nome.data());

    if (!strcmp(nome.data(), "cerveja"))
    {
        if (qtd_cerveja >= qtd)
        {
            mensagem = (char *)"Bebida entregue";
            qtd_cerveja -= qtd;
        }
        else
        {
            mensagem = (char *)"Quantidade solicitada indisponivel";
        }
        cout << nome.data() << endl;
    }
    else if (!strcmp(nome.data(), "agua"))
    {
        if (qtd_agua >= qtd)
        {
            mensagem = (char *)"Bebida entregue";
            qtd_agua -= qtd;
        }
        else
        {
            mensagem = (char *)"Quantidade solicitada indisponivel";
        }
        cout << nome.data() << endl;
    }
    else if (!strcmp(nome.data(), "refrigerante"))
    {
        if (qtd_refrigerante >= qtd)
        {
            mensagem = (char *)"Bebida entregue";
            qtd_refrigerante -= qtd;
        }
        else
        {
            mensagem = (char *)"Quantidade solicitada indisponivel";
        }
        cout << nome.data() << endl;
    }
    else
    {
        mensagem = (char *)"Nome da bebida incorreto";
    }

    send(new_socket, mensagem, strlen(mensagem), 0);
    cout << "Mensagem enviada" << endl;
    return 0;
}
