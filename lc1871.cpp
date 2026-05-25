#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    int curr_max = 0;
    queue<int> q;
    q.push(0);


    while(!q.empty()) {
        int i = q.front();
        q.pop();

        if(i == n-1)
            return true;
        
        for(int j = max(i+minJump, curr_max); j <= min(i+maxJump, n-1); j++) {
            if(s[j] == '0')q.push(j);
        }

        curr_max = max(curr_max,i+maxJump+1);
    }

    return false;
}

int main() {
    cout<<endl;
    cout<< "LC1871: Jump Game VII" << endl;
    string s; cout << "Enter the binary string: ";
    cin >> s;
    int minJump,maxJump;
    cout << "Enter the minimum and maximum jump lengths: ";
    cin >> minJump >> maxJump;

    cout << "Can reach the end of the string: " << (canReach(s, minJump, maxJump) ? "True" : "False") << endl;
    cout << endl;
    return 0;
}