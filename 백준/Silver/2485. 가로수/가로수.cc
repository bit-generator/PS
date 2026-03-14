#include <iostream>
#include <numeric>
using namespace std;

int N, target, ans;
int trees[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> trees[0] >> trees[1];
    target = trees[1] - trees[0];
    for(int i = 2; i < N; ++i) {
        cin >> trees[i];
        int tmp = trees[i] - trees[i - 1];
        target = gcd(target, tmp);
    }
    
    for(int i = 1; i < N; ++i) {
        int tmp = (trees[i] - trees[i - 1]) / target - 1;
        ans += tmp;
    }
    
    cout << ans;
    return 0;
}