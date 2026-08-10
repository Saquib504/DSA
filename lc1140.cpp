#include <iostream>
using namespace std;


int n;
int memo[2][101][101];

int dfs(vector<int>& piles, int person, int idx, int M) {
    if(idx >= n) return 0;
    int result = person == 1 ? -1 : 1e9;
    int stones = 0;

    if(memo[person][idx][M] != -1)return memo[person][idx][M];

    for(int x = 1; x <= min(n-idx, 2*M); x++) {
        if(person == 1) {
            stones += piles[idx];
            result = max(result, stones + dfs(piles, 0, idx+x, max(M, x)));
        } else {
            stones += piles[idx];
            stones = min(result, stones + dfs(piles, 1, idx+x, max(M, x)));
        }
    }

    return memo[person][idx][M] = result;
}


int stoneGmaeII(vector<int> &piles) {
    memeset(memo, -1, sizeof(memo));
}


int main() {
    vector<int> piles;
    cout << "Enter the stones present in the piles(-1 to stop adding) : ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        piles.push_back(n);
    }

    cout << "Total stones Alice can capture is " << stoneGmaeII(piles) << endl;

    return 0;
}