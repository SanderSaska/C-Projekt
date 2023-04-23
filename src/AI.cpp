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

void teeKaikAI(Manguvali &manguvali) {
    vector<vector<int>> koikKaigud;
    int parimRate = 0;
    vector<vector<int>> parimadKaigud = {};
    vector<int> parimKaik = {};

    for (int i = 0; i < manguvali.getMLauad().size(); ++i) { // Vaatame iga mängulaua korral
        getKoikKaigud(manguvali.getMLauad()[i], koikKaigud); // Leiame mängulaua kõik võimalikud käidavad käigud
        for (auto &kaik: koikKaigud) { // Vaatame iga käigu korral
            Laud valitudLaud = manguvali.getMLauad()[i]; // Teeme lauast koopia
            valitudLaud.sisesta(kaik[0], kaik[1]); // Sisestame käigu lauale (koopia)
            int rate = getRate(valitudLaud.getMLaud()); // Saame hinnangut tehtud käigule
            if (rate > parimRate) { // Kas hinnang on parem kui eelmine
                parimadKaigud.clear(); // Kustutame eelnevad parimad käigud
                parimRate = rate;
            }
            if (rate == parimRate) { // Kui hinnang on sama
                kaik.insert(kaik.begin(), i); // Lisame käigule ka laua indeksi
                parimadKaigud.push_back(kaik);
            }
        }
        koikKaigud.clear();
    }
    // Valime suvalise käigu
    int random = rand() % parimadKaigud.size();
    parimKaik = parimadKaigud[random];
    manguvali.getMLauad()[parimKaik[0]].sisesta(parimKaik[1], parimKaik[2]);
    manguvali.vahetaKaijat();
}

int getRate(vector<vector<string>> &laud) {
    int rate = 2;
    if (kontrolli(laud, "X", 3)) { // Kui tehtud käiguga saab kolm ritta
        rate = 3; // Siis on võit
        return rate;
    }
    if (kontrolli(laud, "X", 2)) { // Kui tehtud käiguga saab kaks ritta
        rate = 1; // Siis vastane võidab
        return rate;
    }
    return rate;
}
