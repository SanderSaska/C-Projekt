#include "../lib/manguvali.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Konstruktor
Manguvali::Manguvali(int laudadeArv) : m_lauad(vector<Laud>(laudadeArv, Laud())), m_laudadeArv(laudadeArv) {}

bool Manguvali::sisesta(std::string sisestus) {
    string eraldaja{","};
    auto pos = sisestus.find(eraldaja);
    string osa = sisestus.substr(0, pos);
    sisestus.erase(0, pos);
    int lauaIdx = stoi(osa) - 1;

    pos = sisestus.find(eraldaja);
    osa = sisestus.substr(0, pos);
    sisestus.erase(0, pos);
    int i = stoi(osa) - 1;

    if (sisestus.find(eraldaja) != 0) {
        return false;
    } else {
        int j = stoi(sisestus) - 1;
        return m_lauad[lauaIdx].sisesta(i, j);
    }
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


