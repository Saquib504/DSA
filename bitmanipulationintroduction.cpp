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


int main() {
    int n; cout << "Enter an integer to be converted into it's binary form: ";cin >> n;
    string s; cout << "Enter the binary number to be converted into it's decimal form: ";cin >>s;

    cout << "Your decimal to binary conversion is :" << convert2Binary(n) << endl;
    
}