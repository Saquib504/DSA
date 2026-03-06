#include <iostream>
using namespace std;


//Brute Force Approach
int celebrity_BF(vector<vector<int>> &M){
    int n = M.size();

    vector<int> KnowsMe(n, 0), MeKnows(n,0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(M[i][j] == 1) {
                KnowsMe[j]++;
                MeKnows[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(KnowsMe[i] == n-1 && MeKnows[i] == 0) return i;
    }

    return -1;
}

//Optimal Approach
int celebrity_Optimal(vector<vector<int>> &M) {
    int n = M.size();

    int top = 0, down = n-1;

    while(top < down) {
        if(M[top][down] == 1) top++;
        else if(M[down][top] == 1) down--;
        else {
            top++;
            down--;
        }
    }

    if(top > down) return -1;

    for(int i = 0; i < n; i++) {
        if(i == top) continue;

        if(M[top][i] == 1 || M[i][top] == 0) return -1;
    }

    return top;
}


int main() {
    vector<vector<int>> M = {{0, 1, 0},
             {0, 0, 0},
             {0, 1, 0}};
    cout << celebrity_BF(M) << endl;
    cout << celebrity_Optimal(M) << endl;

    return 0;
}