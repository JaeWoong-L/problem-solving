/*************************************
 dp, 그래프(dfs) - Gold 5
 관악산 등산
 * 단방향 그래프를 그리는 것이 중요.
*************************************/ 
#include <iostream>
using namespace std;
int N, M, H;
int height[5000];
bool road[5001][5001] = {false};
long long dp[5001] = {0}; // 쉼터 i에서 쉼터 j까지 

long long solve(int idx) {
    if(dp[idx] > 0) return dp[idx];

    for(int i = 1; i <= N; i++) {
        if(road[idx][i]) {
            dp[idx] = max(dp[idx], solve(i));
        }
    }
    return ++dp[idx];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> H;
        height[i] = H;
    }
    for(int i = 0; i < M; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        height[p1] < height[p2] ? road[p1][p2] = true : road[p2][p1] = true; // 낮은 곳에서 높은 곳으로 가는 것만 길.
    }

    for(int i = 1; i <= N; i++) {
        cout << solve(i) << endl;
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << road[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}