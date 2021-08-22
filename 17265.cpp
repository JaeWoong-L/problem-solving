/*************************************
 dp - Gold 5
 나의 인생에는 수학과 함께
 *
*************************************/ 
#include <iostream>
using namespace std;
#define MAX 4000
#define MIN -1000
int N;
int map[5][5];
int dp_max[5][5];
int dp_min[5][5];

int calculate(int a, int b, int sign) {
    switch(sign) {
        case 0:
            return a+b;
            break;
        case 1:
            return a-b;
            break;
        case 2:
            return a*b;
            break;
        default:
            return -1;
            break;
    }
}

void solve(int x, int y) {
    int val1, val2;
    if(x == 0 && y == 0) {
        dp_max[x][y] = map[x][y];
        dp_min[x][y] = map[x][y];
    }
    else {
        if(x-2 >= 0) {
            dp_max[x][y] = max(dp_max[x][y], calculate(dp_max[x-2][y], map[x][y], map[x-1][y]));
            dp_min[x][y] = min(dp_min[x][y], calculate(dp_min[x-2][y], map[x][y], map[x-1][y]));
        }
        if(x-1 >= 0 && y-1 >= 0) {
            dp_max[x][y] = max(dp_max[x][y], max(calculate(dp_max[x-1][y-1], map[x][y], map[x-1][y]), calculate(dp_max[x-1][y-1], map[x][y], map[x][y-1])));
            dp_min[x][y] = min(dp_min[x][y], min(calculate(dp_min[x-1][y-1], map[x][y], map[x-1][y]), calculate(dp_min[x-1][y-1], map[x][y], map[x][y-1])));
        }
        if(y-2 >= 0) {
            dp_max[x][y] = max(dp_max[x][y], calculate(dp_max[x][y-2], map[x][y], map[x][y-1]));
            dp_min[x][y] = min(dp_min[x][y], calculate(dp_min[x][y-2], map[x][y], map[x][y-1]));
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((i+j) % 2 == 0) {
                cin >> map[i][j];
                dp_max[i][j] = MIN;
                dp_min[i][j] = MAX;
            }
            else {
                char c;
                cin >> c;
                switch(c) {
                    case '+':
                        map[i][j] = 0;
                        break;
                    case '-':
                        map[i][j] = 1;
                        break;
                    case '*':
                        map[i][j] = 2;
                        break;
                    default:
                        break;
                }
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if((i+j) % 2 == 0) solve(i, j);
        }
    }

    cout << dp_max[N-1][N-1] << " " << dp_min[N-1][N-1];

    return 0;
}