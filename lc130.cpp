#include <iostream>
using namespace std;


void solve(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<int, int>> q;


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if((i == 0 || j == 0 || i == n-1 || j == m-1) && (board[i][j] == 'O')) {
                q.push({i, j});
            }
        }
    }

    int du[] = {0,-1,0,1};
    int dv[] = {-1,0,1,0};

    while(!q.empty()) {
        auto [u,v] = q.front(); q.pop();

        vis[u][v] = 1;

        for(int i = 0; i < 4; i++) {
            int nu = u + du[i];
            int nv = v + dv[i];

            if(nu >= 0 && nu < n && nv >= 0 && nv < m && board[nu][nv] == 'O' && vis[nu][nv] == 0) {
                q.push({nu, nv});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(vis[i][j] == 1) {
                board[i][j] = 'O';
            } else {
                board[i][j] = 'X';
            }
        }
    }
}



int main() {
int n, m; cout << "Enter the size of the matrix NxM: "; cin >> n >> m;
vector<vector<char>> mat(n, vector<char>(m));

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

solve(mat);

cout << "Matrix: After Updation with highest peak: \n";
for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
        cout << mat[i][j] << " ";
    }cout << endl;
}cout<<endl;

return 0;
}