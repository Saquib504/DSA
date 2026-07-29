#include <iostream>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int freshCount = 0;
    int minutes = 0;

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({i,j});
            }
            else if(grid[i][j] == 1){
                freshCount++;
            }
        }
    }

    if(freshCount == 0) return 0;

    int du[] = {0,-1,0,1};
    int dv[] = {-1,0,1,0};

    while(!q.empty() && freshCount > 0) {
        int sz = q.size();

        for(int i = 0; i < sz; i++) {
            auto [u,v] = q.front(); q.pop();

            for(int j = 0; j < 4; j++) {
                int nu = u + du[j];
                int nv = v + dv[j];

                if(nu >= 0 && nu < n && nv >= 0 && nv < m && grid[nu][nv] == 1) {
                    q.push({nu,nv});
                    grid[nu][nv] = 2;
                    freshCount--;

                }
            }
        }
        minutes++;
    }

    return freshCount == 0 ? minutes : -1;
}


int main() {
    int n, m; cout << "Enter the size of the grid NxM: "; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the type of orange present in each cell: \n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int cnt = orangesRotting(grid);
    if(cnt == -1) {
        cout << "\nNot all Oranges were rotten, some were left fresh\n";
    } else {
        cout << "\nTotal time taken to rotten all oranges: " << cnt << endl;
    }

    return 0;
}