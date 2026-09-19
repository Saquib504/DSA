#include <iostream>
#include <algorithm>
using namespace std;


bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    int x = clamp(xCenter, x1, x2) - xCenter;
    int y = clamp(yCenter, y1, y2) - yCenter;

    return x*x + y*y <= radius*radius;
}


int main() {
    int radius, xC, yC, x1, x2, y1, y2;
    cout << "Enter radius, xCenter, yCenter, x1, x2, y1, y2 : "; cin >> radius >> xC >> yC >> x1 >> x2 >> y1 >> y2;

    if(checkOverlap(radius, xC, yC, x1, y1, x2, y2)){
        cout << "Overlap!!" << endl;
    } else {
        cout << "Do not Overlap!" << endl;
    }

    return 0;
}