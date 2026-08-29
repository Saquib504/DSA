#include <iostream>
using namespace std;

// TC -> O(NlogN)
// SC -> O(N)
vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    int id = -1;
    vector<vector<int>> grps;
    unordered_map<int, int> map;

    for(int i = 0; i < n; i++) {
        if(i == 0 || sorted[i] - sorted[i-1] > limit) {
            grps.push_back({});
            id++;
        }

        grps[id].push_back(sorted[i]);
        map[sorted[i]] = id;
    }

    vector<int> idx(grps.size(), 0);

    for(int i = 0; i < n; i++) {
        int curr = map[nums[i]];
        nums[i] = grps[curr][idx[curr]];
        idx[curr]++;
    }

    return nums;
}


int main() {
    vector<int> nums; int limit;
    cout << "Enter elements in the nums array: ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        nums.push_back(n);
    }
    cout << "Enter the limit: "; cin >> limit;

    vector<int> res = lexicographicallySmallestArray(nums, limit);
    cout << "The Lexicographically Smallest Array by Swapping Elements is : ";
    for(auto num : res) {
        cout << num << " ";
    }cout<<endl;
    return 0;
}