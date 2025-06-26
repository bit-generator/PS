#include <iostream>
using namespace std;

int N, H, V;
char room[100][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int i = 0; i < N; ++i) {
        cin >> room[i];
        
        int pos = 0, prv = 0;
        while(pos < N) {
            while(pos < N && room[i][pos] == '.') ++pos;
            if(pos - prv >= 2) ++H;
            
            while(pos < N && room[i][pos] == 'X') ++pos;
            prv = pos;
        }
        
    }
    
    for(int j = 0; j < N; ++j) {
        int pos = 0, prv = 0;
        while(pos < N) {
            while(pos < N && room[pos][j] == '.') ++pos;
            if(pos - prv >= 2) ++V;
            
            while(pos < N && room[pos][j] == 'X') ++pos;
            prv = pos;
        }
    }
    
    cout << H << ' ' << V;
    return 0;
}