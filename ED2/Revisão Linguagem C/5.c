//Idade em Dias: https://judge.beecrowd.com/pt/problems/view/1020
//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>

int main()
{
    int D, M, A;
    scanf("%d", &D);
    A = D / 365;
    D %= 365;
    M = D / 30;
    D %= 30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", A, M, D);
}