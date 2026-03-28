#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N;
string str1, str2;
unordered_set<string> us;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    while(N--) {
        cin >> str1 >> str2;
        if((str1 == "ChongChong" || str2 == "ChongChong")
          || (us.find(str1) != us.end() || us.find(str2) != us.end())) {
            us.insert(str1);
            us.insert(str2);
        }
    }
    
    cout << us.size();
    return 0;
}