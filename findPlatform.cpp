#include <iostream>
#include <vector>
using namespace std;

int findPlatform(vector<int>& Arrival, vector<int>& Departure) {
    int n = Arrival.size(), i = 1, j = 0, platform = 1, cnt = 1;
    sort(Arrival.begin(), Arrival.end());
    sort(Departure.begin(), Departure.end());

    while(i < n && j < n) {
        if(Arrival[i] <= Departure[j]) {
            cnt++;
            i++;
        } else {
            cnt--;
            j++;
        }
        platform = max(platform, cnt);
    }
    return platform;
}

int main() {
    vector<int> Arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> Departure = {910, 1200, 1120, 1130, 1900, 2000};

    cout << findPlatform(Arrival, Departure) << endl;
    return 0;
}