#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    vector<int> answer;
    int dp[100001][2] = {0};
    
    for(int i = 1; i <= target; ++i) {
        if(i <= 20 || i == 50) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        else if((i <= 40 && i % 2 == 0) || (i <= 60 && i % 3 == 0)) {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        else if(i <= 70) {
            if(i > 40 && i < 50) {
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
            else {
                dp[i][0] = 2;
                dp[i][1] = 2;
            }
        }
        else {
            int total1 = dp[i - 50][0] + 1;
            int cnt1 = dp[i - 50][1] + 1;
            int total2 = dp[i - 60][0] + 1;
            int cnt2 = dp[i - 60][1];
            
            if(total1 < total2) {
                dp[i][0] = total1;
                dp[i][1] = cnt1;
            }
            else if(total1 > total2) {
                dp[i][0] = total2;
                dp[i][1] = cnt2;
            }
            else {
                dp[i][0] = total1;
                dp[i][1] = max(cnt1, cnt2);
            }
        }
    }
    
    answer.push_back(dp[target][0]);
    answer.push_back(dp[target][1]);
    return answer;
}