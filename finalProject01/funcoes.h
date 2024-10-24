//
// Created by Manara on 23/10/2024.
//

#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_PRODUTOS 100  // Define o número máximo de produtos no estoque
#define TAMANHO_NOME 50   // Define o tamanho máximo do nome do produto

// Estrutura para armazenar informações sobre o produto
typedef struct {
    int id;                  // ID do produto
    char nome[TAMANHO_NOME];  // Nome do produto
    float preco;              // Preço do produto
    int quantidade;           // Quantidade em estoque
} Produto;

int ler_inteiro();
float ler_float();
void adicionar_produto(Produto *produtos, int *total_produtos);
void listar_produtos(Produto *produtos, int total_produtos);
void editar_produto(Produto *produtos, int total_produtos);
void salvar_estoque(Produto *produtos, int total_produtos);
void carregar_estoque(Produto *produtos, int *total_produtos);

#endif //FUNCOES_H
