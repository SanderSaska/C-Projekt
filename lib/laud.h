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

public:
    Laud();

    // hiljem --> explicit Laud(int n) ;

    int getMSuurus() const;

    std::vector<std::vector<std::string>> &getMLaud();

    /// Väljastab mängulaua
    /// \param os - kuhu väljastada
    void print(std::ostream &os);

    /// Sisestab lauale nupu/käigu
    /// \param i - rida [i][]
    /// \param j - veerg [][j]
    /// \return Tagastab tõeväärtuse, kas nupp sai asetatud või mitte
    bool sisesta(int i, int j);

    /// Kontrollib, kas laual on mäng lõppenud
    /// \return Tagastab tõeväärtuse mängu lõppemisest laual
    bool onLopp();
};

/// Kontrollib, kas antud sümbol esineb laual reas, veerus,
/// peadiagonaalil või kõrvaldiagonaalil antud arv kordi
/// \param laud - mängulaud, kus kontrollida
/// \param kontrollija - sümbol, millega kontrollida
/// \param kordi - mitu korda peab sümbol esinema
/// \return Tõeväärtus, kas antud sümbol kordus antud arv kordi laual
bool kontrolli(std::vector<std::vector<std::string>> laud, std::string kontrollija, int kordi);


#endif //PROJEKT_LAUD_H
