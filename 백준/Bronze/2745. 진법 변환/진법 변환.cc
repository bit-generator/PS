#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string N;
int B, ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> B;
    int times = 1;
    for(int i = N.length() - 1; i >= 0; --i) {
        if(isdigit(N[i]))
            ans += (times * (N[i] - '0'));
        else
            ans += (times * (N[i] - 'A' + 10));
        times *= B;
    }
    
    cout << ans;
    return 0;
}