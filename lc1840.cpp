#include <iostream>
using namespace std;




int yCap(vector<int>& l, vector<int>& r) {
    int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
    return min(y2, y1 + abs(x2 - x1));
}

int yPeak(vector<int>& l, vector<int>& r) {
    int x1 = l[0], y1 = l[1], x2 = r[0], y2 = r[1];
    return (y1 + y2 + x2 - x1) >> 1;
}
int maxBuilding(int num, vector<vector<int>>& r) {
    r.push_back({1, 0});
    sort(r.begin(), r.end());
    int n = r.size();

    for (int i = 1; i < n; i++)
        r[i][1] = yCap(r[i - 1], r[i]);

    for (int i = n - 2; i >= 0; i--)
        r[i][1] = yCap(r[i + 1], r[i]);

    int res = 0;
    for (int i = 1; i < n; i++)
        res = max(res, yPeak(r[i - 1], r[i]));

    return max(res, r[n - 1][1] + num - r[n - 1][0]);
}



int main() {
    int n; cout << "Enter the number of buildings : "; cin >> n;
    vector<vector<int>> r;

    while(true) {
        int x, y;
        cout << "Enter the restrictions : ";
        cin >> x >> y;
        if(x == -1 || y == -1)
            break;
        else
            r.push_back({x, y});
    }

    int ans = maxBuilding(n, r);

    cout << ans << endl;
    return 0;
}