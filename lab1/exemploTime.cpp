#include <iostream>
using namespace std;
//------------------------
// Definicao do tipo abstrato de dados Time
struct Time
{   int hour;       // 0 - 23
    int minute;     // 0 - 59
    int second;     // 0 - 59
};
//------------------------
void p1(Time t)
{   t.hour = 0;
    t.minute = 0;
    t.second = 0;
}
//------------------------
void p2(Time &t)
{   t.hour = 0;
    t.minute = 0;
    t.second = 0;
}
//------------------------
    int main()
{   Time almoco;
    // atribuir valores validos
    almoco.hour = 12;
    almoco.minute = 30;
    almoco.second = 15;
    cout << "Inicialmente, almoco sera servido as ";
    cout << almoco.hour << ":" << almoco.minute << ":" << almoco.second << endl;
    p1(almoco);
    cout << "Apos p1, almoco sera servido as ";
    cout << almoco.hour << ":" << almoco.minute << ":" << almoco.second << endl;
    p2(almoco);
    cout << "Apos p2, o almoco sera servido as ";
    cout << almoco.hour << ":" << almoco.minute << ":" << almoco.second << endl;

    return 0;
 }
