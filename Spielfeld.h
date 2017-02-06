#ifndef SPIELFELD_H
#define	SPIELFELD_H
#include <vector>

using namespace std;
class Schiff;
class Schiffteil;

class Spielfeld {
public:
    Spielfeld();
    ~Spielfeld();
    void ausgeben();
    void spielen();
    vector<Schiff> Schiffe;
private:
    vector<vector<char> >leinwand;
        
};

#endif

