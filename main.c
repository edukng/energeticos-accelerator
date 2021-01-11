/*
 Eduardo da Rosa Kolling

 Como sugestão da questão bônus, incluí um desconto de 10% em pedidos de cargas fechadas acima de 1000 unidades.
 O desconto é aplicado de forma automática sobre o valor do produto de R$4,50.

 */

#include <stdio.h>

#define MAX 100

char cliente[MAX][MAX];
int quantidade_pedido[MAX], menu_cadastro = 1, cont = 0, condicao = 0;
float total_pedido[MAX];

int main() {

    printf("===SISTEMA DE VENDAS===");

    while(menu_cadastro == 1){ //loop para cadastros dos clientes e pedidos
        printf("\nNome cliente: ");
        scanf(" %[^\n]s", cliente[cont]);
        printf("Quantidade do pedido: ");
        scanf("%d", &quantidade_pedido[cont]);

        if(quantidade_pedido[cont] > 999){   //condicao para o desconto ser aplicado
            total_pedido[cont] = quantidade_pedido[cont] * 4.05;
        } else{
            total_pedido[cont] = quantidade_pedido[cont] * 4.5;
        }

        printf("Cadastrar novo pedido:\n1 - SIM \n2 - NAO\n");
        scanf("%d", &menu_cadastro);
        cont++;
    }

    printf("\n====RELATORIO FINAL====\n");

    while (condicao < cont){
        printf("\nCliente: %s", cliente[condicao]);
        printf("\nQuantidade pedido: %d", quantidade_pedido[condicao]);
        printf("\nValor Pedido: %.2f", total_pedido[condicao]);
        printf("\nTributacoes: \nICMS: %.2f \nIPI: %.2f \nPIS: %.2f \nCOFINS: %.2f", (total_pedido[condicao] * 0.18), (total_pedido[condicao] * 0.04), (total_pedido[condicao] * 0.0186), (total_pedido[condicao] * 0.0854));
        printf("\nTotal Impostos: %.2f", (total_pedido[condicao] * 0.324));
        printf("\nTotal Mercadoria: %.2f", total_pedido[condicao]);
        printf("\nTotal Geral: %.2f\n", (total_pedido[condicao] * 1.324));
        condicao++;
    }
    return(0);
}

