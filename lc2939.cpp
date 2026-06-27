#include <iostream>
using namespace std;

static constexpr int MOD = 1000000007;

int maximumXorProduct(long long A, long long B, int N) {
    const long long MOD = 1e9 + 7;
    
    long long mask = (1LL << N) - 1;   // bits 0..N-1 set
    long long fixed_A = A & ~mask;     // bits >= N, X can never flip these
    long long fixed_B = B & ~mask;
    
    long long A_prime = 0, B_prime = 0;
    
    for (int i = N - 1; i >= 0; i--) {
        int a_bit = (A >> i) & 1;
        int b_bit = (B >> i) & 1;
        
        if (a_bit == b_bit) {
            // free bit: give it to both
            A_prime |= (1LL << i);
            B_prime |= (1LL << i);
        } else {
            // contested bit: give it to whichever total is currently smaller
            if ((fixed_A + A_prime) <= (fixed_B + B_prime)) {
                A_prime |= (1LL << i);
            } else {
                B_prime |= (1LL << i);
            }
        }
    }
    
    long long A_final = fixed_A + A_prime;
    long long B_final = fixed_B + B_prime;
    
    return ((A_final % MOD) * (B_final % MOD)) % MOD;
}

int main() {
    long long a, b;
    cout << "Enter A and B: "; cin >> a >> b;
    int n; cout << "Enter N: "; cin >> n;

    cout << "The maximum xor product is : " << maximumXorProduct(a, b, n) << endl;
    return 0;
}