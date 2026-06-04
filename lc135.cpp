#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Using two arrays to store the number of candies needed from left and right side respectively
// Time complexity: O(3n), Space complexity: O(2n)
int candy1(vector<int>& ratings) {
    int n = ratings.size();
    int totalCandies = 0;

    int prefix[n], suffix[n];
    prefix[0] = 1;
    suffix[n-1] = 1;

    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            prefix[i] = prefix[i-1] + 1;
        }else prefix[i] = 1;
    }

    for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            suffix[i] = suffix[i+1] + 1;
        } else suffix[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        totalCandies += max(prefix[i], suffix[i]);
    }
    return totalCandies;
}

// Using one array to store the number of candies needed from left side and update it based on right side
// Time complexity: O(2n), Space complexity: O(n)
int candy2(vector<int>& ratings) {
    int n = ratings.size();

    int prefix[n], suffix[n];
    prefix[0] = 1;

    for(int i = 1; i < n; i++) {
        if(ratings[i] > ratings[i-1]) {
            prefix[i] = prefix[i-1] + 1;
        }else prefix[i] = 1;
    }

   for(int i = n-2; i >= 0; i--) {
        if(ratings[i] > ratings[i+1]) {
            prefix[i] = max(prefix[i], prefix[i+1] + 1);
        }
   }
   int totalCandies = accumulate(prefix, prefix + n, 0);
    return totalCandies;
}

//Using Slope method to calculate the number of candies needed
// Time complexity: O(n), Space complexity: O(1)
int candy3(vector<int>& ratings) {
   int n = ratings.size();
   int totalCandies = n; // Each child gets at least one candy
   int i = 1;

   while(i < n) {
    int peak = 0, valley = 0;

    if(ratings[i] == ratings[i-1]) {
        i++;
        continue;
    }

    while(i < n && ratings[i] > ratings[i-1]) {
        peak++;
        i++;
        totalCandies += peak;
    }

    while(i < n && ratings[i] < ratings[i-1]) {
        valley++;
        i++;
        totalCandies += valley;
    }

    totalCandies -= min(peak, valley);
   }
    return totalCandies;
}


int main() {
    int n;
    cout << "Enter the number of children: ";
    cin >> n;
    vector<int> ratings(n);
    cout << "Enter the ratings of the children: ";
    for(int i = 0; i < n; i++) {
        cin >> ratings[i];
    }
    cout << "Minimum number of candies needed: " << candy3(ratings) << endl;
    return 0;
}