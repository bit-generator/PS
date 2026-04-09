#include <iostream>
using namespace std;

int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    if(N >= 3 && M <= 4) cout << "TroyMartian\n";
    if(N <= 6 && M >= 2) cout << "VladSaturnian\n";
    if(N <= 2 && M <= 3) cout << "GraemeMercurian";
    return 0;
}