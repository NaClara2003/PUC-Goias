//Desafio de Bino: https://judge.beecrowd.com/pt/problems/view/2060
//Ana Clara Nery e Mello Figuereido
#include <stdio.h>

int main()
{
    int N,V,C2=0,C3=0,C4=0,C5=0;
    scanf("%d",&N);
    for (int i=0;i<N;i++){
        scanf("%d",&V);
        if (V%2==0){
            C2++;
        }if (V%3==0){
            C3++;
        }if (V%4==0){
            C4++;
        }if (V%5==0){
            C5++;
        }
    }

    printf("%d Multiplo(s) de 2\n%d Multiplo(s) de 3\n%d Multiplo(s) de 4\n%d Multiplo(s) de 5\n",C2,C3,C4,C5);
    
    return 0;
}
