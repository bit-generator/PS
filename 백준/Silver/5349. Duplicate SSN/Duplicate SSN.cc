#include <iostream>
#include <string>
#include <unordered_set>
#include <set>
using namespace std;

string str;
unordered_set<string> us;
set<string> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> str;
        if(str == "000-00-0000") break;
        
        if(us.find(str) == us.end()) us.insert(str);
        else s.insert(str);
    }
    
    for(string st : s) cout << st << '\n';
    return 0;
}