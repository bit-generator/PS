#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, T, P, M;
int info[2001][2001];
int score[2001];
vector<int> solved[2001];
vector<tuple<int, int, int>> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> T >> P;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= T; ++j) {
            cin >> M;
            score[j] += !M;
            if(M) solved[i].push_back(j);
        }
    }
    
    for(int i = 1; i <= N; ++i) {
        int sum = 0;
        
        for(int n : solved[i]) {
            sum += score[n];
        }
        
        v.emplace_back(sum, solved[i].size(), i * (-1));
    }
    
    sort(v.begin(), v.end(), greater<>());
    for(int i = 0; i < v.size(); ++i) {
        if(get<2>(v[i]) == P * (-1)) {
            cout << get<0>(v[i]) << ' ' << i + 1;
        }
    }
    
    return 0;
}