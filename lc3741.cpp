#include <iostream>
using namespace std;



int minimumDistance(vector<int>& nums) {
    unordered_map<int, vector<int>> indices;
    
    for (int i = 0; i < nums.size(); i++)
        indices[nums[i]].push_back(i);
    
    int minDist = INT_MAX;
    
    for (auto& t : indices) {
        vector<int> idx = t.second;
        int val = t.first;
        if (idx.size() < 3) continue;
        
        // Slide a window of 3 consecutive occurrences
        for (int i = 0; i + 2 < idx.size(); i++)
            minDist = min(minDist, 2 * (idx[i+2] - idx[i]));
    }
    
    return minDist == INT_MAX ? -1 : minDist;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 2, 3, 1};
    cout << minimumDistance(nums) << endl; // Output: 4
    return 0;
}