#include <iostream>
#include <string>
using namespace std;

string S;
bool isExist[4][14];
int cnt[4] = {13, 13, 13, 13};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> S;
    for(int i = 0; i < S.length(); i += 3) {
        char c = S[i];
        int num = stoi(S.substr(i + 1, 2));
        if(c == 'P') {
            if(isExist[0][num]) {
                cout << "GRESKA";
                return 0;
            }
            
            isExist[0][num] = true;
            --cnt[0];
        }
        else if(c == 'K') {
            if(isExist[1][num]) {
                cout << "GRESKA";
                return 0;
            }
            
            isExist[1][num] = true;
            --cnt[1];
        }
        else if(c == 'H') {
            if(isExist[2][num]) {
                cout << "GRESKA";
                return 0;
            }
            
            isExist[2][num] = true;
            --cnt[2];
        }
        else {
            if(isExist[3][num]) {
                cout << "GRESKA";
                return 0;
            }
            
            isExist[3][num] = true;
            --cnt[3];
        }
    }
    
    for(int i = 0; i < 4; ++i) {
        cout << cnt[i] << ' ';
    }
    return 0;
}