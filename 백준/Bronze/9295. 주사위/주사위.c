#include <stdio.h>

int T, a, b;

int main() {
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        scanf("%d %d", &a, &b);
        printf("Case %d: %d\n", i, a + b);
    }
    return 0;
}