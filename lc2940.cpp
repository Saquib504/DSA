#include <iostream>
using namespace std;


constexpr int N = 5e4+5;
int segTree[4*N];
void buildSegTree(int i, int l, int r, vector<int>&heights) {
    if(l == r) {
        segTree[i] = l;
        return;
    }

    int mid = l + (r-l)/2;

    buildSegTree(2*i+1, l, mid, heights);
    buildSegTree(2*i+2, mid+1, r, heights);

    int leftIDX = segTree[2*i+1];
    int rightIDX = segTree[2*i+2];

    segTree[i] = (heights[leftIDX] >= heights[rightIDX]) ? leftIDX : rightIDX;
}

int RMIQ(int start, int end, int i, int l, int r, vector<int> &heights) {
    if(l > end || r < start) return -1;
    if(l >= start && r <= end) return segTree[i];

    int mid = l + (r-l)/2;

    int leftIDX = RMIQ(start, end, 2*i+1, l ,mid, heights);
    int rightIDX = RMIQ(start, end, 2*i+2, mid+1, r, heights);

    if(leftIDX == -1) return rightIDX;
    if(rightIDX == -1) return leftIDX;
    return (heights[leftIDX] >= heights[rightIDX]) ? leftIDX : rightIDX;
}

vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size();

    buildSegTree(0, 0, n-1, heights);

    vector<int> result;

    for(auto & q : queries) {
        int minIDX = min(q[0], q[1]);
        int maxIDX = max(q[0], q[1]);

        if(minIDX == maxIDX) {
            result.push_back(minIDX);
        }

        else if(heights[maxIDX] > heights[minIDX]) {
            result.push_back(maxIDX);
        }
        else {
            int l = maxIDX + 1;
            int r = n-1;

            int resultIDX = INT_MAX;

            while(l <= r) {
                int mid = l + (r-l)/2;

                int idx = RMIQ(l, mid, 0, 0, n-1, heights);

                if(heights[idx] > max(heights[minIDX], heights[maxIDX])){
                    resultIDX = idx;
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
            if(resultIDX == INT_MAX) {
                result.push_back(-1);
            } else {
                result.push_back(resultIDX);
            }
        }
    }
    return result;
}


int main() {
    vector<int> heights;
    cout << "Enter heights of each building(enter -1 on completion) : ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        heights.push_back(n);
    }

    vector<vector<int>> queries;
    cout << "Enter each query(a, b) : ";
    while(true) {
        int a, b;
        cin >> a >> b;
        if(a == -1 || b == -1)break;

        queries.push_back({a, b});
    }

    vector<int> ans = leftmostBuildingQueries(heights, queries);


    cout << "LeftMost Building where Alice and Bob can meet : ";
    for(auto x : ans) {
        cout << x << " ";
    }cout <<endl;

    return 0;
}