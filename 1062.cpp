/*************************************
 ??? - Gold 4
 가르침
*************************************/ 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool alpha[26] = {false};
string words[50];
vector<char> added;

int main() {
    int N, K;
    cin >> N >> K;

    alpha['a' - 'a'] = true;
    alpha['n' - 'a'] = true;
    alpha['t' - 'a'] = true;
    alpha['i' - 'a'] = true;
    alpha['c' - 'a'] = true;

    string word;
    for(int i = 0; i < N; i++) {
        cin >> words[i];

        for(int j = 4; j < words[i].size() - 4; j++) {
            if(alpha[words[i][j] - 'a'] == false) {
                alpha[words[i][j] - 'a'] = true;
                added.push_back(words[i][j]);
            }
        }
    }
    sort(added.begin(), added.end());

    int answer = 0;
    if(K < 5) cout << answer;
    else {
        do {
            
        }while(next_permutation(added.begin(), added.end()));
    }
    return 0;
}