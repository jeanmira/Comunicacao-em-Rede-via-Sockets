#include "servidor.h"

//----- Construtor padrão
Servidor::Servidor(int cerveja, int agua, int refrigerante)
{
    this->qtd_cerveja = cerveja;
    this->qtd_agua = agua;
    this->qtd_refrigerante = refrigerante;
}

//----- Destrutor padrão
Servidor::~Servidor()
{
}

//----- Inicializar os parâmetros do servidor na rede
void Servidor::inicializacao()
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

//----- Faz a troca de mensagens
int Servidor::conexao()
{
    int novoSocket;
    int valorLeitura;
    char buffer[15] = {0};

    if ((novoSocket = accept(servidorFd, (struct sockaddr *)&endereco, (socklen_t *)&enderecoSize)) < 0)
    {
        perror("Aceitar");
        exit(EXIT_FAILURE);
    }

    char const *mensagem;

    valorLeitura = read(novoSocket, buffer, 15);
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

    send(novoSocket, mensagem, strlen(mensagem), 0);
    cout << "Mensagem enviada" << endl;
    return 0;
}
