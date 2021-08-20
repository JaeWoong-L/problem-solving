/*************************************
 dp + dfs - Gold 4
 내리막 길
 *top-down 방식으로 구현
*************************************/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int M, N;
int answer = 0;
int map[501][501];
int dp[501][501]; // dp[x][y] = n  =>  (x,y)에서 (M,N)까지 가는 경로 = n
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


int solve(int x, int y) {
    if(x == M && y == N) {
        return 1;
    }

    if(dp[x][y] != -1) return dp[x][y];
    else {
        dp[x][y] = 0;
        for(int direction = 0; direction < 4; direction++) {
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            if(nx >= 1 && ny >= 1 && nx <= M && ny <= N) {
                if(map[nx][ny] < map[x][y]) {
                    dp[x][y] += solve(nx, ny);
                }
            }
        }
        return dp[x][y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    for(int row = 1; row <= M; row++) {
        for(int col = 1; col <= N; col++) {
            cin >> map[row][col];
            dp[row][col] = -1;
        }
    }

    cout << solve(1, 1);

    return 0;
}