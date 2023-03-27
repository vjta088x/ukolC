#pragma once
#include "Osoba.hpp"
#include "Polozka.hpp"
#include <vector>

class Faktura{
    private:
        int cislo;
        Osoba* osoba;
        int celkovy_pocet_polozek;
        Polozka* polozky;
    public:
        Faktura(int cislo, Osoba * osoba);
        ~Faktura();
        double CelkovaCena();
        void PridatPolozku(int cena, string name);
        void OdebratPlozku(string name);
        void UpravitCenuPolozky(string name, int new_price);


};