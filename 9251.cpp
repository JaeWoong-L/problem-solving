/*************************************
 DP - Gold 5
 LCS
 * 전형적인 dp문제
 * dp배열의 시작지점이 0이 아닌 -1.
*************************************/
#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[len1][len2];
 
    return 0;
}