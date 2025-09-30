#include <iostream>
using namespace std;

int main() {
    int a; cout <<"Enter the number to be checked : "; cin >> a;
    int i; cout << "Enter the i-th position that you want to check if set or not: "; cin >> i;

    if((a&(1<<i)) != 0) {
        cout << "Yes, the bit is set" << endl;
    }else {
        cout << "No, the bit is not set" << endl;
    }

    return 0;
}