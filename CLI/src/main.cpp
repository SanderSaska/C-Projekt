#include <iostream>
#include "../lib/laud.h"
#include "../lib/manguvali.h"

using namespace std;
/***
 * Programmeerimine keeles C++ (LTAT.03.025)
 * 2022/2023 kevadsemester
 *
 *  Projekt - Notakto
 *
 * Autor: Rühm AJ: Sander Saska, Jaanis Soosaar
 *
 **/

int sissejuhatus() {//Sissejuhatus funktsioon mängu info andmiseks ja laudade arvu otsustamiseks.
    cout << "Notakto" << endl
         << "Mängu eesmärk on asetada 3x3 lauale X-e. Kui laual on kolm X-i järjest, "
         << "on laud 'surnud' ja sellel laual ei saa enam mängida. "
         << "Mängija, kes tegi viimase käigu viimasel laual, kaotab mängu. " << endl
         << "Palun vali laudade arv, millel hakkad mängima (1-5)." << endl;

    int laudade_arv;

    cin >> laudade_arv;

    while ((cin.fail() || laudade_arv > 5 || laudade_arv < 1) == true) {
        cout << "Error: palun sisesta number 1-5!" << endl;
        cin.clear();
        cin.ignore(123, '\n');
        cin >> laudade_arv;
    }
    cout << endl << "Alustan mängu " << laudade_arv << " lauaga." << endl;
    cout << "Palun sisesta käik kujul 'laua number, rea number, veeru number', kuhu soovid järgmise X-i asetada!"
         << endl
         << "Näide: $ 1,1,2 sisestab X-i esimesele mängulauale, esimesse ritta ning teise veergu.\n" << endl;
    return laudade_arv;
}

void lopetus(Manguvali vali) {//Lõpetusfunktsioon
    cout << "Viimane laud on 'surnud'. Mäng on lõppenud! Võitis " << vali.getMMangunupud()[vali.getMKaija()] << endl;
    cout << "Vajuta klahvi, et väljuda\n";
    system("pause > null");
}


int main() {

    std::srand(time(NULL));

    int laudade_arv = sissejuhatus();

    Manguvali vali(laudade_arv);

    vali.print(cout);

    while (laudade_arv > 0) { //Töötab, kuni lauad saavad otsa. // Vist peaks panema while(true){}, kui onLopp() töötab
        std::string käik;
        cout << "Palun sisesta oma käik!" << endl;
        cin >> käik;
        while (vali.sisesta(käik) ==
               false) { //Kontrollib, kas käigu sisestus on korrektne, kui ei, siis küsib uue sisestuse

            cout
                    << "\nPalun sisesta käik kujul 'laua number, rea number, veeru number', kuhu soovid järgmise X-i asetada!"
                    << endl
                    << "Näide: $ 2,3,2 sisestab X-i teisele mängulauale, kolmandasse ritta ning teise veergu.\n"
                    << endl;
            cin.clear();
            cin.ignore(123, '\n');
            cin >> käik;
        }

        //Siin on mängija käik tehtud

        if (vali.onLopp()) { //Kontrollime, kas kõik lauad on surnud.
            break;
        }

        vali.print(cout);

        cout << "AI teeb käigu\n" << endl;

        //AI teeb oma käigu.
        teeKaikAI(vali);

        if (vali.onLopp()) { //Kontrollime, kas kõik lauad on surnud.
            break;
        }

        vali.print(cout);


    }

    //Kui mäng jõuab siia, siis kontrollin, kelle käik oli viimati ning annan teada, et tema kaotas.

    lopetus(vali);

    //Mänguskoor ja uuesti mängimine tuleb lõppversioonis.


    return 0;
}
