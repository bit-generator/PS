#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string subject, grade;
double score;
unordered_map<string, int> gradeInfo = {
    {"A+", 45}, {"A0", 40}, {"B+", 35}, {"B0", 30},
    {"C+", 25}, {"C0", 20}, {"D+", 15}, {"D0", 10}, {"F", 0}
};
int sum, totalScore;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 0; i < 20; ++i) {
        cin >> subject >> score >> grade;
        if(grade == "P") continue;
        sum += (score * 10 * gradeInfo[grade]);
        totalScore += (score * 10);
    }
    
    cout << fixed;
    cout.precision(6);
    cout << (double)sum / 10 / totalScore;
    return 0;
}