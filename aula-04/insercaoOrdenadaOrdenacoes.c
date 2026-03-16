#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 10

void imprimir(double v[], int n);
void inserirOrdenado(double v[], int n, double x);
void insercaoDireta (double v[], int n);
void selecaoDireta (double v[], int n);
void preencherOrdenadoDigitacao(double v[], int n);
void preencherAleatorio(double v[], int n);

int main() {
    double numeros[MAX_TAM];
    srand(9);
    //preencherOrdenadoDigitacao(numeros, MAX_TAM);
    preencherAleatorio(numeros, MAX_TAM);
    printf("      Vetor sem ordenação: ");
    imprimir(numeros, MAX_TAM);
    insercaoDireta(numeros, MAX_TAM);
    printf("Vetor com inserção direta: ");
    imprimir(numeros, MAX_TAM);
    printf("\n-------------------------------\n\n");
    preencherAleatorio(numeros, MAX_TAM);
    printf("      Vetor sem ordenação: ");
    imprimir(numeros, MAX_TAM);
    selecaoDireta(numeros, MAX_TAM);
    printf(" Vetor com seleção direta: ");
    imprimir(numeros, MAX_TAM);
    return 0;
}

void preencherAleatorio(double v[], int n) {
    for (int i = 0; i < n; i += 1) {
        v[i] = (rand() % 1000) / 100.0;
    }
}

void preencherOrdenadoDigitacao(double v[], int n) {
    double num;
    for (int i = 0; i < n; i += 1) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%lf", &num);
        inserirOrdenado(v, i, num);
        printf("Vetor: ");
        imprimir(v, i + 1);
    }
}

void imprimir(double v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("%.2lf  ", v[i]);
    }
    printf("\n");
}

// inserir o valor x de forma ordenada no vetor atual de 
// tamanho n e que possui pelo menos um espaço livre no vetor
void inserirOrdenado(double v[], int n, double x) {
    int pos = n;
    while (pos > 0 && v[pos - 1] > x) {
        v[pos] = v[pos - 1];
        pos -= 1;
    }
    v[pos] = x;
}

void insercaoDireta (double v[], int n) {
    int i, j;
    double chave;
    for (i = 1; i <= n - 1; i += 1) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = chave;
    }
}

void selecaoDireta (double v[], int n) {
    int i, j, menor;
    double aux;
    for (i = 0; i < n - 1; i += 1) {
        menor = i;
        for (j = i + 1; j <= n - 1 ; j += 1) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void bubblesort (double v[], int n) {
    int i, fim, pos, troca;
    double chave;
    troca = 1; fim = n - 2; pos = 0;
    while (troca == 1) {
        troca = 0;
        for (i = 0; i <= fim; i++) {
            if (v[i] > v[i+1]) {
                chave = v[i]; v[i] = v[i+1]; v[i+1] = chave;
                pos = i; troca = 1;
            }
        }
        fim = pos-1;
    }
}

int buscaBinaria (double v[], int n, double chave) {
    int inicio = 0, meio, fim = n - 1;

    do {
        meio = (inicio + fim) / 2;
        if (v[meio] > chave) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    } while (chave != v[meio] && inicio <= fim);
    
    if (chave == v[meio]) {
        return meio; // retorna a posição
    } else {
        return -1; // não achou
    }
}