#include <iostream>
using namespace std;


static constexpr intdirs[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};


int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(A[0][0] || A.back().back()) {
            return 0;
        }

        int n = A.size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(A[i][j]) {
                    q.push(A[i][j]);
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            int v = A[i][j];

            for(auto& d : dirs) {
                int x = i + d[0];
                int y = j + d[1];

                if(min(x,y) >= 0 && max(x, y) < n && !A[x][y]) {
                    A[x][y] = v + 1;
                    q.push({x,y});
                }
            }
        }

        priority_queue<tuple<int, int, int>>pq;

        pq.push({A[0][0], 0, 0});
        while(!pq.empty()) {
            auto 
        }
}


