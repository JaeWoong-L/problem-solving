/*************************************
 해싱 - Bronze 2
 Hashing
 * 굳이 거듭제곱 값을 저장하는 것보다
   이전 값만 저장해놓고 mod 연산만 해주는 것이 더 좋음.
*************************************/ 
#include <iostream>
#include <string>

using namespace std;
long long dp[50];

void store_pow(int L, int r, int M) {
    dp[0] = 1;
    for(int i = 1; i < L; i++) {
        dp[i] = (dp[i-1] * r) % M;
    }
    return;
}

long long solution(int L, string s) {
    long long answer = 0;
    int r = 31;
    int M = 1234567891;
    store_pow(L, r, M);

    for(int i = 0; i < L; i++) {
        int c = s[i] - 'a' + 1;
        answer += (c * dp[i]);
        answer %= M;
    }

    return answer;
}

int main() {
    int L;
    string s;
    cin >> L >> s;
    cout << solution(L, s);

    return 0;
}