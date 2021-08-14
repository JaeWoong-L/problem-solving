/*************************************
 DP - Silver 2
 가장 긴 증가하는 부분 수열
*************************************/ 
#include <iostream>
using namespace std;
int num[1001] = {0};
int dp[1001] = {0};
// dp[a] = b의 의미: "(num[a]가 가질 수 있는 가장 긴 부분수열의 길이) = b"

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    dp[1] = 1;
    dp[2] = num[2] > num[1] ? 2 : 1;

    for(int i = 2; i <= n; i++) {
        int max = 1;
        for(int j = 1; j <= i; j++) {
            if(num[j] < num[i] && max < dp[j] + 1) max = dp[j] + 1;
        }
        dp[i] = max;
    }

    int answer = dp[1];
    for(int i = 2; i <= n; i++) {
        if(dp[i] > answer) answer = dp[i];
    }
    cout << answer;

    return 0;
}