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
void produtos(){
    float sanduiche = 12.00, refrigerante = 6.00, suco = 8.00, salgado = 7.00, cafe = 4.00;
    printf("Sanduíche: %.2f\n", sanduiche);
    printf("Refrigerante: %.2f\n", refrigerante);
    printf("Suco: %.2f\n", suco);
    printf("Salgado: %.2f\n", salgado);
    printf("Café: %.2f\n", cafe);
}
void pedido(){
    char nome_cliente[50];
    
    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome_cliente);

    produtos();
    carrinho(nome, precos, &totalItens, &valor);
}
void calculadora(){
    float num1, num2;
    int opcao_calc;

    printf("\n=== Calculadora ===\n");
    printf("1- Somar\n");
    printf("2- Subtrair\n");
    printf("3- Multiplicar\n");
    printf("4- Dividir\n");
    printf("0- Voltar")
    
    printf("Digite sua opção: \n");
    scanf("%d", &opcao_calc);
    if (opcao_calc < 0 || opcao_calc > 4)
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
    char nome[MAX_PRODUTOS][50];
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