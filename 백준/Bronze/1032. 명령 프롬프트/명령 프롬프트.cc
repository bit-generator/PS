#include <iostream>
using namespace std;

int N;
char str[51];
char str2[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    cin >> str;
    
    while(--N) {
        cin >> str2;
        for(int i = 0; str2[i] != 0; ++i) {
            if(str[i] != str2[i]) str[i] = '?';
        }
    }
    
    cout << str;
    return 0;
}