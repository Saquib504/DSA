#include <iostream>
using namespace std;

vector<int> findMissingElements(vector<int>& nums) {
    bitset<101> hasx = 0;
    int xMin = 101, xMax = 0;

    for(int num : nums) {
        hasx[num] = 1;
        xMin = min(xMin, num);
        xMax = max(xMax, num);
    }

    vector<int> ans;
    for(int x = xMin+1; x < xMax; x++) {
        if(!hasx[x]) ans.push_back(x);
    }

    return ans;
}

int main() {
    vector<int> nums;
    cout << "Enter the elements of nums array(enter -1 to stop): ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        else nums.push_back(n);
    }

    vector<int> ans = findMissingElements(nums);
    cout << "The missing elements in the nums array are : ";
    if(ans.size() == 0) cout << "NIL" << endl;
    else {
        for(int num : ans) {
        cout << num << " ";
    }cout<<endl;}

    return 0;
}