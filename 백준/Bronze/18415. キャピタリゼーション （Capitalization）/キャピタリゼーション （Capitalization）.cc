#include <iostream>
#include <string>
using namespace std;

int N;
string S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> S;
    int idx = S.find("joi");
    while(idx != -1) {
        S.replace(idx, 3, "JOI");
        idx = S.find("joi");
    }
    
    cout << S;
    return 0;
}