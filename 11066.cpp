/*************************************
 DP - Gold 3
 파일 합치기
 * 11049(행렬곱셈순서)와 거의 동일하나, 점화식을 잘못 세워서 오래 걸림.
 * 점화식 찾을 때 문제의 핵심에 맞게 접근하는 것이 중요하다.
*************************************/
#include <iostream>
using namespace std;
int T, K;
int dp[501][501] = {0}; // dp[x][y] = n  =>  x번째 행렬부터 y번째 행렬까지 곱할 때 최소 연산 수 = n
int files[501];
int sum[501] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int k = 0; k < T; k++) {
        cin >> K;
        for(int i = 1; i <= K; i++) {
            cin >> files[i];
            sum[i] = sum[i-1] + files[i];

            for(int j = 1; j <= K; j++) {
                dp[i][j] = 0;
            }
        }

        for(int diff = 1; diff < K; diff++) {
            for(int left = 1; left <= K - diff; left++) {
                int right = left + diff;
                for(int mid = left; mid < right; mid++) {
                    int curr = dp[left][right];
                    int next = dp[left][mid] + dp[mid+1][right] + (sum[right] - sum[left-1]);

                    if(curr == 0) dp[left][right] = next;
                    else {
                        dp[left][right] = min(curr, next);
                    }
                }
            }
        }
        cout << dp[1][K] << endl;
    }
 
    return 0;
}