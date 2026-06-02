#include <iostream>
#include <vector>
using namespace std;


//TC -> O(N*budget), SC -> O(N*budget)
int mini, n;
int dp[1000][1500];
int solve(int i, int total, vector<vector<int>>& items, vector<int>& free) {
    if(i >= items.size()) return total/mini;
    
    if(dp[i][total] != -1) return dp[i][total];

    int take = 0, notTake = 0;

    if(total >= items[i][1]) {
        take = free[i] + solve(i+1, total - items[i][1], items, free);
    }

    notTake = solve(i+1, total, items, free);


    return dp[i][total] = max(take, notTake);
}


int maximumSaleItems(vector<vector<int>>& items, int budget) {
    n = items.size();
    mini = INT_MAX;
    vector<int> free(n, 0);

    for(int i = 0; i < n; i++) {
        mini = min(mini, items[i][1]);
        for(int j = 0; j < n; j++) {
            if(items[j][0] % items[i][0] == 0) {
                free[i]++;
            }
        }
    }

    memset(dp, -1, sizeof(dp));

    return solve(0, budget, items, free);
}



int main() {
    int n; cout << "Enter number of items: ";
    cin >> n;
    vector<vector<int>> items;
    int budget; cout << "Enter budget: ";
    cin >> budget;
    cout << "Enter item details (value price): " << endl;
    for(int i = 0; i < n; i++) {
        int value, price;
        cin >> value >> price;
        items.push_back({value, price});
    }
    cout << maximumSaleItems(items, budget) << endl;
    return 0;
}