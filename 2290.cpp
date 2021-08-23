/*************************************
 구현 - Silver 2
 LCD Test
 * 44분
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