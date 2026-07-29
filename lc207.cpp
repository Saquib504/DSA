#include <iostream>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> adj[numCourses];
    vector<int> indegree(numCourses, 0);

    for(auto x : prerequisites) {
        adj[x[1]].push_back(x[0]);
        indegree[x[0]]++;
    }

    queue<int> q;
    int count = 0;

    for(int i  = 0; i < numCourses; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        auto t = q.front(); q.pop();
        count++;

        for(auto x : adj[t]) {
            indegree[x]--;
            if(indegree[x] == 0) {
                q.push(x);
            }
        }
    }

    return count == numCourses;

}


int main() {
    int n; cout << "Enter numCourses: "; cin >> n;
    vector<vector<int>> prerequisites;

    cout << "Enter the prerequisites pair: \n";
    while(true) {
        int a, b;
        cin >> a >> b;

        if(a == -1 || b == -1)break;
        prerequisites.push_back({a,b});
    }

    if(canFinish(n, prerequisites)) {
        cout << "Yes, the following prerequisites for the courses can be finished!";
    } else {
        cout << "No, cannot be finished!";
    }cout <<endl;

    return 0;
}