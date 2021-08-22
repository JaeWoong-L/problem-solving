/*************************************
 dp - Gold 5
 수강 과목
 * 0-1 knapsack problem
*************************************/ 
#include <iostream>
using namespace std;
int N, K;
int table[1001][2];
int dp[1001][10001] = {0};

int solve() {
    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            if(table[i][1] <= j) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j - table[i][1]] + table[i][0]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    
    return dp[K][N];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 1; i <= K; i++) {
        cin >> table[i][0] >> table[i][1];
    }
    
    cout << solve();

    return 0;
}