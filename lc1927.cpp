#include <iostream>
#include <string>
#include <math.h>
using namespace std;

bool sumGame(string num) {
    double n = num.length();
    double result = 0.0;

    for(int i = 0; i < n; i++) {
        double sign;
        if(i < n/2) {
            sign = 1;
        } else sign = -1;

        double value;

        if(num[i] == '?') {
            value = 4.5;
        } else {
            value = num[i] - '0';
        }

        result += sign*value;
    }

    if(result != 0.0) return true;
    return false;
}


int main() {
    string num; cout << "Enter string: "; cin >> num;

    if(sumGame(num)) {
        cout << "Alice Wins!"<<endl;
    } else {
        cout << "Bob Wins!"<<endl;
    }
    return 0;
}