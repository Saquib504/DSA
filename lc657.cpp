#include <iostream>
using namespace std;

bool judgeCircle(string moves) {
    if(moves.length() == 0) return true;
    int x = 0, y = 0;
    for(auto m : moves) {
        if(m == 'U') {
            x += 1;
        }
        else if(m == 'D') {
            x -= 1;
        }
        else if(m == 'L') {
            y -= 1;
        }
        else {
            y += 1;
        }
    }

    return (x == 0 && y == 0);
}


int main() {
    string s = "ULURRDDDLU";
    cout << judgeCircle(s) << endl;
    return 0;
}