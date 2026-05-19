#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

/*
Problem
The inner for loop scans from idx+2 to n every time a node is dequeued, potentially re-scanning already-visited same-value indices. This gives O(n²) in the worst case (e.g., all elements equal).
Fix — Erase from map after processing
Pre-build a value → indices map. Once all same-value neighbors of an index are queued, erase that value from the map so no future node wastes time re-scanning them.

Your loop logic
for(int i = idx + 2; i < n; i++) {
    if(arr[i] == arr[idx] && !vis[i]) {
        q.push({i, steps+1});
        vis[i] = 1;
    }
}

Fixed loop logic
if (mp.count(arr[idx])) {
    for (int i : mp[arr[idx]]) {
        if (!vis[i]) {
            vis[i] = true;
            q.push({i, steps + 1});
        }
    }
    mp.erase(arr[idx]);  // ← KEY: never scan this value again
}


Why this works
                    Your code                   Fixed code
Same-value scan     Repeated every dequeue      Done once per unique value, then erased
Time complexity     O(n²)                       O(n) amortized



*/




int minJumps(vector<int>& arr) {

    int n = arr.size();
    if(n <= 1) return 0;

    unordered_map<int, vector<int>>mp;
    for(int i = 0; i < n; i++) {
        mp[arr[i]].push_back(i);
    }

    queue<pair<int, int>> q;
    vector<int> vis(n, 0);
    q.push({0,0});
    vis[0] = 1;

    while(!q.empty()) {
        int idx = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(idx == n-1) return steps;


        if(idx - 1 >= 0 && !vis[idx-1]) {
            q.push({idx-1, steps+1});
            vis[idx-1] = 1;
        }

        if(idx + 1 < n && !vis[idx + 1]) {
            q.push({idx+1, steps+1});
            vis[idx+1] = 1;
        }

        if(mp.count(arr[idx])) {
            for(int i : mp[arr[idx]]) {
                if(!vis[i]) {
                    q.push({i, steps+1});
                    vis[i] = 1;
                }
            }
        }
        mp.erase(arr[idx]);
    }
    return -1;
}


int main() {
    vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << minJumps(arr) << endl;
    return 0;
}