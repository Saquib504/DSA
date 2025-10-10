#include <iostream>
using namespace std;


int findXOR(int L, int R) {
    // complete the function here
    int n1=L-1;
    int xor1;
    if(n1%4==1){
        xor1=1;
    }
    else if(n1%4==2){
        xor1=n1+1;
    }
    else if(n1%4==3){
        xor1=0;
    }
    else{
        xor1=n1;
    }
    
    int n2=R;
    int xor2;
    if(n2%4==1){
        xor2=1;
    }
    else if(n2%4==2){
        xor2=n2+1;
    }
    else if(n2%4==3){
        xor2=0;
    }
    else{
        xor2=n2;
    }
    
    return xor1^xor2;
}

int main() {

    int l = 1, r = 10;

    int res = findXOR(l, r);

    cout << res << endl;

    return 0;
}