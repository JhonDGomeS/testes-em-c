#include <stdio.h>

double valores(int base, int expo) {

	double result = 0;
//possibilidades de entradas
//expoente maior que zero e base diferente de zero
//executa o calculo multiplicando a base por ela mesma diminuindo um no expoente enquanto o expoente é maior que zero
	if (expo > 0 && base != 0) {
		while (expo > 0) {
			result = base * base;
			expo = expo - 1;
			while (expo > 0) {
				result = result * base;
				expo = expo - 1;
			}
		}
//resultado divide pela base por multiplicar uma vez a mais durante o processo
		result = result / base;
	}
	
//se o expoente for 0 e a base diferente de zero, resultado = 1
	else if (expo == 0 && base != 0) {
		result = 1;
	}

//se o expoente for 0 e a base for 0, temos uma indeterminação matemática mas aproxima-se o valor do resultado a 1
	else if (expo == 0 && base == 0) {
		result = 0.0000000000000001 / 0.0000000000000001;
	}
//se o expoente for menor que zero e a base diferente de zero, multiplica o expoente por -1 para e calcula o resultado como 1/resultado
	else if (expo < 0 && base != 0) {
		int expop = expo * -1;
		result = valores(base, expop);

		result = 1 / result;
	}

	return result;
}

int main() {

	int base;
	int expo;

	double result;
//digitação dos valores base e expoente
	printf("Insira uma base: ");
	scanf("%d", &base);

	printf("Insira um expoente: ");
	scanf("%d", &expo);
//calculo do resultado seguindo os padrões estabelecidos em double valores()
	result = valores(base, expo);
//resultado com 4 casas decimais
	printf("O resultado de %d^%d é: %.4f\n", base, expo, result);

	return 0;
}
