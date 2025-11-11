#include <iostream>
#include <string>
using namespace std;

int N, cnt, target, ans;
string D;
long long C;
int arr[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> D >> C;
        if(D == "jinju") target = C;
        if(C > 1000) ++cnt;
        else ++arr[C];
    }
    
    for(int i = target + 1; i <= 1000; ++i) ans += arr[i];
    cout << target << '\n' << ans + cnt;
    return 0;
}