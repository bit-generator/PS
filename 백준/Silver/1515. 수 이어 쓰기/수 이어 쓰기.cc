#include <iostream>
#include <string>
using namespace std;

string nums;
int ans = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> nums;
    
    int i = 0;
    while(i < nums.length()) {
        string tmp = to_string(ans);
        int j = 0;
        
        while(j < tmp.length()) {
            if(nums[i] == tmp[j]) ++i;
            ++j;
        }
        
        ++ans;
    }
    
    cout << ans - 1;
    return 0;
}