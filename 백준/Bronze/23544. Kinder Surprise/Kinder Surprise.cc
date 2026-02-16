#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int n;
string str;
unordered_set<string> us;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        us.insert(str);
    }
    
    cout << n - us.size();
    return 0;
}