#include <iostream>
#include <vector>
using namespace std;


char processStr(string s, long long k) {
    
    long long n = s.size();
    long long CAP = 2000000000000000LL;
    vector<long long> lens(n);
    long long len = 0;

    for(int i = 0; i < n; i++) {
        if(s[i] >= 'a' && s[i] <= 'z') {
            len+=1;
        }
        else if(s[i] == '#') {
            len *= 2;
        }
        else if(s[i] == '*') {
            if(len > 0) len -= 1;
        }

        if(len > CAP) len = CAP;
        lens[i] = len;
    }


    long long finalLen = (n == 0) ? 0 : lens[n-1];
    //check the bounds of k with final Length of the resultant string
    if(k < 0 || k >= finalLen) {
        return '.';
    }


    //run a loop to check backwards for the correct position of the resultant character
    for(long long i = n-1; i >= 0; i--) {
        long long lenBefore = (i == 0) ? 0 : lens[i-1];
        long long currLen = lens[i];
        long long halfLen = lenBefore;

        if(s[i] >= 'a' && s[i] <= 'z') {
            
            if(k == currLen - 1) {
                return s[i];
            }
        }
        else if(s[i] == '#') {
            
            if(k >= halfLen) {
                k -= halfLen;
            }
        }
        else if(s[i] == '%') {
            k = currLen - 1 - k;
        }
    }
    //nothing is found
    return '.';
}


int main() {
    string s;long long k;
    cout << "\nInput: ";  cin >> s;
    cout << "\nEnter k: ";cin >> k;
    char ans = processStr(s, k);
    cout << "\nThe resultant string is : " << ans << endl;

    return 0;
}