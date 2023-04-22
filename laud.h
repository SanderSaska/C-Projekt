#ifndef PROJEKT_LAUD_H
#define PROJEKT_LAUD_H

#include <vector>
#include <string>
#include <iostream>

class Laud {
private:
    int m_suurus;
    std::vector<std::vector<std::string>> m_laud;
public:
    Laud();

    // hiljem --> explicit Laud(int n) ;

    /// print - Väljastab mängulaua
    void print(std::ostream &os ///< - kuhu väljastada
    );

    /// sisesta - Sisestab lauale nupu/käigu
    void sisesta(int i, ///< - rida [i][]
                 int j, ///< - veerg [][j]
                 std::string kaija ///< - kes kaib
    );
};


#endif //PROJEKT_LAUD_H
