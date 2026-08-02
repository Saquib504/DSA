#include <iostream>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int V = numCourses;
    int count = 0;
    vector<int> ans;
    vector<int> inDegree(V, 0);
    vector<int> adj[V];
    queue<int> q;


    for(auto it : prerequisites) {
        int u = it[1];
        int v=  it[0];
        inDegree[v]++;
        adj[u].push_back(v);
    }

    for(int i = 0; i < V; i++) {
        if(inDegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        auto node = q.front();  q.pop();
        ans.push_back(node);
        count++;

        for(auto nbr : adj[node]) {
            inDegree[nbr]--;
            if(inDegree[nbr] == 0)q.push(nbr);
        }
    }

    if(count == numCourses) {
        return ans;
    } else {
        return {};
    }
}

int main() {
    int numCourses; cout << "Enter the number of courses: "; cin >> numCourses;
    vector<vector<int>> prerequisites;

    cout << "Enter the coure pair in the order [v,u], where u comes before v: \n";

    while(true) {
        int n, m;
        cin >> n >> m;
        if(n == -1 || m == -1)break;

        prerequisites.push_back({n, m});
    }

    vector<int> ans = findOrder(numCourses, prerequisites);
    if(ans.size() == 0) cout << "Invalid prerequisites";
    else {
        for(int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }cout<<endl;
    }

    return 0;
}