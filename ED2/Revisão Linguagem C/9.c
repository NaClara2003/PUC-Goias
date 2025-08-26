//Quadrado e ao Cubo: https://judge.beecrowd.com/pt/problems/view/1143
//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>

int main()
{
    int n, i, q, c;
    scanf("%d", &n);
    for(i = 1; i <= n; i++)
    {
        q = pow(i, 2);
        c = pow (i, 3);
        printf("%d %d %d\n", i, q, c);
    }
}