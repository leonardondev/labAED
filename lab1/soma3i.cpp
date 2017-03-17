#include <iostream>
using namespace std;

void soma3(int X, int &Y){
    X = X + 5;
    Y = Y + 5;
}

int main(){
    int A, B;
    A = 0;
    B = 0;
    soma3(A,A);
    cout << A << " " << B << endl;
    soma3(B,A);
    cout << A << " " << B << endl;
    return 0;
}
