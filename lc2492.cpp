#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// roads[i]  --> {u,v, distance}

int minScore(int n, vector<vector<int>>& roads) {
    vector<int> root(n+1);
    iota(root.begin(), root.end(), 0);

    auto find = [&](this auto& self, int i) -> int {
        return root[i] == i ? i : root[i] = self(root[i]);
    };

    for(auto& r : roads) {
        root[find(r[0])] = find(r[1]);
    }

    int res = 10001;
    for(auto& r : roads) {
        if(find(r[0]) == find(r[1])) {
            res = min(res, r[2]);
        }
    }

    return res;
}


int main() {
    int n; cout << "Enter the numebr of nodes: "; cin >> n;

    vector<vector<int>> roads;
    cout << "\nEnter the roads between 2 nodes -> {u,v,distance} : \n";

    while(true) {
        int u, v, distance;
        cin >> u >> v >> distance;
        if(u == -1 || v == -1 || distance == -1)break;
        else {
            roads.push_back({u,v,distance});
        }
    }

    cout << "The minimum score is : " << minScore(n, roads) << endl;

    return 0;
}