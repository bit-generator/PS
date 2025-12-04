#include <iostream>
#include <string>
using namespace std;

string str, ans;
int totalZeros, totalOnes, zeros, ones;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str;

    int len = str.length();
    for (int i = 0; i < len; ++i) {
        if (str[i] == '0') ++totalZeros;
        else ++totalOnes;
    }

    for(int i = 0; i < len; ++i) {
        if(str[i] == '0' && zeros++ < totalZeros / 2) ans += '0';
        if(str[i] == '1' && ones++ >= totalOnes / 2) ans += '1';
    }

    cout << ans;
    return 0;
}