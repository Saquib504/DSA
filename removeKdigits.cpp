#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string removeKdigits(string num, int k) {
    string ans="";// this will represent the stack 
    for(auto ch: num){
        while(ans.size() && ch < ans.back() && k){
            ans.pop_back();
            k--;
        }
        if(ans.size()==0 && ch=='0')continue;
        ans.push_back(ch);
    }

    while(ans.size() && k--)ans.pop_back();

    if(ans.size()>0)return ans;
    return "0";
}


int main() {
    string num = "1807736";
    int k = 1;

    cout << removeKdigits(num, k) << endl;

    return 0;
}