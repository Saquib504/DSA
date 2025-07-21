#include <iostream>
using namespace std;

// BRUTE FORCE METHOD
// T.C -> O(NlogN + MlogM)
// S.C -> O(1)

int assignCookies(vector<int>&children, vector<int>&cookies) {
    int n = children.size(), m = cookies.size();
    int child = 0, cookie = 0;
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());

    while(child < n && cookie < m) {
        if(children[child] <= cookies[cookie]) {
            child++;
        }
        cookie++;
    }
    return child;
}


int main() {
    vector<int>children = {1,5,3,3,4};
    vector<int>cookies = {4,2,1,2,1,3};

    cout << "The number of children whose greed can be fulfilled is " << assignCookies(children, cookies) << endl;
    return 0;
}