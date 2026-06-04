#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;




//Striever Approved Code
static bool comparator(vector<int>& a, vector<int>& b) {
    return a[2] > b[2];
}
vector<int> JobScheduling(vector<vector<int>>& Jobs) { 
    //your code goes here
    int n = Jobs.size();
    int totalJobs = 0, maxProfit = 0, cnt = 0;

    sort(Jobs.begin(), Jobs.end(), comparator);

    for(int i = 0; i < n; i++) {
        //check if the deadline has passed or not
        if(Jobs[i][1] > cnt) {
            maxProfit += Jobs[i][2];
            cnt++;
            totalJobs++;
        }
    }

    return {totalJobs, maxProfit};
} 

//Changed code
ector<int> JobScheduling(vector<vector<int>>& Jobs) { 
    int n = Jobs.size();
    int totalJobs = 0, maxProfit = 0;

    sort(Jobs.begin(), Jobs.end(), comparator);

    int maxDeadline = 0;
    for (const auto& job : Jobs) {
        maxDeadline = max(maxDeadline, job[1]);
    }

    vector<int> slot(maxDeadline + 1, -1);

    for(int i = 0; i < n; i++) {
        for (int time = min(Jobs[i][1], maxDeadline); time > 0; time--) {
            if (slot[time] == -1) {
                slot[time] = Jobs[i][0];
                totalJobs++;
                maxProfit += Jobs[i][2];
                break;
            }
        }
    }

    return {totalJobs, maxProfit};
}

int main() {
    int n;cout << "Enter the number of jobs: ";
    cin >> n;
    vector<vector<int>> Jobs(n, vector<int>(3));
    cout << "Enter the job details (id, deadline, profit): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> Jobs[i][0] >> Jobs[i][1] >> Jobs[i][2];
    }
    vector<int> result = JobScheduling(Jobs);
    cout << "Total Jobs: " << result[0] << ", Max Profit: " << result[1] << endl;
    return 0;
}