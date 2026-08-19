#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//Approach-1
// TC -> O(N)xO(10^4),      SC -> O(N)  ----> We are using extra space for storing corresponding seats for a row i nthe map data structure
//instead we could use bitmask to store the location of the seat for the specific row in the map data structure, that's more reliant and is optimal space 
int maxNumberOfFamiliesI(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, unordered_set<int>> mpp;

    for(auto& reservedSeat : reservedSeats) {   //O(N)
        int row = reservedSeat[0];
        int seat = reservedSeat[1];
        mpp[row].insert(seat);
    }

    int result = (n-mpp.size())*2;

    for(auto& [row, bookedSeats] : mpp) {   //O(10^4)
        auto isAvail = [&](int seat) {
            return bookedSeats.find(seat) == bookedSeats.end(); //O(1) 
        };

        bool GroupA = isAvail(2) && isAvail(3) && isAvail(4) && isAvail(5);
        bool GroupB = isAvail(4) && isAvail(5) && isAvail(6) && isAvail(7);
        bool GroupC = isAvail(6) && isAvail(7) && isAvail(8) && isAvail(9);

        if(GroupA && GroupC) {
            result += 2;
        } else if(GroupA || GroupB || GroupC) {
            result += 1;
        }
    }

    return result;
}

//Approach-2    ---> Using Bitmask
// Improvement in space complexity

int maxNumberOfFamiliesII(int n, vector<vector<int>>& reservedSeats) {
    unordered_map<int, int> mpp;

    for(auto& reservedSeat : reservedSeats) {   //O(N)
        int row = reservedSeat[0];
        int seat = reservedSeat[1];
        mpp[row] |= (1 << seat);
    }

    int result = (n-mpp.size())*2;

    bool maskA = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
    bool maskB = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
    bool maskC = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

    for(auto& [row, bookedSeatsMask] : mpp) {   //O(10^4)
        

        bool GroupA = (maskA & bookedSeatsMask) == 0;
        bool GroupB = (maskB & bookedSeatsMask) == 0;
        bool GroupC = (maskC & bookedSeatsMask) == 0;

        if(GroupA && GroupC) {
            result += 2;
        } else if(GroupA || GroupB || GroupC) {
            result += 1;
        }
    }

    return result;
}


int main() {
    int n; cout << "Enter the number of rows in the cinema: "; cin >> n;
    vector<vector<int>> reservedSeats;
    cout << "Enter the [row, seat] that are already booked: \n";
    while(true) {
        int row, seat; cin >> row >> seat;
        if(row == -1 || seat == -1)break;
        reservedSeats.push_back({row, seat});
    }

    cout << "Maximum number of four-person groups that can be assigned is " << maxNumberOfFamiliesII(n, reservedSeats) << endl;
    return 0;
}