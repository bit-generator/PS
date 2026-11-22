#include <iostream>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;

char c1, c2;
int N;
pair<int, int> king, stone;
string S;
unordered_map<string, int> pos = {
    {"RB", 0}, {"B", 1}, {"LB", 2}, {"L", 3},
    {"LT", 4}, {"T", 5}, {"RT", 6}, {"R", 7} 
};

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {1, 0, -1, -1, -1, 0, 1, 1};

inline bool isValidRange(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> c1 >> king.first >> c2 >> stone.first >> N;
    king.first = 8 - king.first;
    king.second = c1 - 'A';
    stone.first = 8 - stone.first;
    stone.second = c2 - 'A';
    
    while(N--) {
        cin >> S;
        int idx = pos[S];
        int nx = king.first + dx[idx];
        int ny = king.second + dy[idx];
        if(!isValidRange(nx, ny)) continue;
        
        if(stone == make_pair(nx, ny)) {
            if(!isValidRange(nx + dx[idx], ny + dy[idx])) continue;
            stone = {nx + dx[idx], ny + dy[idx]};
        }
            
        king = {nx, ny};
    }
    
    cout << (char)(king.second + 'A') << 8 - king.first << '\n';
    cout << (char)(stone.second + 'A') << 8 - stone.first;
    return 0;
}