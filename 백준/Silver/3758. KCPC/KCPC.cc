#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct Node {
    int id;
    int score;
    int submitted;
    int time;
    
    bool operator<(const Node& a) const {
        if(this->score == a.score) {
            if(this->submitted == a.submitted) {
                return this->time < a.time;
            }
            return this->submitted < a.submitted;
        }
        return this->score > a.score;
    }
};

int T, n, k, t, m, I, J, s;
int scores[101][101];
int submit[101], submitTime[101];
vector<Node> sorted;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while(T--) {
        memset(scores, 0, sizeof(scores));
        memset(submit, 0, sizeof(submit));
        sorted.clear();
        
        cin >> n >> k >> t >> m;
        for(int i = 1; i <= m; ++i) {
            cin >> I >> J >> s;
            scores[I][J] = max(scores[I][J], s);
            ++submit[I]; submitTime[I] = i;
        }
        
        for(int i = 1; i <= n; ++i) {
            Node tmp = {0};
            tmp.id = i;
            tmp.submitted = submit[i];
            tmp.time = submitTime[i];
            
            for(int j = 1; j <= k; ++j) {
                tmp.score += scores[i][j];
            }
            
            sorted.push_back(tmp);
        }
        
        sort(sorted.begin(), sorted.end());
        
        for(int i = 0; i < sorted.size(); ++i) {
            if(sorted[i].id == t) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    
    return 0;
}