/*************************************
 DP - Gold 5
 LCS 2
 * 전형적인 dp문제
 * dp배열의 시작지점이 0이 아닌 -1.
*************************************/
#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001] = {0};
string LCS = "";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();

    int count = 1;
    for(int i = 1; i <= len1; i++) {
        bool isFound = false;
        for(int j = 1; j <= len2; j++) {
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                if(isFound == false && dp[i][j] == count) {
                    LCS += s1[i-1];
                    isFound = true;
                    count++;
                }
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << LCS.length() << endl;

    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int answer = dp[len1][len2];
    cout << answer << endl;
    if(answer > 0) cout << LCS;
 
    return 0;
}