#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "atsp.h"

void testeArtigo() {
    int n1 = 5;
    double **matriz1 = (double **)malloc(n1 * sizeof(double *));
    for (int i = 0; i < n1; i++) {
        matriz1[i] = (double *)malloc(n1 * sizeof(double));
        for (int j = 0; j < n1; j++) {
            matriz1[i][j] = 0.0;  
        }
    }
    double valores1[5][5] = {
        {0.0, 3.5, 9.0, 2.1, 12.0},
        {6.7, 0.0, 4.0, 13.5, 8.6},
        {11.9, 7.8, 0.0, 9.0, 2.5},
        {4.0, 12.0, 6.5, 0.0, 10.0},
        {3.0, 11.0, 5.8, 14.2, 0.0}
    };

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            matriz1[i][j] = valores1[i][j];
        }
    }

    clock_t start1 = clock();
    printf("Matriz 1:\n");
    resolverATSP(n1, matriz1);
    printf("\n");
    clock_t end1 = clock();
    double time_spent1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    printf("Tempo de processamento para matriz 5x5: %.6f segundos\n\n", time_spent1);

    for (int i = 0; i < n1; i++) {
        free(matriz1[i]);
    }
    free(matriz1);
}

void testeMatrizGrande(int N) {
    double **matriz = (double **)malloc(N * sizeof(double *));
    for (int i = 0; i < N; i++) {
        matriz[i] = (double *)malloc(N * sizeof(double));
        for (int j = 0; j < N; j++) {
            matriz[i][j] = (i == j) ? 0.0 : (double)(rand() % 100);  /* Preenche a diagonal com zero */
        }
    }

    clock_t start = clock();
    resolverATSP(N, matriz);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Tempo de processamento para matriz %dx%d: %.6f segundos\n", N, N, time_spent);

    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

int main() {
    testeArtigo();
    srand(time(NULL));
    testeMatrizGrande(10);
    testeMatrizGrande(100);
    testeMatrizGrande(1000);
    testeMatrizGrande(10000);
    /* NOTA: Meu pc não aguentou mais do que 10000 */
    return 0;
}
