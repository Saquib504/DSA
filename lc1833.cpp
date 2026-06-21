#include <iostream>
#include <vector>
using namespace std;


//Greedy Approach -> Sorting the costs array so that we can get the lowest cost Ice cream first, also have to keep in mind that coins should be greater or or equal
// to the Ice cream to buy one.
//      TC -> O(NlogN)
//      SC -> O(1)

int maxIceCream1(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int n = costs.size();

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        if(costs[i] > coins || coins <= 0)break;
        else {
            cnt++;
            coins -= costs[i];
        }
    }

    return cnt;
}


//Approach-2 -> using a hashmap, to store the frequency of each cost so that we can iterate on each freq, and subtract that cost from thr coins and keep a count
//      TC -> O(N)
//      SC -> O(N)


int maxIceCream2(vector<int>& costs, int coins) {
    int n = costs.size();
    int cnt = 0;
    int maxELE = *max_element(costs.begin(), costs.end());

    int hash[maxELE+1];
    fill(hash, hash + maxELE, 0);

    for(auto x : costs) {
        hash[x]++;
    }

    for(int i = 1; i <= maxELE; i++) {
        if(coins <= 0) break;
        while(coins >= i && hash[i] > 0) {
            cnt++;
            coins -= i;
            hash[i]--;
        }
    }

    return cnt;
}


int main() {
    int n; cout << "Enter the number of Ice creams available: "; cin >> n;
    int coins; cout << "Enter total coins the boy have with him: "; cin >> coins;
    vector<int> costs(n);
    cout << "\nInput the costs of each Ice cream: ";
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    cout << "Maximum Ice cream the boy can buy is : " << maxIceCream1(costs, coins) << endl;
    return 0;
}