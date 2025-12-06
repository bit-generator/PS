#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N, M;
string str;
unordered_set<string> us;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(N--) {
        cin >> str;
        us.insert(str);
    }
    
    while(M--) {
        cin >> str;
        int pos = str.find(',');
        int prv = 0;
        
        while(pos != string::npos) {
            string tmp = str.substr(prv, pos - prv);
            if(us.find(tmp) != us.end()) us.erase(tmp);
            
            prv = pos + 1;
            pos = str.find(',', prv);
        }
        
        string tmp = str.substr(prv);
        if(us.find(tmp) != us.end()) us.erase(tmp);
        cout << us.size() << '\n';
    }
    
    return 0;
}