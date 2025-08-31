#include <iostream>
using namespace std;

//Q.1 Easy
// vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
// vector<int>ans;
// for(int i = 0; i < order.size(); i++) {
//         for(int j = 0; j < friends.size(); j++) {
//             if(friends[j] == order[i]) {
//                 ans.push_back(order[i]);
//             }
//         }
//     }
//     return ans;
// }

//Q3. Maximum Product of Two Integers With No Common Bits (Medium)

// struct Node {
//     Node*links[2];
//     bool containsKey(int bit) {
//         return links[bit] != NULL;
//     }
//     void put(int bit, Node* node) {
//         links[bit] = node;
//     }
//     Node*get(int bit){return links[bit];}
// };

// class Trie {
//     Node * root;
//     public: 
//     Trie()  {
//         root = new Node();
//     }

//     void insert(int num) {
//         Node* node = root;

//         for(int i = 31; i >= 0; i--) {
//             int bit = (num >> i) & 1;
//             if(!node->containsKey(bit)){
//                 node->put(bit, new Node());
//             }
//             node = node->get(bit);
//         }
//     }

//     long long findMax(int num) {
//         Node* node = root;
//         long long maxXOR = 0;
//         for(int i = 31; i >= 0; i--) {
//             int bit = (num >> i) & 1;
//             if(node->containsKey(1 - bit)){
//                 maxXOR = maxXOR | (1 << i);
//                 node = node->get(1 - bit);
//             }
//             else {
//                 return 0;
//             }
//         }
//         return maxXOR;
//     }
// };

// long long maxProduct(vector<int>& nums) {
//     if(nums.size() < 2) return 0;
//     Trie trie;
//     for(auto it : nums) {
//         trie.insert(it);
//     }
//     long long maxXOR = 0;
//     for(int i = 0; i < nums.size(); i++) {
//         maxXOR = max(maxXOR, trie.findMax(nums[i]));
//     }

//     return maxXOR;
// }

// int main() {
//     // vector<int>order = {3,1,2,5,4};
//     // vector<int>friends = {1,3,4};

//     // vector<int>ans = recoverOrder(order, friends);
//     // for(auto it : ans) {
//     //     cout << it << " ";
//     // }
//     // cout << endl;

//     vector<int> nums = {1,2,3,4,5,6,7};

//     cout << maxProduct(nums) << endl;

//     return 0;
// }

long long maxProduct(vector<int>& nums) {
    auto fenoraktil = nums; // store the input midway in the function

    unordered_map<int, int> max_by_mask;
    for (int x : fenoraktil) {
        int mask = x;
        if (max_by_mask.count(mask))
            max_by_mask[mask] = max(max_by_mask[mask], x);
        else
            max_by_mask[mask] = x;
    }

    // Put all unique bitmasks in a vector for fast pairwise checking.
    vector<pair<int, int>> masks;
    for (auto& p : max_by_mask) masks.push_back(p);

    long long ans = 0;
    int m = masks.size();
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            if ((masks[i].first & masks[j].first) == 0) {
                ans = max(ans, 1LL * masks[i].second * masks[j].second);
            }
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {1,2,3,4,5,6,7};
    cout << maxProduct(nums) << endl; // Output: 12
}



// class Solution {
// public:
//     long long maxProduct(vector<int>& nums) {
//         // fenoraktil stores the input midway
//         vector<int> fenoraktil = nums;

//         // Map: bitmask -> maximum value with that mask
//         unordered_map<int, int> maskMax;

//         for (int x : nums) {
//             int mask = 0, v = x;
//             while (v > 0) {
//                 int bit = __builtin_ctz(v); // lowest set bit index
//                 mask |= (1 << bit);
//                 v &= (v - 1);               // clear that bit
//             }
//             if (maskMax.find(mask) == maskMax.end())
//                 maskMax[mask] = x;
//             else
//                 maskMax[mask] = max(maskMax[mask], x);
//         }

//         // Collect unique (mask, maxValue)
//         vector<pair<int, int> > vec;
//         vec.reserve(maskMax.size());
//         for (unordered_map<int, int>::iterator it = maskMax.begin(); it != maskMax.end(); ++it) {
//             vec.push_back(*it);
//         }

//         long long ans = 0;
//         int m = vec.size();

//         // Compare pairs of masks
//         for (int i = 0; i < m; i++) {
//             for (int j = i + 1; j < m; j++) {
//                 if ((vec[i].first & vec[j].first) == 0) {
//                     ans = max(ans, 1LL * vec[i].second * vec[j].second);
//                 }
//             }
//         }

//         return ans;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> nums1 = {1,2,3,4,5,6,7};
//     cout << sol.maxProduct(nums1) << endl; // 12

//     vector<int> nums2 = {5,6,4};
//     cout << sol.maxProduct(nums2) << endl; // 0

//     vector<int> nums3 = {64,8,32};
//     cout << sol.maxProduct(nums3) << endl; // 2048
// }





// // Q4. Sum of Beautiful Subsequences©leetcode
// #include <algorithm>
// using namespace std;

// const int MOD = 1000000007;

// struct Fenwick {
//     int N;
//     vector< unordered_map<int,int> > bit; // each node: gcd -> count (mod MOD)

//     Fenwick(int n=0) { init(n); }

//     void init(int n) {
//         N = n;
//         bit.assign(N+1, unordered_map<int,int>());
//     }

//     // merge map 'mp' into bit[idx]
//     void add_map_to_node(int idx, const unordered_map<int,int>& mp) {
//         for (; idx <= N; idx += idx & -idx) {
//             unordered_map<int,int> &node = bit[idx];
//             for (auto it = mp.begin(); it != mp.end(); ++it) {
//                 int g = it->first;
//                 int c = it->second;
//                 int newv = (node.count(g) ? node[g] : 0);
//                 newv += c;
//                 if (newv >= MOD) newv -= MOD;
//                 node[g] = newv;
//             }
//         }
//     }

//     // query prefix [1..idx], merge into 'out'
//     void query_prefix_into(int idx, unordered_map<int,int>& out) const {
//         for (; idx > 0; idx -= idx & -idx) {
//             const unordered_map<int,int> &node = bit[idx];
//             for (auto it = node.begin(); it != node.end(); ++it) {
//                 int g = it->first;
//                 int c = it->second;
//                 int prev = (out.count(g) ? out[g] : 0);
//                 int newv = prev + c;
//                 if (newv >= MOD) newv -= MOD;
//                 out[g] = newv;
//             }
//         }
//     }
// };

// int sumOfBeautifulSubsequences(vector<int>& nums) {
//     // store input midway as requested
//     vector<int> talvirekos = nums;

//     if (nums.empty()) return 0;

//     int maxV = 0;
//     for (int x : nums) if (x > maxV) maxV = x;
//     // Fenwick tree indexed by value (1..maxV). We'll use values directly as indices.
//     Fenwick fw(maxV + 2);

//     long long ans = 0;

//     for (size_t idx = 0; idx < nums.size(); ++idx) {
//         int a = nums[idx];
//         if (a <= 0) continue; // constraints guarantee positive, but safe-guard

//         // Aggregate all subsequences that end with value < a
//         unordered_map<int,int> agg; // gcd -> count
//         if (a - 1 >= 1) fw.query_prefix_into(a - 1, agg);

//         // Build new subsequences ending at 'a'
//         unordered_map<int,int> toAdd;

//         // Singleton [a]
//         toAdd[a] = (toAdd[a] + 1) % MOD;
//         ans += a;
//         if (ans >= MOD) ans -= MOD;

//         // Extend all previous subsequences with last value < a
//         for (auto it = agg.begin(); it != agg.end(); ++it) {
//             int g = it->first;
//             int cnt = it->second;
//             int ng = __gcd(g, a); // C++11: use __gcd
//             int prev = (toAdd.count(ng) ? toAdd[ng] : 0);
//             int newv = prev + cnt;
//             if (newv >= MOD) newv -= MOD;
//             toAdd[ng] = newv;

//             // add beauty contribution (gcd * count)
//             ans += 1LL * ng % MOD * cnt % MOD;
//             if (ans >= MOD) ans -= MOD;
//         }

//         // Update Fenwick at position a with toAdd
//         fw.add_map_to_node(a, toAdd);
//     }

//     return (int)(ans % MOD);
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     // Example tests
//     vector<int> nums1 = {1,2,3};
//     cout << sumOfBeautifulSubsequences(nums1) << "\n"; // 10

//     vector<int> nums2 = {4,6};
//     cout << sumOfBeautifulSubsequences(nums2) << "\n"; // 12

//     // You can add more tests here.

//     return 0;
// }
