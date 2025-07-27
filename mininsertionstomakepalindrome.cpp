#include <iostream>
using namespace std;

int findLCS(string&s) {
    int n = s.size();

    vector<int>prev(n+1, 0);

    for(int i =1; i <= n; i++) {
        vector<int>temp(n+1, 0);
        for(int j = 1; j <= n; j++) {
            if(s[i-1] == s[n-j]) {
                temp[j] = 1 + prev[j-1];
            } else {
                temp[j] = max(prev[j], temp[j-1]);
            }
        }
        prev = temp;
    }
    return n - prev[n];

}

int main() {
    string s;
    cout << "Enter string : "; cin >> s;

    cout << "The minimum number of insertions required are " << findLCS(s) << endl;
    return 0;
}