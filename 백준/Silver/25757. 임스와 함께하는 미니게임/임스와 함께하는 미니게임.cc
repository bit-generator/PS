#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N;
char ch;
string str;
unordered_set<string> us;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> ch;
    while(N--) {
        cin >> str;
        us.insert(str);
    }
    
    if(ch == 'Y') cout << us.size();
    else if(ch == 'F') cout << us.size() / 2;
    else cout << us.size() / 3;
    return 0;
}