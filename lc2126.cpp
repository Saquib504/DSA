#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// --------------MY SOLUTION------------------
// TC -> O(NlogN), SC -> O(1)
// bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//     int n = asteroids.size();
//     sort(asteroids.begin(), asteroids.end());
//     long long planet = mass;

//     for(int asteroid : asteroids) {
//         if(asteroid > planet) return false;
//         planet += asteroid;
//     }
//     return true;
// }


// --------------MY SOLUTION------------------
// TC -> O(N + xmax), SC -> O(xmax)
// bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
//     int n = asteroids.size();
//     int xmax = *max_element(asteroids.begin(), asteroids.end());
//     int xmin = *min_element(asteroids.begin(), asteroids.end());
//     vector<int> count(xmax+1, 0);

//     for(int asteroid : asteroids) {
//         count[asteroid]++;
//     }

//     long long planet = mass;

//     for(int asteroid = xmin; asteroid <= xmax; asteroid++) {
//         if(count[asteroid] == 0)continue;
//         if(asteroid > planet) return false;
//         planet += (long long)asteroid * count[asteroid];
//         count[asteroid] = 0;
//     }
//     return true;
// }

// --------------An-Wen Deng's SOLUTION------------------
unsigned freq[100001]={0};
static bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
    unsigned xmax=0, xmin=1e5;
    for(unsigned x: asteroids){
        freq[x]++;
        xmin=min(xmin, x);
        xmax=max(xmax, x);
    }
    long long planet=mass;// careful for overflow
    for(int x=xmin; x<=xmax; x++){
        if (freq[x]==0) continue;
        if (x>planet) {
            memset(freq+x, 0, (xmax-x+1)*sizeof(unsigned));
            return 0;
        }
        planet+=(long long)x*freq[x];
        freq[x]=0;
    }
    return 1;
}


int main() {
    int mass, n;
    cin >> mass >> n;
    vector<int> asteroids(n);
    for(int i = 0; i < n; i++) {
        cin >> asteroids[i];
    }
    cout << (asteroidsDestroyed(mass, asteroids) ? "true" : "false") << endl;
    return 0;
}