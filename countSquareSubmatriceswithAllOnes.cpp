#include <iostream>
using namespace std;

int countSubMatrix(vector<vector<int>>&mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>memo(n, vector<int>(m, 0));

    //fill first row
    for(int j =0; j <m; j++)memo[0][j] = mat[0][j];
    //fill first column
    for(int i = 0;i <n; i++)memo[i][0] = mat[i][0];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(mat[i][j] ==1) {
                if(mat[i-1][j] == 1 && mat[i][j-1] == 1 && mat[i-1][j-1] == 1) {
                    memo[i][j] = 1 + min(memo[i][j-1], min(memo[i-1][j], memo[i-1][j-1]));
                }
                else {
                    memo[i][j] = mat[i][j];
                }
            }
        }
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            count += memo[i][j];
        }
    }
    return count;
}

int main() {
    vector<vector<int>> mat = {
        {0,1,1,1},
        {1,1,1,1},
        {0,1,1,1},
    };

    cout << "The number of square submatrices in the given matrix is " << countSubMatrix(mat) << endl;

    return 0;
}