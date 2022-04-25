#include <iostream>
#include <stack>
using namespace std;

int main(){
    int num;
    cin >> num;
    stack<int> bracket;
    char *bra = NULL;
    int input=0;
    for (int i=0; i<num; i++) {
        int index=0;
        while (cin >> input) {
            bra[index++] = input;
            char change = getchar();
            if (change == '\n') {
                break;
            }
        }
        for (int j=0; j<index; j++) {
            if (bra[j]=='{' || bra[j]=='[' || bra[j]=='(') {
                bracket.push(bra[j]);
            }
            if (bra[j]=='}' || bra[j]==']' || bra[j]==')') {
                if (bracket.top()=='{' && bra[j]=='}') {
                    bracket.pop();
                }
                else if (bracket.top()=='[' && bra[j]==']') {
                    bracket.pop();
                }
                else if (bracket.top()=='(' && bra[j]==')') {
                    bracket.pop();
                }
                else break;
            }
            
        }
        if (bracket.empty()) {
            cout << "yes" << endl;
        }
        if (!bracket.empty()) {
            cout << "no" << endl;
        }
    }
    
    return 0;
}
