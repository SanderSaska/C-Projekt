#ifndef PROJEKT_MANGUVALI_H
#define PROJEKT_MANGUVALI_H

#include <vector>
#include <iostream>
#include "laud.h"

class Manguvali {
private:
    std::vector<Laud> m_lauad; // mängulauad
    int m_laudadeArv; // mängulaudade arv
public:
    explicit Manguvali(int laudadeArv);

    /// Sisestab kindlale mängulauale käigu
    /// \param sisestus - kasutaja sisestus
    /// \return Tagastab tõeväärtuse, kas käik sai tehtud või mitte
    bool sisesta(std::string sisestus);

    /// Väljastab terve mänguvälja (kõik mängulauad, kus mäng pole veel läbi)
    /// \param os - kuhu väljastada
    void print(std::ostream &os);
};


#endif //PROJEKT_MANGUVALI_H
