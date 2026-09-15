#include <iostream>
using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    return rec1[0] < rec2[2] && rec1[2] > rec2[0] && rec1[1] < rec2[3] && rec1[3] > rec2[1];
}

int main() {
    vector<int> rec1, rec2;
    cout << "Enter rectangle 1 : ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        rec1.push_back(n);
    }

    cout<<endl;
    cout << "Enter rectangle 2 : ";
    while(true) {
        int n; cin >> n;
        if(n == -1) break;
        rec2.push_back(n);
    }

    if(isRectangleOverlap(rec1, rec2)) {
        cout << "Overlap!";
    } else {
        cout << "Don't Overlap!";
    }cout<<endl;
    return 0;
}