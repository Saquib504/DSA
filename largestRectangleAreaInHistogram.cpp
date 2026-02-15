#include <iostream>
using namespace std;


int largeArea(vector<int>&histo) {
    int n = histo.size();
    int maxA = 0;
    stack<int>st;

    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i==n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();

            int width;

            if(st.empty())width = i;
            else width = i - st.top() - 1;

            maxA = max(maxA, width*height);
        }
        st.push(i);
    }

    return maxA;
}

//Stack based solution to find the largest rectangle area in histogram

int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    stack<int> stk;
    int maxArea = INT_MIN;

    for(int i = 0; i < n; i++) {
    while(!stk.empty() && heights[stk.top()] > heights[i]) {
        int element = stk.top(); stk.pop();
        int nse = i;
        int pse = stk.empty() ? -1 : stk.top();

        maxArea = max(maxArea, heights[element]*(nse-pse-1));
    }
    stk.push(i);
    }

    while(!stk.empty()) {
    int element = stk.top(); stk.pop();
    int nse = n;
    int pse = stk.empty() ? -1 : stk.top();

    maxArea = max(maxArea, heights[element]*(nse-pse-1));
    }

    return maxArea;
}

int main() {

    int n; cout << "Enter n : ";cin >> n;
    vector<int>histo(n, 0);
    for(int i = 0; i < n; i++) {
        cout << "Enter element-"<<i<< " : ";cin >> histo[i];
    }

    cout << largeArea(histo) << endl;
    cout << largestRectangleArea(histo) << endl;

    return 0;
}