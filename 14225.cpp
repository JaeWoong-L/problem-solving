/*************************************
 ??? - Gold 5
 부분수열의 합
*************************************/ 
#include <iostream>
using namespace std;
int seq[1100000];
int sum_arr[2000001] = {0};

int main() {
    int N, num;
    cin >> N;

    int count = 0;
    for(int i = 0; i < N; i++) {
        cin >> num;
        
        int curr_count = count;
        seq[count++] = num;
        sum_arr[num] = num;

        int sum;
        for(int j = 0; j < curr_count; j++) {
            sum = seq[j] + num;
            seq[count++] = sum;
            sum_arr[sum] = sum;
        }
    }

    for(int i = 1; i < 2000001; i++) {
        if(sum_arr[i] == 0) {
            cout << i;
            break;
        }
    }


    return 0;
}