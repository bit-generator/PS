#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(const string& s1, const string& s2) const {
        if(s1.length() == s2.length()) return s1 < s2;
        return s1.length() > s2.length();
    }
};

constexpr size_t MAX_SIZE = 8 * 300000 + 5;
const int ROOT = 1;
int w, b, totalScore;
string str;
char board[4][5];
bool visit[4][4];
set<string, compare> words;
int trie[MAX_SIZE][26];
bool check[MAX_SIZE];
char foundStr[9];
int trieCnt = 2;
int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int score[] = {0, 0, 0, 1, 1, 2, 3, 5, 11};

constexpr int getId(char ch) { return ch - 'A'; }

bool validRange(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void insert(string& s) {
    int cur = ROOT;
    
    for(char c : s) {
        if(!trie[cur][getId(c)]) {
            trie[cur][getId(c)] = trieCnt++;
        }
        
        cur = trie[cur][getId(c)];
    }
    
    check[cur] = true;
}

void dfs(int x, int y, int idx, int cur) {
    if(check[cur]) {
        foundStr[idx] = '\0';
        if(words.find(foundStr) == words.end()) {
            words.insert(foundStr);
            totalScore += score[idx];
        }
    }
    
    for(int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!validRange(nx, ny) || visit[nx][ny]) continue;
        if(!trie[cur][getId(board[nx][ny])]) continue;
        
        foundStr[idx] = board[nx][ny];
        visit[nx][ny] = true;
        dfs(nx, ny, idx + 1, trie[cur][getId(board[nx][ny])]);
        visit[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> w;
    for(int i = 0; i < w; ++i) {
        cin >> str;
        insert(str);
    }
    
    cin >> b;
    while(b--) {
        for(int i = 0; i < 4; ++i) {
            cin >> board[i];
        }
        
        words.clear();
        totalScore = 0;
        
        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                if(trie[ROOT][getId(board[i][j])]) {
                    foundStr[0] = board[i][j];
                    visit[i][j] = true;
                    dfs(i, j, 1, trie[ROOT][getId(board[i][j])]);
                    visit[i][j] = false;
                } 
            }
        }
        
        cout << totalScore << ' ' << *words.begin() << ' ' << words.size() << '\n';
    }
    
    return 0;
}