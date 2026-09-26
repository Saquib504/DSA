#include <iostream>
using namespace std;

int n;
vector<int> segTree;

void buildSegTree(int i, int l, int r, vector<int>&baskets) {
    if(l == r) {
        segTree[i] = baskets[l];
        return;
    }

    int mid = l + (r-l)/2;

    buildSegTree(2*i+1, l, mid, baskets);
    buildSegTree(2*i+2, mid+1, r, baskets);

    segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
}

bool querySegTree(int i, int l, int r, int fruit) {
    if(segTree[i] < fruit) return false;
    if(l == r) {
        segTree[i] = -1;
        return true;
    }

    int mid = l + (r-l)/2;
    bool placed = false;

    if(segTree[2*i+1] >= fruit) {
        placed = querySegTree(2*i+1, l, mid, fruit);
    } else {
        placed = querySegTree(2*i+2, mid+1, r, fruit);
    }

    segTree[i] = max(segTree[2*i+1], segTree[2*i+2]);
    return placed;
}

int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    n = fruits.size();
    segTree.resize(4*n);

    buildSegTree(0, 0, n-1, baskets);

    int unplaced = 0;

    for(auto &fruit : fruits) {
        if(querySegTree(0, 0, n-1, fruit)  == false) {
            unplaced++;
        }
    }

    return unplaced;
}

int main() {
    vector<int> fruits, baskets;
    cout << "Enter fruit values : ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        fruits.push_back(n);
    }
    cout << "Enter basket capacities : ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        baskets.push_back(n);
    }

    cout << "Total unplaced fruits are : " << numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}