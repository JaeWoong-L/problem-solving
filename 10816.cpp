/*************************************
 정렬, 이분탐색 - Silver 4
 숫자 카드 2
 *upper bound, lower bound 직접 구현해 볼 필요 있음.
*************************************/ 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int deck[500000];
int quiz[500000];

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
        int *start, *end;
        start = lower_bound(deck, deck + N, quiz[i]);
        end = upper_bound(deck, deck + N, quiz[i]);
        cout << end - start << " ";
    }

    return 0;
}