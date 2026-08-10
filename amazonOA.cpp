#include <iostream>
#include <vector>
#include <climits>
using namespace std;



long long getMinCost(int n, vector<int> &arr) {
    if(n <= 1) return 0;
    long long minCost = LLONG_MAX;
    int i = 0; 

    while(i < n) {
        int start = i;

        while(i+1 < n && arr[i] == arr[i+1]) {
            i++;
        }

        int blockSize = i - start + 1;
        long long currentCost = 1LL * arr[start] * (n - blockSize);
        minCost = min(minCost, currentCost);

        i++;
    }

    return minCost;
}


int main() {
    int n; cout << "Enter the size of the array: "; cin >> n;
    vector<int> arr(n);
    cout << "Enter the element of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The total minimum cost of converting every single element to one specific element is " << getMinCost(n, arr) << endl;
    return 0;
}