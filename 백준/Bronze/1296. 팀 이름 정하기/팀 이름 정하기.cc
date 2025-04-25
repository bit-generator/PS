#include <iostream>
#include <string>
using namespace std;

int N, maxP = -1;
string yd, str, maxStr;
int yds[4], teams[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> yd >> N;
    for(auto c : yd) {
        if(c == 'L') ++yds[0];
        else if(c == 'O') ++yds[1];
        else if(c == 'V') ++yds[2];
        else if(c == 'E') ++yds[3];
    }
    
    while(N--) {
        cin >> str;
        
        teams[0] = 0; teams[1] = 0; teams[2] = 0; teams[3] = 0;
        for(auto c : str) {
            if(c == 'L') ++teams[0];
            else if(c == 'O') ++teams[1];
            else if(c == 'V') ++teams[2];
            else if(c == 'E') ++teams[3];
        }
        
        int ans = 1;
        for(int i = 0; i < 4; ++i) {
            for(int j = i + 1; j < 4; ++j) {
                ans = (ans * ((yds[i] + teams[i]) + (yds[j] + teams[j]))) % 100;
            }
        }
        
        if(ans > maxP) {
            maxP = ans;
            maxStr = str;
        }
        else if(ans == maxP && str < maxStr) {
            maxStr = str;
        }
    }
    
    cout << maxStr;
    return 0;
}