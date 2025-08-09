#include <iostream>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>&arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int>count(n, 1), hash(n, 0);

    for(int i = 0; i < n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[i] % arr[prev] == 0 && 1 + count[prev] > count[i]) {
                count[i] = 1 + count[prev];
                hash[i] = prev;
            }
        }
    }

    int ans = -1; int lastIndex = -1;

    for(int i = 0; i < n; i++) {
        if(count[i] > ans){
            ans = count[i];
            lastIndex = i;
        }
    }

    vector<int>temp;
    temp.push_back(arr[lastIndex]);

    while(lastIndex != hash[lastIndex]) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main() {
    vector<int> arr = {0,1,16,7,8,4};

    vector<int> ans = largestDivisibleSubset(arr);

    cout << "The largest divisible subset length is " << ans.size() << endl;

    return 0;
}