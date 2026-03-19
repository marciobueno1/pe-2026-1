#include <stdio.h>
#include <string.h>

#define TAM_MSG 50

void lerStr(char str[], int tam);

int main() {
    char mensagem[TAM_MSG] = "Mensagem aos alunos!";
    printf("Essa é a mensagem: %s\n\n", mensagem);
    printf("Digite uma mensagem (insegura): ");
    scanf("%[^\n]", mensagem); // versão não segura de digitação
    printf("\nEssa é a mensagem digitada '%s'\n\n\n", mensagem);
    printf("Digite uma mensagem (segura): ");
    lerStr(mensagem, TAM_MSG); // apenas para ler o ENTER da digitação anterior
    lerStr(mensagem, TAM_MSG);
    printf("\nEssa é a mensagem digitada '%s'\n\n", mensagem);
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

int meuStrLen(char str[]) {
    int tam = 0;
    while (str[tam] != '\0') {
        tam += 1;
    }
    return tam;
}

void meuStrCpy(char strDest[], char strOrig[]) {
    int tam = meuStrLen(strOrig);
    for (int i = 0; i < tam; i += 1) {
        strDest[i] = strOrig[i];
    }
    strDest[tam] = '\0';
}