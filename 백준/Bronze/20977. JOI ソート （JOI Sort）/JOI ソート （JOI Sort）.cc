#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

int N;
string str;
unordered_map<char, int> um;

bool compare(char c1, char c2) {
    return um[c1] < um[c2];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> str;
    um['J'] = 0;
    um['O'] = 1;
    um['I'] = 2;
    
    sort(str.begin(), str.end(), compare);
    cout << str;
    return 0;
}