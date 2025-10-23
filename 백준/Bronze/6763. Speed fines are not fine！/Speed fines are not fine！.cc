#include <iostream>
using namespace std;

int A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> A >> B;
    if(B - A <= 0) cout << "Congratulations, you are within the speed limit!";
    else if(B - A <= 20) cout << "You are speeding and your fine is $100.";
    else if(B - A <= 30) cout << "You are speeding and your fine is $270.";
    else cout << "You are speeding and your fine is $500.";
    return 0;
}