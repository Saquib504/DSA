#include <iostream>
using namespace std;

//Better approach
// TC -> O(N), SC -> O(N)
int findTotal(vector<int> &heights) {
    int n = heights.size();
    
    //find the prefix array
    int prefix[n];
    prefix[0] = heights[0];

    for(int i = 1; i < n; i++) {
        prefix[i] = max(prefix[i-1], heights[i]);
    }

    //find the suffix array
    int suffix[n];
    suffix[n-1] = heights[n-1];

    for(int i = n-2; i >= 0; i--) {
        suffix[i] = max(suffix[i+1], heights[i]);
    }


    //find the total water trapped

    int total = 0;

    for(int i = 0; i < n; i++) {
        if(prefix[i] > heights[i] && suffix[i] > heights[i]) {
        total += min(prefix[i], suffix[i]) - heights[i];
        }
    }

    return total;
}


int main() {
    vector<int> heights = {4, 2, 0, 3, 2, 5};

    cout << findTotal(heights) << endl;

    return 0;
}