#include <iostream>
#include <string>
using namespace std;

string digit[10][5] = {
    {"0000", "0  0", "0  0", "0  0", "0000"},
    {"   1", "   1", "   1", "   1", "   1"},
    {"2222", "   2", "2222", "2", "2222"},
    {"3333", "   3", "3333", "   3", "3333"},
    {"4  4", "4  4", "4444", "   4", "   4"},
    {"5555", "5", "5555", "   5", "5555"},
    {"6666", "6", "6666", "6  6", "6666"},
    {"7777", "   7", "   7", "   7", "   7"},
    {"8888", "8  8", "8888", "8  8", "8888"},
    {"9999", "9  9", "9999", "   9", "   9"}
};
string num;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> num;
    for(char c : num) {
        int n = c - '0';
        for(int i = 0; i < 5; ++i) {
            cout << digit[n][i] << '\n';
        }
        cout << '\n';
    }
    
    return 0;
}