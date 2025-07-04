#include <iostream>
#include <string>
using namespace std;

int N;
string str;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> str;
    cout << str.substr(N - 5);
    
    return 0;
}