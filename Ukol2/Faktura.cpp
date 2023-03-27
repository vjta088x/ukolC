#include "Faktura.hpp"
#include "Polozka.hpp"
Faktura::Faktura(int cislo, Osoba * osoba){
    this->cislo = cislo;
    this->osoba = osoba;
    Polozka p[999];
    this->polozky = p;
}
double Faktura::CelkovaCena(){
    double cena = 0;
    for(int i = 0; i < this->celkovy_pocet_polozek; i++){
        Polozka polozka = this->polozky[i];
        cena += polozka.GetCena();
    }
    return cena;
}

void Faktura::PridatPolozku(int cena, string name){
    if(this->celkovy_pocet_polozek >= 999){
        return;
    }
    Polozka polozka(cena, name);
    this->polozky[celkovy_pocet_polozek] = polozka;
    this->celkovy_pocet_polozek ++;
}
void Faktura :: OdebratPlozku(string name){
    for(int i = 0; i < this->celkovy_pocet_polozek; i++){
        if(this->polozky[i].GetNazev() == name){
            this->polozky[i] = 0;
            if(this->celkovy_pocet_polozek > i){
                for(int j = i; j < this->celkovy_pocet_polozek; j ++){
                    this->polozky[j-1] = this->polozky[j];
                }
            }
            this->celkovy_pocet_polozek --;
        }
    }
}
void Faktura :: UpravitCenuPolozky(string name, int new_cost){
     for(int i = 0; i < this->celkovy_pocet_polozek; i++){
        if(this->polozky[i].GetNazev() == name){
            this->polozky[i].SetCena(new_cost);
        }
    }
}

Faktura :: ~Faktura(){

}