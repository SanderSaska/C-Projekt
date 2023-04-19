#ifndef PROJEKT_LAUD_H
#define PROJEKT_LAUD_H

#include <vector>
#include <string>
#include <iostream>

class Laud {
private:
    int m_suurus;
    std::vector<std::string> m_mangijad= {"X", "O", "*"};
    std::vector<std::vector<std::string>> m_laud;
public:
    Laud();
    // hiljem --> explicit Laud(int n) ;
    /// print - väljastab mängulaua
    void print(std::ostream &os ///< - kuhu väljastada
    );
};


#endif //PROJEKT_LAUD_H
