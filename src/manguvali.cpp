#include "../lib/manguvali.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Konstruktor
Manguvali::Manguvali(int laudadeArv) : m_lauad(vector<Laud>(laudadeArv, Laud())), m_laudadeArv(laudadeArv) {}

bool Manguvali::sisesta(std::string sisestus) {
    if (sisestus.length() != 5) {
        cout << "\nKäik ei ole sisestatud korrektselt!" << endl;
        return false;
    }
    // Võtame mängulaua indeksi
    string eraldaja{","};
    auto pos = sisestus.find(eraldaja);
    string osa = sisestus.substr(0, pos);
    sisestus.erase(0, pos + eraldaja.size());
    int lauaIdx = stoi(osa) - 1;

    //Kontroll, et sisestus ei oleks suurem, kui mängulaudasid
    if (stoi(osa) > m_laudadeArv) {
        cout << "\nMängus ei ole nii palju laudasid!" << endl;
        return false;
    }
    // Võtame mängulaua rea indeksi
    pos = sisestus.find(eraldaja);
    osa = sisestus.substr(0, pos);
    sisestus.erase(0, pos + eraldaja.size());
    int i = stoi(osa) - 1;

    //Kontroll, et sisestus ei oleks suurem, kui mängulaua suurus
    if (stoi(osa) > m_lauad[lauaIdx].getMSuurus() || stoi(sisestus) > m_lauad[lauaIdx].getMSuurus()) {
        cout << "\nMängulaud ei ole nii suur!" << endl;
        return false;
    }
    // Kui sisestuses leidub veel sümbolit ','
    if (sisestus.find(eraldaja) != string::npos) {
        return false;
    } else {
        int j = stoi(sisestus) - 1; // Võtame mängulaua veeru indeksi
        if (m_lauad[lauaIdx].sisesta(i, j)) { // Sisestame mängulauda nupu
            vahetaKaijat(); // Vahetame käigukorda
            return true;
        }
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

bool Manguvali::onLopp() {
    for (int i = 0; i < m_laudadeArv; ++i) {
        Laud laud = m_lauad[i];
        if (laud.onLopp()) { // Kui mängulaual on mäng läbi
            laud.print(cout);
            cout << "Laud on 'surnud'\n"
                 << "selle mängulaua võitis "
                 << m_mangunupud[m_kaija]
                 << '\n';
            m_lauad.erase(m_lauad.begin() + i); // Eemaldame selle mänguväljalt
            m_laudadeArv--; // Vähendame mängulaudade arvu
        }
    }
    if (m_laudadeArv == 0) return true; // Kui rohkem pooleli olevaid mängulaude pole
    else return false; // Kui pooleli olevaid mängulaude on
}

vector<Laud> &Manguvali::getMLauad() {
    return m_lauad;
}

int Manguvali::getMLaudadeArv() {
    return m_laudadeArv;
}

int Manguvali::getMKaija() {
    return m_kaija;
}

const vector<std::string> &Manguvali::getMMangunupud() {
    return m_mangunupud;
}

void Manguvali::vahetaKaijat() { m_kaija = 1 - m_kaija; }


