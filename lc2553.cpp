#include <iostream>
#include <vector>
using namespace std;


   vector<int> separateDigits(vector<int>& nums) {
    vector<int> res;
    
    for(int num : nums) {
        string s = to_string(num);
        for(char c : s) {
            res.push_back(c - '0');
        }
    }
    return res;
}


int main() {
    vector<int> nums = {32,43,68,8,100,84,80,14,88,42,53,98,69,64,40,60,23,99};
    vector<int> result = separateDigits(nums);

    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}