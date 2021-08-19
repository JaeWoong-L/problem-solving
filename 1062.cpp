/*************************************
 백트래킹, 브루트 포스, 조합 - Gold 4
 가르침
 *재귀를 이용한 조합 짜는 코드
*************************************/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool alphabet[26] = {false};
string words[50];
char added[26];
int N, K, answer;

int count_readable() {
    int count = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 4; j < words[i].size() - 4; j++) {
            int loc = words[i][j] - 'a';
            if(alphabet[loc] == false) {
                count--;
                break;
            }
        }
        count++;
    }

    return count;
}

void solve(int idx, int cnt) {
    if(cnt == (K - 5)) {
        answer = max(answer, count_readable());
        return;
    }
    
    for(int i = idx; i < 26; i++) {
        if(alphabet[i] == false) {
            alphabet[i] = true;
            solve(i + 1, cnt + 1);
            alphabet[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> words[i];
    }

    alphabet['a' - 'a'] = true;
    alphabet['n' - 'a'] = true;
    alphabet['t' - 'a'] = true;
    alphabet['i' - 'a'] = true;
    alphabet['c' - 'a'] = true;

    int max = K - 5;
    if(K == 26) answer = N;
    else if(max >= 0) {
        solve(0, 0);
    }
    else answer = 0;
    
    cout << answer;

    return 0;
}