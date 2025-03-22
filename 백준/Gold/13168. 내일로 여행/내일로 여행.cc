#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int N, R, M, K, cost, sz;
string city, city2, trans;
int graph[101][101];
int discount[101][101];
unordered_map<string, int> cities;
vector<int> order;
int total1, total2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> R;
    while(N--) {
        cin >> city;
        if(cities.find(city) != cities.end()) continue;
        
        cities[city] = ++sz;
    }
    
    cin >> M;
    while(M--) {
        cin >> city;
        order.push_back(cities[city]);
    }
    
    memset(graph, -1, sizeof(graph));
    memset(discount, -1, sizeof(discount));
    
    cin >> K;
    while(K--) {
        cin >> trans >> city >> city2 >> cost;
        if(graph[cities[city]][cities[city2]] == -1) {
            graph[cities[city]][cities[city2]] = cost << 1;
            graph[cities[city2]][cities[city]] = cost << 1;
            
            if(trans == "Mugunghwa" || trans == "ITX-Saemaeul" || trans == "ITX-Cheongchun") {
                discount[cities[city]][cities[city2]] = 0;
                discount[cities[city2]][cities[city]] = 0;
            }
            else if(trans == "S-Train" || trans == "V-Train") {
                discount[cities[city]][cities[city2]] = cost;
                discount[cities[city2]][cities[city]] = cost;
            }
            else {
                discount[cities[city]][cities[city2]] = cost << 1;
                discount[cities[city2]][cities[city]] = cost << 1;
            }
        }
        else {
            graph[cities[city]][cities[city2]] = min(graph[cities[city]][cities[city2]], cost << 1);
            graph[cities[city2]][cities[city]] = min(graph[cities[city2]][cities[city]], cost << 1);
            
            if(trans == "Mugunghwa" || trans == "ITX-Saemaeul" || trans == "ITX-Cheongchun") {
                discount[cities[city]][cities[city2]] = 0;
                discount[cities[city2]][cities[city]] = 0;
            }
            else if(trans == "S-Train" || trans == "V-Train") {
                discount[cities[city]][cities[city2]] = min(discount[cities[city]][cities[city2]], cost);
                discount[cities[city2]][cities[city]] = min(discount[cities[city2]][cities[city]], cost);
            }
            else {
                discount[cities[city]][cities[city2]] = min(discount[cities[city]][cities[city2]], cost << 1);
                discount[cities[city2]][cities[city]] = min(discount[cities[city2]][cities[city]], cost << 1);
            }
        }
    }
    
    for(int k = 1; k <= sz; ++k) {
        for(int i = 1; i <= sz; ++i) {
            for(int j = 1; j <= sz; ++j) {
                if(i == j || graph[i][k] == -1 || graph[k][j] == -1) continue;
                if(graph[i][j] == -1) graph[i][j] = graph[i][k] + graph[k][j];
                else graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                
                if(discount[i][j] == -1) discount[i][j] = discount[i][k] + discount[k][j];
                else discount[i][j] = min(discount[i][j], discount[i][k] + discount[k][j]);
            }
        }
    }
    
    for(int i = 0; i < order.size() - 1; ++i) {
        total1 += graph[order[i]][order[i + 1]];
        total2 += discount[order[i]][order[i + 1]];
    }
    total2 += (R << 1);
    
    if(total1 > total2) cout << "Yes";
    else cout << "No";
    return 0;
}