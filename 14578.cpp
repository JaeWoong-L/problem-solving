/*************************************
 DP - Gold 2
 영훈이의 색칠공부
 * 완전순열 식 알아야 함.
 * 나머지 연산은 중간식에 해줘도 동일하게 나옴.
 * 기업 코테에는 나오지 않을 문제.
*************************************/
#include <iostream>
using namespace std;
#define divisor 1000000007
int N;
long long dp[100001] = {0, 0, 1,};
long long fact[100001] = {0, 1, 2,};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 3; i <= N; i++) {
        fact[i] = i*fact[i-1] % divisor;
    }

    for(int i = 3; i <= N; i++) {
        dp[i] = ((i-1)*(dp[i-1] + dp[i-2])) % divisor;
    }
    
    long long answer = (fact[N]*dp[N]) % divisor;
    cout << answer;

    return 0;
}