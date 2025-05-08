#include <iostream>
using namespace std;

int burger[3], drink[2];
int mnb;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> burger[0];
    mnb = burger[0];
    for(int i = 1; i < 3; ++i) {
        cin >> burger[i];
        if(burger[i] < mnb) mnb = burger[i];
    }
    
    cin >> drink[0] >> drink[1];
    mnb += (drink[0] > drink[1] ? drink[1] : drink[0]);
    mnb -= 50;
    cout << mnb;
}