#include <stdio.h>
#define N 4
#define M 10

int f,c;
double mt[N][M];
int cont = 1;

int main()
{
    //Declaracion del puntero a la matriz
    double *pMt = &mt[0][0];

    //Recorrido con indice y relleno de valores de la matriz
    for(f = 0; f<N; f++)
    {
        for(c = 0; c<M; c++)
        {
            mt[f][c] = cont;
            printf("%6.2lf  ", mt[f][c]);
            cont++;
        }
        printf("\n");
    }

    printf("\n");

    //Recorrido con aritmetica de punteros
    for (f = 0; f < N; f++)
    {
        for (c = 0; c < M; c++)
        {
            printf("%6.2lf  ", *(pMt + f * M + c) );
        }
        printf("\n");
    }

    printf("\n");

    //Otro recorrido con aritmetica de punteros
    for(f = 0;f<N*M; f++)
    { 
        printf("%6.2lf  ", *(pMt) );
        pMt++;

        if( ( (f+1) % M == 0) && (f != 0) ) printf("\n");
    }
    //Reseteamos el puntero vuelve a apuntar a la matriz
    pMt = &mt[0][0];

    getchar();
    return 0;
}