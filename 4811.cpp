/*************************************
 DP - Gold 5
 알약
*************************************/ 
#include <iostream>
using namespace std;

long long dp[31][31] = {0}; // [W][H]

int main() {
    int N;

    for(int W = 0; W <= 30; W++) {
        for(int H = 0; H <= W; H++) {
            if(H == 0) dp[W][H] = 1;
            else dp[W][H] = dp[W-1][H] + dp[W][H-1];
        }
    }

    while(true) {
        cin >> N;
        if(N == 0) break;
        else cout << dp[N][N] << endl;
    }

    return 0;
}