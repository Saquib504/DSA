#include <iostream>
using namespace std;

int majorElement(vector<int>&votes) {
    int n = votes.size();
    int count  = 0;
    int candid = votes[0];

    for(int i = 1; i < n; i++) {
        //if got the some candid
        if(votes[i] == candid) {
            count++;
        }

        //if candid are diffrent
        else if(votes[i] != candid) {
            count--;
        }
        if(count == 0) {
            candid = votes[i];
            count = 1;
        }
    }

    count = 0;
    for(int i = 0; i < n; i++) {
        if(votes[i] == candid) count++;
    }

    if(count > n/2) {
        return candid;
    }
    return -1;
    
}

int main() {

    vector<int> votes = {1,1,2,2,3,3,1,1,1,};


    int ans = majorElement(votes) != -1 ? majorElement(votes) : -1;

    if(ans != -1) {
    cout << "Majortiy votes goes to " << majorElement(votes) << endl;
    }
    else {
        cout << "There is no candidate who got the majority of the votes, sadly!! " << endl;
    }

    return 0;
}