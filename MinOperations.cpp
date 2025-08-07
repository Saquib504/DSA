#include <iostream>
using namespace std;

class DisjointSet {
    public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v)return;

        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntExtra = 0;

        for(auto it : connections){
            int u = it[0];
            int v = it[1];

            if(ds.findUPar(u) == ds.findUPar(v)) {
                cntExtra++;
            }
            else { 
                ds.unionBySize(u,v);
            }
        }

        int cntParent = 0;

        for(int i = 0;i < n; i++){
            if(ds.parent[i] == i) {
                cntParent++;
            }
        }
        if(cntExtra >= cntParent - 1)return cntParent - 1;
        return -1;
    }
};

int main() {
    vector<vector<int>> connections = {{0,1}, {0,2}, {0,3}, {1,2}, {2,3}, {4,5}, {5,6}, {7,8}};
    int V = 9;
    Solution Sol;
    int ans = Sol.makeConnected(V, connections);

    cout << "Minimum number of operations : " << ans << " \n";

}