#include <iostream>
#include <string>
#include <numeric>
using namespace std;

int N;
string S, S2;
int F[1'000'000];
int num, dvd;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    char ch;
    for(int i = 0; i < N; ++i) {
        cin >> ch;
        S += ch;
    }
    
    cin.ignore();
    getline(cin, S2);
    
    int j = 0;
    for(int i = 1; i < N; ++i) {
        while(j > 0 && S[i] != S[j]) j = F[j - 1];
        if(S[i] == S[j]) F[i] = ++j;
    }
    
    if(F[N - 1] != 0 && F[N - 1] % (N - F[N - 1]) == 0) {
        num = F[N - 1] / (N - F[N - 1]) + 1;
    }
    else num = 1;
    
    dvd = gcd(num, N);
    cout << num / dvd << '/' << N / dvd;
    return 0;
}