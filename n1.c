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

void cardapio(){
    printf("\n1- Sanduíche: R$12,00\n");
    printf("2- Refrigerante: R$6,00\n");
    printf("3- Suco: R$8,00\n");
    printf("4- Salgado: R$7,00\n");
    printf("5- Café: R$4,00\n");
}
void pedido(){
    char nome_cliente[50];
    int continuar;
    int opcao_cardapio;
    
    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome_cliente);

    do{
        cardapio();

        printf("Digite a opção do cardápio: (1 a 5): \n");
        scanf("%d", &opcao_cardapio);
        
        float preco_unitario = 0.0;
        
        switch (opcao_cardapio)
        {
        case 1:
            preco_unitario = 12.00;
            break;
        case 2:
            preco_unitario = 6.00;
            break;
        case 3:
            preco_unitario = 8.00;
            break;
        case 4:
            preco_unitario = 7.00;
            break;
        case 5:
            preco_unitario = 4.00;
            break;
        default:
            printf("Produto inválido!\n");
            continue;
        }

        printf("Digite a quantidade desejada: \n");


        printf("\nDeseja continuar comprando? (1 - Sim || 2 - Não)\n");
        scanf("%d", &continuar);
    }while(continuar == 1);
    printf("Pedido de %s finalizado com sucesso!!!\n", nome_cliente);
}
void calculadora(){
    float num1, num2;
    int opcao_calc;

    printf("\n=== Calculadora ===\n");
    printf("1- Somar\n");
    printf("2- Subtrair\n");
    printf("3- Multiplicar\n");
    printf("4- Dividir\n");
    printf("0- Voltar");
    
    printf("\nDigite sua opção: \n");
    scanf("%d", &opcao_calc);
    if (opcao_calc < 0 || opcao_calc > 4){
        printf("Digite uma opção válida!");
        return;
    }

    printf("Digite o primeiro número: \n");
    scanf("%f", &num1);
    printf("Digite o segundo número; \n");
    scanf("%f", &num2);

    switch(opcao_calc)
    {
    case 1:
        float somar = num1 + num2;
        printf("Resultado; %.2f", somar);
        break;
    case 2:
        float subtrair = num1 - num2;
        printf("Resultado: %.2f", subtrair);
        break;
    case 3: 
        float multiplicar = num1 * num2;
        printf("Resultado: %.2f", multiplicar);
        break;
    case 4:
        if(num2 == 0){
            printf("Não é possivel dividir por zero!");
            break;
        }
        else{
        float dividir = num1 / num2;
        printf("Resultado: %.2f", dividir);
        break;
        }
    case 0:
        printf("Voltando...");
        break;
    default:
        printf("Digite uma opção válida!");
        break;
    }

}
int main(){
    int opcao;
    char nome_produto[MAX_PRODUTOS][50];
    float precos[MAX_PRODUTOS];
    int totalItens = 0;
    float valor = 0.0;

do{
    menu();
    printf("\nDigite uma opção: ");
    scanf("%d", &opcao);

    switch(opcao){
        case 1:
            pedido();
            break;
        case 2:
            calculadora();
            break;
        default:   
            break;
}
}while(opcao != 0);
}