/*************************************
 구현 - Silver 5
 CPU
 * map과 bitset 사용.
*************************************/ 
#include <iostream>
#include <string>
#include <map>
#include <bitset>
using namespace std;
int N;
map<string, string> opcodes;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    opcodes["ADD"] = "00000";
    opcodes["ADDC"] = "00001";
    opcodes["SUB"] = "00010";
    opcodes["SUBC"] = "00011";
    opcodes["MOV"] = "00100";
    opcodes["MOVC"] = "00101";
    opcodes["AND"] = "00110";
    opcodes["ANDC"] = "00111";
    opcodes["OR"] = "01000";
    opcodes["ORC"] = "01001";
    opcodes["NOT"] = "01010";
    opcodes["MULT"] = "01100";
    opcodes["MULTC"] = "01101";
    opcodes["LSFTL"] = "01110";
    opcodes["LSFTLC"] = "01111";
    opcodes["LSFTR"] = "10000";
    opcodes["LSFTRC"] = "10001";
    opcodes["ASFTR"] = "10010";
    opcodes["ASFTRC"] = "10011";
    opcodes["RL"] = "10100";
    opcodes["RLC"] = "10101";
    opcodes["RR"] = "10110";
    opcodes["RRC"] = "10111";

    cin >> N;
    for(int i = 0; i < N; i++) {
        string machine_code = "";
        string opcode;
        int rD, rA, rB, C;
        cin >> opcode >> rD >> rA;
        if(opcode.back() == 'C')
            cin >> C;
        else
            cin >> rB;

        machine_code += opcodes.find(opcode)->second;
        machine_code += "0";
        machine_code += bitset<3>(rD).to_string();
        if(opcode == "MOV" || opcode == "MOVC" || opcode == "NOT") {
            machine_code += "000";
        }
        else {
            machine_code += bitset<3>(rA).to_string();
        }
        if(opcode.back() == 'C') {
            machine_code += bitset<4>(C).to_string();
        }
        else {
            machine_code += bitset<3>(rB).to_string();
            machine_code += "0";
        }

        cout << machine_code << endl;
    }

    return 0;
}