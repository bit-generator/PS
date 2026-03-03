#include <iostream>
#include <vector>
using namespace std;

int n, sum;
vector<int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> n;
        if(n == -1) break;
        
        v.clear();
        sum = 0;
        for(int i = 1; i < n; ++i) {
            if(n % i == 0) {
                sum += i;
                v.push_back(i);
            }
        }
        
        cout << n;
        if(n == sum) {
            cout << " = ";
            for(int i = 0; i < v.size() - 1; ++i) {
                cout << v[i] << " + ";
            }
            cout << v.back() << '\n';
        }
        else {
            cout << " is NOT perfect.\n";
        }
    }
    
    return 0;
}