#include <stdio.h>
#define N 4
#define M 5

int f,c;
double mt[N][M];

int main()
{
    for(f = 0;f<N; f++)
    { 
        for(c = 0;c<M; c++)
        {
            printf("%lf   ", mt[f][c]);
        }
        printf("\n");
    }
    getchar();
    return 0;
}