#include <iostream>
using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    if(!k) return grid;
    int n = grid.size();
    int m = grid[0].size();
    int sz = n*m;

    k %= sz;

    if(!k) return grid;

    auto Reverse = [&](int i, int j) {
        while(i < j) {
            swap(grid[i/m][i%m], grid[j/m][j%m]);
            i++;
            j--;
        }
    };

    Reverse(0, sz-1);
    Reverse(0, k-1);
    Reverse(k, sz-1);

    return grid;
}


int main() {
    int n, m; cout << "Enter the size of rows and cols in the grid: "; cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    
    cout << "Enter the elements present in the grid: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int num; cin >> num;
            grid[i][j] = num;
        }
    }

    int k; cout << "\n Enter the value of shift parameter k: "; cin >> k;

    cout << "Before shifting the grid: \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }cout<<endl;
    }cout <<endl;

    grid = shiftGrid(grid, k);

    cout << "After shifting the grid elements k times, the elements with new position is : \n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << grid[i][j] << " ";
        }cout<<endl;
    }cout <<endl;

    return 0;
}