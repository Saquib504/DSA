#include <iostream>
using namespace std;


int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    int n = fruits.size();

    int unplaced = 0;

    for(int i = 0; i < n; i++) {
        bool placed = false;
        for(int j = 0; j < n; j++) {
            if(fruits[i] <= baskets[j]) {
                baskets[j] = -1;
                placed = true;
                break;
            }
        }
        if(placed == false) unplaced++;
    }

    return unplaced;
}

int main() {
    vector<int> fruits, baskets;
    cout << "Enter fruit values : ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        fruits.push_back(n);
    }
    cout << "Enter basket capacities : ";
    while(true) {
        int n; cin >> n;
        if(n == -1)break;
        baskets.push_back(n);
    }

    cout << "Total unplaced fruits are : " << numOfUnplacedFruits(fruits, baskets) << endl;
    return 0;
}