#include <iostream>
using namespace std;

vector<int> f(int n) {
    vector<int> list;

    for(int i = 2; i <= sqrt(n); i++) {
        if(n%i == 0) {
            list.push_back(i);

            while(n%i == 0)n = n/i;
        }
    }
    if(n != 1)list.push_back(n);

    return list;
}


int main() {
    int n; cout << "Enter number : "; cin >> n;

    vector<int> factors = f(n);

    for(auto factor : factors) {
        cout << factor << ", ";
    }cout << endl;

    return 0;

}