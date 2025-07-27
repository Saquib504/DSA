#include <iostream>
using namespace std;


int minDistance(string word1, string word2) {
    int n = word1.size();
    int m = word2.size();

    vector<int>prev(m+1, 0);

    for(int i =1; i <= n; i++) {
        vector<int>temp(m+1, 0);

        for(int j = 1; j <= m; j++) {
            if(word1[i-1] == word2[j-1]) {
                temp[j] = 1 + prev[j-1];
            }
            else {
                temp[j] = max(prev[j], temp[j-1]);
            }
        }
        prev = temp;
    }
    cout << prev[m] << endl;
    return n + m - 2*prev[m];
}

int main() {
    string s1 = "";cout << "Enter s1 : "; cin >> s1;
    string s2 = "";cout << "Enter s2 : "; cin >> s1;
    cout << minDistance(s1,s2) << endl;
    cout << "The minimum number of deletions required to make two strings same is " << minDistance(s1, s2) << endl;
    return 0;
}
