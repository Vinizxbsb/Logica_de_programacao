#include <stdio.h>
#include <string.h>

int totalPedidos = 0;
int totalItens = 0;
float faturamentoBruto = 0.0;
float descontosConcedidos = 0.0;
float faturamentoFinal = 0.0;

void menu(void){
    printf("\n========================");
    printf("\n===== Cantina UCB ======\n");
    printf("========================\n");
    printf("1 - Novo pedido\n");
    printf("2 - Calculadora\n");
    printf("3 - Simular desconto\n");
    printf("4 - Relatorio da sessao\n");
    printf("0 - Sair\n");
}

void cardapio(){
    printf("\n1- Sanduiche: R$12.00\n");
    printf("2- Refrigerante: R$6.00\n");
    printf("3- Suco: R$8.00\n");
    printf("4- Salgado: R$7.00\n");
    printf("5- Cafe: R$4.00\n");
}


float calcularDesconto(float total) {
    if (total >= 100) return total * 0.15;
    else if (total >= 60) return total * 0.10;
    else if (total >= 30) return total * 0.05;
    return 0.0;
}

void pedido(){
    char nome_cliente[50];
    int opcao_cardapio, quantidade, continuar;
    float subtotalBruto = 0.0;
    int itensDestePedido = 0;
    
    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", nome_cliente);

    do {
        cardapio();
        printf("Digite a opcao do cardapio (1 a 5): ");
        scanf("%d", &opcao_cardapio);
        
        if (opcao_cardapio < 1 || opcao_cardapio > 5) {
            printf("Codigo invalido! Tente novamente.\n");
            continue;
        }

        printf("Digite a quantidade desejada: ");    
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf("Quantidade invalida! Deve ser maior que zero.\n");
            continue;
        }

        itensDestePedido += quantidade;

        switch (opcao_cardapio) {
            case 1: subtotalBruto += 12.00 * quantidade; break;
            case 2: subtotalBruto += 6.00 * quantidade; break;
            case 3: subtotalBruto += 8.00 * quantidade; break;
            case 4: subtotalBruto += 7.00 * quantidade; break;
            case 5: subtotalBruto += 4.00 * quantidade; break;
        }

        printf("Adicionar outro item? (1 - Sim || 0 - Nao): ");
        scanf("%d", &continuar);
    } while(continuar != 0);

    // Cálculos e Saída do Pedido
    float descontoPedido = calcularDesconto(subtotalBruto);
    float totalFinalPedido = subtotalBruto - descontoPedido;

    printf("\n======= RESUMO DO PEDIDO =======\n");
    printf("Cliente: %s\n", nome_cliente);
    printf("Itens registrados: %d\n", itensDestePedido);
    printf("Total bruto: R$ %.2f\n", subtotalBruto);
    printf("Desconto:    R$ %.2f\n", descontoPedido);
    printf("Total final: R$ %.2f\n", totalFinalPedido);
    printf("================================\n");
    printf("Pedido finalizado com sucesso!\n");

    
    totalPedidos++;
    totalItens += itensDestePedido;
    faturamentoBruto += subtotalBruto;
    descontosConcedidos += descontoPedido;
    faturamentoFinal += totalFinalPedido;
}

void calculadora(){
    float num1, num2;
    int opcao_calc;

    printf("\n=== Calculadora ===\n");
    printf("1- Somar\n");
    printf("2- Subtrair\n");
    printf("3- Multiplicar\n");
    printf("4- Dividir\n");
    printf("0- Voltar\n");
    
    printf("Digite sua opcao: ");
    scanf("%d", &opcao_calc);
    
    if (opcao_calc == 0) {
        printf("Voltando...\n");
        return; 
    }
    
    if (opcao_calc < 1 || opcao_calc > 4){
        printf("Digite uma opcao valida!\n");
        return;
    }

    printf("Digite o primeiro numero: ");
    scanf("%f", &num1);
    printf("Digite o segundo numero: ");
    scanf("%f", &num2);
    
    switch(opcao_calc) {
        case 1: printf("Resultado: %.2f\n", num1 + num2); break;
        case 2: printf("Resultado: %.2f\n", num1 - num2); break;
        case 3: printf("Resultado: %.2f\n", num1 * num2); break;
        case 4:
            if(num2 == 0) printf("Nao e possivel dividir por zero!\n");
            else printf("Resultado: %.2f\n", num1 / num2);
            break;
    }
}

void simuladorDesconto(){
    float valorTotal;

    printf("\n=== Simular desconto ===\n");
    printf("Digite o valor total da compra: ");
    scanf("%f", &valorTotal);

    if (valorTotal <= 0){
        printf("Valor invalido!\n");
        return;
    }
    
    
    float valorDesconto = calcularDesconto(valorTotal);
    float valorFinal = valorTotal - valorDesconto;

    printf("Valor do desconto: R$ %.2f\n", valorDesconto);
    printf("Valor final: R$ %.2f\n", valorFinal);
}

void relatorio(){
    printf("\n======= RELATORIO DA SESSAO =======\n");
    printf("Total de pedidos realizados: %d\n", totalPedidos);
    printf("Total de itens vendidos: %d\n", totalItens);
    printf("Faturamento Bruto: R$ %.2f\n", faturamentoBruto);
    printf("Desconto concedido: R$ %.2f\n", descontosConcedidos);
    printf("Faturamento Final: R$ %.2f\n", faturamentoFinal);
    printf("===================================\n");
}

int main(void) {
    int opcao;

    do {
        menu();
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: pedido(); break;
            case 2: calculadora(); break;
            case 3: simuladorDesconto(); break;
            case 4: relatorio(); break;
            case 0: printf("Encerrando o sistema...\n"); break;
            default: printf("Opcao invalida! Tente novamente.\n"); break;
        }
    } while(opcao != 0);

    return 0;
}