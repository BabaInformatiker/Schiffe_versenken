#ifndef SCHIFF_H
#define	SCHIFF_H
#include <vector>

using namespace std;

enum Status {Unbeschaedigt, Getroffen, Versenkt};
enum Ausrichtung {Nord, Ost, Sued, West};

class Schiffteil{
private:
    int m_reihe;
    int m_spalte;
    Status m_status;
public:
    Schiffteil();
    Schiffteil(int reihe, int spalte, Status status);
    int getReihe();
    int getSpalte();
    Status getStatus();
    void setStatus(Status status);
};


class Schiff {
public:
    Schiff(int reihe, int spalte, int laenge, Ausrichtung ausrichtung);
    ~Schiff();
    Status getStatus();
    bool belegt(int reihe, int spalte);
    bool beschuss(int reihe, int spalte);
    
private:
    vector<Schiffteil> vschiff;
};
#endif	

