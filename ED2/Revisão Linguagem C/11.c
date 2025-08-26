//Substituição em Vetor I: https://judge.beecrowd.com/pt/problems/view/1172
//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>

int main()
{
    int x[10], i;
    for(i = 0; i < 10; i++)
    {
        scanf("%d", &x[i]);
        if(x[i] <= 0)
        {
            x[i] = 1;
        }
        printf("X[%d] = %d\n", i, x[i]);
    }
}