#include <iostream>
using namespace std;


//Brute Force Approach
//Adding all elements in a set and checking for maximum XOR
// int findMaximumXOR(vector<int>&nums) {
//     int maxXOR = 0;
//     if(nums.size() < 2) return 0;
//     int n = nums.size();
//     for(int i = 0; i < n; i++) {
//         for(int j = i+1; j < n; j++) {
//             maxXOR = max(maxXOR, (nums[i] ^ nums[j]));
//         }
//     }
//     return maxXOR;
// }


//Optimal Approach using Trie
struct Node {
    Node*links[2];
    bool containsKey(int bit) {
        return links[bit] != NULL;
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node*get(int bit) {
        return links[bit];
    }
};

class Trie {
    Node*root;
    public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node*node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node*node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            //searching for opposite bit
            if(node->containsKey(1-bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            }
            //oppostie bit not found
            else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

int findMaximumXOR(vector<int>&nums) {
    Trie trie;
    int maxXOR = 0;
    if(nums.size() < 2) return 0;
    for(auto &it : nums) {
        trie.insert(it);
    }

    for(auto &it : nums) {
        maxXOR = max(maxXOR, trie.getMax(it));
    }
    return maxXOR;
}


int main(){

    vector<int>nums = {9,8,7,5,4};
    cout << findMaximumXOR(nums) << endl;

    return 0;
}