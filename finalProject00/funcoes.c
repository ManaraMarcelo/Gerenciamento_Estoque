#include <stdio.h>
#include "funcoes.h"

// Função para adicionar um novo produto ao estoque
void adicionar_produto(Produto *produtos, int *total_produtos) {
    if (*total_produtos < MAX_PRODUTOS) {  // Verifica se ainda há espaço no estoque
        Produto novo_produto;  // Cria uma variável para armazenar o novo produto
        // Coleta as informações do novo produto
        printf("ID do produto: ");
        scanf("%d", &novo_produto.id);
        printf("Nome do produto: ");
        scanf(" %[^\n]s", novo_produto.nome);  // Lê o nome do produto (com espaços)
        printf("Preço do produto: ");
        scanf("%f", &novo_produto.preco);
        printf("Quantidade no estoque: ");
        scanf("%d", &novo_produto.quantidade);

        // Adiciona o novo produto ao array de produtos
        produtos[*total_produtos] = novo_produto;
        (*total_produtos)++;  // Incrementa o total de produtos cadastrados
    } else {
        printf("Estoque cheio!\n");  // Se o estoque estiver cheio, exibe mensagem de erro
    }
}

// Função para atualizar as informações de um produto existente no estoque
void atualizar_produto(Produto *produtos, int total_produtos) {
    int id, encontrado = 0;  // Variáveis para armazenar o ID procurado e se o produto foi encontrado
    printf("Digite o ID do produto a ser atualizado: ");
    scanf("%d", &id);  // Lê o ID do produto que o usuário quer atualizar

    // Percorre o array de produtos para procurar o produto com o ID fornecido
    for (int i = 0; i < total_produtos; i++) {
        if (produtos[i].id == id) {  // Se encontrar o produto
            printf("Novo preço: ");
            scanf("%f", &produtos[i].preco);  // Atualiza o preço
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);  // Atualiza a quantidade
            encontrado = 1;  // Marca que o produto foi encontrado
            break;  // Sai do loop pois já encontrou o produto
        }
    }

    if (!encontrado) {  // Se o produto não foi encontrado, exibe mensagem de erro
        printf("Produto não encontrado!\n");
    }
}

// Função para listar todos os produtos no estoque
void listar_estoque(Produto *produtos, int total_produtos) {
    // Itera sobre todos os produtos e exibe suas informações
    for (int i = 0; i < total_produtos; i++) {
        printf("ID: %d\n", produtos[i].id);
        printf("Nome: %s\n", produtos[i].nome);
        printf("Preço: %.2f\n", produtos[i].preco);
        printf("Quantidade: %d\n\n", produtos[i].quantidade);
    }
}

// Função para salvar o estoque em um arquivo
void salvar_estoque(Produto *produtos, int total_produtos) {
    FILE *arquivo = fopen("estoque.txt", "w");  // Abre o arquivo para escrita

    if (arquivo != NULL) {  // Verifica se o arquivo foi aberto corretamente
        // Grava os dados de cada produto no arquivo
        for (int i = 0; i < total_produtos; i++) {
            fprintf(arquivo, "%d %s %.2f %d\n", produtos[i].id, produtos[i].nome, produtos[i].preco, produtos[i].quantidade);
        }
        fclose(arquivo);  // Fecha o arquivo após a gravação
    } else {
        printf("Erro ao abrir o arquivo!\n");  // Se não conseguir abrir o arquivo, exibe erro
    }
}

// Função para carregar o estoque de um arquivo
void carregar_estoque(Produto *produtos, int *total_produtos) {
    FILE *arquivo = fopen("estoque.txt", "r");  // Abre o arquivo para leitura

    if (arquivo != NULL) {  // Verifica se o arquivo foi aberto corretamente
        // Lê os dados do arquivo e armazena no array de produtos
        while (fscanf(arquivo, "%d %49s %f %d", &produtos[*total_produtos].id, produtos[*total_produtos].nome, &produtos[*total_produtos].preco, &produtos[*total_produtos].quantidade) != EOF) {
            (*total_produtos)++;  // Incrementa o número total de produtos carregados
        }
        fclose(arquivo);  // Fecha o arquivo após a leitura
    } else {
        printf("Nenhum arquivo de estoque encontrado, iniciando um novo estoque.\n");  // Se não encontrar o arquivo, começa um novo estoque vazio
    }
}
