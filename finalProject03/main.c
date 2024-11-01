#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100
#define TAM_CPF 12  // 11 dígitos + 1 para '\0'
#define TAM_SENHA 9 // 8 dígitos + 1 para '\0'

// Estrutura para armazenar informações do usuário
typedef struct {
    char cpf[TAM_CPF];
    char senha[TAM_SENHA];
} Usuario;

// Função para validar CPF e senha
int validarDados(const char* cpf, const char* senha) {
    if (strlen(cpf) != 11 || strlen(senha) != 8) {
        printf("CPF deve ter 11 dígitos e senha 8 caracteres.\n");
        return 0; // Dados inválidos
    }
    return 1; // Dados válidos
}

// Função para carregar usuários do arquivo
int carregarUsuarios(Usuario* usuarios) {
    FILE* file = fopen("H:\\ACADEMIC\\CODES\\C\\Gerenciamento_Estoque_C\\finalProject03\\usuarios.txt", "r");
    if (!file) {
        return 0; // Retorna 0 se o arquivo não existir
    }

    int count = 0;
    while (fscanf(file, "%s %s", usuarios[count].cpf, usuarios[count].senha) == 2) {
        count++;
    }
    fclose(file);
    return count; // Retorna o número de usuários carregados
}

// Função para salvar usuários no arquivo
void salvarUsuarios(Usuario* usuarios, int numUsuarios) {
    FILE* file = fopen("H:\\ACADEMIC\\CODES\\C\\Gerenciamento_Estoque_C\\finalProject03\\usuarios.txt", "w");
    if (!file) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numUsuarios; i++) {
        fprintf(file, "%s %s\n", usuarios[i].cpf, usuarios[i].senha);
    }
    fclose(file);
}

// Função para realizar o login
int login(Usuario* usuarios, int numUsuarios) {
    char cpf[TAM_CPF], senha[TAM_SENHA];
    printf("Digite seu CPF (11 dígitos): ");
    scanf("%s", cpf);
    printf("Digite sua senha (8 caracteres): ");
    scanf("%s", senha);

    // Validação de dados
    if (!validarDados(cpf, senha)) {
        return 0; // Dados inválidos
    }

    // Verifica se o usuário existe
    for (int i = 0; i < numUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login bem-sucedido. Bem-vindo!\n");
            return 1; // Login bem-sucedido
        }
    }
    printf("Credenciais incorretas.\n");
    return 0; // Login falhou
}

// Função para cadastrar novo usuário
void cadastrarUsuario(Usuario* usuarios, int* numUsuarios) {
    if (*numUsuarios >= MAX_USUARIOS) {
        printf("Limite de usuários alcançado.\n");
        return;
    }

    char cpf[TAM_CPF], senha[TAM_SENHA];
    printf("Digite seu CPF (11 dígitos): ");
    scanf("%s", cpf);
    printf("Digite sua senha (8 caracteres): ");
    scanf("%s", senha);

    // Validação de dados
    if (!validarDados(cpf, senha)) {
        return; // Dados inválidos
    }

    // Verifica se o CPF já está cadastrado
    for (int i = 0; i < *numUsuarios; i++) {
        if (strcmp(usuarios[i].cpf, cpf) == 0) {
            printf("CPF já cadastrado.\n");
            return;
        }
    }

    // Cadastra novo usuário
    strcpy(usuarios[*numUsuarios].cpf, cpf);
    strcpy(usuarios[*numUsuarios].senha, senha);
    (*numUsuarios)++;
    salvarUsuarios(usuarios, *numUsuarios); // Salva usuários atualizados
    printf("Usuário cadastrado com sucesso!\n");
}

// Função principal
int main() {
    Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = carregarUsuarios(usuarios); // Carrega usuários do arquivo

    int opcao;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Login\n");
        printf("2. Cadastrar Usuário\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                login(usuarios, numUsuarios);
                break;
            case 2:
                cadastrarUsuario(usuarios, &numUsuarios);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
