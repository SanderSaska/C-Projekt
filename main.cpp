#include <iostream>
#include "laud.h"
#include "manguvali.h"

using namespace std;

const vector<string> m_mangijad = {"X", "O", "*"};

int main() {
    Manguvali vali(2);
    vali.print(cout);
    return 0;
}
