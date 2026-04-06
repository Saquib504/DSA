#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    unordered_set<string> obs;
    for (auto &arr : obstacles) {
        obs.insert(to_string(arr[0]) + "," + to_string(arr[1]));
    }

    char ch = 'N';
    int x = 0, y = 0;
    int maxDist = 0;

    for (int curr : commands) {

        if (curr == -1) {
            if (ch == 'N') ch = 'E';
            else if (ch == 'E') ch = 'S';
            else if (ch == 'S') ch = 'W';
            else ch = 'N';

        } else if (curr == -2) {
            if (ch == 'N') ch = 'W';
            else if (ch == 'W') ch = 'S';
            else if (ch == 'S') ch = 'E';
            else ch = 'N';

        } else {

            if (ch == 'N') {
                for (int j = 0; j < curr; j++) {
                    if (obs.count(to_string(x) + "," + to_string(y + 1))) break;
                    y++;
                }
            } else if (ch == 'S') {
                for (int j = 0; j < curr; j++) {
                    if (obs.count(to_string(x) + "," + to_string(y - 1))) break;
                    y--;
                }
            } else if (ch == 'W') {
                for (int j = 0; j < curr; j++) {
                    if (obs.count(to_string(x - 1) + "," + to_string(y))) break;
                    x--;
                }
            } else if (ch == 'E') {
                for (int j = 0; j < curr; j++) {
                    if (obs.count(to_string(x + 1) + "," + to_string(y))) break;
                    x++;
                }
            }

            maxDist = max(maxDist, x * x + y * y);
        }
    }

    return maxDist;
}

int main() {
    vector<int> commands = {4,-1,4,-2,4};
    vector<vector<int>> obstacles = {{2,4}};
    cout << robotSim(commands, obstacles) << endl;
    return 0;

}