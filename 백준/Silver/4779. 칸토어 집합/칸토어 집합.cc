#include <iostream>
#include <algorithm>
using namespace std;

int N;
char str[540000];

void func(int start, int len) {
    if(len == 1) {
        str[start] = '-';
        return;
    }
    
    len /= 3;
    func(start, len);
    func(start + len * 2, len);
}

inline int pow(int base, int cnt) {
    int ret = 1;
    for(int i = 0; i < cnt; ++i) ret *= base;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> N) {
        int len = pow(3, N);
        fill(str, str + len, ' ');
        func(0, len);
        str[len] = 0;
        cout << str << '\n';
    }
    
    return 0;
}