#include <iostream>
#include <math.h>
using namespace std;

static constexpr int MAX = 31623;
int maximumLength(vector<int>& nums) {
    int freq[MAX] = {0};
    bitset<MAX> ps;

    for(auto &n : nums) {
        if(n < MAX)freq[n]++;

        int sq = sqrt(n);
        if(sq*sq == n)ps.set(sq);
    }

    int res = max(1, (freq[1]-1) | 1);

    for(int i = 2; i < MAX; i++) {
        if(!freq[i]) continue;
        int sq = sqrt(i);
        if(sq*sq == i && freq[sq] > 1) continue;

        int n = 0, x = i;

        while(x < MAX && freq[x] > 1 && ps.test(x)){
            n += 2;
            x *= x;
        }

        res = max(res, n+1);
    }

    return res;
}


int main() {
    int n; cout << "Enter the number of elements: "; cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "\nMax number of elements in the subset are: " << maximumLength(nums) << endl;
    return 0;
}