#include <iostream>
#define MIN(X, Y)    ((X) < (Y) ? (X) : (Y))
#define MAX(X, Y)    ((X) > (Y) ? (X) : (Y))
using namespace std;

int N, M, n, a, b;
int minTree[200002];
int maxTree[200002];

void update(int i, int x) {
    minTree[i += N] = x;
    maxTree[i] = x;
    
    while(i >>= 1) {
        minTree[i] = MIN(minTree[i << 1], minTree[i << 1 | 1]);
        maxTree[i] = MAX(maxTree[i << 1], maxTree[i << 1 | 1]);
    }
}

int minQuery(int l, int r) {
    int result = 1'000'000'001;
    for(l += N, r += N; l != r; l >>= 1, r >>= 1) {
        if(l & 1) {
            result = MIN(result, minTree[l]);
            ++l;
        }
        
        if(r & 1) {
            --r;
            result = MIN(result, minTree[r]);
        }
    }
    
    return result;
}

int maxQuery(int l, int r) {
    int result = 0;
    for(l += N, r += N; l != r; l >>= 1, r >>= 1) {
        if(l & 1) {
            result = MAX(result, maxTree[l]);
            ++l;
        }
        
        if(r & 1) {
            --r;
            result = MAX(result, maxTree[r]);
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> n;
        update(i, n);
    }
    
    while(M--) {
        cin >> a >> b;
        cout << minQuery(a - 1, b) << ' ' << maxQuery(a - 1, b) << '\n';
    }
    
    return 0;
}