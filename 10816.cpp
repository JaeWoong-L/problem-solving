/*************************************
  - Silver 4
 숫자 카드 2
*************************************/ 
#include <iostream>
#include <algorithm>
using namespace std;
int deck[500000];
int quiz[500000];
int answer[500000] = {0};

int main() {
    int N, M;
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> deck[i];
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> quiz[i];
    }

    sort(deck, deck + N);

    for(int i = 0; i < M; i++) {
        int count = 0;    
        int left = 0;
        int right = N - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(deck[mid] == quiz[i]) {
                if(mid == N-1) {
                    count++;
                    break;
                }
                else if(mid == 0) {}
            }
            else if(deck[mid] > quiz[i]) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        cout << count << " ";
    }

    return 0;
}