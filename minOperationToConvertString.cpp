#include <iostream>
using namespace std;



int minOperations(string&s1, string&s2) {
    int n = s1.size();
    int m = s2.size();  

    vector<vector<int>>memo(n+1, vector<int>(m+1, 0));


    for(int i =1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) {
                memo[i][j] = 1 + memo[i-1][j-1];
            }
            else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    return n+m  - 2*memo[n][m];
}
 

int main() {

    string s1; cout << "Enter String A : ";cin >> s1;
    string s2; cout << "Enter String B : ";cin >> s2;

    cout << "The minimum number of operations to convert string A to B is " << minOperations(s1,s2) << endl;
    return 0;
}