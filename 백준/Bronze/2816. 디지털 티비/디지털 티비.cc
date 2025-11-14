#include <iostream>
#include <string>
using namespace std;

int N, pos1, pos2;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> str;
        if(str == "KBS1") pos1 = i;
        if(str == "KBS2") pos2 = i;
    }
    
    if(pos1 > pos2) ++pos2;
    for(int i = 0; i < pos1; ++i) cout << 1;
    for(int i = 0; i < pos1; ++i) cout << 4;
    for(int i = 0; i < pos2; ++i) cout << 1;
    for(int i = 0; i < pos2 - 1; ++i) cout << 4;
    return 0;
}