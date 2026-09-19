#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 50
void menu(void){
    printf("\n========================");
    printf("\n===== Cantina UCB ======\n");
    printf("========================\n");
    printf("\n1 - Novo pedido");
    printf("\n2 - Calculadora");
    printf("\n3 - Simular desconto");
    printf("\n4 - Relatório da sessão");
    printf("\n0 - Sair");
}
void carrinho(char nome[][50], float precos[], int *totalItens, float *valor){
    if(*totalItens >= MAX_PRODUTOS){
        printf("Carrinho Cheio!");
        return;
    }
    else{
        printf("Nome do produto: ");
        scanf(" %[^\n]", nome[*totalItens]);
        printf("Preço: ");
        scanf("%f", &precos[*totalItens]);

        *valor += precos[*totalItens];
        (*totalItens)++;
    }
}
void produtos(void){
    float sanduiche = 12.00, refrigerante = 6.00, suco = 8.00, salgado = 7.00, cafe = 4.00;
    printf("Sanduíche: %f", sanduiche);
    printf("Refrigerante: %f", refrigerante);
    printf("Suco: %f", suco);
    printf("Salgado: %f", salgado);
    printf("Café: %f", cafe);
}
void pedido(void){
    char nome_cliente[50];
    printf("Digite o nome do cliente");
    fgets(nome_cliente, 49, stdin);
    produtos();
    printf("Qual produto deseja comprar? ");
    carrinho;
}
void calculadora(void){
    
}
int main(){
    int opcao;
    char nome[MAX_PRODUTOS][50];
    float precos[MAX_PRODUTOS];
    int totalItens = 0;
    float valor = 0.0;

    menu();
    printf("\nDigite uma opção: ");
    scanf("%d", &opcao);
}