#include <iostream>
using namespace std;

int N;
int ranks[11] = {12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6};
int penalty[11] = {1600, 894, 1327, 1311, 1004, 1178, 1357,
                  837, 1055, 556, 773};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    cout << ranks[N - 1] << ' ' << penalty[N - 1];
    
    return 0;
}