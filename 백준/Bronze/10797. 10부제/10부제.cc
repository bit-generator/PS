#include <iostream>
using namespace std;

int N, M, cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < 5; ++i) {
        cin >> M;
        if(M % 10 == N) ++cnt;
    }
    
    cout << cnt;
    return 0;
}