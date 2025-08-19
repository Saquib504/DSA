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

int main() {

    int n; cout << "Enter n : ";cin >> n;
    vector<int>histo(n, 0);
    for(int i = 0; i < n; i++) {
        cout << "Enter element-"<<i<< " : ";cin >> histo[i];
    }

    cout << largeArea(histo) << endl;

    return 0;
}