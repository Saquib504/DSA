#include <iostream>
using namespace std;

static bool comparator(int a, int b) {
    return a > b;
}

// --------------MY SOLUTION------------------
// TC -> O(NlogN), SC -> O(1)
int minimumCost(vector<int>& cost) {
    int n = cost.size(), sum = 0;
    sort(cost.begin(), cost.end(), comparator);

    for(int i = 0; i < n; i++) {
        if((i+1)% 3) {
            sum += cost[i];
        }
    }
    return sum;
}


// --------------MY SOLUTION------------------
// TC -> O(N + M), SC -> O(M)
int minimumCost(vector<int>& cost) {
    int freq[101]={0}, M=0, n=cost.size();
    for(int x: cost) {
        freq[x]++;
        M=max(x, M);
    }
    int sz=0, r=0, sum=0;
    for(int x=M; sz<n; x--){
        int f=freq[x];
        while (f-->0){
            sz++;
            if (sz%3==0) break;
            else sum+=x;
        }
        if (f<=0) continue;
        auto [q, r]=div(f, 3);
        sum+=(2*q+r)*x;
        sz+=f;
    }
    return sum;
}

int main() {
    vector<int> cost = {1, 2, 3, 4};
    cout << minimumCost(cost) << endl;
}