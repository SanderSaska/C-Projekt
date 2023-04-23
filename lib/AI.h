#ifndef PROJEKT_AI_H
#define PROJEKT_AI_H

#include "laud.h"
#include "manguvali.h"
/***
 * Programmeerimine keeles C++ (LTAT.03.025)
 * 2022/2023 kevadsemester
 *
 *  Projekt - Notakto
 *
 * Autor: Rühm AJ: Sander Saska, Jaanis Soosaar
 *
 **/


/// Leiab kõik võimalikud käigud ühel laual
/// \param laud - mängulaud, kust otsida
void getKoikKaigud(class Laud laud);

/// Leiab hinnangu tehtud käigule
/// \param laud - mängulaud, kuhu käik on tehtud
/// \return Hinnang tehtud käigule
int getRate(std::vector<std::vector<std::string>> &laud);

/// Tehisintellekt (AI) teeb käigu
/// \param manguvali - mänguväli, kus on mängulauad
void teeKaikAI(class Manguvali &manguvali);

#endif //PROJEKT_AI_H
