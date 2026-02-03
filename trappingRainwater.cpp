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

//OPtimized approach
// TC -> O(N), SC -> O(1)

int findTotalOptimized(vector<int>&heights) {
    int n = heights.size();
    int leftMax = 0, rightMax = 0, total = 0;
    int l = 0, r = n-1;

    while(l <= r) {
        if(heights[l] <= heights[r]) {
            if(leftMax > heights[l]) {
                total += leftMax - heights[l];
            }
            else {
                leftMax = heights[l];
            }
            l++;
        }
        else {
            if(rightMax > heights[r]) {
                total += rightMax - heights[r];
            }
            else {
                rightMax = heights[r];
            }
            r--;
        }
    }
    return total;
}

int main() {
    vector<int> heights = {4, 2, 0, 3, 2, 5};

    cout << findTotalOptimized(heights) << endl;

    return 0;
}