# C++ projekt Notakto
Tegemist on projektiga aines LTAT.03.025 - Programmeerimine keeles C++.

Notakto on üks variant tavalisest trips-traps-trullist. 
Erinevus on selles, et mõlemad mängijad mängivad “X”-na ning **viiki pole võimalik jääda**. 
Mängu mängitakse ühel või mitmel laual. 
Kui laual on kolm X-i järjest, on laud surnud ja sellel laual ei saa enam mängida.

**Mängija, kes tegi viimase käigu viimasel laual, kaotab mängu.**

### CLI
CLI (*Command-line interface*) versioonis on võimalik:
* näha mängureegleid (alguses)
* valida mängulaudade arv, millel mängida;
* mängida AI vastu, kes suudab oma käigu panna ükskõik millisesse lauda;
* pärast mängu lõppu näha, kes oli võitja (*ei sulge programmi koheselt*)

CLI versioon on testitud järgmistes IDEs:
* VSCode
* CLion

### GUI
GUI (*Graphical user interface*) versioonis on võimalik:
- [x] näha mängureegleid (alguses ja ka pärast mängu)
- [x] mängida AI vastu
- [x] pärast mängu lõppu näha, kes oli võitja
- [x] alustada uut mängu (ülevalt vasakult nurgast) programmi sulgemata
- [ ] valida laudade arv
  - [ ] liikuda mööda laudu

GUI versioon on tesitud järgmistes IDEs:
* CLion
* Qt Creator

Tuleb panna tähele, et `CMakeLists.txt` failis tuleb Qt-s oleva kompileerija CMake asukoht
ära muuta enda asukohaks. See on kommentaariga märgitud. Võimalusel tuleb guugeldada, kui tekib lisaprobleeme kompileerimisel.