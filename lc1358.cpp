#include <iostream>
using namespace std;


int sumSubStrings(string s) {
    int n = s.size();
    int lastscan[3] = {-1, -1, -1};
    int count = 0;

    for(int r = 0; r < n; r++) {
        lastscan[s[r] - 'a'] = r;

        count += 1 + min(lastscan[0], min(lastscan[1], lastscan[2]));
    }

    return count;
}

int main() {
    string s; cout << "Enter a string: ";
    cin >> s;
    cout << sumSubStrings(s) << endl;
    return 0;
}