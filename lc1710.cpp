#include <iostream>
#include <vector>
using namespace std;

static bool comparator(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
} 

int maxUnits(vector<vector<int>>& boxTypes, int truckSize) {
    int n = boxTypes.size();
    vector<pair<int, int>> items;
    for(int i = 0; i < n; i++) {
        items.push_back({boxTypes[i][1], boxTypes[i][0]});
    }
    sort(items.begin(), items.end(), comparator);

    int maxUnits = 0;

    for(auto [v,w] : items) {
        if(w <= truckSize) {
            maxUnits += v*w;
            truckSize -= w;
        }
        else {
            maxUnits += v * truckSize;
            break;
        }
    }

    return maxUnits;
}


int main() {
    cout << endl;
    cout << "LC1710: Maximum Units on a Truck" << endl;
    int n; cout << "Enter the number of box types: ";
    cin >> n;
    vector<vector<int>> boxTypes(n, vector<int>(2));
    cout << "Enter the number of boxes and units per box for each type:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> boxTypes[i][0] >> boxTypes[i][1];
    }
    int truckSize; cout << "Enter the truck size (number of boxes it can carry): ";
    cin >> truckSize;

    cout << "Maximum units that can be loaded onto the truck: " << maxUnits(boxTypes, truckSize) << endl;
    cout << endl;
    return 0;
}