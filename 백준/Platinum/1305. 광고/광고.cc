#include <iostream>
#include <string>
using namespace std;

int L;
string str;
int F[1'000'001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> L >> str;
    int j = 0;
    for(int i = 1; i < L; ++i) {
        while(j > 0 && str[i] != str[j]) j = F[j - 1];
        if(str[i] == str[j]) F[i] = ++j;
    }
    
    cout << L - F[L - 1];
    return 0;
}