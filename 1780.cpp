/*************************************
 분할정복, 재귀 - Silver 2
 종이의 개수
*************************************/ 
#include <iostream>
using namespace std;
int arr[3000][3000];
int answer[3] = {0};

bool all_same(int row, int col, int n) {
    int num = arr[row][col];

    for(int i = row; i < row + n; i++) {
        for(int j = col; j < col + n; j++) {
            if(arr[i][j] != num) return false;
        }
    }
    
    return true;
}

void divide(int row, int col, int n) {
    if(all_same(row, col, n)) {
        answer[arr[row][col]]++;
    }
    else {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                divide(row + (n/3 * i), col + (n/3 * j), n/3);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;

    int num;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> num;
            arr[i][j] = num + 1;
        }
    }

    divide(0, 0, N);

    for(int i = 0; i < 3; i++) {
        cout << answer[i] << endl;
    }

    return 0;
}