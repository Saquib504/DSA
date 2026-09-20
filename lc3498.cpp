#include <iostream>
using namespace std;

int reverseDegree(string s) {
    int n = 0;

    for(int i = 0; i < s.size(); i++) {
        n += (i+1)*(26 + 'a' - s[i]);
    }

    return n;
}

int main() {
    string s;
    cout << "Enter string: "; cin >> s;


    cout << reverseDegree(s) << endl;

    return 0;
}