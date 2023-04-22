#include <iostream>
#include "laud.h"
#include "manguvali.h"

using namespace std;

const vector<string> m_mangijad = {"X", "O", "*"};

int sissejuhatus(){//Sissejuhatus funktsioon mängu info andmiseks ja laudade arvu otsustamiseks.
    cout << "Notakto" << endl
    << "Mängu eesmärk on asetada 3x3 lauale X-e. Kui laual on kolm X-i järjest, " 
    << "on laud 'surnud' ja sellel laual ei saa enam mängida. "
    << "Mängija, kes tegi viimase käigu viimasel laual, kaotab mängu. " << endl
    << "Palun vali laudade arv, millel hakkad mängima (1-5)." << endl;

    int laudade_arv;

    cin >> laudade_arv;

    while((cin.fail() || laudade_arv > 5 || laudade_arv < 1) == true){
        cout << "Error: palun sisesta number 1-5!" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> laudade_arv;
    }
    cout << endl << "Alustan mängu " << laudade_arv << " lauaga." << endl;
    cout << "Palun sisesta käik kujul 'laua number, rea number, veeru number', kuhu soovid järgmise X-i asetada!" << endl
    << "Näide: $ 1,1,2 sisestab X-i esimesele mängulauale, esimesse ritta ning teise veergu.\n" << endl;
    return laudade_arv;
}

void lopetus(){//Lõpetusfunktsioon
    cout << "Viimane laud on 'surnud'. Mäng on lõppenud!" << endl;
}


int main() {

int laudade_arv = sissejuhatus();

Manguvali vali(laudade_arv);

vali.print(cout);

std::string kaija = "mangija";

while (laudade_arv > 0){ //Töötab, kuni lauad saavad otsa.
    std::string käik;
    cout << "Palun sisesta oma käik!" << endl;
    cin >> käik;
    while(cin.fail()==false /*&& vali.sisesta(käik, kaija)==true*/){ //Kontrollib, kas käigu sisestus on korrektne, kui ei, siis küsib uue sisestuse
        cout << "Error: palun sisesta oma käik korrektselt!" << endl;
        cout << "Palun sisesta käik kujul 'laua number, rea number, veeru number', kuhu soovid järgmise X-i asetada!" << endl
        << "Näide: $ 2,3,2 sisestab X-i teisele mängulauale, kolmandasse ritta ning teise veergu.\n" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> käik;
    }

    //siin on mängija käik tehtud
    vali.print(cout);

    //Kui laud sai surma siis annan teada, alles on laudade_arv - 1 lauda.

    //AI teeb oma käigu.
    vali.print(cout);

    //Kui laud sai surma siis annan teada, alles on laudade_arv - i lauda.



}

lopetus();

//Mänguskoor ja uuesti mängimine tuleb lõppversioonis.


return 0;
}
