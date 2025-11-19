#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#include "atsp.h"

void resolverATSP(int n, double **custo)
{
    int *cidadesVisitadas = (int *)malloc(n * sizeof(int));
    int cidadeAtual = 0;
    int *tour = (int *)malloc(n * sizeof(int));
    double custoTotal = 0;

    for (int i = 0; i < n; i++)
    {
        tour[i] = -1;
        cidadesVisitadas[i] = 0;
    }
    tour[0] = cidadeAtual;
    cidadesVisitadas[cidadeAtual] = 1;

    for (int i = 1; i < n; i++)
    {
        int proximaCidade = encontrarMinimo(n, custo, cidadeAtual, cidadesVisitadas); /* cidade menor distância */
        tour[i] = proximaCidade; 
        cidadesVisitadas[proximaCidade] = 1;
        custoTotal += custo[cidadeAtual][proximaCidade];
        cidadeAtual = proximaCidade; 
    }
    custoTotal += custo[cidadeAtual][0]; /* retorna ao inicial */

    printf("Tour final:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d -> ", tour[i]);
    }
    printf("0\n");
    printf("Custo final: %.2f\n", custoTotal);

    free(cidadesVisitadas);
    free(tour);
}

int encontrarMinimo(int n, double **custo, int u, int cidadesVisitadas[])
{
    double minimo = DBL_MAX; /* maior valor possível*/
    int indiceMinimo = -1; 

    for (int v = 0; v < n; v++)
    {
        if (!cidadesVisitadas[v] && custo[u][v] < minimo) 
        {
            minimo = custo[u][v]; 
            indiceMinimo = v; 
        }
    }
    return indiceMinimo;
}
