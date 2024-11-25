#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#define X    first
#define Y    second
using namespace std;

constexpr size_t MAX_SIZE = 10;
int N, ans;
int effects[MAX_SIZE][4][4];
int elements[MAX_SIZE][4][4];
int effBoard[5][5];
int elemBoard[5][5];
int order[3], rot[3], pos[3];
bool check[MAX_SIZE];
int dx[] = {0, 0, 1, 1};
int dy[] = {0, 1, 0, 1};

pair<int, int> (*rotatePos[4])(int, int) = {
    [](int x, int y) -> pair<int, int> { return {x, y}; },
    [](int x, int y) -> pair<int, int> { return {y, 3 - x}; },
    [](int x, int y) -> pair<int, int> { return {3 - x, 3 - y}; },
    [](int x, int y) -> pair<int, int> { return {3 - y, x}; }
};

void solve() {
    memset(effBoard, 0, sizeof(int) * 25);
    memset(elemBoard, 0, sizeof(int) * 25);
    
    for(int k = 0; k < 3; ++k) {
        int idx = order[k];
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                pair<int, int> coord = rotatePos[rot[k]](i, j);
                coord.X += dx[pos[k]];
                coord.Y += dy[pos[k]];
                effBoard[coord.X][coord.Y] += effects[idx][i][j];
                if(effBoard[coord.X][coord.Y] < 0)
                    effBoard[coord.X][coord.Y] = 0;
                if(effBoard[coord.X][coord.Y] > 9)
                    effBoard[coord.X][coord.Y] = 9;
                
                if(elements[idx][i][j]) {
                    elemBoard[coord.X][coord.Y] = elements[idx][i][j];
                }
            }
        }
    }
    
    int bucket[5] = {0};
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 5; ++j) {
            bucket[elemBoard[i][j]] += effBoard[i][j];
        }
    }
    
    int sum = 7 * bucket[1] + 5 * bucket[2] + 3 * bucket[3] + 2 * bucket[4];
    ans = max(ans, sum);
}

void setPosition(int cnt) {
    if(cnt == 3) {
        if(pos[0] != 0 && pos[0] == pos[1] && pos[1] == pos[2]) {
            return;
        }
        
        solve();
        return;
    }
    
    for(int i = 0; i < 4; ++i) {
        pos[cnt] = i;
        setPosition(cnt + 1);
    }
}

void setRotation(int cnt) {
    if(cnt == 3) {
        setPosition(0);
        return;
    }
    
    for(int i = 0; i < 4; ++i) {
        rot[cnt] = i;
        setRotation(cnt + 1);
    }
}

void setOrder(int cnt) {
    if(cnt == 3) {
        setRotation(1);
        return;
    }
    
    for(int i = 0; i < N; ++i) {
        if(check[i]) continue;
        check[i] = true;
        order[cnt] = i;
        setOrder(cnt + 1);
        check[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    for(int k = 0; k < N; ++k) {
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                cin >> effects[k][i][j];
            }
        }
        
        char tmp;
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                cin >> tmp;
                if(tmp == 'R') elements[k][i][j] = 1;
                else if(tmp == 'B') elements[k][i][j] = 2;
                else if(tmp == 'G') elements[k][i][j] = 3;
                else if(tmp == 'Y') elements[k][i][j] = 4;
            }
        }
    }
    
    setOrder(0);
    cout << ans;
    return 0;
}