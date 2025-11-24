#include <iostream>
using namespace std;


string convert2Binary(int n) {
    string result = "";

    while(n != 1) {
        if(n % 2 == 1) {
            result = "1" + result;
        }
        else {
            result = "0" + result;
        }

        n = n/2;
        if(n == 1) {
            result = '1' + result;
            break;
        }
    }

    return result;
}

string convert2Decimal(string s) {
    int result = 0;
    int power = 1; // 2^0

    for(int i = s.length() - 1; i >= 0; i--) {
        if(s[i] == '1') {
            result += power;
        }
        power = power * 2;
    }

    return to_string(result);
}


int main() {
    int n; cout << "Enter an integer to be converted into it's binary form: ";cin >> n;
    string s; cout << "Enter the binary number to be converted into it's decimal form: ";cin >>s;

    cout << "Your decimal to binary conversion is :" << convert2Binary(n) << endl;
    cout << "Your binary to decimal conversion is :" << convert2Decimal(s) << endl;
    
}