#include <iostream>
using namespace std;

int N, M;
int days[200001];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 1; i <= N; ++i) {
        cin >> M;
        if(M) days[i] = days[i - 1] + 1;
        else days[i] = days[i - 1] - 1;
        ans += days[i];
    }
    
    cout << ans;
    return 0;
}