/*************************************
 활용할 수 있는 함수(코드) 모음
 -필요한 내용이 있는지 키워드 검색하여 확인.
 -각 함수 위의 주석 코드는 메인함수에서 테스트를 위한 코드.
*************************************/ 
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> tenToTwo(int *, int);
vector<int> findInt(string);

int main() {
    vector<int> ans;
    string s = "12D7S*#654@#1#&@0!";

    ans = findInt(s);
    for(int i = 0; i < 5; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}

// 비트 연산을 활용한 10진수 - 2진수 변환(2018 카카오 코딩테스트 1차 - 1번 문제)
/*
    int arr[] = {9, 20, 28, 18, 11};
    vector<string> ans = tenToTwo(arr, 5);
    for(int i = 0; i < 5; i++) {
        cout << ans[i] << endl;
    }
*/
vector<string> tenToTwo(int *arr, int size) {
    vector<string> answer;
    for(int i = 0; i < size; i++) {
        string line = "";
        for(int j = 0; j < size; j++) {
            if(arr[i] % 2 == 0) {
                line = "0" + line;
            }
            else {
                line = "1" + line;
            }
            arr[i] = arr[i] >> 1;
        }
        answer.push_back(line);
    }

    return answer;
}

// 문자와 숫자가 섞인 문자열에서 숫자 찾아 저장하기(2018 카카오 코딩테스트 1차 - 2번 문제)

vector<int> findInt(string s) {
    vector<int> answer;
    
    int num = 0;
    for(int i = 0; i < s.size(); i++) {
        char c = s[i];
        if(c >= '0' && c <= '9') {
            num = num * 10 + (c - '0');
        }
        else {
            answer.push_back(num);
            num = 0;
        }
    }

    return answer;
}

