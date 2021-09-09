#include <iostream>

#include "NumberList.hpp"

using namespace std;

int main() {

    Number n = Number(501);
    Number n2 = Number(123);
    Number n3 = Number(5);

    cout << n.iAt(0) << endl;

    NumberList nl = NumberList(3);

    nl.insertAt(n, 0);
    nl.insertAt(n2, 1);
    nl.insertAt(n3, 2);

    Number* np = nl.get(0);

    cout << nl.get(0)->getValue() << endl;

    nl.sort();

    return 0;
}
