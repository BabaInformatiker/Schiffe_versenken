#include "Spielfeld.h"
#include "Schiff.h"
#include <iostream>


Spielfeld::Spielfeld() {
    
    leinwand.resize(11);
    
    for (int i = 0; i < leinwand.size(); i++)
        leinwand[i].resize(11);
    
    for (int i = 0; i < leinwand.size(); i++)
        for (int j = 0; j < leinwand.size(); j++)
            leinwand[i][j] = '.';
    
    for (int i = 0; i < 11; i++){
        leinwand[0][0] = ' ';
        leinwand[0][i] = i - 1 + '0';
        leinwand[i][0] = i - 1 + '0';
    }
    
    Schiff s1(1, 1, 3, Sued);
    Schiff s2(5, 1, 4, Ost);
    Schiff s3(1, 3, 5, Ost);
    Schiff s4(7, 4, 2, Ost);
    Schiff s5(4, 7, 3, Sued);
    
    Schiffe.push_back(s1);
    /*Schiffe.push_back(s2);
    Schiffe.push_back(s3);
    Schiffe.push_back(s4);
    Schiffe.push_back(s5); */
}


Spielfeld::~Spielfeld() {
}

void Spielfeld::ausgeben(){
    
    for (int i = 0; i < leinwand.size(); i++) {
        
        for (int j = 0; j < leinwand.size(); j++){
            cout << leinwand[i][j] << " ";
            
        }
        cout << endl;
    }
}

void Spielfeld::spielen(){
    
    
    while (true){
        bool getroffen = false;
        ausgeben();    
        cout << "Welche Reihe und welche Spalte moechten sie beschießen? ";
        int r;
        int s;
        cin >> r;
        cin >> s;
        cout << endl;
        r++;
        s++;
            
    
        for (int i = 0; i < Schiffe.size(); i++){
            if (Schiffe[i].belegt(r - 1, s - 1) == true){
                leinwand[r][s] = '%';
                getroffen = true;
            }
    
            if (Schiffe[i].beschuss(r - 1, s - 1) == true)
                cout << "VERSENKT!!!  " << endl;
        }
        
        if (!getroffen)
            leinwand[r][s] = 'X';
        }
}
