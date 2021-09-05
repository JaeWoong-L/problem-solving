/*************************************
 문자열, deque - Gold 3
 창업
 * string만으로 문제를 풀었지만, 이런 경우엔 deque을 사용하는 것이 바람직하다.
*************************************/ 
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool desc(char &a, char &b) {
    return a > b;
}

string solution(string s1, string s2) {
    string answer;
    int size = s1.size();
    for(int i = 0; i < size; i++) {
        answer += "?";
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end(), desc);
    
    if(size % 2 == 0) {
        s1 = s1.substr(0, size/2);
        s2 = s2.substr(0, size/2);
    }
    else {
        s1 = s1.substr(0, size/2 + 1);
        s2 = s2.substr(0, size/2);
    }
    
    int idx_left = 0, idx_right = size - 1;
    while(s1.size() > 0 || s2.size() > 0) {
        if(s1.front() < s2.front()) {
            answer[idx_left++] = s1.front();
            s1.erase(0, 1);
        }
        else {
            answer[idx_right--] = s1.back();
            s1.erase(s1.size() - 1, 1);     
        }
        // cout << "1: " << answer << endl;
        if(s2.size() == 0) break;

        if(s2.front() > s1.front()) {
            answer[idx_left++] = s2.front();
            s2.erase(0, 1);
        }
        else {
            answer[idx_right--] = s2.back();
            s2.erase(s2.size() - 1, 1);
        }
        // cout << "2: " << answer << endl;
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