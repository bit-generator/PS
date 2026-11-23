#include <iostream>
#include <set>
#include <vector>
using namespace std;

char ch;
int idx;
char arr[12];
int lines[6][4] = {
    {0, 2, 5, 7}, {0, 3, 6, 10}, {7, 8, 9, 10},
    {1, 2, 3, 4}, {1, 5, 8, 11}, {4, 6, 9, 11}
};
bool isExist[12];
vector<int> v;

bool solve() {
    int sum = 0;
    
    for(int i = 0; i < 6; ++i) {
        int tempsum = 0;
        
        for(int j = 0; j < 4; ++j) {
            int k = lines[i][j];
            tempsum += arr[k];
        }
        
        if(sum == 0) sum = tempsum;
        else if(sum != tempsum) return false;
    }
    
    return true;
}

bool backtrack(int n) {
    if(n == v.size()) {
        if(solve()) return true;
        else return false;
    }
    
    for(int i = 0; i < 12; ++i) {
        if(isExist[i]) continue;
        isExist[i] = true;
        arr[v[n]] = i + 'A';
        if(backtrack(n + 1)) return true;
        isExist[i] = false;
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 5; ++i) {
        for(int j = 0; j < 9; ++j) {
            cin >> ch;
            if (ch != '.') {
                if (ch != 'x') {
                    arr[idx] = ch;
                    isExist[arr[idx] - 'A'] = true;
                }
                else v.push_back(idx);
                
                ++idx;
            }
        }
    }
    
    backtrack(0);
    cout << "...." << arr[0] << "....\n";
    cout << "." << arr[1] << "." << arr[2] << "." << arr[3] << "." << arr[4] << ".\n";
    cout << ".." << arr[5] << "..." << arr[6] << "..\n";
    cout << "." << arr[7] << "." << arr[8] << "." << arr[9] << "." << arr[10] << ".\n";
    cout << "...." << arr[11] << "....";
    return 0;
}