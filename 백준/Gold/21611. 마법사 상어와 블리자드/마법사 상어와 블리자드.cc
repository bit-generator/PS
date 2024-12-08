#include <iostream>
#include <vector>
using namespace std;

int N, M, d, s, len;
int arr[50][50];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int order[] = {3, 2, 4, 1};
int explodeCnt[4];
vector<int> tempVec;

struct Point {
    int x, y;
    int idx;
    int limit;
    int cnt;
    
    Point() {
        this->x = N / 2;
        this->y = N / 2;
        this->idx = 0;
        this->limit = 1;
        this->cnt = 0;
    }
    Point(const Point& p) {
        this->x = p.x;
        this->y = p.y;
        this->idx = p.idx;
        this->limit = p.limit;
        this->cnt = p.cnt;
    }    
    Point operator++() {
        this->x += dx[order[idx]];
        this->y += dy[order[idx]];
        
        if(++cnt == limit) {
            if(idx == 1 || idx == 3) ++limit;
            idx = (idx + 1) % 4;
            cnt = 0;
        }
        
        return *this;
    }
};

void blast() {
    int x = N / 2;
    int y = N / 2;
    for(int i = 0; i < s; ++i) {
        x += dx[d];
        y += dy[d];
        arr[x][y] = 0;
    }
}

void moveMarbles() {
    Point p1, p2;
    int cnt = 0;
    for(int i = 0; i < len; ++i) {
        ++p2;
        if(arr[p2.x][p2.y] == 0) continue;
        ++p1;
        ++cnt;
        arr[p1.x][p1.y] = arr[p2.x][p2.y];
    }
    
    len = cnt;
}

bool explosion() {
    Point p1, p2;
    int i = 0;
    bool exploded = false;
    
    while(i <= len) {
        ++p2; ++i;
        int cnt = 1;
        while(i <= len && arr[p1.x][p1.y] == arr[p2.x][p2.y]) {
            ++cnt;
            ++p2;
            ++i;
        }
        
        if(cnt >= 4) {
            exploded = true;
            while(cnt--) {
                ++explodeCnt[arr[p1.x][p1.y]];
                arr[p1.x][p1.y] = 0;
                ++p1;
            }
        }
        else p1 = p2;
    }
    
    return exploded;
}

void rearrange() {
    Point p1, p2;
    ++p1; ++p2;
    int i = 0;
    tempVec.clear();
    
    while(i < len) {
        ++p2; ++i;
        int cnt = 1;
        while(i < len && arr[p1.x][p1.y] == arr[p2.x][p2.y]) {
            ++cnt;
            ++p2;
            ++i;
        }
        
        tempVec.push_back(cnt);
        tempVec.push_back(arr[p1.x][p1.y]);
        p1 = p2;
    }
    
    Point p3;
    len = tempVec.size() < N * N - 1 ? tempVec.size() : N * N - 1;
    for(int i = 0; i < len; ++i) {
        ++p3;
        arr[p3.x][p3.y] = tempVec[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if(arr[i][j] > 0) ++len;
        }
    }
    
    while(M--) {
        cin >> d >> s;
        blast();
        do {
            moveMarbles();
        } while(explosion());
        rearrange();
    }
    
    cout << explodeCnt[1] + 2 * explodeCnt[2] + 3 * explodeCnt[3];
    return 0;
}