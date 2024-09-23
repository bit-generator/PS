#include <iostream>
#include <string>
#include <cstring>
using namespace std;

constexpr int OFFSET = 1896;

int N, year, ans1, ans2;
string game, medal;
int medals[130], goldmedals[130];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        cin >> N;
        if(N == 0) break;
        
        memset(medals, 0, sizeof(int) * 130);
        memset(goldmedals, 0, sizeof(int) * 130);
        
        while(N--) {
            cin >> year >> game >> medal;
            medals[year - OFFSET]++;
            if(medal == "Gold") goldmedals[year - OFFSET]++;
        }
        
        int maxMedal = 0, maxGoldMedal = 0;
        for(int i = 0; i < 130; i++) {
            if(goldmedals[i] > maxGoldMedal) {
                maxGoldMedal = goldmedals[i];
                ans1 = i + OFFSET;
            }
            
            if(medals[i] > maxMedal) {
                maxMedal = medals[i];
                ans2 = i + OFFSET;
            }
        }
        
        cout << ans1 << ' ' << ans2 << '\n';
    }
    
    return 0;
}