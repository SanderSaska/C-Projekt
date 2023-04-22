#ifndef PROJEKT_LAUD_H
#define PROJEKT_LAUD_H

#include <vector>
#include <string>
#include <iostream>
#include "AI.h"

class Laud {
private:
    int m_suurus; // laua suurus (n x n)
    std::vector<std::vector<std::string>> m_laud; // mängulaud
    int m_kaija = 0; // kelle kord on käia
    std::vector<std::string> m_mangunupud = {"mängija", "AI"}; // mängijad

public:
    Laud();

    // hiljem --> explicit Laud(int n) ;

    /// Väljastab mängulaua
    /// \param os - kuhu väljastada
    void print(std::ostream &os);

    /// Sisestab lauale nupu/käigu
    /// \param i - rida [i][]
    /// \param j - veerg [][j]
    bool sisesta(int i, int j);

    /// Kontrollib, kas laual on mäng lõppenud
    /// \return Tagastab tõeväärtuse mängu lõppemisest laual
    bool onLopp();

    /// Kontrollib, kas antud sümbol esineb laual reas, veerus,
    /// peadiagonaalil või kõrvaldiagonaalil antud arv kordi
    /// \param kontrollija - sümbol, millega kontrollida
    /// \param kordi - mitu korda peab sümbol esinema
    /// \return Tõeväärtus, kas antud sümbol kordus antud arv kordi laual
    bool kontrolli(std::string kontrollija, int kordi);
};


#endif //PROJEKT_LAUD_H
