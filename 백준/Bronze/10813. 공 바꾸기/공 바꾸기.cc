#include <iostream>
using namespace std;

int N, M, I, J;
int arr[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 1; i <= N; ++i) arr[i] = i;
    
    while(M--) {
        cin >> I >> J;
        int tmp = arr[I];
        arr[I] = arr[J];
        arr[J] = tmp;
    }
    
    for(int i = 1; i <= N; ++i) cout << arr[i] << ' ';
    return 0;
}