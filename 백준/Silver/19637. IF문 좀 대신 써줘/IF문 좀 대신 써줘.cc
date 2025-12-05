#include <iostream>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

int N, M, K;
string str;
unordered_map<int, string> um;
set<int> s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    while(N--) {
        cin >> str >> K;
        if(um.find(K) == um.end()) {
            um.emplace(K, str);
            s.insert(K);
        }
    }
    
    while(M--) {
        cin >> K;
        int key = *(s.lower_bound(K));
        cout << um[key] << '\n';
    }
    
    return 0;
}