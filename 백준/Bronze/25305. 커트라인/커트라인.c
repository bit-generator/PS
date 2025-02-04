#include <stdio.h>
#include <stdlib.h>

int N, k;
int arr[1000];

int compare(const void* a, const void* b) {
    if(*(int*)a > *(int*)b) return -1;
    else if(*(int*)a == *(int*)b) return 0;
    else return 1;
}

int main() {
    scanf("%d %d", &N, &k);
    for(int i = 0; i < N; ++i) scanf("%d", &arr[i]);
    
    qsort(arr, N, sizeof(int), compare);
    printf("%d", arr[k - 1]);
    return 0;
}