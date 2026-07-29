#include <iostream>
using namespace std;


vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int n = image.size();
    int m = image[0].size();
    int originalColor = image[sr][sc];

    if(originalColor == color) return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = color;
    

    int du[] = {0,-1,0,1};
    int dv[] = {-1,0,1,0};

    while(!q.empty()) {
        int sz = q.size();

        for(int i = 0; i < sz; i++) {
            auto [u,v] = q.front(); q.pop();

            for(int j = 0; j < 4; j++) {
                int nu = u + du[j];
                int nv = v + dv[j];

                if(nu >= 0 && nu < n && nv >= 0 && nv < m && image[nu][nv] == originalColor) {
                    q.push({nu,nv});
                    image[nu][nv] = color;
                }
            }
        }
    }

    return image;
}




int main() {
    int n, m; cout << "Enter the size of the image NxM: "; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    cout << "Enter the type of color present in each cell of the image: \n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int sr,sc,color;
    cout << "\nEnter the coordinates of the source cell (sr,sc): "; cin >> sr >> sc;
    cout << "\nEnter the preferred color: "; cin >> color;

    vector<vector<int>> image = floodFill(grid, sr, sc, color);

    cout << "Here is the image after changing the color: \n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << image[i][j] << " ";
        }cout<<endl;
    }cout<<endl;

    return 0;
}