#include <stdio.h>

int N, B, C;
int A[1000000];
long long ans;

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);
    scanf("%d %d", &B, &C);
    
    for(int i = 0; i < N; ++i) {
        A[i] -= B;
        ++ans;
        if(A[i] > 0) {
            ans += ((A[i] - 1) / C + 1);
        }
        
    }
    
    printf("%lld", ans);
    return 0;
}