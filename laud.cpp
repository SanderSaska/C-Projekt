#include "laud.h"

using namespace std;


Laud::Laud() : m_suurus(3), m_laud(vector<vector<string>>(3, vector<string>(3, m_mangijad[2]))) {}

/*Laud::Laud(int n) : m_suurus(n), m_laud(vector<vector<string>>(n, vector<string>(n, " "))) {}*/


void Laud::print(ostream &os) {
    for (int i = 0; i < m_suurus; ++i) {
        for (int j = 0; j < m_suurus; ++j) {
            if (j == m_suurus - 1) os << m_laud[i][j];
            else os << m_laud[i][j] << " | ";
        }
        os << '\n';
        if (i < m_suurus - 1){
            for (int j = 0; j < m_suurus; ++j) {
                if (j == m_suurus - 1) os << string(1, '-');
                else os << string(1+3, '-');
            }
            os << '\n';
        }
    }
}