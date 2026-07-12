#include <iostream>
#include <map>
using namespace std;



vector<int> arrayRankTransform(vector<int>& arr) {
    map<int, int> rank;          // like B: sorted unique values -> rank
    for (int x : arr) rank[x] = 0;   // mark existence (like B[x+k] = i)

    int i = 1;
    for (auto& [val, r] : rank) r = i++;   // assign rank in ascending order

    vector<int> res;
    res.reserve(arr.size());
    for (int x : arr) res.push_back(rank[x]);  // A.map(n => B[n])
    return res;
}


int main() {
    vector<int> arr;
    cout << "Enter the elements in the array(stop by entering -1): \n";
    while(true) {
        int n;
        cin >> n;
        if(n == -1)break;
        else arr.push_back(n);
    }

    vector<int> ans = arrayRankTransform(arr);
    cout << "The rank for each element in the array is: ";
    for(int n : ans) {
        cout << n << " ";
    }cout<<endl;

    return 0;
}