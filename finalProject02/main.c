#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Estrutura para armazenar informações do produto
struct Produto {
    int id;
    char nome[50];
    float preco;
    int quantidade;
};

// Estrutura para armazenar informações do usuário
struct Usuario {
    char cpf[12];  // CPF deve ter 11 dígitos + 1 para o caractere nulo
    char senha[9]; // Senha deve ter 8 dígitos + 1 para o caractere nulo
    char tipo[10]; // Tipo de usuário (Gerente ou Estoquista)
};

// Variáveis globais
struct Produto produtos[100];  // Array para armazenar produtos
int numProdutos = 0;           // Contador de produtos

struct Usuario usuarios[100];   // Array para armazenar usuários
int numUsuarios = 0;            // Contador de usuários

// Protótipos das funções
void cadastrarUsuario();
void loginUsuario();
void cadastrarProduto();
void listarProdutos();
void pesquisarProduto();
void editarProduto();
void menuPrincipal();
int validarCpfSenha(const char *cpf, const char *senha);

// Função para validar se o CPF e a senha estão no comprimento correto
int validarCpfSenha(const char *cpf, const char *senha) {
    return (strlen(cpf) == 11 && strlen(senha) == 8);  // Verifica comprimento correto
}

// Função para cadastrar um novo usuário
void cadastrarUsuario() {
    char cpf[12], senha[9], tipo[10];

    // Entrada do CPF do novo usuário
    printf("Digite o CPF do novo usuario (11 digitos): ");
    fflush(stdin); // Limpa o buffer
    scanf("%11s", cpf);  // Lê até 11 caracteres para o CPF

    // Entrada da senha do novo usuário
    printf("Digite a senha (8 digitos): ");
    fflush(stdin); // Limpa o buffer
    scanf("%8s", senha);  // Lê até 8 caracteres para a senha

    // Validação do comprimento do CPF e senha
    if (!validarCpfSenha(cpf, senha)) {
        printf("CPF ou senha invalidos. Certifique-se de que o CPF tenha 11 digitos e a senha tenha 8 caracteres.\n");
        return;
    }

    // Entrada do tipo de usuário
    printf("Tipo de usuario (Gerente ou Estoquista): ");
    fflush(stdin); // Limpa o buffer
    scanf("%10s", tipo);  // Lê até 10 caracteres para o tipo de usuário

    // Adiciona o novo usuário ao array de usuários
    strcpy(usuarios[numUsuarios].cpf, cpf);
    strcpy(usuarios[numUsuarios].senha, senha);
    strcpy(usuarios[numUsuarios].tipo, tipo);
    numUsuarios++;
    printf("Usuario cadastrado com sucesso.\n");
}

// Função para autenticar um usuário no login
void loginUsuario() {
    char cpf[12], senha[9];
    int tentativas = 3;

    // Loop de tentativas de login com limite de 3
    while (tentativas > 0) {
        printf("Digite seu CPF (11 digitos): ");
        fflush(stdin); // Limpa o buffer
        scanf("%11s", cpf);  // Lê até 11 caracteres para o CPF

        printf("Digite sua senha (8 caracteres): ");
        fflush(stdin); // Limpa o buffer
        scanf("%8s", senha);  // Lê até 8 caracteres para a senha

        // Verifica as credenciais nos usuários registrados
        for (int i = 0; i < numUsuarios; i++) {
            if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
                printf("Login bem-sucedido. Bem-vindo, %s!\n", usuarios[i].tipo);
                return;  // Sai da função se o login for bem-sucedido
            }
        }
        tentativas--;
        printf("Credenciais incorretas. Tente novamente. (%d tentativas restantes)\n", tentativas);
    }

    // Encerramento do programa após três tentativas sem sucesso
    printf("Numero maximo de tentativas alcançado. Encerrando o programa.\n");
    exit(1);
}

// Função para cadastrar um produto no sistema
void cadastrarProduto() {
    struct Produto p;

    p.id = numProdutos + 1;  // Gera um novo ID automaticamente
    printf("Digite o nome do produto: ");
    fflush(stdin); // Limpa o buffer
    scanf("%49[^\n]", p.nome);  // Lê até 49 caracteres para o nome do produto

    printf("Digite o preco do produto: ");
    fflush(stdin); // Limpa o buffer
    scanf("%f", &p.preco);  // Lê o preço do produto

    printf("Digite a quantidade em estoque: ");
    fflush(stdin); // Limpa o buffer
    scanf("%d", &p.quantidade);  // Lê a quantidade em estoque

    // Adiciona o novo produto ao array de produtos
    produtos[numProdutos++] = p;
    printf("Produto cadastrado com sucesso.\n");
}

// Função para listar todos os produtos no estoque
void listarProdutos() {
    printf("----- Produtos em Estoque -----\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("ID: %d, Nome: %s, Preco: %.2f, Quantidade: %d\n",
               produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
    }
}

// Função para pesquisar um produto pelo nome
void pesquisarProduto() {
    char nome[50];
    int encontrado = 0;

    printf("Digite o nome do produto que deseja pesquisar: ");
    fflush(stdin); // Limpa o buffer
    scanf("%49[^\n]", nome);  // Lê até 49 caracteres para o nome do produto

    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].nome, nome) == 0) {
            printf("Produto encontrado - ID: %d, Nome: %s, Preco: %.2f, Quantidade: %d\n",
                   produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Produto nao encontrado.\n");
    }
}

// Função para editar um produto existente
void editarProduto() {
    int id;

    printf("Digite o ID do produto que deseja editar: ");
    fflush(stdin); // Limpa o buffer
    scanf("%d", &id);  // Lê o ID do produto

    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].id == id) {
            printf("Digite o novo nome do produto: ");
            fflush(stdin); // Limpa o buffer
            scanf("%49[^\n]", produtos[i].nome);  // Lê o novo nome do produto

            printf("Digite o novo preco do produto: ");
            fflush(stdin); // Limpa o buffer
            scanf("%f", &produtos[i].preco);  // Lê o novo preço do produto

            printf("Digite a nova quantidade em estoque: ");
            fflush(stdin); // Limpa o buffer
            scanf("%d", &produtos[i].quantidade);  // Lê a nova quantidade em estoque

            printf("Produto atualizado com sucesso.\n");
            return;
        }
    }

    printf("Produto com ID %d nao encontrado.\n", id);
}

// Menu principal com as opções do sistema
void menuPrincipal() {
    char opcao[3];  // Char para ler a opção de menu

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar Produto\n");
        printf("2. Listar Produtos\n");
        printf("3. Pesquisar Produto\n");
        printf("4. Editar Produto\n");
        printf("5. Cadastrar Usuario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        fflush(stdin); // Limpa o buffer
        scanf("%2s", opcao);  // Lê a opção do menu

        switch (opcao[0]) {
            case '1':
                cadastrarProduto();
                break;
            case '2':
                listarProdutos();
                break;
            case '3':
                pesquisarProduto();
                break;
            case '4':
                editarProduto();
                break;
            case '5':
                cadastrarUsuario();
                break;
            case '0':
                printf("Saindo...\n");
                return;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

// Função principal que executa o sistema
int main() {
    // Criação de um usuário inicial com perfil de gerente
    strcpy(usuarios[0].cpf, "00000000000"); // CPF deve ter 11 dígitos
    strcpy(usuarios[0].senha, "12345678");   // Senha deve ter 8 caracteres
    strcpy(usuarios[0].tipo, "Gerente");
    numUsuarios = 1;  // Define que já existe um usuário

    // Chama a função de login antes de exibir o menu principal
    loginUsuario();

    // Exibe o menu principal após o login bem-sucedido
    menuPrincipal();

    return 0;
}
