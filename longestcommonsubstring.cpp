#include <iostream>
using namespace std;


string findLCS(string&s1, string&s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>memo(n+1, vector<int>(m+1, 0));
    int maxSize = 0;
    int row = 0, col = 0;

    for(int i =1; i <=n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                memo[i][j] = 1 + memo[i-1][j-1];
                maxSize = memo[i][j] > maxSize ? memo[i][j] : maxSize;
                row = maxSize == memo[i][j] ? i : row;
            }
        }
    }

    int index = memo[row][col]-1;
    string ans = s1.substr(row - maxSize, maxSize);
    return ans;
}

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";

    cout << "The longest commmon substring is : " << findLCS(s1, s2) << endl;
}