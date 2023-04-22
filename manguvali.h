#ifndef PROJEKT_MANGUVALI_H
#define PROJEKT_MANGUVALI_H

#include <vector>
#include <iostream>
#include "laud.h"

class Manguvali {
private:
    std::vector<Laud> m_lauad;
    int m_laudadeArv;
public:
    explicit Manguvali(int laudadeArv);

    /// sisesta - Sisestab kindlale mängulauale käigu
    void sisesta(std::string sisestus, ///< - kasutaja sisestus
                 std::string kaija ///< - kes kaib
    );

    /// print - Väljastab terve mänguvälja (kõik mängulauad, kus mäng pole veel läbi)
    void print(std::ostream &os);
};


#endif //PROJEKT_MANGUVALI_H
