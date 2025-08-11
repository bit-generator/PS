#include <iostream>
using namespace std;

int N, A, B, Pa, Pb, tank, deal;
long long sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> A >> Pa >> B >> Pb;
    for(int i = 0; i * Pa <= N; ++i) {
        int j = (N - i * Pa) / Pb;
        long long tmp = (long long)i * A + (long long)j * B;
        if(sum < tmp) {
            sum = tmp;
            tank = i;
            deal = j;
        }
    }
    
    cout << tank << ' ' << deal;
    return 0;
}