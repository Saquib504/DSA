#include <iostream>
using namespace std;

vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> answer;
    int val = 0;

    for(auto x : nums) {
        val = (val*2 + x)%5;
        answer.push_back(val == 0);
    }

    return answer;
}


int main() {
    vector<int> nums = {0, 1, 1};
    vector<bool> result = prefixesDivBy5(nums);
    for(bool res : result) {
        cout << (res ? "true" : "false") << " ";
    }
    cout << endl;
    return 0;
}