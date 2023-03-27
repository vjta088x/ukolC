#include "Polozka.hpp"

Polozka :: Polozka(int cena, string nazev){
    this->cena = cena;
    this->nazev = nazev;
}

int Polozka::GetCena(){
    return this->cena;
}
string Polozka :: GetNazev(){
    return this->nazev;
}
void Polozka :: SetCena(int cena){
    this->cena = cena;
}
Polozka :: ~Polozka(){
    
}