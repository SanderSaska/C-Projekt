#include <iostream>
#include "laud.h"
#include "manguvali.h"

using namespace std;

const vector<string> m_mangijad = {"X", "O", "*"};

int main() {

cout << "Notakto" << endl
<< "Mängu eesmärk on asetada 3x3 lauale X-e. Kui laual on kolm X-i järjest, " 
<< "on laud surnud ja sellel laual ei saa enam mängida."
<< " Mängija, kes tegi viimase käigu viimasel laual, kaotab mängu. " << endl
<< "Palun vali laudade arv, millel hakkad mängima (1-5)." << endl;

int laudade_arv;

cin >> laudade_arv;

while((cin.fail() || laudade_arv > 5 || laudade_arv < 1) == true){
    cout << "Error: palun sisesta number 1-5!" << endl;
    cin.clear();
    cin.ignore(123, '\n');
    cin >> laudade_arv;
}

cout << "Alustan mängu " << laudade_arv << " lauaga." << endl;

Manguvali vali(laudade_arv);
vali.print(cout);
return 0;
}
