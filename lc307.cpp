#include <iostream>
using namespace std;

int n;
vector<int> segTree;
vector<int> temp;

void buildTree(int i, int l, int r) {
    if(l == r) {
        segTree[i] = temp[l];
        return;
    }
    int mid = l + (r-l)/2;

    buildTree(2*i+1, l, mid);
    buildTree(2*i+2, mid+1, r);

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

void updateSegTree(int idx, int val, int i, int l ,int r) {
    if(l == r) {
        segTree[i] = val;
        return;
    }

    int mid = l + (r-l)/2;

    if(idx <= mid) {
        updateSegTree(idx, val, 2*i+1, l, mid);
    } else {
        updateSegTree(idx, val, 2*i+2, mid+1, r);
    }

    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int Query(int start, int end, int i, int l, int r) {
    if(l > end || r < start) return 0;
    if(l >= start && r <= end) return segTree[i];
    int mid = l + (r-l)/2;

    return Query(start, end, 2*i+1, l, mid) + Query(start, end, 2*i+2, mid+1, r);
}
NumArray(vector<int>& nums) {
    n = nums.size();
    segTree.resize(4*n);
    temp = nums;
    buildTree(0, 0, n-1);
}

void update(int index, int val) {
    updateSegTree(index, val, 0, 0, n-1);
}

int sumRange(int left, int right) {
    return Query(left, right, 0, 0, n-1);
}


