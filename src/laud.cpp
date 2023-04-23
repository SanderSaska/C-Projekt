#include "../lib/laud.h"
#include <algorithm>
#include <string>
#include <vector>

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
        m_laud[i][j] = "X"/*m_mangunupud[m_kaija]*/; // paneb nupu ära
        return true;
    } else {
        cout << "\nTeie sisestatud koht on laual juba hõivatud!" << endl;
        return false;
    }
}

bool kontrolli(vector<vector<string>> laud, string kontrollija, int kordi) {
    int loendur{0};
    int n = laud.size();
    // Kas reas on 3 X-i
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laud[i][j] == kontrollija)
                loendur++;
        }
        if (loendur == kordi) {
            return true;
        }
        loendur = 0;
    }
    // Kas veerus on 3 X-i
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (laud[j][i] == kontrollija)
                loendur++;
        }
        if (loendur == kordi) {
            return true;
        }
        loendur = 0;
    }
    // Kas peadiagonaalil on 3 X-i
    for (int i = 0; i < n; ++i) {
        if (laud[i][i] == kontrollija) {
            loendur++;
            continue;
        }
        if (loendur == kordi) {
            return true;
        }
    }
    loendur = 0;
    // Kas kõrvaldiagonaalil on 3 X-i
    for (int i = 0; i < n; ++i) {
        if (laud[i][n - 1 - i] == kontrollija) {
            loendur++;
        }
        if (loendur == kordi) {
            return true;
        }
    }
    return false;
}

bool Laud::onLopp() {
    if (kontrolli(m_laud, "X", m_suurus)) return true; // Kui laual on kolm reas
    else return false; // Järelikult pole keegi võitnud veel
}

int Laud::getMSuurus() const {
    return m_suurus;
}

vector<vector<string>> &Laud::getMLaud() {
    return m_laud;
}
