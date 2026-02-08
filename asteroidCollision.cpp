#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    int n = asteroids.size();
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        if(asteroids[i] > 0) {
            stk.push(asteroids[i]);
        }
        else {
            while(!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])) {
                stk.pop();
            }
            if(!stk.empty() && stk.top() == abs(asteroids[i]))
                stk.pop();
            else if(stk.empty() || stk.top() < 0)
                stk.push(asteroids[i]);
        }
    }

    vector<int> ans(stk.size());

    for(int i = ans.size()-1; i >= 0; i--) {
        ans[i] = stk.top();
        stk.pop();
    }
    return ans;
}

int main() {
    vector<int> arr = {5,10,-5};

    vector<int> res = asteroidCollision(arr);

    for(int x : res) {
        cout << x << " ";
    }cout << endl;

    return 0;
}