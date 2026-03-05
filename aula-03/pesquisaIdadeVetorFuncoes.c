#include <stdio.h>

#define MIN_QTD 2
#define MAX_QTD 3
#define MIN_IDADE 0
#define MAX_IDADE 130

double calcularMedia(int v[], int n);
void imprimirMaiorIgualMedia(int v[], int n, double media);
void preencherIdadesDigitacao(int v[], int n);
int buscaSequencial(int v[], int n, int x);
void buscarIdades(int v[], int n);
void imprimir(int v[], int n);
int inserirIdades(int v[], int n, int max);
void inserir(int v[], int n, int pos, int x);

int main() {
    int idades[MAX_QTD];
    int tam;
    double media;
    do {
        printf("Digite a quantidade de participantes (%d-%d): ", MIN_QTD, MAX_QTD);
        scanf("%d", &tam);
    } while (tam < MIN_QTD || tam > MAX_QTD);
    preencherIdadesDigitacao(idades, tam);
    media = calcularMedia(idades, tam);
    printf("A média de idade dos participantes é de %.2lf anos\n", media);
    imprimirMaiorIgualMedia(idades, tam, media);
    buscarIdades(idades, tam);
    tam = inserirIdades(idades, tam, MAX_QTD);
    printf("Vetor final = ");
    imprimir(idades, tam);
    return 0;
}

double calcularMedia(int v[], int n) {
    int soma;
    for (int i = 0; i < n; i += 1) {
        soma += v[i];
    }
    return (double) soma / (double) n;
}

void imprimirMaiorIgualMedia(int v[], int n, double media) {
    printf("\n\nAs idades maiores ou iguais a média são\n");
    for (int i = 0; i < n; i += 1) {
        if (v[i] >= media) {
            printf("idade do %dº participiante: %d\n", i + 1, v[i]);
        }
    }
}

void preencherIdadesDigitacao(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        do {
            printf("Digite a idade do %dº participante (%d-%d): ", i + 1, MIN_IDADE, MAX_IDADE);
            scanf("%d", &v[i]);
        } while (v[i] < MIN_IDADE || v[i] > MAX_IDADE);
    }
}

// retorna o índice de onde achou ou -1 caso não encontre
int buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

void buscarIdades(int v[], int n) {
    int idade, pos;
    printf("Digite uma idade a ser buscada: ");
    scanf("%d", &idade);
    while (idade >= 0) {
        pos = buscaSequencial(v, n, idade);
        if (pos != -1) {
            printf("Encontrou a idade %d na posição %d\n", idade, pos + 1);
        } else {
            printf("A idade %d não se encontra no vetor\n", idade);
        }
        printf("Digite uma idade a ser buscada (< 0 p/ finalizar): ");
        scanf("%d", &idade);
    }
}

void inserir(int v[], int n, int pos, int x) {
    for (int i = n - 1; i >= pos; i -= 1) {
        v[i + 1] = v[i];
    }
    v[pos] = x;
}

int inserirIdades(int v[], int n, int max) {
    int idade, pos, tam = n;
    char opcao;
    do {
        if (tam >= max) {
            printf("\nVetor está cheio!\n");
            return tam;
        }
        imprimir(v, tam);
        do {
            printf("Digite uma idade a ser inserida (%d-%d): ", MIN_IDADE, MAX_IDADE);
            scanf("%d", &idade);
        } while (idade < MIN_IDADE || idade > MAX_IDADE);
        do {
            printf("Digite a posição em que esta idade deve ser inserida (1-%d): ", tam + 1);
            scanf("%d", &pos);
        } while (pos < 1 || pos > tam + 1);
        inserir(v, tam, pos - 1, idade);
        tam += 1;
        imprimir(v, tam);
        printf("\nVocê quer inserir outra idade (s/n)? ");
        scanf("%c", &opcao); // essa leitura irá ler o ENTER da digitação anterior e deve ser descartado
        scanf("%c", &opcao);
    } while (opcao == 's' || opcao == 'S');
    return tam;
}

void imprimir(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("%d  ", v[i]);
    }
    printf("\n");
}