#include <iostream>
using namespace std;
//------------------------
int soma1(int a, int b)
{ b = a + b;
    return b;
}
//------------------------
int soma2(int &a, int b)
{ b = a + b;
    return b;
}
//------------------------
int soma3(int a, int &b)
{ b = a + b;
    return b;
}
//------------------------
int main()
{   int x=3, y=4;
    cout << "Valores iniciais x=" << x << " e y=" << y << endl;
    cout << "soma1(" << x << "," << y << ")" << endl;
    cout << soma1(x,y) << endl;
    cout << "soma2(" << x << "," << y << ")" << endl;
    cout << soma2(x,y) << endl;
    cout << "soma3(" << x << "," << y << ")" << endl;
    cout << soma3(x,y) << endl;
    cout << "Valores finais x=" << x << " e y=" << y << endl;
    return 0;
}
