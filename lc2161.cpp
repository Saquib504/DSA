#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int n = nums.size();
    vector<int> answer(n);
    int equalPivot = 0;
    int i = 0;
    int pivotIDX = 0;

    for(int num : nums) {
        if(num < pivot) {
            answer[i++] = num;
        } else {
            equalPivot += (num == pivot);
        }
    }

    pivotIDX = i;

    while(equalPivot--) {
        answer[i++] = pivot;
    }

    for(int num : nums) {
        if(num > pivot) {
            answer[i++] = num;
        }
    }


    return answer;
}

int main() {
    int pivot;
    cout << "Enter pivot: ";
    cin >> pivot;
    vector<int> nums;
    cout << "Enter numbers (end with -1): ";
    while(true) {
        int num;
        cin >> num;
        if(num == -1)break;
        nums.push_back(num);
    }
    vector<int> answer = pivotArray(nums, pivot);
    for(int num : answer) {
        cout << num << " ";
    }cout<<endl;
}