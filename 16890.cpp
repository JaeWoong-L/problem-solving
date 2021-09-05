/*************************************
 문자열, deque - Gold 3
 창업
 * 1. 처음엔 string으로 풀었으나,
 * input string의 양끝에서만 삭제가 발생하므로 deque을 사용하는 것이 바람직하다.
 * 
 * 2. 문자열의 앞뒤 모두로 문자가 추가되는 경우,
 * 문자열 2개를 만든 뒤 이어붙이면 훨씬 간편하다.
 * (앞뒤 인덱스를 따로 만들어서 값을 증가,감소시키는 시간을 절약할 수 있다.)
 * 
 * 3. 반복문이 필요할 때 주로 while문을 사용하는 경향이 있는데,
 * for문을 사용하는 것이 가독성이 좋은 경우가 많은 것 같다.
 * 
 * 참고: https://yeeybook.tistory.com/136
*************************************/ 
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

string solution(string s1, string s2) {
    deque<char> koo, cube;
    int n = s1.size();
    string answer(n, '?'); // 정답 문자열 초기화

    // 정렬
    sort(s1.begin(), s1.end()); // 오름차순
    sort(s2.begin(), s2.end(), greater<char>()); // 내림차순
    
    for(int i = 0; i < (n + 1) / 2; i++) {
        koo.push_back(s1[i]);
    }
    for(int i = 0; i < n / 2; i++) {
        cube.push_back(s2[i]);
    }
    
    int idx_left = 0, idx_right = n - 1;
    while(koo.size() > 0 || cube.size() > 0) {
        if(koo.front() < cube.front()) {
            answer[idx_left++] = koo.front();
            koo.pop_front();
        }
        else {
            answer[idx_right--] = koo.back();
            koo.pop_back();     
        }
        if(koo.size() == 0) break;

        if(cube.front() > koo.front()) {
            answer[idx_left++] = cube.front();
            cube.pop_front();
        }
        else {
            answer[idx_right--] = cube.back();
            cube.pop_back();
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    cout << solution(s1, s2);

    return 0;
}