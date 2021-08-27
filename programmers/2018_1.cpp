/*************************************
 비트연산 - 카카오 2018 1차 코딩테스트
 비밀지도
 *정답률: 81.78%
*************************************/ 
#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    vector<int> arr_sum(n);
    
    for(int i = 0; i < n; i++) {
        arr_sum[i] = arr1[i] | arr2[i];
        string line = "";
        for(int j = 0; j < n; j++) {
            if(arr_sum[i] % 2 == 0) {
                line = " " + line;
            }
            else {
                line = "#" + line;
            }
            arr_sum[i] = arr_sum[i] >> 1;
        }
        answer.push_back(line);
    }
    
    return answer;
}

int main() {
    int n = 5;
    vector<int> arr1 = {9, 20, 28, 18, 11};
    vector<int> arr2 = {30, 1, 21, 17, 28};
    vector<string> ans = solution(n, arr1, arr2);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }

    return 0;
}