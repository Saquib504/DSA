#include <iostream>
using namespace std;


int largeRectangle(vector<int>&histo) {
    int n = histo.size();
    stack<int>st;
    int maxA = 0;

    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
            int height = histo[st.top()];
            st.pop();
            int width;
            if(st.empty()) width = i;
            else width = i - st.top() - 1;

            maxA = max(maxA, width*height);
        }
        st.push(i);
    }
    return maxA;
}


int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> histo(m ,0);
    int maxArea = 0;

    for(int i = 0; i < n;i++) {
    for(int j = 0; j < m; j++) {
        if(matrix[i][j] == 1)histo[j]++;
        else histo[j] = 0;
    }
    int area = largeRectangle(histo);
    maxArea = max(maxArea, area);
    }

    return maxArea;
}

int main() {

    vector<vector<int>> matrix = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    cout << "The maximum area of a rectangle in the matrix is " << maximalAreaOfSubMatrixOfAll1(matrix) << endl;

    return 0;
}