#include <iostream>
using namespace std;

class DisjointSet{
    vector<int> rank, size, parent;
    public:
    DisjointSet(int n){
        rank.resize(n+1, 1);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v)return;       //u and v part of same component

        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);

        if(ulp_u == ulp_v)return;       //u and v part of same component

        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

int main(){
    DisjointSet ds(7);

    ds.unionBySize(1,2);
    ds.unionBySize(2,3);
    ds.unionBySize(4,5);
    ds.unionBySize(6,7);
    ds.unionBySize(5,6);
    //are 3 and 7 part of same component
    if(ds.findPar(3) == ds.findPar(7)){
        cout << "\nBoth \3 and \7 are part of same component\n";
    }
    else{
        cout << "\nNope, they are not part of same component\n";
    }
    cout << "\nBut after finding their ultimate parent\n" << endl;
    ds.unionByRank(3,7);
    int u = 3;
    int v = 7;
    if(ds.findPar(u) == ds.findPar(v)){
        cout << "\nBoth " << u << " and " << v << " are part of same component\n";
    }
    else{
        cout << "\nNope, they are not part of same component\n";
    }
}