/*Em uma loja de eletrodomésticos, os funcionários da seção de TVs recebem,
mensalmente um salário fixo mais comissão. Essa comissão é calculada em relação
ao tipo e número de televisores vendidos, de acordo com a tabela abaixo:
Tipo                    Quantidade vendida                    Comissões
  8K                        10 ou mais                  R$ 25 por TV vendida
						   menos que 10                 R$ 10 por TV vendida
  4K                        10 ou mais                  R$ 15 por TV vendida
						   menos que 10                 R$ 5 por TV vendida
Sabe-se ainda, que ele tem um desconto de 8% do salário total para pagamento do
INSS e se o seu salário for superior à R$950,00 ele ainda tem um desconto de 5% do
salário para fins de imposto de renda. Faça um programa que leia os dados de vários
funcionários e:
a. Para cada funcionário, calcule o salário líquido (já com os descontos).
b. Imprima o número de funcionários.
c. Imprima o total de salários pagos.
d. Imprima o média das comissões.
e. Imprima o valor da maior e menor comissão paga pelo departamento. */
//Realizada por: Bruna Andrade;

#pragma warning (disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define COMISSAO_TV_8K_10_OU_MAIS_VENDIDAS 25
#define COMISSAO_TV_8K_MENOS_DE_10_VENDIDAS 10
#define COMISSAO_TV_4K_10_OU_MAIS_VENDIDAS 15
#define COMISSAO_TV_4K_MENOS_DE_10_VENDIDAS 5
#define DESCONTO_INSS 0.08
#define IMPOSTO_RENDA 0.05 

void main() {
	int funcionarios = 0, i = 0, sair = 0, quantidade_tv_8k, quantidade_tv_4k, comissao_8k, comissao_4k, comissao_total, total_comissoes = 0;
	float menor_comissao = 0, maior_comissao = 0;
	float salario, salario_total, salario_liquido, total_salarios = 0;

	do {
	    funcionarios += 1;
		system("cls");
		do {
			printf("\nDigite qual o salario do funcionario %d: ", funcionarios);
			scanf("%f", &salario);
			if (salario <= 0)
				printf("Valor invalido!");
		} while (salario <= 0);

		do {
			printf("\nQuantas televisoes 8k foram vendidas por esse funcionario?  ");
			scanf("%d", &quantidade_tv_8k);
			if (quantidade_tv_8k < 0)
				printf("Valor invalido!");
		} while (quantidade_tv_8k < 0);

		if (quantidade_tv_8k >= 10) 
			comissao_8k = quantidade_tv_8k * COMISSAO_TV_8K_10_OU_MAIS_VENDIDAS;
		else 
			comissao_8k = quantidade_tv_8k * COMISSAO_TV_8K_MENOS_DE_10_VENDIDAS;
		
		do {
			printf("\nQuantas televisoes 4k foram vendidas por esse funcionario?  ");
			scanf("%d", &quantidade_tv_4k);
			if (quantidade_tv_4k < 0)
				printf("Valor invalido!");
		} while (quantidade_tv_4k < 0);

		if (quantidade_tv_4k >= 10)
			comissao_4k = quantidade_tv_4k * COMISSAO_TV_4K_10_OU_MAIS_VENDIDAS;
		else
			comissao_4k = quantidade_tv_4k * COMISSAO_TV_4K_MENOS_DE_10_VENDIDAS;

		comissao_total = comissao_4k + comissao_8k;

		if (maior_comissao == 0)
			maior_comissao = comissao_total;
		if (menor_comissao == 0)
			menor_comissao = comissao_total;
		
		if (comissao_total > maior_comissao)
			maior_comissao = comissao_total;

		if (comissao_total < menor_comissao)
			menor_comissao = comissao_total;

		salario_total = salario + comissao_4k + comissao_8k;

		if (salario <= 950)
			salario_liquido = salario_total - (salario_total * DESCONTO_INSS);
		else 
			salario_liquido = salario_total - (salario_total * DESCONTO_INSS) - (salario_total * IMPOSTO_RENDA);
        
		printf("++++    O salario do funcionario %d eh: %.2f    ++++\n\n", i, salario_liquido);
        total_comissoes += comissao_total;
		total_salarios += salario_liquido;
		getch();
		
		do {
			printf("\n Deseja cadastrar um novo funcionário?\n (0) Sim \n (1) Não \n Sua resposta: ");
			scanf("%d", &sair);
			if (sair < 0 || sair > 1)
				printf("Valor invalido!");
		} while (sair < 0 || sair > 1);
	} while (sair == 0);

	system("cls");
	printf("\n O numero de Funcionarios cadastrado foi: %d\n", funcionarios);
	printf("\n O salario total dos funcionarios foi de:R$ %.2f\n", total_salarios);
	printf("\n A media de comissoes foi dei: R$ %.2f\n", (float)(total_comissoes / funcionarios) );
	printf("\n A menor comissao foi de:R$ %.2f\n ", menor_comissao);
	printf("\n A maior comissao foi de:R$ %.2f\n\n", maior_comissao);
	system("pause");
}
//Revisada por: Ana Clara e Bruna Andrade;