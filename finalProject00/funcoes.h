#ifndef FUNCOES_H
#define FUNCOES_H

#define MAX_PRODUTOS 100  // Define o número máximo de produtos no estoque

// Estrutura para representar um produto
typedef struct {
    int id;               // ID único do produto
    char nome[50];        // Nome do produto
    float preco;          // Preço do produto
    int quantidade;       // Quantidade do produto no estoque
} Produto;  // 'Produto' é um nome alternativo para a struct que guarda as informações de um produto

void adicionar_produto(Produto *produtos, int *total_produtos);
void atualizar_produto(Produto *produtos, int total_produtos);
void listar_estoque(Produto *produtos, int total_produtos);
void salvar_estoque(Produto *produtos, int total_produtos);
void carregar_estoque(Produto *produtos, int *total_produtos);

#endif //FUNCOES_H
