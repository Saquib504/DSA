#include <iostream>
#include<unordered_map>
#include <unordered_set>
using namespace std;


int uniqueXorTriplets(vector<int>& nums) {
    vector<int> u_nums = nums;
    sort(u_nums.begin(), u_nums.end());
    u_nums.erase(unique(u_nums.begin(), u_nums.end()), u_nums.end());

    vector<bool> u_xors(2048, false);
    vector<int> u_pairs;
    int n = u_nums.size();

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int p = u_nums[i] ^ u_nums[j];
            if(!u_xors[p]) {
                u_xors[p] = true;
                u_pairs.push_back(p);
            }
        }
    }

    vector<bool> triplet_xors(2048, false);
    int cnt = 0;

    for(int p : u_pairs) {
        for(int c : nums) {
            int t_xor = p ^ c;
            if(!triplet_xors[t_xor]) {
                triplet_xors[t_xor] = true;
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    vector<int> nums;

    cout << "\nEnter the elements in the nums array : ";
    while(true) {
        int n; 
        cin >> n;
        if(n == -1)break;
        else {
            nums.push_back(n);
        }
    }

    cout << "\nMax unique XOR triplets : " << uniqueXorTriplets(nums) << endl;
    return 0;
}