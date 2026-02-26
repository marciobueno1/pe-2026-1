#include <stdio.h>

int main() {
    int idade, qtdPessoas = 0, soma = 0;
    double media;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    while (idade >= 0) {
        qtdPessoas += 1;
        soma += idade;
        printf("Digite sua idade (<0 p/ finalizar): ");
        scanf("%d", &idade);
    }
    if (qtdPessoas != 0) {
        media = (double) soma / (double) qtdPessoas;
        printf("A média de idade dos participantes é de %.2lf anos\n", media);
    } else {
        printf("Nenhuma idade válida foi digitada!\n");
    }
    return 0;
}