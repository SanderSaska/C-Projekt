#ifndef PROJEKT_MANGUVALI_H
#define PROJEKT_MANGUVALI_H

#include <vector>
#include <iostream>
#include "laud.h"
/***
 * Programmeerimine keeles C++ (LTAT.03.025)
 * 2022/2023 kevadsemester
 *
 *  Projekt - Notakto
 *
 * Autor: Rühm AJ: Sander Saska, Jaanis Soosaar
 *
 **/

class Manguvali {
private:
    std::vector<class Laud> m_lauad; // mängulauad
    int m_laudadeArv; // mängulaudade arv
    int m_kaija = 0; // kelle kord on käia (0 on mängija, 1 on AI)
    std::vector<std::string> m_mangunupud = {"mängija", "AI"}; // mängijad

public:
    explicit Manguvali(int laudadeArv);

    std::vector<Laud> &getMLauad();

    int getMLaudadeArv();

    int getMKaija();

    const std::vector<std::string> &getMMangunupud();

    /// Sisestab kindlale mängulauale käigu
    /// \param sisestus - kasutaja sisestus
    /// \return Tagastab tõeväärtuse, kas käik sai tehtud või mitte
    bool sisesta(std::string sisestus);

    /// Väljastab terve mänguvälja (kõik mängulauad, kus mäng pole veel läbi)
    /// \param os - kuhu väljastada
    void print(std::ostream &os);

    /// Kontrollib, kas mängulaudadel on mängud lõppenud.
    /// Lõppenud mänguga lauad eemaldatakse
    /// \return Tõeväärtus, kas mänguväljas on veel pooleli olevaid mänge
    bool onLopp();

    /// Vahetab ära, kelle kord on käija
    void vahetaKaijat();
};


#endif //PROJEKT_MANGUVALI_H
