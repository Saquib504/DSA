#include <iostream>
using namespace std;

void f(int n, vector<int>&temp) {

    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            temp.push_back(i);

            while(n%i == 0)
                n = n/i;
                temp.push_back(i);
        }
    }
    if(n != 1)temp.push_back(n);
}


vector<vector<int>> returnList(vector<int>&nums) {
    vector<vector<int>> arr;

    for(auto num : nums) {
        vector<int>temp;
        f(num, temp);

        arr.push_back(temp);
    }

    return arr;
}


int main() {
    vector<int> nums = {2,3,4,5,6,7,8,9};

    vector<vector<int>> factors = returnList(nums);

    cout << "\n[";
    for(int i = 0; i < factors.size(); i++) {
        cout << "[";
        for(auto factor : factors[i]) {
            cout << factor << ",";
        }
        cout << "]";
    }
    cout << "]\n\n";

    return 0;

}