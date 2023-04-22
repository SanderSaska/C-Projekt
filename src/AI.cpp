#include "../lib/AI.h"
#include <string>
#include <random>
#include <algorithm>
#include <vector>
#include <ctime>


using namespace std;

void getKoikKaigud(Laud laud, vector<vector<int>> &koikKaigud) {
    vector<vector<string>> mangulaud = laud.getMLaud();
    int n = laud.getMSuurus();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mangulaud[i][j] == "*") {
                koikKaigud.push_back({i, j});
            }
        }
    }
}

void teeKaikAI(Manguvali manguvali) {
    vector<Laud> lauad = manguvali.getMLauad();
    vector<vector<int>> koikKaigud;
    int parimRate = 0;
    vector<vector<int>> parimadKaigud = {};
    vector<int> parimKaik = {};

    for (int i = 0; i < lauad.size(); ++i) {
        getKoikKaigud(lauad[i], koikKaigud);
        for (auto &kaik: koikKaigud) {
            Laud valitudLaud = lauad[i];
            lauad[i].sisesta(kaik[0], kaik[1]);
            int rate = getRate(valitudLaud.getMLaud());
            if (rate > parimRate) {
                parimRate = rate;
            }
            if (rate == parimRate) {
                kaik.insert(kaik.begin(), i);
                parimadKaigud.push_back(kaik);
            }
        }
    }

    std::srand(time(NULL));
    int random = rand() % parimadKaigud.size();
    parimKaik = parimadKaigud[random];
    lauad[parimKaik[0]].sisesta(parimKaik[1], parimKaik[2]);

    /*sample(parimadKaigud.begin(),
           parimadKaigud.end(),
           back_inserter(parimKaik),
           1,
           mt19937{random_device{}()}
    );*/
}

int getRate(vector<vector<string>> laud) {
    int rate = 1;
    if (kontrolli(laud, "X", 2)) {
        rate = 2;
        return rate;
    }
    if (kontrolli(laud, "X", 3)) {
        rate = 3;
        return rate;
    }
    return rate;
}
