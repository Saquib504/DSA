#include <iostream>
using namespace std;


int numEnclaves(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || i == n-1 || j == 0 || j == m-1) && grid[i][j] == 1) {
                grid[i][j] = 0;
                q.push({i,j});
            }
        }
    }

    int du[] = {0,-1,0,1};
    int dv[] = {-1,0,1,0};

    while(!q.empty()) {
        auto [u,v] = q.front(); q.pop();

        for(int i = 0; i < 4; i++) {
            int nu = u + du[i];
            int nv = v + dv[i];

            if(nu >= 0 && nu < n && nv >= 0 && nv < m && grid[nu][nv] == 1) {
                grid[nu][nv] = 0;
                q.push({nu, nv});
            }
        }
    }

    int numEnclaves = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(grid[i][j] == 1)numEnclaves++;
        }
    }

    return numEnclaves;
}



int main() {
    int n, m; cout << "Enter the size of the matrix NxM: "; cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    cout << "Enter the value present in each cell: \n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int num = numEnclaves(mat);

    cout << "The num of enclaved 1's in the matrix are " << num << endl;
    

    return 0;
}