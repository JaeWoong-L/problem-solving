/*************************************
 DP - Gold 5
 LCS 2
 * 9251 문제에서 실제 LCS string을 찾는 문제.
 * bottom-up으로 풀려다가 복잡하기만 하고 성과가 없었다.
 * 재귀로 푸는 것이 훨씬 간단하고 명료함.
*************************************/
#include <iostream>
#include <string>
using namespace std;
int dp[1001][1001] = {0};
string s1, s2;
string LCS = "";

void find_lcs(int i, int j) {
    if(dp[i][j] == 0) return;
    if(s1[i-1] == s2[j-1]) {
        LCS = s1[i-1] + LCS;
        find_lcs(i-1, j-1);
    }
    else {
        dp[i-1][j] > dp[i][j-1] ? find_lcs(i-1, j) : find_lcs(i, j-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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

    find_lcs(len1, len2);

    int answer = dp[len1][len2];
    cout << answer << endl;
    if(answer > 0) cout << LCS;
 
    return 0;
}