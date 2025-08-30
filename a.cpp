#include <iostream>
using namespace std;



int main() {
    string name = "saquib";
    cout << name << endl;
    name = name.substr(0,2) + " " + name.substr(2,5);
    cout << name << endl;

    return 0;
}