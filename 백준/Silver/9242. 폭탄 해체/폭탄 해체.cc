#include <iostream>
#include <unordered_map>
#include <cstdlib>
using namespace std;

char code[5][33];
char num[9];
unordered_map<int, int> segbit = {
    {0b111101101101111, 0}, {0b11111, 1}, {0b111001111100111, 2},
    {0b111001111001111, 3}, {0b101101111001001, 4}, {0b111100111001111, 5},
    {0b111100111101111, 6}, {0b111001001001001, 7}, {0b111101111101111, 8},
    {0b111101111001111, 9}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int idx = 0;
    int offset = 0;
    bool isOne = false;
    for(int i = 0; i < 5; ++i) cin.getline(code[i], 32);
    while(offset < 33) {
        int cnt = 0;
        for(int i = 0; i < 5; ++i) {
            cnt += (code[i][offset] == '*');
        }
        
        if(cnt == 0) {
            ++offset;
            continue;
        }
        else if(cnt == 5) {
            bool isBlank = true;
            for(int i = 0; i < 5; ++i) {
                if(code[i][offset + 1] == '*') {
                    isBlank = false;
                    break;
                }
            }
            
            if(isBlank) {
                num[idx++] = 1 + '0';
                offset += 2;
                continue;
            }
        }
        
        int bitmask = 0;
        for(int i = 0; i < 5; ++i) {
            for(int j = 0; j < 3; ++j) {
                bitmask <<= 1;
                bitmask |= (code[i][j + offset] == '*');
            }
        }
        
        if(segbit.find(bitmask) != segbit.end()) {
            num[idx++] = segbit[bitmask] + '0';
        }
        else {
            cout << "BOOM!!";
            return 0;
        }
        
        offset += 4;
    }
    
    int encrypted = atoi(num);
    if(encrypted % 6 == 0) {
        cout << "BEER!!";
    }
    else {
        cout << "BOOM!!";
    }
    
    return 0;
}