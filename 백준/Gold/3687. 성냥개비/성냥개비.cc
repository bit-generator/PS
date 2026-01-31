#include <iostream>
#include <string>
using namespace std;

int T, n, digit = 1, cnt = 1;
int segment[10] =  {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string minNum[101] = {"", "", "1", "7", "4", "2", "6", "8"};
string maxNum[101] = {"", "", "1", "7"};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 8; i <= 100; ++i) {
        while(minNum[i - segment[cnt]].length() > digit) {
            ++cnt;
            if(cnt >= 10) {
                cnt = 1;
                ++digit;
            }
        }
        
        minNum[i] = minNum[segment[cnt]];
        int idx = i - segment[cnt];
        int j = 0;
        
        if(minNum[idx].substr(0, 2) == "28") {
            minNum[i] += "00";
            j = 2;
        }
        
        for( ; j < minNum[idx].length(); ++j) {
            if(minNum[idx][j] == '6') minNum[i] += '0';
            else minNum[i] += minNum[idx][j];
        }
    }
    
    for(int i = 4; i <= 100; ++i) {
        if(i % 2) {
            maxNum[i] += '7';
            maxNum[i] += maxNum[i - 3];
        }
        else {
            maxNum[i] += '1';
            maxNum[i] += maxNum[i - 2];
        }
    }
    
    cin >> T;
    while(T--) {
        cin >> n;
        cout << minNum[n] << ' ' << maxNum[n] << '\n';
    }
    
    return 0;
}