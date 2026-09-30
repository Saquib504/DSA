#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


int n;
vector<int> segMin, segMax, lazy;

void propagate(int i, int l, int r) {
    if(lazy[i] != 0) {
        segMin[i] += lazy[i];
        segMax[i] += lazy[i];

        if(l != r) {
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }

        lazy[i] = 0;
    }
}

void updateRange(int start, int end, int i, int l, int r, int val) {
    propagate(i, l, r);

    if(l > end || r < start) return;

    if(l >= start && r <= end) {
        lazy[i] += val;
        propagate(i, l, r);
        return;
    }

    int mid = l + (r - l)/2;

    updateRange(start, end, 2*i+1, l, mid, val);
    updateRange(start, end, 2*i+2, mid+1, r, val);

    segMin[i] = (segMin[2*i+1] > segMin[2*i+2] ? segMin[2*i+2] : segMin[2*i+1]);
    segMax[i] = max(segMax[2*i+1], segMax[2*i+2]);
}

int findleftmostZero(int i, int l, int r) {
    propagate(i, l, r);

    if(segMin[i] > 0 || segMax[i] < 0) return -1;

    if(l == r) return l;

    int mid = l + (r-l)/2;

    int left = findleftmostZero(2*i+1, l, mid);
    if(left != -1) return left;

    return findleftmostZero(2*i+2, mid+1, r);
}

int longestBalanced(vector<int>&nums) {
    n = nums.size();
    segMin.assign(4*n, 0);
    segMax.assign(4*n, 0);
    lazy.assign(4*n, 0);

    int maxL = 0;
    unordered_map<int, int> mpp;

    for(int r = 0; r < n; r++) {
        int val = (nums[r] % 2 == 0 ? 1 : -1);
        int prev = -1;
        if(mpp.count(nums[r])) {
            prev = mpp[nums[r]];
        }

        if(prev != -1) {
            updateRange(0, prev, 0, 0, n-1, -val);
        }

        updateRange(0, r, 0, 0, n-1, val);

        int left = findleftmostZero(0, 0, n-1);
        if(left != -1) {
            maxL = max(maxL, r - left + 1);
        }

        mpp[nums[r]] = r;
    }

    return maxL;
}


int main() {
    vector<int> nums;
    cout << "Enter : "; 
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        nums.push_back(n);
    }

    cout << "The longest balanced subarray is of length : " << longestBalanced(nums) << endl;
    return 0;
}