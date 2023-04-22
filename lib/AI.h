#ifndef PROJEKT_AI_H
#define PROJEKT_AI_H

#include "laud.h"
#include "manguvali.h"

void getKoikKaigud(class Laud laud);

int getRate(std::vector<std::vector<std::string>> laud);

void teeKaikAI(class Manguvali manguvali, std::vector<std::vector<int>> &kaigud);

#endif //PROJEKT_AI_H
