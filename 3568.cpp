/*************************************
 구현 - Silver 4
 iSharp
 * enum을 사용하면 가독성이 더 나은 것 같으나 불필요해 보이기도 함.
*************************************/ 
#include <iostream>
#include <string>
using namespace std;
enum {
    ALPHA,
    COMMA,
    END,
    SPACE,
    SYMBOL
};
string input;
string data_type_1 = "", data_type_2 = "";
string var[50][2];

int check(char c) {
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return ALPHA;
    else if(c == ',')
        return COMMA;
    else if(c == ';')
        return END;
    else if(c == ' ')
        return SPACE;
    else
        return SYMBOL;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getline(cin, input);
    int idx = 0, count = 0;
    bool isDone = false;
    while(check(input[idx]) == ALPHA) {
        data_type_1 += input[idx++];
    }
    while(check(input[idx]) != SPACE) {
        data_type_2 += input[idx++];
    }
    idx++;
    while(true) {
        int c = check(input[idx]);
        switch(c) {
            case ALPHA:
                var[count][0] += input[idx++];
                break;
            case SYMBOL:
                if(input[idx] == '[') {
                    var[count][1].insert(0, "[]");
                    idx += 2;
                }
                else {
                    string tmp_str;
                    tmp_str += input[idx++];
                    var[count][1].insert(0, tmp_str);
                }
                break;
            case COMMA:
                count++;
                idx += 2;
                break;
            case END:
                isDone = true;
                break;
            default:
                break;
        }
        if(isDone) break;
    }

    for(int i = 0; i <= count; i++) {
        cout << data_type_1 << data_type_2 << var[i][1] << " ";
        cout << var[i][0] << ";" << endl;
    }

    return 0;
}