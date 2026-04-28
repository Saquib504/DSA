#include <iostream>
#include <vector>
using namespace std;


// vector<int> findvalidElements(vector<int> &nums) {
//     int n = nums.size();

//     if (n == 0) {
//         return {};
//     }

//     vector<int> leftMax(n), rightMax(n), ans;

//     leftMax[0] = nums[0];
//     for (int i = 1; i < n; i++) {
//         leftMax[i] = max(leftMax[i - 1], nums[i]);
//     }

//     rightMax[n - 1] = nums[n - 1];
//     for (int i = n - 2; i >= 0; i--) {
//         rightMax[i] = max(rightMax[i + 1], nums[i]);
//     }

//     for (int i = 0; i < n; i++) {
//         bool greaterThanAllLeft = (i == 0) || (nums[i] > leftMax[i - 1]);
//         bool greaterThanAllRight = (i == n - 1) || (nums[i] > rightMax[i + 1]);

//         if (greaterThanAllLeft || greaterThanAllRight) {
//             ans.push_back(nums[i]);
//         }
//     }

//     return ans;
// }


// long long minOps(vector<int>& nums) {
//     int n = nums.size();
//     if(n == 0) return 0;

//     long long minOps = 0;
//     for(int i = 0; i < n-1; i++) {
//         if(nums[i] > nums[i+1]) {
//             minOps += nums[i] - nums[i+1];
//         }
//     }
//     return minOps;
// }



string sortVowels(string s) {
    auto isVowel = [](char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    };
    
    map<char,int> freq, firstOcc;
    vector<int> pos;
    
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i])) {
            freq[s[i]]++;
            if (!firstOcc.count(s[i])) firstOcc[s[i]] = i;
            pos.push_back(i);
        }
    }
    
    // Collect unique vowels present
    vector<char> uv;
    for (auto& [c,f] : freq) uv.push_back(c);
    
    // Sort: freq desc, tie → first occurrence asc
    sort(uv.begin(), uv.end(), [&](char a, char b) {
        if (freq[a] != freq[b]) return freq[a] > freq[b];
        return firstOcc[a] < firstOcc[b];
    });
    
    // Expand sorted vowels
    string sv = "";
    for (char c : uv) sv += string(freq[c], c);
    
    // Place back
    for (int i = 0; i < pos.size(); i++)
        s[pos[i]] = sv[i];
    
    return s;
}



int main() {
    string s = "leetcode";
    cout << sortVowels(s) << endl; // Output: "leotcedeisacommunityforcoders"

    return 0;
}