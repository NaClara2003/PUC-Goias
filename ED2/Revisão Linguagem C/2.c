//Média 1: https://judge.beecrowd.com/pt/problems/view/1005
//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>

int main() {
    float A, B, M;
    scanf("%f %f", &A, &B);
    M = (A * 3.5 + B * 7.5) / 11;
    printf("MEDIA = %.5f\n", M);
}