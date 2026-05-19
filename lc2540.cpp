#include <iostream>
using namespace std;


int getCommon(vector<int>&nums1, vector<int>& nums2) {
    int n = nums1.size(), m = nums2.size();
    int i = 0, j = 0;


    while(i < n && j < m) {
        if(nums1[i] == nums2[j]) {
            return nums1[i];
        }
        else if(nums1[i] < nums2[j])i++;
        else j++;
    }

    return -1;
}


int main() {
   vector<int> nums1 = {1,2,3,6};
   vector<int> nums2 = {2,3,4,5};

   int common = getCommon(nums1,nums2);

   if(common == -1) {
    cout << "There's no minimum common integer between the two arrays." << endl;
   } else {
    cout << "There is one minimum common integer '" << common << "' between the two arrays." << endl;
    return 0;
   }

}