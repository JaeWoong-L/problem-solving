/*************************************
 DP - Gold 3
 행렬 곱셈 순서
 *bottom-up으로 구현
 *디버깅이 어려우므로 처음 변수 범위 넣을 때 주의해서 넣어야 함.
*************************************/
#include <iostream>
using namespace std;
int N;
int dp[500][500] = {0}; // dp[x][y] = n  =>  x번째 행렬부터 y번째 행렬까지 곱할 때 최소 연산 수 = n
int matrix_size[501];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int row, col;
        cin >> row >> col;
        if(i == 0) {
            matrix_size[i] = row;
            matrix_size[i+1] = col;
        }
        else matrix_size[i+1] = col;
    }

    int diff = 1;
    while(diff < N) {
        for(int left = 0; left < N - diff; left++) {
            int right = left + diff;

            for(int mid = left; mid < right; mid++) {
                int curr = dp[left][right];
                int next = dp[left][mid] + dp[mid+1][right] + matrix_size[left]*matrix_size[mid+1]*matrix_size[right+1];

                if(curr == 0) {
                    dp[left][right] = next;
                }
                else {
                    dp[left][right] = min(curr, next);
                }
            }
        }
        diff++;
    }

    cout << dp[0][N-1];
 
    return 0;
}