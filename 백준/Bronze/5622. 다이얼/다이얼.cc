#include <iostream>
#include <string>
using namespace std;

string str;
int arr[26] = {
    3, 3, 3, 4, 4, 4,
    5, 5, 5, 6, 6, 6,
    7, 7, 7, 8, 8, 8, 8,
    9, 9, 9, 10, 10, 10, 10
};
int ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> str;
    for(char c : str) {
        ans += arr[c - 'A'];
    }
    
    cout << ans;
    return 0;
}