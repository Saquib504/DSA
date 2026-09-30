#include <iostream>
using namespace std;

vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ans;
    int cnt = 0;

    for(auto &ch : seq) {
        if(ch == '(') {
            cnt++;
            ans.push_back(cnt % 2);
        } else {
            ans.push_back(cnt % 2);
            cnt--;
        }
    }

    return ans;
}


int main() {
    string seq;
    cout << "Enter Sequence : "; cin >> seq;

    vector<int> ans = maxDepthAfterSplit(seq);

    for(auto x : ans) {cout << x << " ";}
    cout<<endl;
    return 0;
}