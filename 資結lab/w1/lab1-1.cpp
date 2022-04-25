#include <iostream>

using namespace std;

int add(int a,int b/*TODO*/) {
    return a + b;
    //TODO
}

void sub(int *a,int *b,int *val/*TODO*/) {
    *val = *a - *b;//TODO
}

void mul(int a ,int b,int& val/*TODO*/) {
    val = a * b;
    //TODO
}

void div(int *a,int b,int& val/*TODO*/) {
    val = (*a) / b;
    //TODO
}

int main() {
    int num1;
    int num2;

    cin >> num1 >> num2;

    int value = 0;
    value = add(num1, num2);
    cout << value << " ";
    
    sub(&num1, &num2, &value);
    cout << value << " ";
    
    mul(num1, num2, value);
    cout << value << " ";
    
    div(&num1, num2, value);
    cout << value << endl;
    return 0;
}