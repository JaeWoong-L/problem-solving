/*************************************
 dp - Gold 5
 평범한 배낭
 * 0-1 knapsack problem
*************************************/ 
#include <iostream>
using namespace std;
int N, K;
int table[101][2]; // [][0] = weight, [][1] = value
int dp[101][100001] = {0};

int solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(table[i][0] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - table[i][0]] + table[i][1]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[N][K];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        cin >> table[i][0] >> table[i][1];
    }
    
    cout << solve();

    return 0;
}