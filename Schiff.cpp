#include "Schiff.h"
#include <vector>

using namespace std;




Schiffteil::Schiffteil(int reihe, int spalte, Status status){
    m_reihe = reihe;
    m_spalte = spalte;
    m_status = status;
}

Status Schiffteil::getStatus(){
    return m_status;
}

int Schiffteil::getReihe(){
    return m_reihe;
} 

int Schiffteil::getSpalte(){
    return m_spalte;
}

void Schiffteil::setStatus(Status status){
    m_status = status;
}

Schiff::Schiff(int reihe, int spalte, int laenge, Ausrichtung ausrichtung) {
          
    for (int i = 0; i < laenge; i++){
        if (ausrichtung == Nord){           
            vschiff.push_back(Schiffteil(reihe - i, spalte, Unbeschaedigt));
        }
        if (ausrichtung == Ost){
            Schiffteil s(reihe, spalte + i, Unbeschaedigt);
            vschiff.push_back(s);
        }
        if (ausrichtung == Sued){
            Schiffteil s(reihe + i, spalte, Unbeschaedigt);
            vschiff.push_back(s);
        }
        if (ausrichtung == West){
            Schiffteil s(reihe, spalte - i, Unbeschaedigt);
            vschiff.push_back(s);
        }
    }   
}

Schiff::~Schiff() {
}

Status Schiff::getStatus(){
    int status = 0;
    
    for(int i = 0; i < vschiff.size(); i++){
        if (vschiff[i].getStatus() == Getroffen)
            status++;
       
    }
        
    if (status == 0)
        return Unbeschaedigt;
    
    if (status > 0 && status < vschiff.size())
        return Getroffen;
    
    if (status == vschiff.size())
        return Versenkt;

}

bool Schiff::belegt(int reihe, int spalte){
    
    for(int i = 0; i < vschiff.size(); i++){
        if (vschiff[i].getReihe() == reihe && vschiff[i].getSpalte() == spalte)
            return true;
    }
  return false;      
}

bool Schiff::beschuss(int reihe, int spalte){
    
    for(int i = 0; i < vschiff.size(); i++) {
        if (vschiff[i].getReihe() == reihe && vschiff[i].getSpalte() == spalte)
            vschiff[i].setStatus(Getroffen);
        if (getStatus() == Versenkt )    
            return true;
        
    }
    return false;
}
