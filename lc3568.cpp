#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

// TC -> O(MxNxmaxEnergyx2^10) ~ O(MxNxmaxEnergy)
// SC -> O(MxNxmaxEnergy) 
struct State {
    int row;
    int col;
    int energy;
    int bitMask;
};

using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VVVVB = vector<VVVB>;

int minMoves(vector<string>& classroom, int energy) {
    int m = classroom.size();
    int n = classroom[0].size();
    int litterCount = 0;
    int litterBit[20][20];
    int maxEnergy = energy;
    int sRow = -1, sCol = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (classroom[i][j] == 'S') {
                sRow = i;
                sCol = j;
            } else if (classroom[i][j] == 'L') {
                litterBit[i][j] = litterCount;
                litterCount++;
            }
        }
    }

    if (litterCount == 0) return 0;

    int allCollected = (1 << litterCount) - 1;
    int maskSize = 1 << litterCount;

    // energy dimension needs maxEnergy+1 (values 0..maxEnergy)
    VVVVB visited(m, VVVB(n, VVB(maxEnergy + 1, VB(maskSize, false))));

    queue<State> que;
    que.push({sRow, sCol, maxEnergy, 0});
    visited[sRow][sCol][maxEnergy][0] = true;
    int moves = 0;

    vector<pair<int, int>> dirs = {{0,-1}, {-1,0}, {0,1}, {1,0}};

    while (!que.empty()) {
        int sz = que.size();
        for (int i = 0; i < sz; i++) {
            State curr = que.front();
            que.pop();

            if (curr.bitMask == allCollected) return moves;
            if (curr.energy == 0) continue;

            for (auto dir : dirs) {
                int nRow = curr.row + dir.first;
                int nCol = curr.col + dir.second;

                if (nRow < 0 || nRow >= m || nCol < 0 || nCol >= n) continue;
                char cell = classroom[nRow][nCol];
                if (cell == 'X') continue;

                int nextEnergy = curr.energy - 1;   // every move costs 1 energy
                int nextBitMask = curr.bitMask;

                if (cell == 'R') nextEnergy = maxEnergy;   // reset, not decrement
                else if (cell == 'L') nextBitMask |= (1 << litterBit[nRow][nCol]);

                if (nextEnergy < 0) continue;  // safety guard, shouldn't trigger given the energy==0 check above

                if (!visited[nRow][nCol][nextEnergy][nextBitMask]) {
                    visited[nRow][nCol][nextEnergy][nextBitMask] = true;
                    que.push({nRow, nCol, nextEnergy, nextBitMask});
                }
            }
        }
        moves++;
    }

    return -1;
}

int main() {
    int energy;
    cout << "Enter total energy available: ";
    cin >> energy;
    cin.ignore();

    cout << "Enter the classroom grid, one row per line.\n";
    cout << "Use 'S' for start, 'L' for litter, 'R' for reset, 'X' for wall, '.' for empty.\n";
    cout << "Enter an empty line when finished:\n";

    vector<string> classroom;
    while (true) {
        string row;
        getline(cin, row);
        if (row.empty()) break;
        classroom.push_back(row);
    }

    if (classroom.empty()) {
        cout << "No grid entered.\n";
        return 0;
    }

    int result = minMoves(classroom, energy);
    if (result == -1) {
        cout << "It is not possible to collect all litter.\n";
    } else {
        cout << "Minimum moves required: " << result << "\n";
    }

    return 0;
}