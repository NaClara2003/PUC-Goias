//Comparação de substrings: https://judge.beecrowd.com/pt/problems/view/1237
//Ana Clara Nery e Mello Figueiredo
#include <stdio.h>
#include <string.h>

#define MAX 55

static void strip_eol(char *s) {
    size_t n = strlen(s);
    while (n > 0 && (s[n-1] == '\n' || s[n-1] == '\r')) {
        s[--n] = '\0';
    }
}

int main(void) {
    char a[MAX], b[MAX];

    while (fgets(a, sizeof a, stdin) && fgets(b, sizeof b, stdin)) {
        strip_eol(a);
        strip_eol(b);

        int n = strlen(a);
        int m = strlen(b);
        int dp[MAX][MAX] = {{0}};
        int maxLen = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    if (dp[i][j] > maxLen) maxLen = dp[i][j];
                } else {
                    dp[i][j] = 0; // substring quebra aqui
                }
            }
        }

        printf("%d\n", maxLen);
    }
    return 0;
}
