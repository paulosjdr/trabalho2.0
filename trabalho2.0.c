#include <stdio.h>
#include <locale.h>

    const char *unidades[] = {
    "zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"
    };
    const char *onze_a_dezenove[] = {
    "onze", "doze", "treze", "catorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"
    };
    const char *dezenas[] = {
    "", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"
    };
    const char *centenas[] = {
    "", "cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"
    };

    void print_extenso(int numero){

    if (numero < 0 || numero > 10000) {
        printf("Número inválido\n");
        return;
    }

    if (numero == 0) {
        printf("zero\n");
        return;
    }

    if (numero >= 1000) {
        int milhar = numero / 1000;
        printf("%s mil ", unidades[milhar]);
        numero %= 1000;
    }

    if (numero >= 100) {
        int centena = numero / 100;
        printf("%s ", centenas[centena]);
        numero %= 100;
    }

    if (numero >= 20) {
        int dezena = numero / 10;
        printf("%s ", dezenas[dezena]);
        numero %= 10;
    }

    if (numero >= 11 && numero <= 19) {
        printf("%s\n", onze_a_dezenove[numero - 11]);
    } else if (numero >= 1 && numero <= 9) {
        printf("%s\n", unidades[numero]);
    } else {
        printf("\n");
    }
}

int main()
{

    setlocale(LC_ALL, "");

    int numero;

    printf("Digite um número entre 1 e 10000: ");
    scanf("%d", &numero);

    print_extenso(numero);

    return 0;

}
