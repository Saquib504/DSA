#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> segTree;

void updateSegTree(int i, int l, int r, int idx) {
    if(l == r) {
        segTree[i] = 1;
        return;
    }

    int mid = l + (r-l)/2;

    if(idx <= mid) {
        updateSegTree(2*i+1, l, mid, idx);
    } else {
        updateSegTree(2*i+2, mid+1, r, idx);
    }

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

long long query(int start, int end, int i, int l, int r) {
    if(l > end || r < start) {
        return 0;
    }
    else if(l >= start && r <= end) {
        return segTree[i];
    }

    int mid = l + (r-l)/2;

    int left = query(start, end, 2*i+1, l, mid);
    int right = query(start, end, 2*i+2, mid+1, r);

    return left + right;
}
long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    unordered_map<int, int> map;
    segTree.assign(4*n, 0);

    for(int i = 0; i < n; i++) {
        map[nums2[i]] = i;
    }
    long long result = 0;

    updateSegTree(0, 0, n-1, map[nums1[0]]);

    for(int i = 1; i < n; i++) {
        int idx = map[nums1[i]];
        long long leftCommonCount = query(0, idx, 0, 0, n-1);
        long long leftUncommonCount = i - leftCommonCount;
        long long rightCommonCount = (n - 1 - idx) - leftUncommonCount;

        result += leftCommonCount * rightCommonCount;

        updateSegTree(0, 0, n-1, idx);
    }

    return result;
}


int main() {
    vector<int> nums1, nums2;

    cout << "Enter nums1 elements : "; 
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums1.push_back(n);
    }

    cout << "Enter nums2 elements : ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        nums2.push_back(n);
    }

    cout << "Tota good triplets are : " << goodTriplets(nums1, nums2) << endl;

    return 0;
}