#include "../lib/manguvali.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Konstruktor
Manguvali::Manguvali(int laudadeArv) : m_lauad(vector<Laud>(laudadeArv, Laud())), m_laudadeArv(laudadeArv) {}

bool Manguvali::sisesta(std::string sisestus) {
    if(sisestus.length() != 5){
        cout << "\nKäik ei ole sisestatud korrektselt!" << endl;
        return false;
    }
    string eraldaja{","};
    auto pos = sisestus.find(eraldaja);
    string osa = sisestus.substr(0, pos);
    sisestus.erase(0, pos + eraldaja.size());
    int lauaIdx = stoi(osa) - 1;

    //Kontroll, et sisestus ei oleks suurem, kui mängulaudasid
    if(stoi(osa) > m_laudadeArv){
        cout << "\nMängus ei ole nii palju laudasid!" << endl;
        return false;
    }

    pos = sisestus.find(eraldaja);
    osa = sisestus.substr(0, pos);
    sisestus.erase(0, pos + eraldaja.size());
    int i = stoi(osa) - 1;

    //Kontroll, et sisestus ei oleks suurem, kui mängulaua suurus
    if(stoi(osa) > m_lauad[lauaIdx].getMSuurus() || stoi(sisestus) > m_lauad[lauaIdx].getMSuurus()){
        cout << "\nMängulaud ei ole nii suur!" << endl;
        return false;
    }

    if (sisestus.find(eraldaja) != string::npos) {
        return false;
    } else {
        int j = stoi(sisestus) - 1;
        if (m_lauad[lauaIdx].sisesta(i, j) == true) return true;
    }
    return false;
}

void Manguvali::print(ostream &os) {
    int i = 1;
    for (auto &laud: m_lauad) {
        os << i << ". Laud\n";
        laud.print(os);
        os << '\n';
        i++;
    }
}

vector<Laud> &Manguvali::getMLauad() {
    return m_lauad;
}

int Manguvali::getMLaudadeArv() {
    return m_laudadeArv;
}


