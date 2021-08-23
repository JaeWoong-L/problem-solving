/*************************************
 구현 - Silver 2
 LCD Test
 * 44분
 * 하드코딩해서 풀었지만, 선이 생길 수 있는 7개 구역을 0,1로 나누어서 코딩하면 좀 더 괜찮은 코드가 된다.
 * e.g. 1 = {0,0,1,0,0,1,0}, 0 = {1,1,1,0,1,1,1} 등
*************************************/ 
#include <iostream>
#include <string>
using namespace std;
int s;
long long n;
char LCD[25][130];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> n;

    string str = to_string(n);
    int height = 2*s + 3;
    int width = s + 2;
    for(int i = 0; i < height; i++) {
        if(i == 0) {
            for(int j = 0; j < str.length(); j++) {
                switch(str[j]) {
                    case '1':
                    case '4':
                        for(int k = 0; k < width; k++) {
                            cout << " ";
                        }
                        break;
                    default:
                        cout << " ";
                        for(int k = 2; k < width; k++) {
                            cout << "-";
                        }
                        cout << " ";
                        break;
                }
                cout << " ";
            }
        }
        else if(i <= s) {
            for(int j = 0; j < str.length(); j++) {
                switch(str[j]) {
                    case '1':
                    case '2':
                    case '3':
                    case '7':
                        for(int i = 1; i < width; i++) {
                            cout << " ";
                        }
                        cout << "|";
                        break;
                    case '5':
                    case '6':
                        cout << "|";
                        for(int i = 1; i < width; i++) {
                            cout << " ";
                        }
                        break;
                    default:
                        cout << "|";
                        for(int i = 2; i < width; i++) {
                            cout << " ";
                        }
                        cout << "|";
                        break;
                }
                cout << " ";
            }
        }
        else if(i == s+1) {
            for(int j = 0; j < str.length(); j++) {
                switch(str[j]) {
                    case '1':
                    case '7':
                    case '0':
                        for(int k = 0; k < width; k++) {
                            cout << " ";
                        }
                        break;
                    default:
                        cout << " ";
                        for(int k = 2; k < width; k++) {
                            cout << "-";
                        }
                        cout << " ";
                        break;
                }
                cout << " ";
            }
        }
        else if(i == 2*s + 2) {
            for(int j = 0; j < str.length(); j++) {
                switch(str[j]) {
                    case '1':
                    case '4':
                    case '7':
                        for(int k = 0; k < width; k++) {
                            cout << " ";
                        }
                        break;
                    default:
                        cout << " ";
                        for(int k = 2; k < width; k++) {
                            cout << "-";
                        }
                        cout << " ";
                        break;
                }
                cout << " ";
            }
        }
        else {
            for(int j = 0; j < str.length(); j++) {
                switch(str[j]) {
                    case '1':
                    case '3':
                    case '4':
                    case '5':
                    case '7':
                    case '9':
                        for(int i = 1; i < width; i++) {
                            cout << " ";
                        }
                        cout << "|";
                        break;
                    case '2':
                        cout << "|";
                        for(int i = 1; i < width; i++) {
                            cout << " ";
                        }
                        break;
                    default:
                        cout << "|";
                        for(int i = 2; i < width; i++) {
                            cout << " ";
                        }
                        cout << "|";
                        break;
                }
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}