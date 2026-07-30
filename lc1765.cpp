#include <iostream>
using namespace std;


vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n = isWater.size();
    int m = isWater[0].size();

    queue<pair<int, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(isWater[i][j] == 1) {
                q.push({i, j});
                isWater[i][j] = 0;
            } else {
                isWater[i][j] = INT_MAX;
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

            if(nu >= 0 && nu < n && nv >= 0 && nv < m && isWater[nu][nv] > isWater[u][v] + 1) {
                isWater[nu][nv] = isWater[u][v] + 1;
                q.push({nu, nv});
            }
        }
    }

    return isWater;
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

    cout << "\nMatrix: Before Updation: \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }cout << endl;
    }cout<<endl;

    mat = highestPeak(mat);
    
    cout << "Matrix: After Updation with highest peak: \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }cout << endl;
    }cout<<endl;

    return 0;
}