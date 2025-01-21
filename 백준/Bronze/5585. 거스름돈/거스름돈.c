#include <stdio.h>

int N, ans;
int charge[6] = {500, 100, 50, 10, 5, 1};

int main() {
    scanf("%d", &N);
    
    N = 1000 - N;
    for(int i = 0; i < 6 && N > 0; ++i) {
        ans += N / charge[i];
        N %= charge[i];
    }
    
    printf("%d", ans);
    return 0;
}