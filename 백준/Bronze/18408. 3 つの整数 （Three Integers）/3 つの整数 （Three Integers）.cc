#include <iostream>
using namespace std;

int a, b, c;
int arr[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> a >> b >> c;
    arr[a]++;
    arr[b]++;
    arr[c]++;
    
    if(arr[1] < arr[2]) cout << 2;
    else cout << 1;
    
    return 0;
}