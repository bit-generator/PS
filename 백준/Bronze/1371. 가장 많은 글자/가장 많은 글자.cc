#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str;
int arr[26];
vector<char> mx;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(getline(cin, str)) {
        for(char c : str) {
            if(c != ' ') {
                ++arr[c - 'a'];
            }
        }
    }
    
    int maxCnt = 0;
    for(int i = 0; i < 26; ++i) {
        if(arr[i] > maxCnt) {
            mx.clear();
            maxCnt = arr[i];
            mx.push_back(i + 'a');
        }
        else if(arr[i] == maxCnt) {
            mx.push_back(i + 'a');
        }
    }
    
    for(char ch : mx) cout << ch;
    return 0;
}