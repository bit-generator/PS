#include <iostream>
using namespace std;

long long S, sum;
int N = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> S;
    while(true) {
        sum += N;
        if(sum + N + 1 > S) break;
        ++N;
    }
    
    cout << N;
    return 0;
}