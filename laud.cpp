#include "laud.h"

using namespace std;


Laud::Laud() : m_suurus(3), m_laud(vector<vector<string>>(3, vector<string>(3, "*"))) {}

/*Laud::Laud(int n) : m_suurus(n), m_laud(vector<vector<string>>(n, vector<string>(n, "*"))) {}*/


void Laud::print(ostream &os) {
    for (int i = 0; i < m_suurus; ++i) {
        for (int j = 0; j < m_suurus; ++j) {
            if (j == m_suurus - 1) os << m_laud[i][j];
            else os << m_laud[i][j] << " | ";
        }
        os << '\n';
        if (i < m_suurus - 1) {
            for (int j = 0; j < m_suurus; ++j) {
                if (j == m_suurus - 1) os << string(1, '-');
                else os << string(1 + 3, '-');
            }
            os << '\n';
        }
    }
}

bool Laud::sisesta(int i, int j) {
    if (m_laud[i][j].compare("*") == 0) { // Kas antud koordinaatidel on tühi koht või mitte
        m_laud[i][j] = m_mangunupud[m_kaija]; // paneb nupu ära
        m_kaija = 1-m_kaija; // vahetab käigukorda
        return true;
    }
    else return false;
}

bool Laud::kontrolli(string kontrollija, int kordi) {
    // Kas reas on 3 X-i
    for (auto &rida:m_laud) {
        if (std::count(rida.begin(), rida.end(),"X") == kordi){
            return true;
        }
    }
    // Kas veerus on 3 X-i
    int loendur{0};
    for (int i = 0; i < m_suurus; ++i) {
        for (int j = 0; j < m_suurus; ++j) {
            if (m_laud[i][j].compare(kontrollija) == 0)
                loendur++;
        }
        if (loendur == kordi){
            return true;
        }
        loendur = 0;
    }
    // Kas peadiagonaalil on 3 X-i
    for (int i = 0; i < m_suurus; ++i) {
        if (m_laud[i][i].compare(kontrollija) == 0){
            loendur++;
        }
        if (loendur == kordi){
            return true;
        }
        loendur = 0;
    }
    // Kas kõrvaldiagonaalil on 3 X-i
    for (int i = 0; i < m_suurus; ++i) {
        if (m_laud[i][m_suurus-1-i].compare(kontrollija) == 0){
            loendur++;
        }
        if (loendur == kordi){
            return true;
        }
        loendur = 0;
    }
    return false;
}

bool Laud::onLopp() {
    // Kui laual pole ühtegi tärni ehk tühja välja, on mäng lõppenud
    bool lopp{true};
    for (auto &rida: m_laud){
        if(std::find(rida.begin(), rida.end(), "*") != rida.end()) {
            lopp = false; // Järelikult on tühi koht
        }
    }
    if (lopp){
        // Kui laual on kolm reas
        kontrolli("X", 3);
    }
    else return false;
}


